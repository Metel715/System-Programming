#include "../include/client.h"
#include <pthread.h>

#define PING_COUNT 10
int sk;
int pid;
int count_rcv = 0;

unsigned short compute_checksum(unsigned short *addr, unsigned int count) {
        unsigned long sum = 0;

        while (count > 1) {
                sum += *addr++;
                count -= 2;
        }

        if(count > 0) {
                sum += ((*addr)&htons(0xFF00));
        }

        while (sum>>16) {
                sum = (sum & 0xffff) + (sum >> 16);
        }

        sum = ~sum;
        return ((unsigned short)sum);
}

void pr_pack(char *buf, int cc, struct sockaddr_in *from){
	struct icmp *icmp = NULL;
	/*struct iphdr *iph = NULL;*/

	icmp = (struct icmp*) (buf + sizeof(struct iphdr));
	/*iph = (struct iphdr*) buf;*/

	if (icmp->icmp_type == ICMP_ECHOREPLY){
		if (icmp->icmp_id != pid){
			return;
		}
		count_rcv++;
		printf("%d bytes from %s: icmp_seq=%u\n", cc,
			inet_ntoa(*(struct in_addr *)&from->sin_addr.s_addr),
			icmp->icmp_seq);
	}
}

void ping(struct sockaddr_in *addr, unsigned char *send_buf){
	int i = 0;
	int n_sent;
	struct icmp *icmp;
	icmp = (struct icmp*) (send_buf + sizeof(struct iphdr));

	while(i < PING_COUNT){
		i++;

		icmp->icmp_seq = i;
		icmp->icmp_cksum = 0;
		icmp->icmp_cksum = compute_checksum((unsigned short *)icmp,
					 	sizeof(struct icmp));

		n_sent = sendto(sk, send_buf, MAXBUF, 0,
			(struct sockaddr*) addr, sizeof(struct sockaddr));
		if (n_sent<0) {
			perror("Problem sending data");
			exit(1);
		}
		printf("Ping\n");
		sleep(1);
	}
	usleep(500000);
	printf("%d/%d packet received (%0.2f%%)\n", count_rcv, PING_COUNT,
					 (double)count_rcv/PING_COUNT * 100);
}

void* rcv_pct(void* arg){
	unsigned char rcv_buf[256];
	int i = 0;
	struct sockaddr_in from;
	socklen_t fromlen = 0;
	int n_read;
	fromlen = sizeof(from);

	while(i < PING_COUNT){
		i++;
		n_read = recvfrom(sk, rcv_buf, 256, 0, (struct sockaddr *)&from, (socklen_t *) &fromlen);
		if (n_read<0) {
			perror("Problem in recvfrom");
			exit(1);
		}
		pr_pack((char *)rcv_buf, n_read, &from);
	}
	return NULL;
}

int main( int argc, char **argv ) {
	struct sockaddr_in server;
	/*struct hostent *hname;*/
	unsigned char send_buf[256];
	char source_ip[32] = "192.168.2.1";
	struct iphdr *iph = NULL;
	struct icmp *icmp;
	pthread_t tid;
	int one = 1;
	const int *val = &one;
	iph = malloc(sizeof(struct iphdr));
	icmp = malloc(sizeof(struct icmp));

	pid = getpid();

	if(argc!=2){
		printf("Usage: %s #addr#", argv[1]);
		exit(-1);
	}

	if ((sk = socket( AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0){
		printf("Problem creating socket\n");
		exit(1);
	}
	server.sin_family = AF_INET;
	server.sin_addr.s_addr =inet_addr(argv[1]);
	server.sin_port = htons(7777);

	/*create ICMP structure*/
	memset(icmp, 0, sizeof(struct icmp));
	icmp->icmp_type = ICMP_ECHO;
	icmp->icmp_code = 0;
	icmp->icmp_id = pid;
	icmp->icmp_seq = 0;
	icmp->icmp_cksum = compute_checksum((unsigned short *)icmp,
					 sizeof(struct icmp));/* ???  */

	/*create IP structure*/
	memset(iph, 0, sizeof(struct iphdr));
	iph->ihl = 5;
	iph->version = 4;
	iph->tos = 0;
	iph->tot_len = htons(sizeof (struct iphdr) + sizeof (struct icmp));
	iph->id = htons (12345);
	iph->frag_off = 0;
	iph->ttl = 255;
	iph->protocol = IPPROTO_ICMP;
	iph->check = 0;
	iph->daddr = inet_addr(argv[1]);
	iph->saddr = inet_addr (source_ip);

	memcpy(send_buf, iph, sizeof(struct iphdr));
	memcpy(send_buf + sizeof(struct iphdr), icmp, sizeof(struct icmp));

	if (setsockopt (sk, IPPROTO_IP, IP_HDRINCL, val, sizeof(one)) < 0){
		perror("Error setting IP_HDRINCL");
		exit(0);
	}
	pthread_create(&tid, NULL, rcv_pct, (void*)NULL);
	ping(&server, send_buf);


	return 0;
}

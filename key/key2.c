#include<stdio.h>
#include<pthread.h>
#include "pirnt_n.h"

void* func(void* arc){
	char * buf;
	buf = print_n(10);
	printf("thread -> %s\n", buf);
}

int main(void){
	char *buf;
	pthread_t t;
	int status;
	buf=print_n(15);
	pthread_create(&t, NULL, func, NULL);
	pthread_join(t,(void**)&status);
	printf("M -> %s\n", buf);

}

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

pthread_key_t key;
pthread_once_t once = PTHREAD_ONCE_INIT;

static void dist(void *buf){
	free(buf);
}

static void keyer(void){
	pthread_key_create(&key , dist);
}

char* print_n(int n){
	char *buf=NULL;
	int s;
	pthread_once(&once, keyer);
	buf = pthread_getspecific(key);
	if (buf == NULL){
		buf = malloc(50);
	}
	else {snprintf(buf, 50, "M -> %d\n", n);}
	pthread_setspecific(key, buf);
}

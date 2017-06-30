#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<sys/types.h>
#include<linux/unistd.h>

#define ERROR_CREATE_THREAD -11
#define ERROR_JOIN_THREAD -12
#define SUCCESS 0


void* kolvo(void * args){
	printf("%d\n", pthread_self());
//	printf("Hello from thread!\n");
	return SUCCESS;
}

pid_t gettid(void);

int main(){	

	pid_t my_tid;
	my_tid = gettid();
	pthread_t thread;
	int i;
	int status;
	int status_addr;
	for(i=1; i < 5; i++){
		status = pthread_create(&thread, NULL, kolvo, NULL);
		printf("%d \n" , &thread);
//		if(status!=0){
//			printf("Error create, status = %d\n", status);
//			exit(ERROR_CREATE_THREAD);
//		}
	}
	return 0;                                                         
}














/*
void* kolvo(void * args){
	printf("%d\n", pthread_self());
//	printf("Hello from thread!\n");
	return SUCCESS;
}

int main(){
	pthread_t thread;
	int i;
	int status;
	int status_addr;
	for(i=1; i < 5; i++){
		status = pthread_create(&thread, NULL, kolvo, NULL);
		if(status!=0){
			printf("Error create, status = %d\n", status);
			exit(ERROR_CREATE_THREAD);
		}
	}
//	printf("Hello from main!\n");
	
//	status = pthread_join(thread , (void**)&status_addr);
//	if (status != SUCCESS){
//		printf("Error can't join , status = %d\n", status);
//		exit(ERROR_JOIN_THREAD);
//	}
//	printf("joined with adress %d\n", status_addr);

	return 0;                                                         
}
*/



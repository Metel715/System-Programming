#include<stdio.h>
#include<string.h>
#include<math.h>
#include<pthread.h>

int main(){
	
	/*int a;
	while ((a = getchar()) != EOF)	
	 putchar(a);*/
	FILE *fo;
	fo = fopen("333.txt", "wt");
	int i;
	int adress[20];
	for(i=0; i<5; i++){
	  
	 scanf("%20s",adress);
	fprintf(fo, "%s\n" , adress);	 
	}
fclose (fo);
/*	srand(time(NULL));
	int a[5];
	int b;
	FILE *fo;
	fo = fopen("mr.txt","wt");
	int i,g;
	for(i=0;i<5;i++){
		a[i]=rand()%1000;
		printf("%d\n",a[i]);
		fprintf(fo, "%d\n",a[i]);
		}
fclose(fo);
*/
/*
FILE * fi; //Считывание
fi = fopen("mr.txt", "rt");
int n;
while(!feof(fi)){
fscanf(fi, "%d", &n);
printf("%d\n",n);
}
fclose(fi);
*/
/*
FILE *fo; //Рандомное заполнение файла

fo = fopen("mr.txt","wt");
int i,g;

for( i=0; i<10; i++){
g=rand()%10000;
fprintf (fo, "%d\n", g);
}
fclose(fo);*/

 /* printf("Hi!\n");

 int a[10]; 
 int i;
 int V;
for(i=0;i<10;i++){
		V=rand()%100;
		printf("a[%d]\n",V);		
		   }
*/
/*int a;
 a=rand() % 100;
 printf("%d\n", a);*/
 /*int g;
 g=rand()%10000; 
 int i;
 for (i=0; i < 10; i++ )
	{printf("%d\n", g);
	g=rand()%10000;}
	getchar();
*/
 return 0;
}

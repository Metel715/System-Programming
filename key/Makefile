key: key.o key2.c 
		gcc  key2.c -o key.o key2.o -lpthread -Wall

key.o: key.c
		gcc -c key.c

key2.o: key2.c pirnt_n.h
		gcc -c key2.c

.PHONY: clean

clean:
		rm -rf *.o key

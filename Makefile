main: main.o array.o link_list.o bst.o bs.o hash.o
	gcc -o main main.o array.o link_list.o bst.o bs.o hash.o
main.o: main.c data_struct.h
	gcc -c main.c
array.o: array.c data_struct.h
	gcc -c array.c 
link_list.o: link_list.c data_struct.h
	gcc -c link_list.c
bst.o: bst.c data_struct.h
	gcc -c bst.c
bs.o: bs.c data_struct.h
	gcc -c bs.c
hash.o: hash.c data_struct.h
	gcc -c hash.c
clean:
	rm main main.o array.o link_list.o bst.o bs.o

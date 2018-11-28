project2: project2.o item.o
	gcc -o project2 project2.o item.o

project2.o: project2.c
	gcc -c project2.c

item.o: item.c
	gcc -c item.c

clean:
	rm *.o

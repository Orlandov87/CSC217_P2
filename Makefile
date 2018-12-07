project2: project2.o item.o sale.o
	gcc -o project2 project2.o item.o sale.o

project2.o: project2.c
	gcc -c project2.c

item.o: item.c
	gcc -c item.c

sale.o: sale.c
	gcc -c sale.c

clean:
	rm *.o

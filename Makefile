project3: project3.o item.o sale.o
	gcc -o project3 project3.o item.o sale.o

project3.o: project3.c
	gcc -c project3.c

item.o: item.c
	gcc -c item.c

sale.o: sale.c
	gcc -c sale.c

clean:
	rm *.o

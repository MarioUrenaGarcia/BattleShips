exe: main.o interfaz.o
	gcc -o battleships.out main.o interfaz.o
	clear
	./battleships.out

main.o: main.c
	gcc -c main.c

interfaz.o: interfaz.c
	gcc -c interfaz.c

clean:
	rm *.o
	rm *.txt
	rm *.out
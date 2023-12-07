exe: main.o interfaz.o jugabilidad.o general.o cargar.o
	gcc -o battleships.out main.o interfaz.o jugabilidad.o general.o cargar.o
	./battleships.out

main.o: main.c
	gcc -c main.c

interfaz.o: interfaz.c
	gcc -c interfaz.c

jugabilidad.o: jugabilidad.c
	gcc -c jugabilidad.c

general.o: general.c
	gcc -c general.c

cargar.o: cargar.c
	gcc -c cargar.c

clean:
	rm *.o
	rm *.txt
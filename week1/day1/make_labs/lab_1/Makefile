
exer1.exe: data.o main.o io.o 
	cc data.o main.o io.o -o exer1.exe
data.o: data.c data.h
	cc -c data.c
main.o: data.h io.h main.c
	cc -c main.c
io.o: io.c io.h
	cc -c io.c

clean: 
	rm *.o
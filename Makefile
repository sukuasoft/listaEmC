run: clean  build
	listApp.exe

clean:
	del listApp.exe & del list.o
build: list.o
	gcc list.o main.c -o listApp.exe

list.o:
	gcc -c list.c

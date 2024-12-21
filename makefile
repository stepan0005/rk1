app.exe : main.o array.o
	gcc -o app.exe main.o array.o -lm

main.o : main.c array.h
	gcc -std=c99 -Wall -Werror -c -g3 main.c
	
array.o : main.c array.h
	gcc -std=c99 -Wall -Werror -c -g3 array.c

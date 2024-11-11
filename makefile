convert: main.c convert.c convert.h
	gcc -o convert main.c convert.c

ctest: main.c convert.c convert.h
	gcc -o ctest main.c convert.c -Wall -Werror --coverage

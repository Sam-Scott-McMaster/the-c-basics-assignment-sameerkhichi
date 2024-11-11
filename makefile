convert: main.c convert.c convert.h
	gcc -o convert main.c convert.c 

ctest: main.c convert.c convert.h
	gcc -o ctest --coverage main.c convert.c 

clean:
	rm -f convert ctest *.gcda *.gcno *.gcov

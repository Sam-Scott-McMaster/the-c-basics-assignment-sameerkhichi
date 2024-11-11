#include <stdio.h>
#include <stdlib.h>
#include "convert.h"

int main(int argc, char *argv[]) {
    int base = 16;
    long start = 0, finish = 0;

    if (identify_args(argc, argv, &base, &start, &finish) != 0) {
        print_usage();
        exit(1);
    }
}
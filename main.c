#include <stdio.h>
#include <stdlib.h>
#include "convert.h"

int main(int argc, char *argv[]) {
    int base = 16;
    long start = 0, finish = 0;
    int range_mode = 0;

    if (identify_args(argc, argv, &base, &start, &finish, &range_mode) != 0) {
        print_usage();
        exit(1);
    }

    if (range_mode) {
        //converts for the whole range
        convert_range(start, finish, base); 
    } else {
        //converts from standard input
        convert_stdin(base);
    }

    return 0;
}
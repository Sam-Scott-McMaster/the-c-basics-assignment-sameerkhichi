#include <stdio.h>
#include <stdlib.h>
#include "convert.h"

int main(int argc, char *argv[]) {
    //default base was 16
    int base = 16;
    long start = 0, finish = 0;
    //variable to know which conversion function to call, updated by identify_args
    int range_mode = 0;

    //go through the command line inputs and set the utility up with info
    if (identify_args(argc, argv, &base, &start, &finish, &range_mode) != 0) {
        print_usage();
        exit(1);
    }

    if (range_mode){
        //converts for the whole range
        convert_range(start, finish, base); 
    } 
    else{
        //converts from standard input
        convert_stdin(base);
    }

    return 0;
}
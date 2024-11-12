#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "convert.h"

//method for printing the usage
void print_usage(){
    fprintf(stderr, "Usage: convert [-b BASE] [-r START FINISH]\n");
    fprintf(stderr, "1 < BASE < 37\n");
    fprintf(stderr, "START and FINISH are long integers\n");
}

//method for printing when the help flag is used
void print_help(){
    printf("Convert Utility Help:\n");
    printf("Usage: convert [-b BASE] [-r START FINISH]\n");
    printf("Flags:\n");
    printf(" -b BASE Specify base for the conversion (1 < BASE < 37). The default base is 16.\n");
    printf(" -r START FINISH Convert a range of numbers from START to FINISH.\n");
    printf("If no range is specified, the convert utility reads from standard input until end of file.\n");
    printf("Example usage:\n");
    printf("  convert -b 36           Convert numbers from stdin in base 36.\n");
    printf("  convert -b 2 -r -3 3    Convert numbers from -3 to 3 in base 2 (binary).\n");
}

//this method checks for arguments given in the command line
int identify_args(int argc, char *argv[], int *base, long *start, long *finish, int *range_mode){

    //skips first index as that is the program name
    for (int i = 1; i < argc; i++) {  

        //help logic
        if (strcmp(argv[i], "--help") == 0) {
            print_help();
            exit(0);
        }
        
        if (strcmp(argv[i], "-b") == 0){  
            //if a base is given
            if (i + 1 < argc) { 
                //store the integer of the value to the base pointer
                *base = atoi(argv[++i]); 

                //validate base
                if (*base < 2 || *base > 36){  
                    return -1;  
                }
            } 

            else {
                return -1;  //if no base is provided
            }
        } 

        //if the range is given
        else if (strcmp(argv[i], "-r") == 0){ 
            
            //making sure both start and finish values are given
            if (i + 2 < argc){  

                //setting the start and finish values
                *start = atol(argv[++i]);  
                *finish = atol(argv[++i]);  

                //range mode lets the main function know which converting method to call
                *range_mode = 1;


            } 
            else{
                return -1; 
            }
        }

        else{
            return -1;
        }
    }
    return 0;
}

//this is the method that recursively prints the conversion
void convert_and_print(long num, int base){

    //these are used for base conversions only for this function
    const char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    //used to print the minus sign if negative
    if (num < 0){
        putchar('-');
        num = -num; 
    }

    if (num >= base){
        //recursive case, divide by the base and keep calling the function
        convert_and_print(num / base, base);
    }
    putchar(digits[num % base]); //printing the current digit
}

void convert_range(long start, long finish, int base){
    //uses the start and finish pointers that hold the range
    for (long i = start; i <= finish; i++){
        convert_and_print(i, base);
         putchar('\n');
    }
}

//uses input from stdin for conversion and calls the recursive function
void convert_stdin(int base){
    long number;
    while (scanf("%ld", &number) == 1){
        convert_and_print(number, base);
        //adds a new line after each number
        putchar('\n');
    }
    //if something was passed in that wasnt an integer and it wasnt end of file
    if (!feof(stdin)){
        fprintf(stderr, "Error: Non long int token encountered.\n");
        exit(1);
    }
}
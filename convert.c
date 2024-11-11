#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_usage(){
    fprintf(stderr, "Usage: convert [-b BASE] [-r START FINISH]\n");
    fprintf(stderr, "1 < BASE < 37\n");
    fprintf(stderr, "START and FINISH are long integers\n");
}

void print_help(){
    printf("Convert Utility Help:\n");
    printf("Usage: convert [-b BASE] [-r START FINISH]\n");
    printf("Flags: \n");
    printf(" -b BASE Specify base for the conversion (1 < BASE < 37). The default base is 16.\n");
    printf(" -r START FINISH Convert a range of numbers from START to FINISH.\n");
    printf("If no range is specified, the convert utility reads from standard input until end of file.\n");
    printf("Example usage:\n");
    printf("  convert -b 36           Convert numbers from stdin in base 36.\n");
    printf("  convert -b 2 -r -3 3    Convert numbers from -3 to 3 in base 2 (binary).\n");
}

int identify_args(int argc, char *argv[], int *base, long *start, long *finish, int *range_mode){

    for (int i = 1; i < argc; i++) {  

        if (strcmp(argv[i], "-b") == 0){  
            if (i + 1 < argc) { 
                *base = atoi(argv[++i]); 

                if (*base < 2 || *base > 36){  
                    return -1;  
                }
            } 

            else {
                return -1;  
            }
        } 

        else if (strcmp(argv[i], "-r") == 0){ 
          
            if (i + 2 < argc){  

                //setting the start and finish values
                *start = atol(argv[++i]);  
                *finish = atol(argv[++i]);  

            } 
            else{
                return -1; 
            }
        }

        else if (argv[i][0] == '-'){ 
            return -1;
        }

        else{
            return -1;
        }
    }
    return 0;
}

void convert_and_print(long num, int base){

    const char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    if (num < 0){
        putchar('-');
        num = -num; 
    }

    if (num >= base){
        convert_and_print(num / base, base);
    }
    putchar(digits[num % base]);
}

void convert_range(long start, long finish, int base){
    for (long i = start; i <= finish; i++){
        convert_and_print(i, base);
    }
}

void convert_stdin(int base){
    long number;
    while (scanf("%ld", &number) == 1){
        convert_and_print(number, base);
        //adds a new line after each number
        putchar('\n');
    }
    if (!feof(stdin)){
        fprintf(stderr, "Error: Non long int token encountered.\n");
        exit(1);
    }
}
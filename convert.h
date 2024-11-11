void print_usage(void);
void print_help();
int identify_args(int argc, char *argv[], int *base, long *start, long *finish);
void convert_and_print(long num, int base);
void convert_range(long start, long finish, int base);
void convert_stdin(int base);
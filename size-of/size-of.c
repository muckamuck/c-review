#include <stdio.h>

typedef struct {
    int a;
    int b;
} A_and_B;

typedef union {
    int a;
    int b;
} A_or_B;

int main(int argc, char** argv, char** envp) {
    int x = 0;
    int* where_x = &x;

    printf("sizeof(x): %ld\n", sizeof(x));
    printf("sizeof(where_x): %ld\n", sizeof(where_x));
    printf("sizeof(A_and_B): %ld\n", sizeof(A_and_B));
    printf("sizeof(A_or_B): %ld\n", sizeof(A_or_B));

    return 0;
}

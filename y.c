#include <stdio.h>

typedef struct {
    int a;
    int b;
} AB;

void foo(AB* thing) {
    thing->a = 12;
    thing->b = 24;
}

int main() {
    AB ab;
    foo(&ab);
    printf("a = %d\n", ab.a);
    printf("b = %d\n", ab.b);
}

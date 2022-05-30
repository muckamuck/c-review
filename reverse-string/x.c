#include <stdio.h>
#include <stdbool.h>

void foo(char* m, char* n) {
    m[0] = 'x';
    n[0] = 'a';
}

bool bar() {
    if (1 == 1.0) {
        return true;
    } else {
        return false;
    }
}

int main() {
    char stuff[] = "abc";
    char junk[] = "xyz";
    printf("%s - %s\n", stuff, junk);
    foo(stuff, junk);
    printf("%s - %s\n", stuff, junk);
    if (bar()) {
        printf("true\n");
    } else {
        printf("false\n");
    }
}

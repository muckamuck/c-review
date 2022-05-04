#include <stdio.h>

void foo(char* m, char* n) {
    m[0] = 'x';
    n[0] = 'a';
}

int main() {
    char stuff[] = "abc";
    char junk[] = "xyz";
    printf("%s - %s\n", stuff, junk);
    foo(stuff, junk);
    printf("%s - %s\n", stuff, junk);
}

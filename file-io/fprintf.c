#include <stdio.h>

int main(int argc, char** argv, char** envp) {
    int answer = 42;
    FILE* f = fopen("/tmp/fprintf.txt", "w");
    fprintf(f, "Byte me! answer=%d\n", answer);
    fclose(f);

    return 0;
}

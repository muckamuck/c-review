#include <stdio.h>

void reverse(char* s);

int main(int argc, char** argv) {
    for (int idx = 0; idx < argc; idx++) {
       reverse(argv[idx]);
    }
    return 0;
}

void reverse(char* s) {
    char tmp;
    int strLen = 0;
    int lastIdx = 0;
    for (int idx = 0; s[idx] != 0; idx++) {
        strLen++;
    }
    
    lastIdx = strLen - 1;
    printf("%s is %d long\n", s, strLen);
    printf("%s", s);

    for (int idx = 0, jdx = lastIdx; idx < jdx; idx++, jdx--) {
        tmp = s[jdx];
        s[jdx] = s[idx];
        s[idx] = tmp;
    }
    
    printf(" => %s\n", s);
    return;
}

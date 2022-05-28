#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char** argv, char** envp) {
    char* token = NULL;
    bool first = true;

    for (int idx = 0; envp[idx] != NULL; idx++) {
        first = true;
        token = strtok(envp[idx], "=");
        while (token != NULL) {
            printf("%s", token);
            if (first) {
                first = false;
                printf(" => ");
            }
            token = strtok(NULL, "=");
        }
        printf("\n");
    }

    return 0;
}

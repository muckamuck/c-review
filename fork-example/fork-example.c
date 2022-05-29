#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

void busy() {
    long i = 1;
    for (long j = 0; j < 10; j++) {
        i += i;
        printf("i = %ld\n", i);
        if (i <= 0) {
            i = 1;
        }
    }
}

int main(int argc, char** argv, char** envp) {
    int parent_id = 0;
    int waited_kid_pid = 0;
    int status = 0;
    int kid_id = fork();
    if (kid_id > 0) {
        busy();
        waited_kid_pid = wait(&status);
        parent_id = getpid();
        printf("parent: parent_id=%d kid_id=%d\n", parent_id, kid_id);
    } else {
        busy();
        parent_id = getppid();
        kid_id = getpid();
        printf("kid: parent_id=%d kid_id=%d\n", parent_id, kid_id);
    }
}

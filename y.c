#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int a;
    int b;
    char* msg;
} Answer;

Answer foo(int a, int b, char* msg) {
    Answer answer;
    answer.a = a * a;
    answer.b = b * b;
    answer.msg = msg;

    return answer;
}

void print_answer(Answer* a, char* label) {
    printf("[%s]   a = %d\n", label, a->a);
    printf("[%s]   b = %d\n", label, a->b);
    printf("[%s] msg = %s\n", label, a->msg);
    printf("[%s] len = %d\n", label, strlen(a->msg));
}

int main() {
    Answer the_answer;
    Answer another_answer;
    char* s;

    s = malloc(10 * sizeof(char));
    s[0] = 'x';
    s[1] = 'b';
    s[2] = 'c';
    s[3] = 0;
    the_answer = foo(2, 4, s);
    another_answer = the_answer;

    print_answer(&the_answer, "the_answer");
    the_answer.msg[0] = 'a';
    print_answer(&another_answer, "another_answer");
    /*printf("a = %d\n", the_answer.a);*/
    /*printf("b = %d\n", the_answer.b);*/
    /*printf("msg = %s\n", the_answer.msg);*/
    /*printf("    &the_answer = %lx\n", &the_answer);*/
    /*printf("&another_answer = %lx\n", &another_answer);*/
    /*printf("msg = %s\n", another_answer.msg);*/
}

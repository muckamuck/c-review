#include <stdio.h>
#include <string.h>

#define WINDOW_SIZE 20

/* char* message = "The race is long and in the end only with yourself"; */
char* message = "abcdefghijklmnopqrstuvwxyz1234567890";
char  window[WINDOW_SIZE + 1];

void clearWindow() {
    for (int i = 0; i < WINDOW_SIZE + 1; i++) {
        window[i] = 0;
    }

    return;
}

int main() {
    clearWindow();

    /* Fill up the display */
    for (int i = 0; i < WINDOW_SIZE; i++) {
        window[i] = message[i];
        printf("%s\n", window);
    }

    /* Scroll through the message */
    clearWindow();
    for (int i = 1; i < strlen(message); i++) {
        strncpy(&window[0], &message[i], WINDOW_SIZE);
        printf("%s\n", window);
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct _item {
    char message[128];
    struct _item* next;
    struct _item* prev;
};

typedef struct _item item;

item* add_item(item* prev, char* message) {
    item* new_item = malloc(sizeof(item)); 
    strcpy(new_item->message, message);
    new_item->prev = prev;
    new_item->next = NULL;
    return new_item;
}

void print_list(item* start) {
    item* current = start;
    while (current != NULL) {
        printf("x%lx -> %s\n", current, current->message);
        current = current->next;
    }
}

int main(int argc, char** argv, char** envp) {
    item* current_head = NULL;
    item* new_item = NULL;
    new_item = add_item(NULL, "stuff");
    current_head = new_item;

    print_list(current_head);
}

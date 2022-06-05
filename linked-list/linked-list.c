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

struct _list {
    item* current_head;
    item* current_tail;
};
typedef struct _list list;


list* create_list() {
    list* new_list = malloc(sizeof(list));
    new_list->current_head = NULL;
    new_list->current_tail = NULL;
}

item* add_item(list* the_list, char* message) {
    item* new_item = malloc(sizeof(item));
    new_item->next = NULL;
    strcpy(new_item->message, message);

    if (the_list->current_head == NULL) {
        the_list->current_head = new_item;
        the_list->current_tail = new_item;
        new_item->prev = NULL;
    } else {
        the_list->current_tail->next = new_item;
        new_item->prev = the_list->current_tail;
        the_list->current_tail = new_item;
    }
}

void walk_list(list* the_list) {
    item* current = the_list->current_head;
    while (current != NULL) {
        printf("x%lx -> %s\n", current, current->message);
        current = current->next;
    }
}

int main(int argc, char** argv, char** envp) {
    list* the_list = NULL;
    item* current_item = NULL;

    the_list = create_list();
    current_item = add_item(the_list, "stuff");
    current_item = add_item(the_list, "junk");
    current_item = add_item(the_list, "crap");

    walk_list(the_list);
}

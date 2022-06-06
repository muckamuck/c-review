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
    long item_count;
};
typedef struct _list list;


list* create_list() {
    list* new_list = malloc(sizeof(list));
    new_list->current_head = NULL;
    new_list->current_tail = NULL;
    new_list->item_count = 0;
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

    the_list->item_count++;
    return new_item;
}

bool remove_item(list* the_list, item* x) {
    printf("deleting 0x%lx\n", x);
    
    if (x->prev) {
        x->prev->next = x->next;
    } else {
        the_list->current_head = x->next;
    }

    if (x->next) {
        x->next->prev = x->prev;
    } else {
        the_list->current_tail = x->prev;
    }

    the_list->item_count--;
    free(x);
}

void walk_list(list* the_list) {
    item* current = the_list->current_head;
    if (the_list->item_count > 0) {
        while (current != NULL) {
            printf("0x%12lx -> %s\tprev=0x%012lx next=0x%012lx\n", current, current->message, current->prev, current->next);
            current = current->next;
        }
    } else {
        printf("the list is empty\n");
    }
}

int main(int argc, char** argv, char** envp) {
    list* the_list = NULL;
    item* current_item = NULL;

    the_list = create_list();
    item* stuff = add_item(the_list, "stuff");
    item* junk = add_item(the_list, "junk");
    item* crap = add_item(the_list, "crap");
    walk_list(the_list);
    printf("---\n\n");

    remove_item(the_list, stuff);
    walk_list(the_list);
    printf("---\n\n");

    remove_item(the_list, junk);
    walk_list(the_list);
    printf("---\n\n");

    remove_item(the_list, crap);
    walk_list(the_list);
    printf("---\n\n");
}

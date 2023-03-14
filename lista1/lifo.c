#include <stdio.h>
#include <stdlib.h>
#include "lifo.h"

void lifo_show_list(Lifo *head){
    if (head != NULL) {
        Lifo *temp = head;
        do {
            printf("_ %d _\n", temp->element);
            temp = temp->next;
        } while (temp != NULL);
    } else {
        printf("Nothing to show, fifo-queue is empty\n");
    }
}

Lifo * lifo_push (Lifo *head, int element){
    if (head == NULL){
        head = (Lifo *) malloc(sizeof(Lifo));
        head->element = element;
        head->next = NULL;
    } else {
        Lifo *new_element = (Lifo *) malloc(sizeof(Lifo));
        new_element->element = element;
        new_element->next = head;
        head = new_element;
    }
    return head;
}


Lifo * lifo_pop (Lifo *head){
    if (head != NULL) {
        printf("Pop: %d\n", head->element);
        Lifo *to_delete = head;
        head = head->next;
        free(to_delete);
        return head;
    } else {
        printf("Queue is empty!\n");
        return NULL;
    }
}

void lifo_remove_all (Lifo *linked_list){
    if (linked_list != NULL) {
        Lifo *to_delete = linked_list->next;

        while (to_delete != NULL) {
            printf("DELETING:   _ %d _\n", to_delete->element);
            linked_list->next = linked_list->next->next;
            free(to_delete);
            to_delete = linked_list->next;
        }

        free(linked_list);
    }
}
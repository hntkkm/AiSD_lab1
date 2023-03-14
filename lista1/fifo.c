#include <stdio.h>
#include <stdlib.h>
#include "fifo.h"

void fifo_show_list(Fifo *head){
    if (head != NULL) {
        Fifo *temp = head;
        do {
            printf("_ %d _\n", temp->element);
            temp = temp->next;
        } while (temp != NULL);
    } else {
        printf("Nothing to show, fifo-queue is empty\n");
    }
}

Fifo * fifo_push (Fifo *head, int element){
    if (head == NULL){
        head = (Fifo *) malloc(sizeof(Fifo));
        head->element = element;
        head->next = NULL;
    } else {
        Fifo *temp = head;
        Fifo *new_element = (Fifo *) malloc(sizeof(Fifo));
        new_element->element = element;
        new_element->next = NULL;
        while (head->next != NULL) {
            head = head->next;
        }
        head->next = new_element;
        head = temp;
    }
    return head;
}


Fifo * fifo_pop (Fifo *head){
    if (head != NULL) {
        printf("Pop: %d\n", head->element);
        Fifo *to_delete = head;
        head = head->next;
        free(to_delete);
        return head;
    } else {
        printf("Queue is empty!\n");
        return NULL;
    }
}

void fifo_remove_all (Fifo *linked_list){
    if (linked_list != NULL) {
        Fifo *to_delete = linked_list->next;

        while (to_delete != NULL) {
            printf("DELETING:   _ %d _\n", to_delete->element);
            linked_list->next = linked_list->next->next;
            free(to_delete);
            to_delete = linked_list->next;
        }

        free(linked_list);
    }
}
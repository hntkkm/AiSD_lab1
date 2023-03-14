#include <stdio.h>
#include <stdlib.h>
#include "singlyLinkedList.h"


bool s_find_element(SListType *head, int element){
    SListType * tempNext = head;
    while ( tempNext != NULL) {
        if (tempNext->element != element) {
            if (tempNext->next != NULL) {
                tempNext = tempNext->next;
            } else return false;
        } else return true;
    }
    return 0;
}

void s_show_list(SListType *head){
    SListType * temp = head;
    do {
        printf("_ %d _\n", temp->element);
        temp = temp -> next;
    } while (temp != NULL);
}

SListType * s_create_list (int element){
    SListType * new_element = (SListType *) malloc(sizeof(SListType));
    new_element->element = element;
    new_element->next = NULL;
    return new_element;
}

SListType * s_add_element (SListType *head, int element){
    SListType * new_element =(SListType *) malloc(sizeof(SListType));

    new_element->element = element;
    new_element->next = head -> next;
    head -> next = new_element;

    return head;
}

void s_remove_all (SListType *linked_list){
    SListType *to_delete = linked_list->next;

    while (to_delete != NULL) {
        //printf("DELETING:   _ %d _\n", to_delete->element);
        linked_list->next = linked_list->next->next;
        free(to_delete);
        to_delete = linked_list ->next;
    }

    free (linked_list);
}

void s_merge_lists(SListType *linked_list1, SListType *linked_list2) {
    SListType *temp = linked_list1->next;
    linked_list1->next = linked_list2;


    while (linked_list2->next != NULL) {
        linked_list2 = linked_list2 ->next;
    }

    linked_list2 ->next = temp;
}
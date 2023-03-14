#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "doublyLinkedList.h"

bool find_element(DListType *head, int element){
    DListType * tempNext = head;
    DListType * tempPrev = head->previous;
    while (tempNext->element != element
    && tempPrev->element != element
    && tempNext->element != tempPrev->element) {

        tempNext = tempNext -> next;
        tempPrev = tempPrev -> previous;
    }

    if (tempPrev->element == element || tempNext->element == element){
        return true;
    } else return false;
}

void show_list(DListType *head){
    DListType * temp = head;
    do {
        printf("_ %d _\n", temp->element);
        temp = temp -> next;
    } while (temp->element != head->element);
}

DListType * create_list (int element){
    DListType * new_element =(DListType *) malloc(sizeof(DListType));
    new_element->element = element;
    new_element->next = new_element;
    new_element->previous = new_element;
    return new_element;
}

DListType * add_element (DListType *head, int element){
    DListType * new_element =(DListType *) malloc(sizeof(DListType));
    new_element->element = element;

    new_element->previous =  head ->previous;
    new_element->next = head;

    new_element->previous->next = new_element;
    head -> previous = new_element;
    return head;
}

void remove_all (DListType *linked_list){
    DListType *to_delete = linked_list->next;
    while (to_delete != linked_list) {
//        printf("DELETING:   _ %d _\n", to_delete->element);
        linked_list->next = linked_list->next->next;
        free(to_delete);
        to_delete = linked_list ->next;
    }
    free (linked_list);
}

void merge_lists(DListType *linked_list1, DListType *linked_list2){
    DListType *temp = linked_list1->previous;

    linked_list2->previous->next = linked_list1;
    linked_list1->previous->next = linked_list2;
    linked_list1->previous = linked_list2->previous;
    linked_list2->previous = temp;
}
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "singlyLinkedList.h"
#include "doublyLinkedList.h"
#include "fifo.h"
#include "lifo.h"

void run_lifo(){
    printf("LIFO\n");
    Lifo * head = NULL;
    head = lifo_push(head, 0);
    for (int i = 1; i < 10; i++) {
        head = lifo_push(head, i);
    }
    lifo_show_list(head);

    for (int i = 1; i < 10; i++) {
        head = lifo_pop(head);
    }

    lifo_show_list(head);
    lifo_remove_all(head);
}

void run_fifo(){
    printf("FIFO\n");
    Fifo * head = NULL;
    head = fifo_push(head, 0);
    for (int i = 1; i < 10; i++) {
        head = fifo_push(head, i);
    }
    fifo_show_list(head);

    for (int i = 1; i < 10; i++) {
        head = fifo_pop(head);
    }

    fifo_show_list(head);
    fifo_remove_all(head);
}

void run_singly_linked_list(){
    SListType * head;
    head = s_create_list(0);
    for (int i = 1; i < 1000; i++) {
        head = s_add_element(head, i);
    }
    //s_show_list(head);

    clock_t begin = clock();
    for (int i = 0; i < 10000; i++) {
        bool find_elem1 = s_find_element(head, 10);
    }
    clock_t end = clock();
    double time_spent = (double) (end - begin);
    printf("Average time spent in SLL: %lf\n\n", time_spent);


    SListType * second = s_create_list(1000);
    for (int i = 1000; i < 1200; i++) {
        second = s_add_element(second, i);
    }
    s_merge_lists(head, second);
    //s_show_list(head);
    s_remove_all(head);
}
void run_doubly_linked_list(){
    DListType * head;
    head = create_list(0);
    for (int i = 1000; i > 1; i--) {
        head = add_element(head, i);
    }
    //show_list(head);

    clock_t begin = clock();
    for (int i = 0; i < 10000; i++) {
        bool find_elem1 = find_element(head, 10);
    }
    clock_t end = clock();
    double time_spent = (double) (end - begin);
    printf("Average time spent in DLL: %lf\n\n", time_spent);

    DListType * second = create_list(1000);
    for (int i = 1000; i < 1200; i++) {
        second = add_element(second, i);
    }

    printf("Przykladowe merge'owanie dwoch list DLL\n\n");
    merge_lists(head, second);
    show_list(head);
    remove_all(head);
}


int main() {
    run_fifo();
    run_lifo();
    run_singly_linked_list();
    run_doubly_linked_list();
}

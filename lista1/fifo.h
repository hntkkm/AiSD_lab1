#ifndef LAB1AISD_FIFO_H
#define LAB1AISD_FIFO_H

#include <stdbool.h>

typedef struct fifo_linked_list{
    int element;
    struct fifo_linked_list * next;
} Fifo;

void fifo_show_list(Fifo *head);
Fifo * fifo_push (Fifo *head, int element);
Fifo * fifo_pop (Fifo *head);
void fifo_remove_all (Fifo *linked_list);

#endif //LAB1AISD_FIFO_H

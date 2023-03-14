#ifndef LAB1AISD_LIFO_H
#define LAB1AISD_LIFO_H

#include <stdbool.h>

typedef struct lifo_linked_list{
    int element;
    struct lifo_linked_list * next;
} Lifo;

void lifo_show_list(Lifo *head);
Lifo * lifo_push (Lifo *head, int element);
Lifo * lifo_pop (Lifo *head);
void lifo_remove_all (Lifo *linked_list);

#endif //LAB1AISD_LIFO_H

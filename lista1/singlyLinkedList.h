#ifndef LAB1AISD_SINGLYLINKEDLIST_H
#define LAB1AISD_SINGLYLINKEDLIST_H

#include <stdbool.h>

typedef struct singly_linked_list{
    int element;
    struct singly_linked_list * next;
} SListType;

void s_show_list(SListType *head);
SListType * s_create_list (int element);
SListType * s_add_element (SListType *head, int element);
void s_remove_all (SListType *linked_list);
void s_merge_lists(SListType *linked_list1, SListType *linked_list2);
bool s_find_element(SListType *head, int element);

#endif //LAB1AISD_SINGLYLINKEDLIST_H

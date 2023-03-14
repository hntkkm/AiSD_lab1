#ifndef LAB1AISD_DOUBLYLINKEDLIST_H
#define LAB1AISD_DOUBLYLINKEDLIST_H

typedef struct doubly_linked_list{
    int element;
    struct doubly_linked_list * previous;
    struct doubly_linked_list * next;
} DListType;

void show_list(DListType *head);
DListType * create_list (int element);
DListType * add_element (DListType *head, int element);
void remove_all (DListType *linked_list);
void merge_lists(DListType *linked_list1, DListType *linked_list2);
bool find_element(DListType *head, int element);

#endif  //LAB1AISD_DOUBLYLINKEDLIST_H

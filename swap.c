#include <stdio.h>
#include <stdlib.h>

typedef struct List_node {
    int value;
    struct List_node *next;
}  List;

List *swap(List *head, List *node_1, List *node_2)
{
    if (!head ||
        (node_1 == NULL) || (node_2 == NULL) ||
        (node_1 == node_2)) 
        return head;

    int exist_2 = 0; 

    List *_head = head;
    List *pre_node_1 = NULL,*pre_node_2 = NULL,*tmp_node;

    while (head && head->next && exist_2 != 2) { //bad performance (add exist_2 != 2 to stop)
        if (head->next == node_1) { //if node1 == head, it cant work
            pre_node_1 = head;
            exist_2 = exist_2+ 1;
        }

        if (head->next == node_2) { //if node2 == head, it cant work
            pre_node_2 = head;
            exist_2 = exist_2 + 1;
        }
        head = head->next;
    }

    head = _head;
    if (head == node_1) { //handle the case : node1 == head (move to previous can get better performance)
        pre_node_1 = NULL;
        exist_2 = exist_2+ 1;
    }

    if (head == node_2) { //handle the case : node2 == head (move to previous can get better performance)
        pre_node_2 = NULL;
        exist_2 = exist_2+ 1;
    }

    if (exist_2 != 2) //cant find both or either node1 or node2
        return head;

//swap process

    if (pre_node_1 == NULL) { 
        pre_node_2->next = node_1;
        tmp_node = node_1->next;
        node_1->next = node_2->next;
        node_2->next = tmp_node;
        return node_2;
    }

    if (pre_node_2 == NULL) {
        pre_node_1->next = node_2;
        tmp_node = node_2->next;
        node_2->next = node_1->next;
        node_1->next = tmp_node;
        return node_1;
    }

    if (node_2->next == node_1) {
        pre_node_2->next = node_1;
        tmp_node = node_1->next;
        node_1->next = node_2;
        node_2->next = tmp_node;
        return head;
    }

    if (node_1->next == node_2) {
        pre_node_1->next = node_2;
        tmp_node = node_2->next;
        node_2->next = node_1;
        node_1->next = tmp_node;
        return head;
    }

    pre_node_1->next = node_2;
    tmp_node = node_2->next;
    node_2->next = node_1->next;
    pre_node_2->next = node_1;
    node_1->next = tmp_node;
    return head;
}

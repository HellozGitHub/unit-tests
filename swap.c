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

    int exit_2 = 0;
    
    List *extra,*pre_node_1 = NULL,*pre_node_2 = NULL,*tmp_node; //add a extra node 
    extra = (List *) malloc(sizeof(entry));
    extra->next = head;
    tmp = extra;

    while (tmp && tmp->next && exist_2 != 2 ){ //if node_1 node_2 == head, it can also work
        if (tmp->next == node_1) { 
            pre_node_1 = tmp;
            exist_2 = exist_2+ 1;
        }
        if (tmp->next == node_2) {
            pre_node_2 = tmp;
            exist_2 = exist_2 + 1;
        }
        tmp = tmp->next;
    }
    
    if (exist_2 != 2) //cant find both or either node1 or node2
        free(extra);
        return head;
 
    if (node_2->next == node_1) {
        pre_node_2->next = node_1;
        tmp_node = node_1->next;
        node_1->next = node_2;
        node_2->next = tmp_node;
    }

    else if (node_1->next == node_2) {
        pre_node_1->next = node_2;
        tmp_node = node_2->next;
        node_2->next = node_1;
        node_1->next = tmp_node;
    }
    else{
        pre_node_1->next = node_2;
        tmp_node = node_2->next;
        node_2->next = node_1->next;
        pre_node_2->next = node_1;
        node_1->next = tmp_node;
    }
    if (extra == pre_node_1){ //indicate that the new head of the list is node_2
        free(extra);
        return node_2; 
    }
    else if (extra == pre_node_2){ //indicate that the new head of the list is node_1
        free(extra);
        return node_1;    
    else{
        free(extra);
        return head;
    }
}

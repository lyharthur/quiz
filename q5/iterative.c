#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;
ListNode *head=NULL;
ListNode *tail=NULL;
ListNode *detectCycle(ListNode *head)
{
    struct ListNode *node_f = head;
    struct ListNode *node_s = head;
    while(node_f && node_s) {
        node_f = node_f->next;
        node_s = node_s->next;
        if(node_f == node_s)
            break;
    }
    if(!node_s) return NULL;
    node_f = head;
    while(node_f!=node_s) {
        node_f = node_f->next;
        node_s = node_s->next;
    }
    return node_f;
}
void traverse_list(struct ListNode *head)
{
    while(head) {
        printf("%d\n", head->val);
        head = head->next;
    }
    return;
}


struct ListNode* create_node(int val)
{
    struct ListNode *new_node = (struct ListNode *)malloc(sizeof(struct ListNode));
    new_node->val = val;
    new_node->next = NULL;
    return new_node;
}


struct ListNode *create_cycle_list(int cycle_pos, int size)
{
    struct ListNode *list_head = create_node(0);
    struct ListNode* parse = list_head;

    if (cycle_pos > size) return NULL;

    for (int i = 1; i <= size; i++) {
        if (i == cycle_pos) list_head = parse;
        parse->next = create_node(i);
        parse = parse->next;
    }
    parse->next = list_head->next;

    return list_head;
}


struct ListNode *create_linear_list(int size)
{
    struct ListNode *list_head = create_node(0);
    struct ListNode *parse = list_head;

    for(int i = 1; i <= size; i++) {
        parse->next = create_node(i);
        parse = parse->next;
    }
    return list_head;
}
void free_list(struct ListNode *head)
{
    struct ListNode *current = head;
    struct ListNode *prev = NULL;
    struct ListNode *cycleNode = NULL;

    while ((cycleNode = detectCycle(head)) != NULL) {
        cycleNode->next = NULL;
    }

    while (current) {
        prev = current;
        current = current->next;
        free(prev);
    }
}


int main()
{

    struct ListNode *cycle_list = create_cycle_list(1, 6);
    struct ListNode *linear_list = create_linear_list(5);

    /* detect cycle */
    detectCycle(NULL);
    detectCycle(linear_list);
    detectCycle(cycle_list);

    /* free memory */
    //free_list(linear_list);
    //  free_list(cycle_list);


    return 0;
}

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;


struct ListNode *detectCycle(ListNode *node_s, ListNode *node_f, ListNode *result, int done)
{
    if(node_f && node_s) {
        if(done) {
            if(node_s == result)
                return result;
            else
                return detectCycle(node_s, node_f, result->next, 1);
        } else {
            if(node_f == node_s && done == 0)
                return detectCycle(node_s, node_f, result, 1);
            return detectCycle(node_s->next, node_f->next->next, result, 0);
        }
    }
    return NULL;
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


int main()
{

    struct ListNode *cycle_list = create_cycle_list(1, 6);
    struct ListNode *linear_list = create_linear_list(5);

    /* detect cycle */
    if(detectCycle(NULL, NULL, NULL, 0))
        printf("case 4 : has cycle\n");
    if(detectCycle(linear_list->next, linear_list->next->next, cycle_list, 0))
        printf("case 2 : has cycle\n");
    if(detectCycle(cycle_list->next, cycle_list->next->next, cycle_list, 0))
        printf("case3 : has cylce\n");

    return 0;
}


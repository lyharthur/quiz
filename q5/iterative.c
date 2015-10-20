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
int main()
{

}

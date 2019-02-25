

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "list.h"


Node * createList()
{
    Node * head = (Node * )malloc(sizeof(Node));
    //...
    head->next = NULL;
    return head;
}

void insertList(Node * head, int data)
{
    Node * now = (Node *)malloc(sizeof(Node));
    //...
    now->data = data;
    
    now->next = head->next;
    head->next = now;

}

void travereList(Node * head)
{
    Node * rhead = head->next;
    for( ;rhead!=NULL; rhead = rhead->next)
    {
        printf("%d ", rhead->data);
    }
    printf("\n");
}

int lenList(Node * head)
{
    int count = 0;
    Node * rhead = head->next;
    for( ;rhead!=NULL; rhead = rhead->next)
    {
        count ++;
    }
    return count;
}

Node * searchList(Node * head, int find)
{
    Node * rhead = head->next;
    while(rhead)
    {
        if(rhead->data == find)
        {
            break;
        }
        rhead = rhead->next;
    }
    return rhead;
}

void deleteList(Node * head, Node * pfind)
{
#define TRICKY 
#ifdef TRICKY

    if(pfind->next!=NULL) //unnecessary to find previous node if pfind is not last node
    {
        Node * next = pfind->next;
        pfind->data = next->data;  //copying next node to pfind and then delete next node.
        pfind->next = next->next;
        free(next);
        return;
    }
    
#endif

    while(head->next!=pfind)  //finding the previous node
    {
        head = head->next;
    }
    Node * dhead = head->next;
    head->next = dhead->next;
    free(dhead);
}

void popSortList(Node * head)
{
    int len = lenList(head);
    Node * p = head->next;
    Node * q = p->next;

#if 0
    for(int i = 0; i < len - 1; i++)
    {
        for(int j = 0; j < len - 1 - i; j++)
        {
            if(p->data > q->data)
            {
                p->data = p->data ^ q->data;
                q->data = p->data ^ q->data;
                p->data = p->data ^ q->data;
            }
            p = q;
            q = q->next;
        }
        p = head->next;
        q = p->next;
    }
#endif
    Node * pre = head;

    for(int i = 0; i < len - 1; i++)
    {
        for(int j = 0; j < len - 1 - i; j++)
        {
            if(p->data > q->data)
            {
                pre->next = q;
                p->next = q->next;
                q->next = p;

                q = q->next;
                p = pre->next;
            }
            pre = p;
            p = q;
            q = q->next;
        }
        p = head->next;
        q = p->next;
        pre = head;
    }

}

void reverseList(Node * head)
{
    Node * h = head->next;
    head->next = NULL;
    Node * tmp = NULL;
    while(h)
    {
        tmp = h->next;

        h->next = head->next;
        head->next = h;
        h = tmp;
    }
}

void destroyList(Node * head)
{
    //Node * ohead = head;
    for(;head!=NULL;)
    {
        Node * tmp = head->next;
        free(head);
        head = tmp;
    }
}


int main()
{
    Node * head =  createList();

    srand(time(NULL));
    for(int i=0; i<10; i++)
    {
        insertList(head, rand()%10);
    }
    travereList(head);

    int len =  lenList(head);
    printf("%d\n", len);

    Node * dNode = NULL;
    int i = 0;
    while(!dNode)
    {
        dNode = searchList(head, i);
        i++;
    }

    deleteList(head, dNode);

    popSortList(head);

    travereList(head);

    reverseList(head);

    travereList(head);

    destroyList(head);
    return 0;
}

#ifndef __LIST_H__
#define __LIST_H__

typedef struct _Node
{
   int data;
   struct _Node * next; 
}Node;


Node * createList();
void insertList(Node * head, int data);
void travereList(Node * head);
int lenList(Node * head);
Node * searchList(Node * head, int find);
void deleteList(Node * head, Node * pfind);
void popSortList(Node * head);
void reverseList(Node * head);
void destroyList(Node * head);




#endif // __LIST_H__
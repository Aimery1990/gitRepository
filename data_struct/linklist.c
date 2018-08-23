#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef void LinkList;

typedef struct _tag_Linklist_Node{
    struct _tag_Linklist_Node * next;
}LinkListNode;

LinkList * LinkList_Create()
{
    LinkList * list = NULL;
    return list;
}

void LinkList_Clear(LinkList * list)
{
    return ;
}

unsigned LinkList_Length(LinkList * list)
{
    return 0;
}


LinkList * LinkList_Insert(LinkList * list,  LinkListNode * node, int pos)
{
    return list;
}


LinkListNode * LinkList_Get(LinkList * list, int pos)
{
    
    return NULL;
}

LinkListNode * LinkList_Delete(LinkList * list,  int pos)
{
    return NULL;
}

void LinkList_Destory(LinkList * list)
{
    return;
}


typedef struct _Teacher{
    LinkListNode node;
    char name[64];
    int age;
}Teacher;



int main()
{
    LinkList * list = NULL;
    int i = 0;
    int length = 0;
    
    Teacher t1, t2, t3;
    t1.age = 30;
    t2.age = 31;
    t3.age = 32;
    
    list = LinkList_Create();
    length = LinkList_Length(list);
    
    LinkList_Insert(list, (LinkListNode*)&t1, LinkList_Length(list));
    LinkList_Insert(list, (LinkListNode*)&t2, LinkList_Length(list));
    LinkList_Insert(list, (LinkListNode*)&t3, LinkList_Length(list));
    
    for(i = 0; i< LinkList_Length(list); i++)
    {
        Teacher * tmp = (Teacher *)LinkList_Get(list, i);
        if(tmp){
            printf("%s %d\n", tmp->name,  tmp->age);
        }
    }
    
    while(LinkList_Length(list)>0)
    {
        Teacher * tmp = (Teacher *)LinkList_Delete(list,  i);
        if(tmp){
            printf("%s %d\n", tmp->name,  tmp->age);
        }
    }

    
    LinkList_Destory(list);
    
    return 0;
}

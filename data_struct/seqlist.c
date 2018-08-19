#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef void SeqList;
typedef void SeqListNode;

SeqList * SeqList_Create(int capacity)
{
    SeqList * list = NULL;
    return list;
}

SeqList * SeqList_Insert(SeqList * list,  SeqListNode * node, int pos)
{
    return list;
}

unsigned SeqList_Length(SeqList * list)
{
    return 0;
}

SeqListNode * SeqList_Get(SeqList * list, int pos)
{
    
    return NULL;
}

void SeqList_Delete(SeqList * list,  int pos)
{
    return;
}

void SeqList_Destory(SeqList * list)
{
    return;
}


typedef struct _Teacher{
    char name[64];
    int age;
}Teacher;



int main()
{
    SeqList * list = NULL;
    int i = 0;
    
    Teacher t1, t2, t3;
    list = SeqList_Create(20);
    SeqList_Insert(list, (SeqListNode*)&t1, 0);
    SeqList_Insert(list, (SeqListNode*)&t2, 0);
    SeqList_Insert(list, (SeqListNode*)&t3, 0);
    
    for(i = 0; i< SeqList_Length(list); i++)
    {
        Teacher * tmp = (Teacher *)SeqList_Get(list, i);
        if(tmp){
            printf("%s %d\n", tmp->name,  tmp->age);
        }
    }
    
    
    for(i = 0; i< SeqList_Length(list); i++)
    {
        SeqList_Delete(list,  i);
    }
    
    SeqList_Destory(list);
    
    return 0;
}












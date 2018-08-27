#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SEQ_MAX_SIZE 10

typedef void SeqList;
typedef void SeqListNode;

typedef struct tSeqList{
    int capacity;
    unsigned int length;
    unsigned int * node[SEQ_MAX_SIZE];
}TSeqList;

SeqList * SeqList_Create(int capacity)
{
    SeqList * list = NULL;
    return list;
}

SeqList * SeqList_Insert(SeqList * list,  SeqListNode * node, int pos)
{
    int i = 0;
    TSeqList * tList = (TSeqList *)list;
    if(!list || !node){
        printf("Invalid parameter\n");
        return (SeqList *)-1;
    }
    
    if(pos>=SEQ_MAX_SIZE){
        printf("pos is out of SEQ_MAX_SIZE\n");
        return (SeqList *)-1;
    }
    
    if(tList->length>=tList->capacity){
        printf("length is full\n");
        return (SeqList *)-3;
    }
    
    if(pos>tList->length && pos<SEQ_MAX_SIZE){
        printf("pos should be optimized and done automatically\n");
        pos = tList->length;
    }
    
    for(i = tList->length; i>pos; i--)
    {
        tList->node[i] = tList->node[i-1];
    }
    
    tList->node[pos] = (unsigned *)node;
    tList->length++;
    
    return list;
}

unsigned SeqList_Length(SeqList * list)
{
    return 0;
}

SeqListNode * SeqList_Get(SeqList * list, int pos)
{
    SeqListNode * ret = NULL;
    TSeqList * tList = (TSeqList *)list;
    if(!list||pos<0||pos>=tList->length){
        printf("Invalid given paramter");
        return (SeqListNode *)-1;
    }
    
    ret = (SeqListNode *)(tList->node)[pos];
    return ret;
}

SeqListNode * SeqList_Delete(SeqList * list,  int pos)
{
    int i = 0;
    TSeqList * tList = (TSeqList *)list;
    SeqListNode * ret = (SeqListNode *)(tList->node)[pos];
    
    if(!list||pos<0||pos>=tList->length){
        printf("Invalid given paramter");
        return (SeqListNode *)-1;
    }
    
    for(i = pos + 1; i< tList->length; i ++)
    {
        tList->node[i-1] = tList->node[i];
    }
    
    tList->length--;
    
    return ret;
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












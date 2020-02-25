#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"LinkList.h"

LinkList* Init_Link() {
    LinkList* list = (LinkList*)malloc(sizeof(LinkList));
    list->size = 0;
    LinkNode* node = (LinkNode*)malloc(sizeof(LinkNode));
//初始化，顾名思义是需要初始化linklist以及其对应的结点
    list->head = node;
    node->data = NULL;
    node->next = NULL;
    return list;
}
void Insert_Link(LinkList* list,int pos, void* data) {
    if (NULL == list||NULL==data)
        return;
    //对pos做友好处理
    if (pos<0 || pos>list->size)
        pos = list->size;
    LinkNode* pCurrent = list->head;
    for (int i = 0; i < pos-1; i++) {
        pCurrent = pCurrent->next;
    }//出来时 指针应该刚好指pos-1 然后考虑插入时候 需要先断开后继指针
    LinkNode* newNode = (LinkNode*)malloc(sizeof(LinkNode));
    newNode->data = data;
    newNode->next = pCurrent->next;
    pCurrent->next = newNode;

    list->size += 1;

}
void RemoveByPos_Link(LinkList* list, int pos) {
    if (NULL == list)
        return;
    if (pos < 0 || pos >= list->size)
        return;
    LinkNode* pCurrent = list->head;
    for (int i = 0; i < pos; i++) {
        pCurrent = pCurrent->next;
    }
    LinkNode* pTemp = pCurrent->next;
    pCurrent->next = pTemp->next;
    free(pTemp);

}
void RemoveByValue_Link(LinkList* list, void* data) {
    if (NULL == list)
        return;
}
void RemoveAllValue_Link(LinkList* list, void* data) {
    if (NULL == list)
        return;
}
//增删改查之改过于简单，就不写了
int Find_Link(LinkList* list, void* data) {
    if (NULL == list)
        return -1;
    int pos = -1;
    return pos;
}
void Print_Link(LinkList* list, LinkPrint print) {
    if (NULL == list)
        return;

    printf("---------------------------------\n");
    LinkNode* pCurrent = list->head->next;//这里一定不能从头结点开始 因为头结点是空的
    for (int i = 0; i < list->size; i++) {
        if (NULL == pCurrent||pCurrent==NULL)
            break;
        print(pCurrent->data);
        pCurrent = pCurrent->next;
    }
    printf("____________________________________\n");
}
void FreeSpace_Link(LinkList* list) {
    if (NULL == list)
        return;
    LinkNode* pTemp = NULL;
    LinkNode* pCurrent = list->head;
    for (int i = 0; i < list->size; i++) {
        pTemp = pCurrent->next;
        free(pCurrent);
        pCurrent = pTemp;
    }
    list->size = 0;
    free(list);

}


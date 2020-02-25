#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"EnLinkList.h"

EnLinkList* Init_EnLink() {
    EnLinkList* enlist = (EnLinkList*)malloc(sizeof(EnLinkList));
    enlist->head.next = NULL;
    enlist->size = 0;
    return enlist;
}
void Insert_EnLink(EnLinkList* enlist, int pos, EnLinkNode* node) {

    //这里的数据直接就是一个结点，所以是直接插入了一个结点，但是结点中只包含了next 数据如何处理？
    //用强转？但是node里只有next没有数据如何强转
    if (NULL == enlist)
        return;
    if (pos<0 || pos>enlist->size)
        pos = enlist->size;

    EnLinkNode* pCurrent = &(enlist->head);
    for (int i = 0; i < pos; i++) {
        pCurrent = pCurrent->next;
    }
    node->next = pCurrent->next;//仍然是后插，
    pCurrent->next = node;
    enlist->size += 1;
}
void Remove_EnLink(EnLinkList* enlist, int pos) {
    if (NULL == enlist)
        return;
    EnLinkNode* pCurrent = &(enlist->head);
    if (pos<0 || pos>enlist->size) {
        return;
    }
    for (int i = 0; i < pos; i++) {
        pCurrent = pCurrent->next;
    }
    EnLinkNode* pDel = NULL;
    pDel = pCurrent->next;//后位存为del
    pCurrent->next = pDel->next;//后后位变为后位
    enlist->size -= 1;


}
int Find_Enlink(EnLinkList* enlist,EnLinkNode* node) {
    if (NULL == enlist)
        return-1;
    int pos = -1;
    EnLinkNode* pCurrent = &(enlist->head);
    for (int i = 0; i < enlist->size; i++) {
        if (pCurrent == node) {
            pos = i;
        }
        break;
        pCurrent = pCurrent->next;
    }
    EnLinkNode* pDel = NULL;
    pDel = pCurrent->next;//后位存为del
    pCurrent->next = pDel->next;//后后位变为后位
    enlist->size -= 1;

    return pos;
    
    
}
void Print_EnLink(EnLinkList* enlist, EnPrint print) {
    if (NULL == enlist)
        return;
    printf("~~~~~~~~~~~~~~~~~~~~~~\n");
    //EnLinkNode* pCurrent = &(enlist->head);//这里为什么不这样写
    EnLinkNode* pCurrent = enlist->head.next;//好像是因为头结点不写数据
    for (int i = 0; i < enlist->size; i++) {
        print(pCurrent);
        pCurrent = pCurrent->next;
    }
    printf("________________________\n");
}
void FreeSpace_EnLink(EnLinkList* enlist) {
    if (NULL == enlist)
        return;
    free(enlist);
}

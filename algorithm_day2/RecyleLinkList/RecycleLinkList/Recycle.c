#include"Recycle.h"

LinkList* Init_Link() {
    LinkList* list = (LinkList*)malloc(sizeof(LinkList));
    list->size = 0;
    //LinkNode* node = (LinkNode*)malloc(sizeof(LinkNode));
    list->head.next = NULL;//这个头结点是没有实际意义的头结点
    return list;
}
void Insert_Link(LinkList* list, int pos, LinkNode* node) {
    if (NULL == list||NULL==node)
        return;
    if (pos<0 || pos>list->size)
        pos = list->size;
    LinkNode* pCurrent = &(list->head);
    for (int i = 0; i < pos; i++) {
        pCurrent = pCurrent->next;
    }
    node->next = pCurrent->next;
    pCurrent->next = node;

    list->size += 1;
}
int Find_Link(LinkList* list, LinkNode* node, NodeCompare compare) {
    if (NULL == list)
        return -1;
    int pos = -1;
    int flag = 0;
    LinkNode* pCurrent = list->head.next;
    for (int i = 0; i < list->size; i++) {
        flag = compare(pCurrent, node);
        if (flag == 1) {
            pos = i;
            break;
            //return i;
        }
        pCurrent = pCurrent->next;
    }
    return pos;
    
}
void Remove_Link(LinkList* list, int pos){
    if (NULL == list)
        return;
    if (pos<0 || pos>list->size)
        return;
    LinkNode* pCurrent = list->head.next;//删除数据也是从有效数据开始
    for (int i = 0; i<pos; i++) {
        pCurrent = pCurrent->next;
    }
    LinkNode* pDel = pCurrent->next;
    pCurrent = pDel;
    //free(pDel);

    list->size -= 1;
}
void Print_Link(LinkList* list, LinkPrint print) {
    if (NULL == list)
        return;
    printf("~~~~~~~~~~~~~~~~~~~~~\n");
    LinkNode* pCurrent = list->head.next;//实际内容是从next开始
    for (int i = 0; i < list->size; i++) {
        print(pCurrent);
        pCurrent = pCurrent->next;
    }
    printf("______________________\n");
}
void FreeSpace_Link(LinkList* list) {
    if (NULL == list)
        return;
    free(list);
}

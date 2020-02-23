#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"CLinkList.h"

LinkList* Init_LinkList() {
    // 初始化
    LinkList* list = (LinkList*)malloc(sizeof(LinkList));
    if (NULL == list)
        return NULL;
    list->head = (LinkNode*)malloc(sizeof(LinkNode));
    //为了简化对于首结点的判断，此处定义一个首结点，但是不存入数据
    list->head->data = NULL;
    list->head->next = NULL;
    list->size = 0;
    return list;
}
void Insert_LinkList(LinkList* list, int pos, void* data) {
    if (NULL == list||NULL==data) {
        return;
    }
    //这里对pos作一个友好处理，即下标不规范时，直接添加到尾部
    if (pos<0 || pos>list->size) {
        pos = list->size;
    }
    //现在pos合乎规范了
    LinkNode* newNode = (LinkNode*)malloc(sizeof(LinkNode));//开辟空间
    newNode->data = data;
    newNode->next = NULL;
    //然后要遍历链表到pos位置
    LinkNode* pCurrent = list->head;//初始位置设为头结点//pCurrent不用开辟空间吗？
    for (int i = 0; i < pos; i++) {
        pCurrent = pCurrent->next;
    }
    newNode->next = pCurrent->next;
    pCurrent->next = newNode;
    list->size += 1;
}
void RemoveByPos_LinkList(LinkList* list, int pos) {
    if (NULL == list) {
        return;
    }
    //删除一个节点和插入类似，但是不能做友好处理了
    if (pos < 0 || pos >= list->size)
        return;
    //LinkNode* pCurrent = (LinkNode*)malloc(sizeof(LinkNode));
    LinkNode* pCurrent = list->head;
    for (int i = 0; i < pos; i++) {
        pCurrent = pCurrent->next;
    }
    LinkNode* pDel = pCurrent->next;//pDel目前就是要删除的那个结点
    pCurrent->next= pDel->next;
    free(pDel);
    list->size -= 1;
}
int Size_LinkList(LinkList* list) {
    if (NULL == list)
        return -1;

    return list->size;
}
int Find_LinkList(LinkList* list, void* data) {
    if(NULL==list||NULL==data)
        return -1;
    int pos = -1;
    LinkNode* pCurrent= (LinkNode*)malloc(sizeof(LinkNode));
    pCurrent = list->head->next;//这里视头结点作无效，从头结点后的结点开始视作有效数据
    
    for (int i = 0; i < list->size; i++) {
        if (pCurrent->data == data) {
            pos = i;
        }
        break;//一定要注意这个break
        pCurrent = pCurrent->next;
    }
    return pos;
}
void* Front_LinkList(LinkList* list) {
    return list->head->next;
}
void Print_LinkList(LinkList* list, PRINTLINKNODE print) {
    if (NULL == list)
        return;
    LinkNode* pCurrent = list->head->next; 
    for (int i = 0; i < list->size; i++) {
        print(pCurrent->data);
        pCurrent = pCurrent->next;
    }
}
void Free_LinkList(LinkList* list) {
    if (NULL == list) {
        return;
    }
    //由于每一个结点都是指针，故此都需要依次释放内存
    LinkNode* pCurrent = list->head;
    //这里不能先free内存 如果先删 那么就无法找到后继结点了
    LinkNode* pTemp = NULL;
    for (int i = 0; i < list->size; i++) {
        //**
        pTemp = pCurrent->next;
        free(pCurrent);
        pCurrent = pTemp;
    }
    list->size = 0;
    free(list);

}

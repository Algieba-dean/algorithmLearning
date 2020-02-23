#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"CLinkList.h"

LinkList* Init_LinkList() {
    // ��ʼ��
    LinkList* list = (LinkList*)malloc(sizeof(LinkList));
    if (NULL == list)
        return NULL;
    list->head = (LinkNode*)malloc(sizeof(LinkNode));
    //Ϊ�˼򻯶����׽����жϣ��˴�����һ���׽�㣬���ǲ���������
    list->head->data = NULL;
    list->head->next = NULL;
    list->size = 0;
    return list;
}
void Insert_LinkList(LinkList* list, int pos, void* data) {
    if (NULL == list||NULL==data) {
        return;
    }
    //�����pos��һ���Ѻô������±겻�淶ʱ��ֱ����ӵ�β��
    if (pos<0 || pos>list->size) {
        pos = list->size;
    }
    //����pos�Ϻ��淶��
    LinkNode* newNode = (LinkNode*)malloc(sizeof(LinkNode));//���ٿռ�
    newNode->data = data;
    newNode->next = NULL;
    //Ȼ��Ҫ��������posλ��
    LinkNode* pCurrent = list->head;//��ʼλ����Ϊͷ���//pCurrent���ÿ��ٿռ���
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
    //ɾ��һ���ڵ�Ͳ������ƣ����ǲ������Ѻô�����
    if (pos < 0 || pos >= list->size)
        return;
    //LinkNode* pCurrent = (LinkNode*)malloc(sizeof(LinkNode));
    LinkNode* pCurrent = list->head;
    for (int i = 0; i < pos; i++) {
        pCurrent = pCurrent->next;
    }
    LinkNode* pDel = pCurrent->next;//pDelĿǰ����Ҫɾ�����Ǹ����
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
    pCurrent = list->head->next;//������ͷ�������Ч����ͷ����Ľ�㿪ʼ������Ч����
    
    for (int i = 0; i < list->size; i++) {
        if (pCurrent->data == data) {
            pos = i;
        }
        break;//һ��Ҫע�����break
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
    //����ÿһ����㶼��ָ�룬�ʴ˶���Ҫ�����ͷ��ڴ�
    LinkNode* pCurrent = list->head;
    //���ﲻ����free�ڴ� �����ɾ ��ô���޷��ҵ���̽����
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

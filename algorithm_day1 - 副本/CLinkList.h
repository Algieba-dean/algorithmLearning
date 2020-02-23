#pragma once
#ifndef CLINKLIST_H
#define CLINKLIST_H

typedef struct LINKNODE {
    void* data;//���κε����ݣ��ÿ�ָ��
    struct LINKNODE* next;//���ַ
}LinkNode;//linkNode��һ������
typedef struct LINKLIST {
    LinkNode* head;
    int size;
}LinkList;
typedef void(*PRINTLINKNODE)(void*);//����һ������ָ��

LinkList* Init_LinkList();
void Insert_LinkList(LinkList* link, int pos, void* data);
void RemoveByPos_LinkList(LinkList* link, int pos);
int Size_LinkList(LinkList* link);
int Find_LinkList(LinkList* list, void* data);//����λ��
void* Front_LinkList(LinkList* list);//�����׽�㣿��㲻Ӧ����LinkNode*��
void Print_LinkList(LinkList* list, PRINTLINKNODE print);
void Free_LinkList(LinkList* list);
#endif

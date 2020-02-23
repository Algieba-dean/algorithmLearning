#pragma once
#ifndef CLINKLIST_H
#define CLINKLIST_H

typedef struct LINKNODE {
    void* data;//存任何的数据，用空指针
    struct LINKNODE* next;//存地址
}LinkNode;//linkNode是一种类型
typedef struct LINKLIST {
    LinkNode* head;
    int size;
}LinkList;
typedef void(*PRINTLINKNODE)(void*);//定义一个函数指针

LinkList* Init_LinkList();
void Insert_LinkList(LinkList* link, int pos, void* data);
void RemoveByPos_LinkList(LinkList* link, int pos);
int Size_LinkList(LinkList* link);
int Find_LinkList(LinkList* list, void* data);//返回位置
void* Front_LinkList(LinkList* list);//返回首结点？结点不应该是LinkNode*吗？
void Print_LinkList(LinkList* list, PRINTLINKNODE print);
void Free_LinkList(LinkList* list);
#endif

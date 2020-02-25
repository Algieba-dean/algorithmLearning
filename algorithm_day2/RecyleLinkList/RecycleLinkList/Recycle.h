#pragma once
#ifndef __RECYCLE_H__
#define __RECYCLE_H__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct LINKNODE {
    struct LINKNODE* next;
}LinkNode;

typedef struct LINKLIST {
    LinkNode head;
    int size;
}LinkList;

typedef void (*LinkPrint)(LinkNode* node);
typedef int (*NodeCompare)(LinkNode* node1, LinkNode* node2);

LinkList* Init_Link();
void Insert_Link(LinkList* list, int pos, LinkNode* node);
int Find_Link(LinkList* list, LinkNode* node, NodeCompare compare);
void RemoveByValue_Link(LinkList* list, LinkNode* node, NodeCompare compare);
int IsEmpty_Link(LinkList* list);
void Remove_Link(LinkList* list, int pos);
void Print_Link(LinkList* list, LinkPrint print);
void FreeSpace_Link(LinkList* list);
#endif

#pragma once
#ifndef __ENLINKLIST_H__
#define __ENLINKLIST_H__
typedef struct ENLINKNODE {
    struct ENLINKNODE* next;//因为可以通过指针转换来获取数据，所以暂时就只用存放一个下一指针
}EnLinkNode;
typedef struct ENLINKLIST {
    EnLinkNode head;//这里不再是指针而是值
    int size;
}EnLinkList;
typedef void (*EnPrint)(EnLinkNode*);//为啥传入node了
EnLinkList* Init_EnLink();//初始化
void Insert_EnLink(EnLinkList* enlist,int pos, EnLinkNode* node);//数据现在是node了
void Remove_EnLink(EnLinkList* enlist, int pos);
int Find_Enlink(EnLinkList* enlist,EnLinkNode* node);
void Print_EnLink(EnLinkList* enlist, EnPrint print);
void FreeSpace_EnLink(EnLinkList* enlist);
#endif

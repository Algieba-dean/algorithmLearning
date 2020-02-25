#ifndef __LINKLIST_H__
#define __LINKLIST_H__

typedef struct LINKNODE {
    void* data;
    struct LINKNODE* next;//这里是自身调用 但注意只能调用得到一个指针，否则会无限循环的
    
}LinkNode;
typedef struct LINKLIST {
    LinkNode* head;//别忘了头结点
    int size;

}LinkList;

typedef void(*LinkPrint)(void*);

LinkList* Init_Link();
void Insert_Link(LinkList* list, int pos, void* data);
void RemoveByPos_Link(LinkList* list, int pos);
void RemoveByValue_Link(LinkList* list, void* data);
void RemoveAllValue_Link(LinkList* list, void* data);
//增删改查之改过于简单，就不写了
int Find_Link(LinkList* list, void* data);
void Print_Link(LinkList* list, LinkPrint print);
void FreeSpace_Link(LinkList* list);

#endif
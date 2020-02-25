#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Recycle.h"

typedef struct PERSON {
    LinkNode* next;
    char name[255];
    int age;
}Person;
int Compare(LinkNode* node1, LinkNode *  node2) {
    Person* p1 = (Person*)node1;
    Person* p2 = (Person*)node2;
    if (strcmp(p1->name, p2->name) && (p1->age == p2->age))
        return 1;
    return 0;
}
void Print(LinkNode* node) {
    Person* p = (Person*)node;
    printf("name:%s age:%d\n", p->name, p->age);
}
void TestLink();
int main() {

    TestLink();
    return 0;
}
void TestLink() {
    Person DongYQ, DongYS, DongYT, DongYL,FakeYQ;
    /*

    strcpy_s(DongYQ.name, strlen("000") + 1, "000");
    strcpy_s(DongYS.name, strlen("111") + 1, "111");
    strcpy_s(DongYT.name, strlen("222") + 1, "222");
    strcpy_s(DongYL.name, strlen("333") + 1, "333");
    strcpy_s(FakeYQ.name, strlen("111") + 1, "111");

    */
    //printf("name:%s\n", DongYL.name);

    strcpy_s(DongYQ.name, strlen("董云清") + 1, "董云清");
    strcpy_s(DongYS.name, strlen("董云舒") + 1, "董云舒");
    strcpy_s(DongYT.name, strlen("董云天") + 1, "董云天");
    strcpy_s(DongYL.name, strlen("董云兰") + 1, "董云兰");
    strcpy_s(FakeYQ.name, strlen("董云清") + 1, "董云清");

    DongYQ.age = 31;
    DongYS.age = 28;
    DongYT.age = 22;
    DongYL.age = 19;
    FakeYQ.age = 31;

    LinkList* list = Init_Link();
    Insert_Link(list, 0,(LinkNode*)&DongYQ);
    Insert_Link(list, 0,(LinkNode*)&DongYS);
    Insert_Link(list, 0,(LinkNode*)&DongYT);
    Insert_Link(list, 0,(LinkNode*)&DongYL);
    Print_Link(list, Print);
    FreeSpace_Link(list);

}
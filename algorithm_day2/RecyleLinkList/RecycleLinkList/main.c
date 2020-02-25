#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Recycle.h"

typedef struct PERSON {
    LinkNode node;
    char name[255];
    int age;
}Person;
int Compare(LinkNode* node1, LinkNode *  node2) {
    Person* p1 = (Person*)node1;
    Person* p2 = (Person*)node2;
    if (0==(strcmp(p1->name, p2->name)) && (p1->age == p2->age))
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
    Person DongYQ, DongYS, DongYT, DongYL,FakeYL;

    strcpy_s(DongYQ.name, strlen("DongYQ") + 1, "DongYQ");
    strcpy_s(DongYS.name, strlen("DongYS") + 1, "DongYS");
    strcpy_s(DongYT.name, strlen("DongYT") + 1, "DongYT");
    strcpy_s(DongYL.name, strlen("DongYL") + 1, "DongYL");
    strcpy_s(FakeYL.name, strlen("DongYL") + 1, "DongYL");

    /*
    printf("name:%s\n", DongYQ.name);
    printf("name:%s\n", DongYS.name);
    printf("name:%s\n", DongYT.name);
    printf("name:%s\n", DongYL.name);
    printf("name:%s\n", FakeYQ.name);
    */

    /*
    strcpy_s(DongYQ.name, strlen("董云清") + 1, "董云清");
    strcpy_s(DongYS.name, strlen("董云舒") + 1, "董云舒");
    strcpy_s(DongYT.name, strlen("董云天") + 1, "董云天");
    strcpy_s(DongYL.name, strlen("董云兰") + 1, "董云兰");
    strcpy_s(FakeYQ.name, strlen("董云清") + 1, "董云清");
    */

    DongYQ.age = 31;
    DongYS.age = 28;
    DongYT.age = 22;
    DongYL.age = 19;
    FakeYL.age = 19;

    LinkList* list = Init_Link();
    Insert_Link(list, -1,(LinkNode*)&DongYQ);
    Insert_Link(list, -1,(LinkNode*)&DongYS);
    Insert_Link(list, -1,(LinkNode*)&DongYT);
    Insert_Link(list, -1,(LinkNode*)&DongYL);
    printf("\n%d\n\n", Find_Link(list, (LinkNode*)&DongYS,Compare));
    printf("\n%d\n", list->size);
    Print_Link(list, Print);
    Remove_Link(list, 999);
    Print_Link(list, Print);
    RemoveByValue_Link(list, (LinkNode*)&DongYQ, Compare);
    Print_Link(list, Print);

    FreeSpace_Link(list);

}
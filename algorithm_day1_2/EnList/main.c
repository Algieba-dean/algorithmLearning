#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"DynamicArray.h"
#include"LinkList.h"
#include"EnLinkList.h"

void DynamicArrTest();
void LinkListTest();
void PrintLinkTest(void* data);
void EnListTest();
void EnLinkPrintTest(EnLinkNode* node);
typedef struct GIRL {
    char name[256];
    int age;
}Girl;

typedef struct PERSON {
    EnLinkNode node;
    char name[245];
    int age;
}Person;
int main() {
    //DynamicArrTest();
    //LinkListTest();
    EnListTest();
    
    return 0;
}
void DynamicArrTest() {
    DynamicArray* arr = Init_Array();
    for (int i = 0; i < 10; i++) {
        PushBack_Array(arr, i);
        if (0 == i % 3)
            PushBack_Array(arr, i);//增加一点没有顺序的数
    }
    printf("size:%d, capacity:%d\n", arr->size, arr->capacity);
    Print_Array(arr);
    ChangeAllValue_Array(arr, 3,999);//如果正序就会删错
    Print_Array(arr);
    //RemoveByPos_Link()
    FreeSpace_Array(arr);


}
void LinkListTest() {

    LinkList* list = Init_Link();
    Girl miao1 = { "miao1",33 };
    Girl miao2 = { "miao2",23 };
    Girl miao3 = { "miao3",13 };
    Insert_Link(list, 0, &miao1);
    Insert_Link(list, 0, &miao2);
    Insert_Link(list, 0, &miao3);
    Insert_Link(list, 0, &miao3);
    Insert_Link(list, 0, &miao3);
    Insert_Link(list, 0, &miao3);
    Insert_Link(list, 0, &miao3);
    Print_Link(list, PrintLinkTest);
    RemoveByPos_Link(list, 0);
    Print_Link(list, PrintLinkTest);
    FreeSpace_Link(list);
    

}
void PrintLinkTest(void* data) {
    Girl* girl = (Girl*)data;
    printf("name:%s,age:%d\n", girl->name, girl->age);
    
}
void EnListTest() {
    EnLinkList* enlist = Init_EnLink();

    Person w1, w2, w3, w4;
    strcpy_s(w1.name, strlen("11") + 1, "11");
    strcpy_s(w2.name, strlen("22") + 1, "22");
    strcpy_s(w3.name, strlen("33") + 1, "33");
    strcpy_s(w4.name, strlen("44") + 1, "44");
    w1.age = 101;
    w2.age = 102;
    w3.age = 103;
    w4.age = 104;
    Insert_EnLink(enlist, 0, (EnLinkNode*)&w1);//由于EnLinkNode类型地址 头部和person一样 但是小很多 只能访问地址
    Insert_EnLink(enlist, 0, (EnLinkNode*)&w2);
    Insert_EnLink(enlist, 0, (EnLinkNode*)&w3);
    Insert_EnLink(enlist, 0, (EnLinkNode*)&w4);
    Print_EnLink(enlist, EnLinkPrintTest);
    Remove_EnLink(enlist, 0);
    Print_EnLink(enlist, EnLinkPrintTest);
    Remove_EnLink(enlist, Find_Enlink(enlist, (EnLinkNode*)&w3));
    Print_EnLink(enlist, EnLinkPrintTest);
    FreeSpace_EnLink(enlist);


}
void EnLinkPrintTest(EnLinkNode* node) {
    Person* p = (Person*)node;
    printf("name:%s,age:%d\n", p->name, p->age);
}

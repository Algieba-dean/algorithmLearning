#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include<stdio.h>
#include<string.h>
#include"CDynamicArray.h"
#include"CLinkList.h"

typedef struct PERSON {
    char name[255];
    int age;
    int score;
}Person;

void TestArr();
void TestLink();
void Print(void* data);
int main() {
    
    TestLink();
    return 0;
}
void TestArr() {
    
    CDynamic_Array* MyArr= CDynamic_Init();
    for (int i = 0; i < 29; i++) {
        //MyArr->pAddr[i] = i;//不能这么写
        PushBack_Array(MyArr, i);
    }
    Print_Array(MyArr);
    RemoveByPos_Array(MyArr, 0);
    for (int i = 1; i <= 10; i++)
        PushBack_Array(MyArr, 13);
    Print_Array(MyArr);
    RemoveAllByValue_Array(MyArr, 13);
    Print_Array(MyArr);
}
void Print(void* data) {
    Person* p = (Person*)data;
    printf("name:%s , age:%d ,score:%d\n", p->name, p->age, p->score);
}
void TestLink() {

    LinkList* list = Init_LinkList();
    Person p1 = { "01",11,99 };
    Person p2 = { "02",12,92 };
    Person p3 = { "03",13,93 };
    Person p4 = { "04",14,98 };
    Person p5 = { "05",15,95 };
    Insert_LinkList(list, 0, &p1);
    Insert_LinkList(list, 1, &p2);
    Insert_LinkList(list, 2, &p3);
    Insert_LinkList(list, 3, &p4);
    Insert_LinkList(list, 5, &p5);

    Print_LinkList(list, Print);
    RemoveByPos_LinkList(list, 1);
    printf("---------------------\n");
    Print_LinkList(list, Print);

}
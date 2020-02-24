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

int main() {
    DynamicArrTest();
    //LinkListTest();
    //EnListTest();
    
    return 0;
}
void DynamicArrTest() {
    DynamicArray* arr = Init_Array();
    for (int i = 0; i < 40; i++) {
        PushBack_Array(arr, i);
        if (0 == i % 3)
            PushBack_Array(arr, i);//增加一点没有顺序的数
    }
    printf("size:%d, capacity:%d\n", arr->size, arr->capacity);
    Print_Array(arr);


}
void LinkListTest() {

}
void PrintLinkTest(void* data) {

}
void EnListTest() {

}

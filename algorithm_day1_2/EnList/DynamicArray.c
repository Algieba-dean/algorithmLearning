#pragma once
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"DynamicArray.h"

DynamicArray* Init_Array() {
    DynamicArray* arr = (DynamicArray*)malloc(sizeof(DynamicArray));//初始化内存空间
    arr->size = 0;//默认大小为0
    arr->capacity = 20;//默认容量为20
    arr->pAddr = (int*)malloc(sizeof(int) * arr->capacity);//为数据空间开辟新地址

    return arr ;
}
void PushBack_Array(DynamicArray* array, int data) {
    if (NULL == array)
        return;
    if (array->size >= array->capacity) {
        //超过容量，需要进行扩容，暂定按2倍扩容
        array->capacity *= 2;
        int* newAddr = (int*)malloc(sizeof(int) * array->capacity);//开辟新地址
        memcpy(newAddr, array->pAddr, sizeof(int) * array->size);//将旧地址中内容拷贝到新地址去
        

        
    }
}
int Find_Array(DynamicArray* array, int data) {
    return -1;
}
void RemoveByPos_Array(DynamicArray* array, int pos) {

}
void RemoveByValue_Array(DynamicArray* array, int data) {

}
void RemoveAllValue_Array(DynamicArray* array, int data) {

}
int Size_Array(DynamicArray* array) {
    return -1;
}
int Capacity_Array(DynamicArray* array) {
    return -1;
}
void FreeSpace_Array(DynamicArray* array) {

}


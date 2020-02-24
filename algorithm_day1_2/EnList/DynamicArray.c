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
    //数组有效判断
    if (NULL == array)
        return;
    //扩容判断
    if (array->size >= array->capacity) {
        //超过容量，需要进行扩容，暂定按2倍扩容
        array->capacity *= 2;
        int* newAddr = (int*)malloc(sizeof(int) * array->capacity);//开辟新地址
        memcpy(newAddr, array->pAddr, sizeof(int) * array->size);//将旧地址中内容拷贝到新地址去
        free(array->pAddr);//释放原来空间
        array->pAddr = newAddr;//把旧地址更新为扩容后的新地址
    }
    //将新数据置于末端
    array->pAddr[array->size] = data;//直接用下标存入数据即可！！！
    array->size += 1;

}
int Find_Array(DynamicArray* array, int data) {
    if (NULL == array)
        return -1;
    int pos = -1;
/*
    for (int i = array->size - 1; i >= 0; i--) {
        //逆向查找，方便删除调用查找函数的时候数组越界
        if (array->pAddr[i] == data) {
            pos = i;
            break;//找到之后要跳出循环
        }
    }

*/
    for (int i = 0; i < array->size; i++) {
        //暂时改为正向->这里不会出错是因为size进行了维护 若使用的是一次性变量 那么就会出现越界
        if (array->pAddr[i] == data) {
            pos = i;
            break;
        }
    }
    return pos;
}
void RemoveByPos_Array(DynamicArray* array, int pos) {
    if (NULL == array)
        return;
    if (pos<0 || pos>array->size)
        return;
    for (int i = pos; i < array->size-1; i++) {
        array->pAddr[i] = array->pAddr[i + 1];
    }
    array->size -= 1;
}
void RemoveByValue_Array(DynamicArray* array, int data) {
    if (NULL == array)
        return;
    RemoveByPos_Array(array, Find_Array(array, data));
}
void RemoveAllValue_Array(DynamicArray* array, int data) {
    if (NULL == array)
        return;
    for (int i = 0; i < array->size; i++) {
        RemoveByValue_Array(array, data);
    }
}

void Print_Array(DynamicArray* array) {
    if (NULL == array)
        return;
    for (int i = 0; i < array->size; i++) {
        printf("%d ", array->pAddr[i]);
    }
    printf("\n--------------------------\n");
}
void ChangeByPos_Array(DynamicArray* array, int pos, int data) {
    if (NULL == array)
        return;
    if (pos<0 || pos>array->size)
        return;
    array->pAddr[pos] = data;

}
void ChangeByValue_Array(DynamicArray* array, int data,int newData) {
    if (NULL == array)
        return;
    int pos = Find_Array(array, data);
    ChangeByPos_Array(array,pos, newData);
}
void ChangeAllValue_Array(DynamicArray* array, int data,int newData) {
    if (NULL == array)
        return;
    for (int i = 0; i < array->size; i++) {
        ChangeByValue_Array(array, data, newData);
    }
}void FreeSpace_Array(DynamicArray* array) {
    if (NULL == array||NULL==array->pAddr)
        return;
    free(array->pAddr);
    free(array);
}



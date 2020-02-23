#pragma once
#ifndef CDYNAMICARRAY_H
#define CDYNAMICARRAY_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct CDYNAMICARRAY {
    int* pAddr;
    int size;
    int capacity;

}CDynamic_Array;

CDynamic_Array* CDynamic_Init();//初始化
void PushBack_Array(CDynamic_Array* arr, int value);//因为是后项插入，无需知道
void RemoveByPos_Array(CDynamic_Array* arr, int pos);//按位置删除
void RemoveByValue_Array(CDynamic_Array* arr, int value);//按值删除
void RemoveAllByValue_Array(CDynamic_Array* arr, int value);

int Find_Array(CDynamic_Array* arr, int value);
void Print_Array(CDynamic_Array* arr);
void Clear_Array(CDynamic_Array* arr);
int Capacity_Array(CDynamic_Array* arr);
int Size_Array(CDynamic_Array* arr);
int At_Array(CDynamic_Array* arr, int pos);//按照位置去获取对应
void FreeSpace_Array(CDynamic_Array* arr);//释放内存
#endif

#pragma once
#ifndef __DYNAMICARRAY_H__
#define __DYNAMICARRAY_H__

typedef struct DYNAMICARRAY {
    int* pAddr;//应该存入数据地址，不能直接存放数据
    int size;
    int capacity;
}DynamicArray;
//动态数组的增删改查
DynamicArray* Init_Array();
void PushBack_Array(DynamicArray* array, int data);//接在后面进行添加，故不需要位置
int Find_Array(DynamicArray* array, int data);//返回第一个找到的数据
void RemoveByPos_Array(DynamicArray* array, int pos);//按位置删除
void RemoveByValue_Array(DynamicArray* array, int data);//按数据删除一个
void RemoveAllValue_Array(DynamicArray* array, int data);//按数据删除所有
void Print_Array(DynamicArray* array);
void FreeSpace_Array(DynamicArray* array);//释放空间

#endif

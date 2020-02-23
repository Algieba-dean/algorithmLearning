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

CDynamic_Array* CDynamic_Init();//��ʼ��
void PushBack_Array(CDynamic_Array* arr, int value);//��Ϊ�Ǻ�����룬����֪��
void RemoveByPos_Array(CDynamic_Array* arr, int pos);//��λ��ɾ��
void RemoveByValue_Array(CDynamic_Array* arr, int value);//��ֵɾ��
void RemoveAllByValue_Array(CDynamic_Array* arr, int value);

int Find_Array(CDynamic_Array* arr, int value);
void Print_Array(CDynamic_Array* arr);
void Clear_Array(CDynamic_Array* arr);
int Capacity_Array(CDynamic_Array* arr);
int Size_Array(CDynamic_Array* arr);
int At_Array(CDynamic_Array* arr, int pos);//����λ��ȥ��ȡ��Ӧ
void FreeSpace_Array(CDynamic_Array* arr);//�ͷ��ڴ�
#endif

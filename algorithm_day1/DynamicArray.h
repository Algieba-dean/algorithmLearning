#pragma once
#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

template <class T>
class DYNAMIC_ARRAY {
private:
    T* pAddr;//存放的地址
    int size;//元素的数量
    int capacity;//容器的当前容量

public:
    DYNAMIC_ARRAY(void);//默认空参数的
    DYNAMIC_ARRAY(const DYNAMIC_ARRAY<T>& arr);//默认的拷贝构造函数
    DYNAMIC_ARRAY<T>* operator=(const DYNAMIC_ARRAY<T>& arr);
    T& operator[](int i);//重载下标运算符
    void Push_Back_Array(DYNAMIC_ARRAY* arr, T value);//因为动态数组为顺序插入故不需要传入地址
    void Remove_Array(DYNAMIC_ARRAY*)
    ~DYNAMIC_ARRARY();
};
#endif

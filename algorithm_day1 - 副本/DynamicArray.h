#pragma once
#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

template <class T>
class DYNAMIC_ARRAY {
private:
    T* pAddr;//��ŵĵ�ַ
    int size;//Ԫ�ص�����
    int capacity;//�����ĵ�ǰ����

public:
    DYNAMIC_ARRAY(void);//Ĭ�Ͽղ�����
    DYNAMIC_ARRAY(const DYNAMIC_ARRAY<T>& arr);//Ĭ�ϵĿ������캯��
    DYNAMIC_ARRAY<T>* operator=(const DYNAMIC_ARRAY<T>& arr);
    T& operator[](int i);//�����±������
    void Push_Back_Array(DYNAMIC_ARRAY* arr, T value);//��Ϊ��̬����Ϊ˳�����ʲ���Ҫ�����ַ
    void Remove_Array(DYNAMIC_ARRAY*)
    ~DYNAMIC_ARRARY();
};
#endif

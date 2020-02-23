#include"CDynamicArray.h"


CDynamic_Array* CDynamic_Init() {
    //
    //��Ϊ����ֵ���ٿռ�
    CDynamic_Array* arr = (CDynamic_Array*)malloc(sizeof(CDynamic_Array));

    arr->size = 0;//��ʼ�������СΪ0
    arr->capacity = 20;//ÿ��block�Ĵ�СΪ20
    
    arr->pAddr = (int*)malloc(sizeof(int) * arr->capacity);

    return arr;
}
void PushBack_Array(CDynamic_Array* arr, int value) {
    if (NULL == arr) {
        return;
    }
    //��Ϊ��ֱ�ӽ���֮ǰ�ĵ�ַ��Ӽ��� �ʶ�����Ҫ�����ַ
    //������Ҫ�ж�һ���Ƿ���Ҫ�����µ��ڴ�
    if (arr->size >= arr->capacity) {
        arr->capacity *= 2;//���������ڴ�ͻᱶ�����е����⣬���ݲ�����
        int* nAddr = (int*)malloc(sizeof(int) * arr->capacity);
        memcpy(nAddr, arr->pAddr, sizeof(int) * arr->size);//����ǰ�����ݿ�����ȥ
        free(arr->pAddr);//ɾ��ԭ�пռ�
        arr->pAddr = nAddr;//����(����free��֮����������)
        //free(nAddr);//����ط������ͷ� ��ַͬ�ڱ���
    }
    arr->pAddr[arr->size] = value;
    arr->size += 1;
}
void RemoveByPos_Array(CDynamic_Array* arr, int pos) {
    if (NULL == arr) {
        return;
    }
    //ɾ�������Ǽ򵥵ؽ���Ӧλ��Ϊ0������Ҫ����Ӧλ�ú����������ǰ�ƶ�
    //����Ҫ���һ������Խ��
    if (pos<0 || pos>=arr->size) {
        return;
    }
    for (int i = arr->size-1; i <=pos; i++) {
        arr->pAddr[i] = arr->pAddr[i + 1];
    }
    arr->size -= 1;
    //�������һ��λ����Ȼû�д��� ��������
}
void RemoveByValue_Array(CDynamic_Array* arr, int value) {
    if (NULL == arr) {
        return;
    }
    int pos = Find_Array(arr, value);
    RemoveByPos_Array(arr, pos);
}

void RemoveAllByValue_Array(CDynamic_Array* arr, int value) {
    if (NULL == arr) {
        return;
    }
    for (int i = arr->size-1; i >= 0; i--) {//��������˳������ν����Ҫ����ִ��ɾ���ĵط���Ҫ���ţ��������һ����������size
        RemoveByPos_Array(arr, value);
    }
}
int Find_Array(CDynamic_Array* arr, int value) {
    if (NULL == arr) {
        return -1;
    }
    int pos = -1;
    for (int i = 0; i < arr->size; i++) {
        if (arr->pAddr[i] == value) {
            pos = i;
        }
        break;//������Ҫ����ѭ������Ȼ��ֻ���жϳ����һ����λ��

    }

    return pos;
}
void Print_Array(CDynamic_Array* arr) {
    if (NULL == arr) {
        return;
    }
    for (int i = 0; i < arr->size; i++) {
        printf("%d ", arr->pAddr[i]);
    }
    printf("\n");
}
void Clear_Array(CDynamic_Array* arr) {
    if (NULL == arr) {
        return;
    }
    arr->size = 0;//�����ܸо� ��ַ�л�����ֵ
    arr->pAddr = NULL;//�ѵ�ַָ��� Ӧ�þͺ���
}
int Capacity_Array(CDynamic_Array* arr) {
 if (NULL == arr) {
        return -1;
    }   
 return arr->capacity;
}
int Size_Array(CDynamic_Array* arr) {
 if (NULL == arr) {
        return -1;
    }   return arr->size;
}
int At_Array(CDynamic_Array* arr, int pos) {
  if (NULL == arr) {
        return -1;
    }  return 0;
  return arr->pAddr[pos];
}

void FreeSpace_Array(CDynamic_Array* arr) {
if (NULL == arr) {
        return;
    }
//�����ڴ��ͷ������� һ���ǽṹ��ָ����ڴ��ͷ� һ���ǽṹ���е����ݵ�ַ
free(arr->pAddr);
free(arr);
}

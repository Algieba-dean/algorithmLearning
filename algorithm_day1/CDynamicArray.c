#include"CDynamicArray.h"


CDynamic_Array* CDynamic_Init() {
    //
    //先为返回值开辟空间
    CDynamic_Array* arr = (CDynamic_Array*)malloc(sizeof(CDynamic_Array));

    arr->size = 0;//初始化数组大小为0
    arr->capacity = 20;//每个block的大小为20
    
    arr->pAddr = (int*)malloc(sizeof(int) * arr->capacity);

    return arr;
}
void PushBack_Array(CDynamic_Array* arr, int value) {
    if (NULL == arr) {
        return;
    }
    //因为是直接接在之前的地址后加即可 故而不需要传入地址
    //但是需要判断一下是否需要开辟新的内存
    if (arr->size >= arr->capacity) {
        arr->capacity *= 2;//但是这样内存就会倍增，有点问题，但暂不处理
        int* nAddr = (int*)malloc(sizeof(int) * arr->capacity);
        memcpy(nAddr, arr->pAddr, sizeof(int) * arr->size);//把先前的内容拷贝过去
        free(arr->pAddr);//删除原有空间
        arr->pAddr = nAddr;//更新(不用free掉之后重新来吗？)
        //free(nAddr);//这个地方不能释放 地址同于变量
    }
    arr->pAddr[arr->size] = value;
    arr->size += 1;
}
void RemoveByPos_Array(CDynamic_Array* arr, int pos) {
    if (NULL == arr) {
        return;
    }
    //删除并不是简单地将对应位置为0，而是要将对应位置后的数依次往前移动
    //首先要检查一下数组越界
    if (pos<0 || pos>=arr->size) {
        return;
    }
    for (int i = arr->size-1; i <=pos; i++) {
        arr->pAddr[i] = arr->pAddr[i + 1];
    }
    arr->size -= 1;
    //但是最后一个位置仍然没有处理 被遗弃了
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
    for (int i = arr->size-1; i >= 0; i--) {//这里正反顺序无所谓，重要的是执行删除的地方需要倒着，否则得有一个变量来存size
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
        break;//这里需要跳出循环，不然就只会判断出最后一个的位置

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
    arr->size = 0;//但是总感觉 地址中还存有值
    arr->pAddr = NULL;//把地址指向空 应该就好了
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
//这里内存释放有两层 一层是结构体指针的内存释放 一层是结构体中的数据地址
free(arr->pAddr);
free(arr);
}

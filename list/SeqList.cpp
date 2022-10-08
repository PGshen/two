//
// Created by guishen peng on 2022/10/7.
//
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10
#define InitSize 10

// 静态分配
typedef struct {
    int data[MaxSize];
    int length;
}SsqList;

/**
 * 初始化 静态分配
 * @param L
 */
void InitSsqList(SsqList &L) {
    // 未设置的话会是内存中的"脏数据"
//    for (int i = 0; i < MaxSize; ++i) {
//        L.data[i] = 0;
//    }
    L.length = 0;
}

void TestSsqList() {
    SsqList L;   // 会分配内存
    InitSsqList(L);
    for (int i = 0; i < MaxSize; ++i) {
        printf("data[%d]=%d\n", i, L.data[i]);
    }
}


// 动态分配内存空间
typedef struct {
    int *data;
    int capacity;
    int length;
}DsqList;

// 初始化动态分配
void InitDsqList(DsqList &L) {
    L.data = (int *)malloc(InitSize * sizeof(int));
    L.length = 0;
    L.capacity = InitSize;
}

// 增加动态数组长度
void IncreaseSize(DsqList &L, int len) {
    int *p = L.data;
    L.data = (int *) malloc((L.capacity + len) * sizeof(int));
    for (int i = 0; i < L.length; ++i) {
        L.data[i] = p[i];
    }
    L.capacity = L.capacity + len;
    free(p);    // 释放原内存空间
}

void PrintList(DsqList L) {
    for (int i = 0; i < L.length; ++i) {
        printf("data[%d]=%d\n", i, L.data[i]);
    }
}

void TestDsqList() {
    DsqList L;
    InitDsqList(L);
    L.data[0] = 10;
    L.data[1] = 20;
    L.length = 2;
    printf("%d", *L.data);
    IncreaseSize(L, 5);
    PrintList(L);
    printf("capacity = %d\n", L.capacity);
}

int main() {
    TestDsqList();
    printf("len(int)=%lu",sizeof(int));
    return 0;
}


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
    for (int i = 0; i < MaxSize; ++i) {
        L.data[i] = 0;
    }
    L.length = 0;
}

/**
 * 插入
 * @param L
 * @param i
 * @param e
 * @return
 */
bool SsqListInsert(SsqList &L, int i, int e) {
    if (i<0 || i>L.length) {
        return false;
    }
    if (L.length >= MaxSize) {
        return false;
    }
    for (int j = L.length; j >= i; --j) {   // 向后移动
        L.data[j] = L.data[j-1];
    }
    L.data[i] = e;
    L.length++;
    return true;
}

/**
 * 删除
 * @param L
 * @param i
 * @param e
 * @return
 */
bool SsqListDelete(SsqList &L, int i, int &e) {
    if (i<0 || i>L.length-1) {
        return false;
    }
    e = L.data[i];
    for (int j = i; j < L.length; ++j) {        // 向前移动
        L.data[j] = L.data[j+1];
    }
    L.length--;
    return true;
}

/**
 * 按位置查找
 * @param L
 * @param i
 * @return
 */
int SsqListGet(SsqList L, int i) {
    return L.data[i];
}

/**
 * 按指查找
 * @param L
 * @param e
 * @return
 */
int SsqListLocate(SsqList L, int e) {
    for (int i = 0; i < L.length; ++i) {
        if (L.data[i] == e) {
            return i;
        }
    }
    return 0;
}

/**
 * 打印
 * @param L
 */
void SsqListPrint(SsqList L) {
    for (int i = 0; i < MaxSize; ++i) {
        printf("data[%d]=%d\n", i, L.data[i]);
    }
}

void TestSsqList() {
    printf("%s\n", "TestSsqList...");
    SsqList L;   // 会分配内存
    InitSsqList(L);
    SsqListInsert(L, 0, 33);
    SsqListInsert(L, 1, 99);
    SsqListInsert(L, 2, 110);
    SsqListInsert(L, 1, 333);
    int e = -1;
    SsqListDelete(L, 2, e);
    printf("Delete: %d\n", e);
    SsqListPrint(L);
    printf("Get: %d -> %d\n", 1, SsqListGet(L, 1));
    printf("Locate %d: %d\n", 333, SsqListLocate(L, 333));
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

// 插入
bool DsqListInsert(DsqList &L, int i, int e) {
    if (i<0 || i>L.length) {
        return false;
    }
    if (L.length >= MaxSize) {
        return false;
    }
    for (int j = L.length; j >= i; --j) {   // 向后移动
        L.data[j] = L.data[j-1];
    }
    L.data[i] = e;
    L.length++;
    return true;
}

// 删除
bool DsqListDelete(DsqList &L, int i, int &e) {
    if (i<0 || i>L.length-1) {
        return false;
    }
    e = L.data[i];
    for (int j = i; j < L.length; ++j) {        // 向前移动
        L.data[j] = L.data[j+1];
    }
    L.length--;
    return true;
}

// 获取第i位
int DsqListGet(DsqList L, int i) {
    return L.data[i];
}

// 按值查找
int DsqListLocate(DsqList L, int e) {
    for (int i = 0; i < L.length; ++i) {
        if (L.data[i] == e) {
            return i;
        }
    }
    return 0;
}

void DsqListPrint(DsqList L) {
    for (int i = 0; i < L.length; ++i) {
        printf("data[%d]=%d\n", i, L.data[i]);
    }
}

void TestDsqList() {
    printf("%s\n", "TestDsqList...");
    DsqList L;
    InitDsqList(L);
    DsqListInsert(L, 0, 10);
    DsqListInsert(L, 1, 20);
    DsqListInsert(L, 2, 30);
    IncreaseSize(L, 5);
    printf("capacity = %d\n", L.capacity);
    printf("Get %d -> %d\n", 1, DsqListGet(L, 1));
    printf("Locate %d: %d\n", 20, DsqListLocate(L, 20));
    int e = -1;
    DsqListDelete(L, 0, e);
    DsqListDelete(L, 1, e);
    DsqListPrint(L);
}

int main() {
    TestDsqList();
//    printf("len(int)=%lu",sizeof(int));
    printf("%s\n", "--------");
    TestSsqList();
    return 0;
}


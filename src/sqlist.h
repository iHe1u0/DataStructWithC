#pragma once
#include "common.h"

#define MAXSIZE 128  // 定义线性表最大长度

// 线性表的数据结构
typedef struct
{
  ElemType* elem;    // 存储的数据
  int       length;  // 当前数据的长度
} SqList;

Status   init_sqlist(SqList* list);                         // 初始化线性表
Status   insert_data(SqList* list, ElemType e, int index);  // 插入数据
ElemType get_sqlist_data(SqList* list, int index);          // 获取线性表第index个位置的数据
int      find_data(SqList* list, ElemType e);               // 查找数据,返回所在位置,要是没找到返回0
Status   delete_elem(SqList* list, int index);              // 删除元素

int sqlist_main();
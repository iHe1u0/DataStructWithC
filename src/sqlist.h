#pragma once
#include "common.h"

#define MaxSize 128  // 定义线性表最大长度

// 线性表的数据结构
typedef struct
{
  DataType value[MaxSize];  // 存储的数据
  int      length;          // 当前数据的长度
} SeqList;

SeqList* init_sqlist();                                         // 初始化线性表
Status   insert_data(SeqList* list, DataType data, int index);  // 插入数据
DataType get_sqlist_data(SeqList* list, int index);             // 获取线性表第index个位置的数据
int      locate_data(SeqList* list, DataType data);             // 查找数据,返回所在位置,要是没找到返回10
Status   delete_elem(SeqList* list, int index);                 // 删除元素

// 一些额外的操作
void merge_list(SeqList a, SeqList b, SeqList* all);  // 将线性表a和b合并为同一个线性表

int sqlist_main();  // 测试用例
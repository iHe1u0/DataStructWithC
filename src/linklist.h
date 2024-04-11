#pragma once

#include "common.h"

// 定义链表数据结构
typedef struct
{
  DataType         data;
  struct linklist* p_next;
} linklist, linknode;

Status init_linklist(linklist* list);       // 初始化链表
Status insert(linklist* list, DataType data);  // 向链表插入一个数据
Status destory(linklist* list);             // 销毁链表并释放内存

int linklist_main();

#pragma once

#include "common.h"

// 定义链表数据结构,注意:头结点不存数据
// 当存储数据的时候,样子如下:
// +------+------+         +------+         +------+         +------+
// |      |      |         | 1001 |         | 1002 |         | 1003 |
// | HEAD | NEXT |  ---->  | NEXT |  ---->  | NEXT |  ---->  | NULL |
// |      |      |         |      |         |      |         |      |
// +------+------+         +------+         +------+         +------+

typedef struct linklist
{
  DataType         data;
  struct linklist* p_next;
} linklist, linknode;

Status init_linklist(linklist* list);                       // 初始化链表
Status insert_in_linklist(linklist* list, DataType data);   // 向链表插入一个数据
int    get_linklist_length(linklist* list);                 // 获取链表长度
int    find_in_linklist(linklist* list, DataType data);     // 查找某个节点在链表中的位置
Status delete_elem_in_linklist(linklist* list, int index);  // 删除第index处的元素
Status destroy_linklist(linklist* list);                    // 销毁链表并释放内存

void print_linklist(const linklist* list);  // 打印链表

int linklist_main();
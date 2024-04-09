#include <stdlib.h>
#include <stdio.h>
#include "common.h"
#include "sqlist.h"

Status init_sqlist(SqList* list)
{
  // list = (SqList*)malloc(sizeof(SqList));
  if (list != NULL)
  {
    list->elem = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
    list->length = 0;
    if (list->elem != NULL)
    {
      return OK;
    }
  }
  return Error;
}

Status insert_data(SqList* list, ElemType e, int index)
{
  // 判断表是否没有初始化,以及插入位置是否在合理的范围内,即 0~MAXSIZE-1
  if (list == NULL || index < 0 || index >= MAXSIZE)
  {
    return Error;
  }

  // 判断表是否已满
  if (list->length >= MAXSIZE)
  {
    return Error;
  }

  // 从插入位置开始，往后移动元素
  for (int current_index = list->length; current_index > index; current_index--)
  {
    list->elem[current_index] = list->elem[current_index - 1];
  }

  // 插入元素到指定位置
  list->elem[index] = e;

  // 更新列表长度
  list->length++;

  return OK;
}

ElemType get_sqlist_data(SqList* list, int index)
{
  if (list == NULL)
  {
    exit(EXIT_CAUSE_NULL);
  }
  if (index < 0 || index > list->length)
  {
    exit(EXIT_CAUSE_OUT_OF_RANGE);
  }
  ElemType e = list->elem[index];
  return e;
}

int find_data(SqList* list, ElemType e)
{
  if (list == NULL)
  {
    return NotFound;
  }
  for (int i = 0; i < list->length; i++)
  {
    if (e == list->elem[i])
    {
      return i + 1;
    }
  }
  return NotFound;
}

Status delete_elem(SqList* list, int index)
{
  if (list == NULL || index < 0 || index > list->length)
  {
    return Error;
  }
  if (list->length == 0)
  {
    return OK;
  }
  for (int current_index = index; current_index < list->length; current_index++)
  {
    list->elem[current_index] = list->elem[current_index + 1];
  }
  list->length--;
  return OK;
}

int sqlist_main()
{
  SqList sqlist;
  // 初始化
  {
    Status status = init_sqlist(&sqlist);
    if (status != OK)
    {
      exit(EXIT_FAILURE);
    }
    printf("初始化线性表成功.\n");
  }
  // 插入数据
  {
    for (int i = 0; i < MAXSIZE; i++)
    {
      insert_data(&sqlist, i, i);
    }
    printf("数据插入完成.\n");
  }
  // 查找数据
  {
    int index = find_data(&sqlist, 6);
    if (index != NotFound)
    {
      printf("查找元素[%d]成功: %d\n", 6, index);
    }
    else
    {
      printf("元素查找失败.\n");
    }
  }
  // 删除数据
  delete_elem(&sqlist, 6);
  // 删除元素后查找数据
  {
    int index = find_data(&sqlist, 6);
    if (index != NotFound)
    {
      printf("查找元素[%d]成功: %d\n", 6, index);
    }
    else
    {
      printf("元素查找失败.\n");
    }
  }
  return 0;
}

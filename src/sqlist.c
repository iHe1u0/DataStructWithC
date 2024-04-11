#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "common.h"
#include "sqlist.h"

SeqList* init_sqlist()
{
  SeqList* list;
  list = malloc(sizeof(SeqList));
  list->length = 0;
  return list;
}

Status insert_data(SeqList* list, DataType data, int index)
{
  // 判断表是否没有初始化,以及插入位置是否在合理的范围内,即 0~MaxSize-1
  if (list == NULL || index < 0 || index >= MaxSize)
  {
    return Error;
  }

  // 判断表是否已满
  if (list->length >= MaxSize)
  {
    return OutOfRange;
  }

  // 从插入位置开始，往后移动元素
  for (int current_index = list->length; current_index > index; current_index--)
  {
    list->value[current_index] = list->value[current_index - 1];
  }

  // 插入元素到指定位置
  list->value[index] = data;

  // 更新列表长度
  list->length++;

  return OK;
}

DataType get_sqlist_data(SeqList* list, int index)
{
  if (list == NULL)
  {
    exit(EXIT_CAUSE_NULL);
  }
  if (index < 0 || index > list->length)
  {
    exit(EXIT_CAUSE_OUT_OF_RANGE);
  }
  DataType data = list->value[index];
  return data;
}

int locate_data(SeqList* list, DataType data)
{
  if (list == NULL)
  {
    return NotFound;
  }
  for (int i = 0; i < list->length; i++)
  {
    if (data == list->value[i])
    {
      return i + 1;
    }
  }
  return NotFound;
}

Status delete_elem(SeqList* list, int index)
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
    list->value[current_index] = list->value[current_index + 1];
  }
  list->length--;
  return OK;
}

void merge_list(SeqList a, SeqList b, SeqList* all)
{
  int index_a = 0, index_b = 0, index_c = 0;
  while (index_a <= a.length && index_b <= b.length)
  {
    if (a.value[index_a] < b.value[index_b])
    {
      all->value[index_c++] = a.value[index_a++];
    }
    else
    {
      all->value[index_c++] = b.value[index_b++];
    }
  }
  while (index_a <= a.length)
  {
    all->value[index_c++] = a.value[index_a++];
  }
  while (index_b <= b.length)
  {
    all->value[index_c++] = b.value[index_b++];
  }
}

int sqlist_main()
{
  SeqList* list;
  // 初始化
  {
    list = init_sqlist();
    if (list == NULL)
    {
      exit(EXIT_FAILURE);
    }
    printf("初始化线性表成功.\n");
  }
  // 插入数据
  {
    for (int i = 0; i < MaxSize; i++)
    {
      insert_data(list, i * i, i);
    }
    printf("数据插入完成.\n");
  }
  // 查找数据
  {
    int index = locate_data(list, 6);
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
  delete_elem(list, 6);
  // 删除元素后查找数据
  {
    int index = locate_data(list, 6);
    if (index != NotFound)
    {
      printf("查找元素[%d]成功: %d\n", 6, index);
    }
    else
    {
      printf("元素查找失败.\n");
    }
  }

  END(线性表测试)
}

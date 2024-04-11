#include "linklist.h"
#include <malloc.h>
#include <stdio.h>
#include "common.h"

Status init_linklist(linklist* list)
{
  if (list != NULL)
  {
    list->data = 0;
    list->p_next = NULL;
    return OK;
  }
  return Error;
}

Status insert(linklist* list, DataType data)
{
  if (list == NULL)
  {
    return NULL_POINTER;
  }
  // 创建一个节点
  linknode* node = (linknode*)malloc(sizeof(linknode));
  if (node == NULL)
  {
    return MEMORY_MALLOC_FAILED;
  }
  node->data = data;
  node->p_next = NULL;

  // 从头节点开始遍历,找到末尾指针
  linknode* p_node = list;
  while (p_node->p_next != NULL)
  {
    p_node = p_node->p_next;
  }
  // 将当前链表的下个指针指向刚创建的节点
  p_node->p_next = node;
  return OK;
}

Status destory(linklist* list)
{
  if (list != NULL)
  {
    linknode *p_current_node = list, *p_next_node;
    while (p_current_node != NULL)
    {
      p_next_node = p_current_node->p_next;
      free(p_current_node);
      p_current_node = p_next_node;
    }
    list->p_next = NULL;
    return OK;
  }
}

int linklist_main()
{
  linklist list;
  // 初始化链表
  {
    int status = init_linklist(&list);
    if (status != OK)
    {
      return status;
    }
    printf("链表初始化成功.\n");
  }
  // 插入数据
  {
    for (int i = 0; i < 10; i++)
    {
      insert(&list, i);
    }
    printf("数据插入成功.....\n");
  }
  return 0;
}
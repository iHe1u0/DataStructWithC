#include "linklist.h"
#include <malloc.h>
#include <stdio.h>
#include <time.h>
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

Status insert_in_linklist(linklist* list, DataType data)
{
  if (list == NULL)
  {
    return MEMORY_MALLOC_FAILED;  // 内存分配失败,返回错误状态
  }

  // 创建一个节点
  linknode* node = (linknode*)malloc(sizeof(linknode));
  if (node == NULL)
  {
    return MEMORY_MALLOC_FAILED;  // 返回内存分配失败状态
  }

  node->data = data;
  node->p_next = NULL;

  // 如果链表为空，则将新节点设置为头节点
  if (list->p_next == NULL)
  {
    list->p_next = node;
    return OK;  // 返回成功状态
  }

  // 从头节点开始遍历,找到末尾指针
  linknode* p_node = list->p_next;
  while (p_node->p_next != NULL)
  {
    p_node = p_node->p_next;
  }

  // 将当前链表的下个指针指向刚创建的节点
  p_node->p_next = node;
  return OK;  // 返回成功状态
}

int get_linklist_length(linklist* list)
{
  if (list == NULL)
  {
    return 0;
  }
  int       length = 0;
  linknode* node = list;
  while (node != NULL)
  {
    node = node->p_next;
    ++length;
  }
  return length;
}

int find_in_linklist(linklist* list, DataType data)
{
  if (list == NULL)
  {
    return NotFound;
  }
  linknode* node = list;
  for (int index = 0; node != NULL; index++)
  {
    if (node->data == data)
    {
      return index;
    }
    node = node->p_next;
  }
  return NotFound;
}

Status delete_elem_in_linklist(linklist* list, int index)
{
  // 链表为空或者超出了链表范围
  int length = get_linklist_length(list);
  if (list == NULL || index < 0 || index >= length)
  {
    return OutOfRange;
  }

  // 删除头节点
  if (index == 0)
  {
    linknode* temp = list->p_next;
    list->p_next = list->p_next->p_next;
    free(temp);
    printf("第%d个元素删除成功\n", index);
    return OK;
  }

  // 删除非头节点
  int       i = 0;
  linknode* current = list->p_next;
  linknode* previous = NULL;
  while (current != NULL && i < index - 1)  // i到inex-1是因为头结点没有保存数据
  {
    previous = current;
    current = current->p_next;
    i++;
  }

  if (current == NULL)
  {
    return OutOfRange;  // 超出了链表范围
  }

  // 删除当前节点
  previous->p_next = current->p_next;
  free(current);
  printf("第%d个元素删除成功\n", index);
  return OK;
}

Status destroy_linklist(linklist* list)
{
  if (list != NULL)
  {
    linknode *p_current_node = list->p_next, *p_next_node = NULL;
    while (p_current_node != NULL)
    {
      p_next_node = p_current_node->p_next;
      free(p_current_node);
      p_current_node = p_next_node;
    }
    list->p_next = NULL;
  }
  return OK;
}

void print_linklist(const linklist* list)
{
  if (list != NULL)
  {
    linknode* node = list->p_next;
    while (node != NULL)
    {
      print(node->data);
      node = node->p_next;
    }
    printf("\n");
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
    for (int i = 1; i < 12; i++)
    {
      insert_in_linklist(&list, i * i + 1000);
    }
    printf("数据插入成功.....\n");
    print_linklist(&list);
  }
  // 查找数据
  int data = 1064;
  int index = find_in_linklist(&list, data);
  printf("查找数据%d成功,位于位置:%d\n", data, index);
  // 删除数据
  delete_elem_in_linklist(&list, index);
  print_linklist(&list);
  // 销毁链表
  destroy_linklist(&list);
  print_linklist(&list);
  END(链表)
}
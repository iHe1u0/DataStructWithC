#include <stdlib.h>
#include <time.h>
#include "common.h"
#include "sqlist.h"

Status init_sqlist(SqList* list)
{
  list = (SqList*)malloc(sizeof(SqList));
  if (list != NULL)
  {
    return OK;
  }
  return Error;
}

Status insert_data(SqList* list, ElemType e, int index)
{
  if (list == NULL || index > list->length)
  {
    return Error;
  }

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
    exit(EXIT_CAUSE_NULL);
  }
  for (int i = 0; i < list->length; i++)
  {
    if (e == list->elem[i])
    {
      return i + 1;
    }
  }
  return 0;
}
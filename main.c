#include <stdlib.h>
#include <stdio.h>
#include "src/common.h"
#include "src/sqlist.h"

int main()
{
  SqList sqlist;
  Status status = init_sqlist(&sqlist);
  printf("初始化线性表:%d\n", status);
  return 0;
}

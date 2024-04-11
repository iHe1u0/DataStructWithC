#include <stdlib.h>
#include "src/linklist.h"
#include "src/sqlist.h"

int main()
{
// 解决在Windows系统下中文输出乱码的问题
#ifdef _WIN32
  system("chcp 65001");
#endif  // _WIN32

  sqlist_main();    // 测试线性表
  linklist_main();  // 测试链表

  return 0;
}

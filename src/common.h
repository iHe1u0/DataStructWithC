#pragma once
#ifndef _DATASTRUCT_COMMON_H
#define _DATASTRUCT_COMMON_H

// 定义通用的数据类型为int类型
typedef int DataType;

// 定义状态码
typedef enum
{
  NotFound = -100,             // 未找到
  OK = 0,                      // 成功
  Error = 10,                  // 失败
  OutOfRange,                  // 数据已满
  EXIT_CAUSE_NULL = 100,       // 由于出现空指针而退出
  EXIT_CAUSE_OUT_OF_RANGE,     // 由于超出范围而退出
  MEMORY_MALLOC_FAILED = 200,  // 内存分配失败
  NULL_POINTER,                // 空指针
} Status;

// 打印数据
#define print(data) printf("%d ", data)

// 定义某个测试结束
#if defined(__GNUC__) || defined(__clang__)
#define FUNCTION_NAME __func__
#elif defined(_MSC_VER)
#define FUNCTION_NAME __FUNCTION__
#endif
#define END(x)                             \
  printf("\t%s测试结束\n", FUNCTION_NAME); \
  return 0;

#endif  // !_DATASTRUCT_COMMON_H
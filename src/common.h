#pragma once
#ifndef _DATASTRUCT_COMMON_H
#define _DATASTRUCT_COMMON_H

#define ElemType int  // 定义通用的数据类型为int类型

#define Status   int  // 定义状态码
#define OK       0    // 成功
#define Error    -1   // 失败
#define NotFound -2

#define EXIT_CAUSE_NULL         -64  // 由于出现空指针而退出
#define EXIT_CAUSE_OUT_OF_RANGE -65  // 由于超出范围而退出

#endif  // !_DATASTRUCT_COMMON_H
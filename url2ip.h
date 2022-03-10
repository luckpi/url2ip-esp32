// Copyright 2022-2022 The jdh99 Authors. All rights reserved.
// 核心网ip解析模块
// Authors: jdh99 <jdh821@163.com>

#ifndef URL2IP_H
#define URL2IP_H

#include "bror.h"

// 解析host地址的间隔.单位:s
#define PARSE_INTERVAL 180

// CoreIPLoad 模块载入
bool Url2IPLoad(char *name, int size);

// CoreIPGet 读取核心网ip
uint32_t Url2IPGetIP(void);

// 配置核心网域名
void Url2IPSetName(char* name, int size);

// CoreIPIsOK 是否解析成功
bool Url2IPIsOK(void);

#endif

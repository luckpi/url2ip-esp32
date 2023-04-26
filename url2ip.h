// Copyright 2022-2022 The jdh99 Authors. All rights reserved.
// 核心网ip解析模块
// Authors: jdh99 <jdh821@163.com>

#ifndef URL2IP_H
#define URL2IP_H

#include "bror.h"

// 解析host地址的间隔.单位:s
#define PARSE_INTERVAL 180

// Url2IPLoad 模块载入
bool Url2IPLoad(const char *name);

// Url2IPGetIP 读取核心网ip
uint32_t Url2IPGetIP(void);

// 配置核心网域名
void Url2IPSetName(const char* name);

// Url2IPIsOK 是否解析成功
bool Url2IPIsOK(void);

#endif

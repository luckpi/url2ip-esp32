// Copyright 2021-2021 The jdh99 Authors. All rights reserved.
// 核心网ip解析模块
// Authors: Gumy

#include "url2ip.h"
#include "tzmalloc.h"
#include "lagan.h"
#include "wifi.h"
#include <netdb.h>

#define TAG "url2ip"

// tzmalloc字节数
#define MALLOC_TOTAL 2048

// 线程堆栈大小.单位:KByte
#define THREAD_STACK_SIZE 4

static int mid = -1;

static uint32_t coreIP = 0;
static bool isParseOK = false;
static char* coreName = NULL;
static uint32_t parseInterval = PARSE_INTERVAL;

static void parseThread(void* param);

// Url2IPLoad 模块载入
bool Url2IPLoad(const char* name) {
    mid = TZMallocRegister(0, TAG, MALLOC_TOTAL);
    Url2IPSetName(name);
    return BrorThreadCreate(parseThread, TAG, BROR_THREAD_PRIORITY_LOWEST,
                            THREAD_STACK_SIZE * 1024);
}

static void parseThread(void* param) {
    BrorDelayMS(1);

    struct hostent* h;
    while (1) {
        if (WifiIsConnect() == false) {
            BrorDelay(1);
            continue;
        }

        if ((h = gethostbyname(coreName)) == NULL) {
            LD(TAG, "Failed to get host name %s", coreName);
            BrorDelay(1);
            continue;
        }

        coreIP = (h->h_addr[0] << 24) + (h->h_addr[1] << 16) +
                 (h->h_addr[2] << 8) + h->h_addr[3];
        isParseOK = true;
        BrorDelay(parseInterval);
    }

    BrorThreadDeleteMe();
}

// 配置核心网域名
void Url2IPSetName(const char* name) {
    if (coreName != NULL) {
        TZFree(coreName);
    }
    coreName = TZMalloc(mid, sizeof(name));
    strcpy(coreName, name);
}

// Url2IPGetIP 读取解析ip
uint32_t Url2IPGetIP(void) {
    return coreIP;
}

// Url2IPIsOK 是否解析成功
bool Url2IPIsOK(void) {
    return isParseOK;
}

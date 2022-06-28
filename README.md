# url2ip

## 1. 介绍
域名转换ip模块

## 2. 功能
需要依赖esp32的官方库来获取域名指向的ip地址

## 3. API
```c
// Url2IPLoad 模块载入
bool Url2IPLoad(char *name, int size);

// Url2IPGetIP 读取核心网ip
uint32_t Url2IPGetIP(void);

// 配置核心网域名
void Url2IPSetName(char* name, int size);

// Url2IPIsOK 是否解析成功
bool Url2IPIsOK(void);
```

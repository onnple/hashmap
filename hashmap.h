//
// Created by Once on 2019/8/11.
//

#ifndef DATALGORITHM_HASHMAP_H
#define DATALGORITHM_HASHMAP_H

// 使用整数作为关键字
typedef int Key;

// 记录值
typedef struct value{
    int tag;
    char message[128];
} Value;

// 记录结点
typedef struct hnode{
    Key key;
    Value value;
    struct hnode *next;
} HNode;

// HashMap对外接口
typedef struct hashmap{
    HNode *array; // 数组
    int length; // 数组长度
    int size; // 散列表的元素个数
} HashMap;

// HashMap函数声明
extern HashMap *hashmap_init(int length);
extern int hashmap_is_empty(HashMap *hashmap);
extern int hashmap_is_full(HashMap *hashmap);
extern int hashmap_add(HashMap *hashmap, Key key, Value *value);
extern int hashmap_delete(HashMap *hashmap, Key key);
extern HNode *hashmap_get(HashMap *hashmap, Key key);
extern void hashmap_traverse(HashMap *hashmap);
extern int hashmap_clear(HashMap *hashmap);

#endif //DATALGORITHM_HASHMAP_H

//
// Created by Once on 2019/8/11.
//

#include "hashmap.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

HashMap *hashmap_init(int length){
    if(length <= 0){
        perror("the size should be greater than 0.");
        return NULL;
    }
    HashMap *hashmap = (HashMap*)malloc(sizeof(HashMap));
    if(!hashmap){
        perror("alloc hash map error.");
        return NULL;
    }
    hashmap->length = length;
    hashmap->size = 0;
    hashmap->array = (HNode*)malloc(sizeof(HNode) * length);
    if(!hashmap->array){
        perror("alloc map node error.");
        return NULL;
    }
    for (int i = 0; i < hashmap->length; ++i)
        hashmap->array[i].next = NULL;
    return hashmap;
}

int hashmap_is_empty(HashMap *hashmap){
    if(hashmap == NULL || hashmap->size == 0)
        return 1;
    return hashmap->size == 0;
}

int hashmap_is_full(HashMap *hashmap){
    HNode *node = (HNode*)malloc(sizeof(HNode));
    if(!node)
        return 1;
    free(node);
    return 0;
}

// 散列函数，使用取余散列法
static int hash(HashMap *hashmap, Key key){
    return key % hashmap->length;
}

int hashmap_add(HashMap *hashmap, Key key, Value *value){
    if(hashmap == NULL || value == NULL)
        return 0;
    int index = hash(hashmap, key);
    HNode *next = hashmap->array[index].next;
    while(next != NULL && next->key != key)
        next = next->next;
    if(next == NULL){
        HNode *node = (HNode*)malloc(sizeof(HNode));
        if(!node){
            perror("alloc mem for node error.");
            return 0;
        }
        node->key = key;
        node->value.tag = value->tag;
        strcpy(node->value.message, value->message);

        next = hashmap->array[index].next;
        hashmap->array[index].next = node;
        node->next = next;
        hashmap->size++;
    }
    else{
        next->value.tag = value->tag;
        strcpy(next->value.message, value->message);
    }
    return 1;
}

int hashmap_delete(HashMap *hashmap, Key key){
    if(hashmap == NULL || hashmap->size == 0)
        return 0;
    int index = hash(hashmap, key);
    HNode *parent = &hashmap->array[index];
    HNode *node = parent->next;
    while(node != NULL && node->key != key){
        parent = node;
        node = node->next;
    }
    if(node != NULL){
        parent->next = node->next;
        free(node);
        hashmap->size--;
    }
    return 1;
}

HNode *hashmap_get(HashMap *hashmap, Key key){
    if(hashmap == NULL || hashmap->size == 0)
        return NULL;
    int index = hash(hashmap, key);
    HNode *node = hashmap->array[index].next;
    while(node != NULL && node->key != key)
        node = node->next;
    return node;
}

void hashmap_traverse(HashMap *hashmap){
    if(hashmap == NULL || hashmap->size == 0)
        return;
    for (int i = 0; i < hashmap->length; ++i) {
        if(hashmap->array[i].next == NULL)
            continue;
        HNode *node = hashmap->array[i].next;
        while(node != NULL){
//            printf("[%d %d %s]  ", node->key, node->value.tag, node->value.message);
            printf("[%d] -> ", node->key);
            node = node->next;
        }
        printf("NULL\n");
    }
}

int hashmap_clear(HashMap *hashmap){
    if(hashmap == NULL)
        return 0;
    for (int i = 0; i < hashmap->length; ++i) {
        if(hashmap->array[i].next == NULL)
            continue;
        HNode *node = hashmap->array[i].next;
        HNode *temp;
        while(node != NULL){
            temp = node->next;
            free(node);
            node = temp;
        }
    }
    free(hashmap->array);
    free(hashmap);
    return 1;
}

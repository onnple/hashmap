# 散列表HashMap
使用分离链接法实现散列表，使用散列表实现HashMap，原文地址：http://www.srcmini.com/1507.html  
## HashMap函数操作：
### 1、初始化HashMap
extern HashMap *hashmap_init(int length);
### 2、检查HashMap是否已空
extern int hashmap_is_empty(HashMap *hashmap);
### 3、HashMap是否已满
extern int hashmap_is_full(HashMap *hashmap);
### 4、添加记录到HashMap中
extern int hashmap_add(HashMap *hashmap, Key key, Value *value);
### 5、从HashMap中删除一个记录
extern int hashmap_delete(HashMap *hashmap, Key key);
### 6、从HashMap中搜索一个记录
extern HNode *hashmap_get(HashMap *hashmap, Key key);
### 7、遍历HashMap
extern void hashmap_traverse(HashMap *hashmap);
### 8、清空和释放HashMap
extern int hashmap_clear(HashMap *hashmap);


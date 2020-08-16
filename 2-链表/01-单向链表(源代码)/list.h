#ifndef _LIST_H
#define _LIST_H

typedef int DataType;

//节点
typedef struct _node
{
	DataType value;
	struct _node *next;
} Node;

//链表封装
typedef struct _list
{
	Node *head; //指向链表第一个节点
} List;

//申请节点
Node *createNode(DataType value);

//链表初始化
void initList(List *pList);

//在链表末尾增加元素
void add_at_end(List *pList, DataType value);

//在指定位置后增加元素
void add_at_pos(Node *pos, DataType value);

//删除链表末尾元素
void del_at_end(List *pList);

//删除指定位置元素
void del_at_pos(List *pList, Node* pos);

//删除第一个值为value的节点
void del(List *pList, DataType value);

//更改pos位置节点的value值
void changevalue(Node *pos, DataType value);

//根据指定的value值，找到对应的节点
Node *findNode(List *pList, DataType value);

//打印链表
void printList(List *pList);

//清除链表
void destoryList(List *pList);
#endif
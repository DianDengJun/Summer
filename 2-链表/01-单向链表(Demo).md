# 单向链表示例

```c
#include <stdio.h>
#include <stdlib.h>

//	链表节点
typedef struct _node
{
	int value;
	struct _node *next; //	链接到下一个节点
} Node;

typedef struct _list
{
	Node *head;
	//Node *tail;
} List;	//	list可以代表整个链表

void add(List *pList, int number);
void print(List *pList);

int main(int argc, char *argv[])
{
	Node *head = NULL; //	开始的节点，初始化其为NULL

	List list;
	list.head = NULL;

	int number;
	//	读number直到-1，并记录在链表里
	printf("input numbers (end with -1):");
	do
	{
		scanf("%d", &number);
		if (number != -1)
		{
			//	若为有效数，加到链表里
			add(&list, number);
		}
	} while (number != -1);

	//	输出整个链表
	printf("you inputted these numbers:");
	print(&list);

	//	寻找数字
	printf("input the number you want to delete:");
	scanf("%d", &number);
	Node *p;
	int isFound = 0;
	for (p = list.head; p; p = p->next)
	{
		if (p->value == number)
		{
			printf("find it!\n");
			isFound = 1;
			break;
		}
	}
	if (!isFound)
	{
		printf("not find!\n");
	}

	//	删除数字
	Node *q;	//	定义一个q节点，表示为p前面的节点
	for (q = NULL, p = list.head; p; q = p, p = p->next)
	{
		if (p->value == number)
		{
			if (q)
			{
				q->next = p->next;
			}
			else	//	q为NULL，说明第一个节点是需要删除的，直接让head指向下一个
			{
				list.head = p->next;
			}
			free(p);
			printf("delete successfully\n");
			break;
		}
	}

	//	清除链表
	for (p = head; p; p = q)
	{
		q = p->next;
		free(p);
	}
	return 0;
}

// 在链表里加新的元素
void add(List *pList, int number)
{
	//	add to linked-list
	Node *p = (Node *)malloc(sizeof(Node)); //	以malloc方式创建新的节点
	p->value = number;						//	新节点的value值：number
	p->next = NULL;							//	新节点的next值，初始为NULL(表示为新的末尾)
	//	find the last
	Node *last = pList->head; //	定义一个last的Node变量，以寻找到之前的末尾(NULL)

	if (last) //	先判断last本身是不是NULL(若是，其实指向了head了)
	{
		while (last->next) //	如果last->next不为NULL，说明还不是原来的末尾(NULL)
		{
			last = last->next; //	不是原来的末尾，将last移到下一个节点，以继续检测
		}
		//	attach
		last->next = p; //	找到结尾了，就让它链接到已创建的新的节点p
	}
	else //	last是NULL，就让其直接指向新创建的节点p
	{
		pList->head = p;
	}
}

void print(List *pList)
{
	Node *p;
	for (p = pList->head; p; p = p->next)	//	只要p还存在，就输出
	{
		printf("%d\t", p->value);
	}
	printf("\n");
}
```

## 序

## 链表节点

## 增

## 删

## 改

## 查
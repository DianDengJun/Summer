#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "list.h"

Node *createNode(DataType value)
{
    Node *pNode = (Node *)malloc(sizeof(Node));
    pNode->value = value;
    pNode->next = NULL;
    return pNode;
}

void initList(List *pList)
{
    assert(pList); //检验参数合法性
    pList->head = NULL;
}

void add_at_end(List *pList, DataType value)
{
    assert(pList);                      //检验参数合法性
    Node *pNewNode = createNode(value); //申请新节点存放元素
    Node *last = pList->head;           //last用于标识原链表中的末尾节点
    //判断当前有无非头节点
    if (last)
    {
        while (last->next)
        {                      //如果last->next不为NULL，说明还不是原链表末尾节点
            last = last->next; //不是原链表末尾节点，last后移
        }
        last->next = pNewNode; //找到原链表末尾节点，让其指向已申请的新节点
    }
    else
    { // last为Null，说明只有头节点，直接让头节点指向已申请的新节点
        pList->head = pNewNode;
    }
}

void add_at_pos(Node *pos, DataType value)
{
    Node *pNewNode = NULL;
    if (pos == NULL)
    {
        return;
    }
    pNewNode = createNode(value);

    pNewNode->next = pos->next;
    pos->next = pNewNode;
}

void del_at_end(List *pList)
{
    assert(pList); //检验参数合法性
    if (pList->head == NULL)
    { //链表中没有节点
        return;
    }
    else if (pList->head->next == NULL)
    { //只有一个节点
        free(pList->head);
        pList->head = NULL;
    }
    else
    { //多个节点
        Node *pCur = pList->head;
        Node *pPre = NULL;
        while (pCur->next)
        {
            pPre = pCur;
            pCur = pCur->next;
        }
        free(pCur);
        pPre->next = NULL;
    }
}

void del_at_pos(List *pList, Node *pos)
{
    assert(pList); //检验参数合法性
    if (pos == NULL || pList->head == NULL)
    {
        return;
    }
    if (pos == pList->head)
    {
        pList->head = pos->next;
    }
    else
    {
        Node *pPrePos = pList->head;
        while (pPrePos && pPrePos->next != pos)
        {
            pPrePos = pPrePos->next;
        }
        pPrePos->next = pos->next;
    }
    free(pos);
}

void del(List *pList, DataType value)
{
    assert(pList); //检验参数合法性
    if (pList->head == NULL)
    {
        return;
    }
    Node *pPre = NULL;
    Node *pCur = pList->head;
    while (pCur)
    {
        if (pCur->value == value)
        {
            if (pCur == pList->head)
            { //要删除的是第一个位置的节点
                pList->head = pCur->next;
            }
            else
            {
                pPre->next = pCur->next; //其它位置的情况，让前一个节点指向其后一个节点
            }
            free(pCur);
            return;
        }
        else
        {
            pPre = pCur;
            pCur = pCur->next;
        }
    }
}

void changevalue(Node *pos, DataType value)
{ //此value为更改后的value
    pos->value = value;
}

Node *findNode(List *pList, DataType value)
{
    assert(pList); //检验参数合法性
    Node *pCur = pList->head;
    while (pCur)
    {
        if (pCur->value == value)
        {
            return pCur;
        }
        pCur = pCur->next;
    }
    return NULL;
}

void printList(List *pList)
{
    assert(pList); //检验参数合法性
    Node *pCur = pList->head;
    while (pCur)
    {
        printf("%d--->", pCur->value);
        pCur = pCur->next;
    }
    printf("\n");
}

void destoryList(List *pList)
{
    assert(pList); //检验参数合法性
    if (pList->head = NULL)
    {
        free(pList->head);
        return;
    }
    while (pList->head)
    {
        Node *temp = pList->head->next;
        free(pList->head);
        pList->head = temp;
    }
}
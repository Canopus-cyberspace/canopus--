#include <stdio.h>
typedef struct Linked_list
{
    int data;
    struct Linked_list *next;
} list; // 节点类型

typedef void fun(int, list *);
typedef list *fun1(int, list *); // 定义函数指针 方便之后调用
static list *tail = NULL;        // 定义尾指针 并且在函数中尾指针的改变会被保留
static list *head = NULL;

void insertNode(int n, list *p)
{ // 用于尾部加入节点
    if (n != 0)
    { // 基准条件 n=0
        p->next = (list *)malloc(sizeof(list));
        p->data = (int)getInt;
        insertNode(n - 1, p->next); // 用n-1实现递归 逐渐靠近基准条件
    }
}

list *insertNode1(int n, list *head)
{ // 用于在头加入节点
    if (n != 0)
    { // 基准情况
        list *p = (list *)malloc(sizeof(list));
        p->data = (int)getInt; // 从文件中得到数值
        p->next = head;
        insertNode1(n - 1, p); // 递归
    }
}

void insertHead(list *head, fun insertNode)
{
    if (head != NULL)
    {
        head = insertNode1(3, head); // 从头开始加上节点 并更新头节点
    }
    else
    {
        head = (list *)malloc(sizeof(list));
        head = insertNode1(2, head);
    }
}

void insertTail(fun insertNode)
{
    insertNode(3, tail);
}

list *traverse(int n, list *p)
{
    if (n != 0)
    {
        return traverse(n - 1, p->next); // 当n=0时 递归结束
    } // 返回此时的指针
}

void deleteNode(list *head, fun1 traverse)
{
    int n = (int)getInt;             // 调用函数找到要删除的节点位置
    list *p = head;                  // 确定从头节点开始
    list *temp = traverse(n - 1, p); // 遍历链表 传递给函数的是p的副本
    // 在函数结束后p依然指向头节点 //但是用temp将此时返回的地址保存
    p = temp;
    p = p->next;
    temp->next = p->next;
    free(p);
}

void circulateNode(list *head)
{ // 尾指针指向头节点
    tail->next = head;
}

int getInt(FILE *file)
{ // 递归寻找到下一个数
    if (fscanf(file, "%2d") != 1)
    { // 读取一位或二位数
        return getInt;
    }
}

int main()
{ // 程序入口
    list *head = (list *)malloc(sizeof(list));
    head->data = 1; // 创建头节点
    list *p = NULL;
    FILE *file = fopen("CS-EASY-02-1.txt", "r"); // FILE是全局变量
    if (file == NULL)
    {                                 // 无正常打开 指针为空指针
        perror("Error opening file"); // 若是无正常打开文件 在stdout中输出这串字符
        return 1;
    }
    char ch;
    while ((ch = fgetc(file)) != EOF)
    { // 一直读取到文件末尾
        switch (ch)
        {
        case 'H':
            insertHead(head, insertNode);
            break;
        case 'T':
            insertTail(tail);
            break;
        case 'C':
            circulateNode(head);
            break;
        case 'D':
            deleteNode(head, traverse);
            break;
        }
    }
    fclose(file); // 打开文件后还要关闭文件
    return 0;
}
//最后输出的结果为311112121211221222122211111111222111
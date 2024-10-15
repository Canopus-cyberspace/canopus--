 #include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char data[MAX_SIZE];
    int top;
} stack;

void initStack(stack *s) {
    s->top = -1;
}

int isStackEmpty(stack *s) {
    return s->top == -1;
}

void push(stack *s, char element) {
    if (s->top < MAX_SIZE - 1) {
        s->data[++s->top] = element;
    }
}

char pop(stack *s) {
    if (!isStackEmpty(s)) {
        return s->data[s->top--];
    }
    return '\0'; // Stack is empty
}

int main() {
    stack *p = (stack *)malloc(sizeof(stack));
    initStack(p);
    char buff[MAX_SIZE];
    int i = 0, j = 0;
    char f[] = "311112121211221222122211111111222111"; // 数字串
    char t[] = "kiglnmrmeiahenrteof4ardar"; // 密文串

    int d = -1;
    int num;
    do {
        d++;
        num = f[d] - '0'; // 将字符转换为整数
        for (int k = 0; k < num; k++, j++) {
            push(p, t[j]); // 压入栈
        }
        d++;
        num = f[d] - '0';
        for (int k = 0; k < num; k++) {
            if (!isStackEmpty(p)) {
                buff[i++] = pop(p);
            }
        }
    } while (f[d + 1] != '\0');

    while (!isStackEmpty(p)) {
        buff[i++] = pop(p);
    }

    buff[i] = '\0';
    printf("%s\n", buff);

    free(p);
    return 0;
}
//最后的结果是liamhedrtaanofrehtieke
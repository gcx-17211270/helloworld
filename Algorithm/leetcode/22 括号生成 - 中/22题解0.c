/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define TRUE 1
#define NULL 0
char ** generateParenthesis(int n, int* returnSize){
    Stack* s = (Stack *)malloc(sizeof(Stack) * n);
    int i = n;
    int j = n;
    while (TRUE)
    {
        if (i > 0 && j > i)
        {
            //这段的代码块不知道怎么写
            //想让入栈出栈得到遍历
            //而且这样只不过得到的是第一组解罢了，后面的很多种怎么办呢？
            //2020.04.13，看到了不同的java和C的dfs，什么时候能用自己的语言描述出dfs呢
        }
        if (i == 0 && j == 0) break;
    }
}

typedef struct Stack{
    char ch;
    Stack* next;
    Stack* pre;
}Stack;
void push(Stack* s, char ch)
{
    s->ch = ch;
    s->next->pre = s;
    s = s->next;
}
char pop(Stack* s)
{
    char ch = s->ch;
    s->pre->next = NULL;
    s = s->pre;
}
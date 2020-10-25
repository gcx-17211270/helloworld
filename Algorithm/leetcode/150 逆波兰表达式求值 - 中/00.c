/**
 * 使用堆栈的普通做法
 * 讲逆波兰表达式遇到值则入栈，遇到表达式则取出两个操作数并将结果入栈最后返回结果
 * 
 * 栈的实现是使用链栈，每当有新的数据入栈，新增一个结点，每当弹出一个数据，删掉一个结点
 * 
 * 执行用时：12 ms, 在所有 C 提交中击败了45.95%的用户
 * 内存消耗：8.2 MB, 在所有 C 提交中击败了5.15%的用户
 * 
 * 奇怪的是，如果将free部分的注释去掉，得到这样的结果，按理来说改善的应该是空间使用，可是为什么其实空间基本没变，时间变化非常大？
 * 执行用时：0 ms, 在所有 C 提交中击败了100.00%的用户
 * 内存消耗：8.1 MB, 在所有 C 提交中击败了5.15%的用户
*/
typedef struct _Stack Stack;
struct _Stack
{
    int data;
    Stack* next;
};

int evalRPN(char ** tokens, int tokensSize){
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->data = NULL;
    stack->next = NULL;
    for(int i = 0; i < tokensSize; i++)
    {
        if(tokens[i][0] <= '9' && tokens[i][0] >= '0' )
        {
            push_char(&stack, tokens[i]);
        }
        else if(tokens[i][0] == '-' && tokens[i][1] != '\0')
        {
            push_minus(&stack, tokens[i]);
        }
        else
        {
            int value1 = pop(&stack);
            int value2 = pop(&stack);
            if(tokens[i][0] == '+')
                push_int(&stack, value2 + value1);
            if(tokens[i][0] == '-')
                push_int(&stack, value2 - value1);
            if(tokens[i][0] == '*')
                push_int(&stack, value2 * value1);
            if(tokens[i][0] == '/')
                push_int(&stack, value2 / value1);
        }
    }
    return pop(&stack);
}


void push_int(Stack** s, int res)
{
    Stack* temp = (Stack*)malloc(sizeof(Stack));
    temp->data = res;
    temp->next = *s;
    *s = temp;
}
void push_char(Stack** stack, char* s)
{
    int res = 0;
    char* c = s;
    while(*c != '\0')
    {
        res = res * 10 + (int)(*c - '0');
        c++;
    }
    push_int(stack, res);
}
void push_minus(Stack** stack, char* s)
{
    int res = 0;
    char* c = s + 1;
    while(*c != '\0')
    {
        res = res * 10 + (int)(*c - '0');
        c++;
    }
    res *= -1;
    push_int(stack, res);
}
int pop(Stack** s)
{
    int temp = (*s)->data;
    Stack* tmp = *s;
    *s = (*s)->next;
    //free(tmp);
    return temp;
}
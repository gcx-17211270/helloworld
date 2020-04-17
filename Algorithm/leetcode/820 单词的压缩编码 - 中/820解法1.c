#define MAX_N 20000

typedef struct Node{
    struct Node* child[26];
    int count;
}Node;

Node D_Tree[MAX_N] = {0};
int memID;
Node* New_Node()
{
    Node* tmp_N = &D_Tree[memID++];
    for(int i = 0; i<26 ;i++)
    {
        tmp_N->child[i] = 0;
    }
    tmp_N->count = 0;
    return tmp_N;
}

void dfs(Node* node, int* count){
    bool flag = true;
    for(int i = 0;i <26; i ++)
    {
        if(node->child[i]!=0){
            dfs(node->child[i], count);
            flag = false;
        }
    }
    if(flag) *count+=node->count +1;
    return;
}

int minimumLengthEncoding(char ** words, int wordsSize){
    memID = 0;
    Node* root = New_Node();
    for(int i = 0; i < wordsSize; i++)
    {
        int c ;
        Node* tmp_H = root;
        int len_w = 0;
        char* tmp_w = words[i];
        while(c = *tmp_w++){
          len_w++;
        }
        int j = len_w; 
        int count = 0;
        while(j--)
        {
            count++;
            if(tmp_H->child[words[i][j]-97] == 0)
            {
                Node* tmp_N = New_Node();
                printf("%c, ", words[i][j]);
                tmp_H->child[words[i][j]-97] = tmp_N;
                tmp_N->count = count;
                tmp_H = tmp_H->child[words[i][j]-97];
            }
            else{
                tmp_H = tmp_H->child[words[i][j]-97];
            }
        }
    }
    int result = 0;
    dfs(root, &result);
    return result;
}

/*
作者：sidian
链接：https://leetcode-cn.com/problems/short-encoding-of-words/solution/cyu-yan-zi-dian-shu-by-sidian/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
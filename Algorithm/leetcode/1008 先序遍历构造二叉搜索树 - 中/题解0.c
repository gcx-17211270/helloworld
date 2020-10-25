TreeNode* binarySearch(int* list, int columnSize)
{
    int k = 0;
    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode)*columnSize);
    TreeNode* temp = root;
    while(columnSize > k)
    {
        temp->val = list[k++];
        if (list[k++] < temp->val) 
        {
            temp->lChildren->val = list[k - 1];
            temp = temp->lChildren;
        }
        else {
            temp->rChildren->val = list[k - 1];
            temp = temp->rChildren;
        }
    }
}
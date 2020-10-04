/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution{
public:
    int ok = 1;
    vector<int> v[100005];
    void dfs(TreeNode *rt, int dep)
    {
        if (rt->val % 2 != dep % 2) ok = 0;
        v[dep].push_back(rt->val);
        if (rt->left) dfs(rt->left, dep + 1);
        if (rt->right) dfs(rt->right, dep + 1);
    }

    bool isEvenOddTree(TreeNode* root)
    {
        if (!root) return 1;
        dfs(root, 1);
        if(!ok) return 0;
        for (int i = 1; ; ++i)
        {
            if (v[i].empty()) break;
            for (int j = 1; j < v[i].size(); ++j)
            {
                if ((i & 1) && v[i][j] <= v[i][j - 1])
                    return 0;
                if ((i % 2 == 0) && v[i][j] >= v[i][j - 1]) 
                    return 0;
            }
        }
        return 1;
    }
};
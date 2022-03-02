class Solution
{
public:
    bool dfs(TreeNode *cur, long long m, long long M)
    {
        if (!(m < cur->val && cur->val < M))
            return false;
        if (cur->left)
            if (!dfs(cur->left, m, cur->val))
                return false;
        if (cur->right)
            if (!dfs(cur->right, cur->val, M))
                return false;
        return true;
    }
    bool isValidBST(TreeNode *root)
    {
        return dfs(root, LLONG_MIN, LLONG_MAX);
    }
};

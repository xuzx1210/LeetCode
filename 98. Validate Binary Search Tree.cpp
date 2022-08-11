class Solution
{
private:
    bool dfs(TreeNode *cur, long long left, long long right)
    {
        if (!cur)
            return true;
        if (cur->val <= left || right <= cur->val)
            return false;
        if (!dfs(cur->left, left, cur->val))
            return false;
        if (!dfs(cur->right, cur->val, right))
            return false;
        return true;
    }

public:
    bool isValidBST(TreeNode *root)
    {
        return dfs(root, LLONG_MIN, LLONG_MAX);
    }
};

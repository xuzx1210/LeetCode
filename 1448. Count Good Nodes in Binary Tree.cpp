class Solution
{
private:
    int dfs(TreeNode *cur, int maximum)
    {
        if (!cur)
            return 0;
        int m, result;
        if (cur->val < maximum)
        {
            m = maximum;
            result = 0;
        }
        else
        {
            m = cur->val;
            result = 1;
        }
        return result + dfs(cur->left, m) + dfs(cur->right, m);
    }

public:
    int goodNodes(TreeNode *root)
    {
        return dfs(root, INT_MIN);
    }
};

class Solution
{
private:
    int result, last;
    void dfs(TreeNode *node)
    {
        if (!node)
            return;
        dfs(node->left);
        result = min(result, node->val - last);
        last = node->val;
        dfs(node->right);
    }

public:
    int getMinimumDifference(TreeNode *root)
    {
        result = INT_MAX;
        last = -100000;
        dfs(root);
        return result;
    }
};

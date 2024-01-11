class Solution
{
private:
    int result;
    void dfs(TreeNode *node, int minimum, int maximum)
    {
        if (node == nullptr)
            return;
        minimum = min(minimum, node->val);
        maximum = max(maximum, node->val);
        result = max(result, maximum - minimum);
        dfs(node->left, minimum, maximum);
        dfs(node->right, minimum, maximum);
    }

public:
    int maxAncestorDiff(TreeNode *root)
    {
        result = 0;
        dfs(root, INT_MAX, INT_MIN);
        return result;
    }
};

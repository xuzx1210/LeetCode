class Solution
{
private:
    int value;
    void dfs(TreeNode *node, int depth)
    {
        if (!node)
            return;
        if (!depth)
        {
            node->left = new TreeNode(value, node->left, nullptr);
            node->right = new TreeNode(value, nullptr, node->right);
            return;
        }
        dfs(node->left, --depth);
        dfs(node->right, depth);
    }

public:
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        if (depth == 1)
            return new TreeNode(val, root, nullptr);
        value = val;
        dfs(root, depth - 2);
        return root;
    }
};

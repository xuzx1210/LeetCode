class Solution
{
private:
    int result, maxDepth;
    void dfs(TreeNode *node, const int depth)
    {
        if (!node)
            return;
        if (depth == maxDepth)
            result += node->val;
        else if (depth > maxDepth)
        {
            result = node->val;
            maxDepth = depth;
        }
        dfs(node->left, depth + 1);
        dfs(node->right, depth + 1);
    }

public:
    int deepestLeavesSum(TreeNode *root)
    {
        result = 0;
        maxDepth = 0;
        dfs(root, 0);
        return result;
    }
};

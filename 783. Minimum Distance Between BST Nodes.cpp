class Solution
{
private:
    int result;
    TreeNode *prev;
    void dfs(TreeNode *node)
    {
        if (node == nullptr)
            return;
        dfs(node->left);
        if (prev != nullptr)
            result = min(result, node->val - prev->val);
        prev = node;
        dfs(node->right);
    }

public:
    int minDiffInBST(TreeNode *root)
    {
        result = INT_MAX;
        prev = nullptr;
        dfs(root);
        return result;
    }
};

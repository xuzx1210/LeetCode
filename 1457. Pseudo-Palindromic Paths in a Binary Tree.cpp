class Solution
{
private:
    void dfs(TreeNode *node, int &path, int &result)
    {
        path ^= (1 << node->val);
        if (!node->left && !node->right)
            if (!(path & (path - 1)))
                ++result;
        if (node->left)
            dfs(node->left, path, result);
        if (node->right)
            dfs(node->right, path, result);
        path ^= (1 << node->val);
    }

public:
    int pseudoPalindromicPaths(TreeNode *root)
    {
        int path = 0, result = 0;
        dfs(root, path, result);
        return result;
    }
};

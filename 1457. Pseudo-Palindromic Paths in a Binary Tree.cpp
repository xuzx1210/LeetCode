class Solution
{
private:
    void dfs(TreeNode *node, int &path, int &result)
    {
        if (!node)
            return;
        int mask = 1 << node->val;
        path ^= mask;
        result += !node->left && !node->right && !(path & (path - 1));
        dfs(node->left, path, result);
        dfs(node->right, path, result);
        path ^= mask;
    }

public:
    int pseudoPalindromicPaths(TreeNode *root)
    {
        int path = 0, result = 0;
        dfs(root, path, result);
        return result;
    }
};

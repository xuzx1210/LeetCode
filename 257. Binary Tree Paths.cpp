class Solution
{
private:
    vector<string> result;
    void dfs(TreeNode *cur, string path)
    {
        if (!cur->left && !cur->right)
        {
            path += to_string(cur->val);
            result.emplace_back(path);
            return;
        }
        path += (to_string(cur->val) + "->");
        if (cur->left)
            dfs(cur->left, path);
        if (cur->right)
            dfs(cur->right, path);
    }

public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        result.clear();
        dfs(root, "");
        return result;
    }
};

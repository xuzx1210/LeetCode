class Solution
{
private:
    vector<int> path;
    vector<vector<int>> result;
    void dfs(TreeNode *node, int remain)
    {
        if (!node)
            return;
        remain -= node->val;
        path.emplace_back(node->val);
        if (!node->left && !node->right && !remain)
            result.emplace_back(path);
        dfs(node->left, remain);
        dfs(node->right, remain);
        path.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        path.clear();
        result.clear();
        dfs(root, targetSum);
        return result;
    }
};

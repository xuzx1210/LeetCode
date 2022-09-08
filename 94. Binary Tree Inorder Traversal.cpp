class Solution
{
private:
    void dfs(TreeNode *cur, vector<int> &result)
    {
        if (!cur)
            return;
        dfs(cur->left, result);
        result.emplace_back(cur->val);
        dfs(cur->right, result);
    }

public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result = {};
        dfs(root, result);
        return result;
    }
};

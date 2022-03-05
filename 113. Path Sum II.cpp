class Solution
{
public:
    vector<vector<int>> result;
    vector<int> sumStack;
    void dfs(TreeNode *cur, int remain)
    {
        sumStack.push_back(cur->val);
        remain -= cur->val;
        if (!cur->left && !cur->right)
        {
            if (!remain)
                result.push_back(sumStack);
            sumStack.pop_back();
            return;
        }
        if (cur->left)
            dfs(cur->left, remain);
        if (cur->right)
            dfs(cur->right, remain);
        sumStack.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        result.clear();
        if (root)
        {
            sumStack.clear();
            dfs(root, targetSum);
        }
        return result;
    }
};

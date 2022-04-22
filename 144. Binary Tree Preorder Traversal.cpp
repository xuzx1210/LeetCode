class Solution
{
public:
    void dfs(TreeNode *node, vector<int> &nums)
    {
        if (!node)
            return;
        nums.push_back(node->val);
        dfs(node->left, nums);
        dfs(node->right, nums);
    }
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> result({});
        dfs(root, result);
        return result;
    }
};

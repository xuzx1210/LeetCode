class Solution
{
public:
    void dfs(TreeNode *node, vector<int> &nums)
    {
        if (!node)
            return;
        dfs(node->left, nums);
        dfs(node->right, nums);
        nums.push_back(node->val);
    }
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> result({});
        dfs(root, result);
        return result;
    }
};

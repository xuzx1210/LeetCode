class Solution
{
private:
    int result;
    int dfs(TreeNode *root)
    {
        if (!root)
            return 0;
        int left = max(0, dfs(root->left)), right = max(0, dfs(root->right));
        result = max(result, root->val + left + right);
        return root->val + max(left, right);
    }

public:
    int maxPathSum(TreeNode *root)
    {
        result = INT_MIN;
        dfs(root);
        return result;
    }
};

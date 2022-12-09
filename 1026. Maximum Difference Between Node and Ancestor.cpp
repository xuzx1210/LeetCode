class Solution
{
private:
    int dfs(TreeNode *root, int minimum, int maximum)
    {
        if (!root)
            return 0;
        minimum = min(minimum, root->val);
        maximum = max(maximum, root->val);
        return max(maximum - minimum, max(dfs(root->left, minimum, maximum), dfs(root->right, minimum, maximum)));
    }

public:
    int maxAncestorDiff(TreeNode *root)
    {
        return dfs(root, root->val, root->val);
    }
};

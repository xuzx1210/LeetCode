class Solution
{
private:
    bool dfs(TreeNode *left, TreeNode *right)
    {
        if (!left && !right)
            return true;
        if (!left || !right)
            return false;
        if (left->val != right->val)
            return false;
        if (!dfs(left->left, right->right))
            return false;
        if (!dfs(left->right, right->left))
            return false;
        return true;
    }

public:
    bool isSymmetric(TreeNode *root)
    {
        return dfs(root->left, root->right);
    }
};

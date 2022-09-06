class Solution
{
public:
    TreeNode *pruneTree(TreeNode *root)
    {
        if (!root)
            return nullptr;
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        return !root->left && !root->right && !root->val ? nullptr : root;
    }
};

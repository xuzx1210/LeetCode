class Solution
{
public:
    bool evaluateTree(TreeNode *root)
    {
        if (root->val == 0)
            return false;
        if (root->val == 1)
            return true;
        const bool left = evaluateTree(root->left), right = evaluateTree(root->right);
        if (root->val == 2)
            return left || right;
        return left && right;
    }
};

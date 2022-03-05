class Solution
{
public:
    int maxDepth(TreeNode *cur)
    {
        if (!cur)
            return 0;
        int leftDepth = maxDepth(cur->left), rightDepth = maxDepth(cur->right);
        if (leftDepth == -1 || rightDepth == -1 || abs(leftDepth - rightDepth) > 1)
            return -1;
        return max(leftDepth, rightDepth) + 1;
    }
    bool isBalanced(TreeNode *root)
    {
        return maxDepth(root) != -1;
    }
};

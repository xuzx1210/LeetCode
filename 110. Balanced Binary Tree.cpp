class Solution
{
public:
    int maxDepth(TreeNode *cur, bool &over1)
    {
        if (!cur)
            return 0;
        int leftDepth = maxDepth(cur->left, over1), rightDepth = maxDepth(cur->right, over1);
        int diff = leftDepth - rightDepth;
        diff = max(diff, -diff);
        if (diff > 1)
            over1 = true;
        return max(leftDepth, rightDepth) + 1;
    }
    bool isBalanced(TreeNode *root)
    {
        bool over1 = false;
        maxDepth(root, over1);
        return !over1;
    }
};

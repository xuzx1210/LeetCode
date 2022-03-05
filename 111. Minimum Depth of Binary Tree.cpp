class Solution
{
public:
    int findMinDepth(TreeNode *cur)
    {
        if (cur->left)
        {
            if (cur->right)
                return min(findMinDepth(cur->left), findMinDepth(cur->right)) + 1;
            else
                return findMinDepth(cur->left) + 1;
        }
        else
        {
            if (cur->right)
                return findMinDepth(cur->right) + 1;
            else
                return 1;
        }
    }
    int minDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        return findMinDepth(root);
    }
};

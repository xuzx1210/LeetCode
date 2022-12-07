class Solution
{
public:
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        if (!root)
            return 0;
        int result = 0;
        if (low < root->val)
            result += rangeSumBST(root->left, low, high);
        if (root->val < high)
            result += rangeSumBST(root->right, low, high);
        if (low <= root->val && root->val <= high)
            result += root->val;
        return result;
    }
};

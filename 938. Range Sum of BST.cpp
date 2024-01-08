class Solution
{
public:
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        if (root == nullptr)
            return 0;
        const bool left = low < root->val, right = root->val < high;
        int result = root->val * (low == root->val || left && right || root->val == high);
        if (left)
            result += rangeSumBST(root->left, low, high);
        if (right)
            result += rangeSumBST(root->right, low, high);
        return result;
    }
};

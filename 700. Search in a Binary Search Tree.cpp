class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        if (!root)
            return nullptr;
        int cur = root->val;
        if (val < cur)
            return searchBST(root->left, val);
        else if (val > cur)
            return searchBST(root->right, val);
        else
            return root;
    }
};

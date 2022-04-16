class Solution
{
public:
    int accumulate;
    Solution()
    {
        accumulate = 0;
    }
    TreeNode *convertBST(TreeNode *root)
    {
        if (root)
        {
            convertBST(root->right);
            accumulate += root->val;
            root->val = accumulate;
            convertBST(root->left);
        }
        return root;
    }
};

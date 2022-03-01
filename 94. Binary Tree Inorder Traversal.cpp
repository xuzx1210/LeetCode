class Solution
{
public:
    vector<int> result;
    void inorder(TreeNode *cur)
    {
        if (cur->left)
            inorder(cur->left);
        result.push_back(cur->val);
        if (cur->right)
            inorder(cur->right);
    }
    vector<int> inorderTraversal(TreeNode *root)
    {
        result.clear();
        if (root)
            inorder(root);
        return result;
    }
};

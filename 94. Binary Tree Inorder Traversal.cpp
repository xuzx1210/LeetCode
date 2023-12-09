class Solution
{
private:
    vector<int> result;
    void inorder(TreeNode *node)
    {
        if (!node)
            return;
        inorder(node->left);
        result.emplace_back(node->val);
        inorder(node->right);
    }

public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        result = {};
        inorder(root);
        return result;
    }
};

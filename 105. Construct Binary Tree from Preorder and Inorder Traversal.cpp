class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int mid = preorder[0];
        auto it = find(inorder.begin(), inorder.end(), mid);
        vector<int> leftInorder(inorder.begin(), it), rightInorder(it + 1, inorder.end());
        vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + 1 + leftInorder.size()), rightPreorder(preorder.begin() + 1 + leftInorder.size(), preorder.end());
        TreeNode *cur = new TreeNode(mid);
        if (!leftInorder.empty())
            cur->left = buildTree(leftPreorder, leftInorder);
        if (!rightInorder.empty())
            cur->right = buildTree(rightPreorder, rightInorder);
        return cur;
    }
};

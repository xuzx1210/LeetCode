class Solution
{
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int mid = postorder.back();
        auto it = find(inorder.begin(), inorder.end(), mid);
        vector<int> leftInorder(inorder.begin(), it), rightInorder(it + 1, inorder.end());
        int leftSize = leftInorder.size();
        vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftSize), rightPostorder(postorder.begin() + leftSize, postorder.end() - 1);
        TreeNode *cur = new TreeNode(mid);
        if (!leftInorder.empty())
            cur->left = buildTree(leftInorder, leftPostorder);
        if (!rightInorder.empty())
            cur->right = buildTree(rightInorder, rightPostorder);
        return cur;
    }
};

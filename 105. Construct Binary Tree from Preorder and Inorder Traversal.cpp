class Solution
{
public:
    TreeNode *makeTree(vector<int> &preorder, vector<int> &inorder, int preLeft, int preRight, int inLeft, int inRight)
    {
        if (preLeft == preRight)
            return nullptr;
        int mid = preorder[preLeft];
        int inPos = find(inorder.begin() + inLeft, inorder.begin() + inRight, mid) - inorder.begin();
        int prePos = preLeft + 1 + inPos - inLeft;
        TreeNode *result = new TreeNode(mid, makeTree(preorder, inorder, preLeft + 1, prePos, inLeft, inPos), makeTree(preorder, inorder, prePos, preRight, inPos + 1, inRight));
        return result;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return makeTree(preorder, inorder, 0, preorder.size(), 0, inorder.size());
    }
};

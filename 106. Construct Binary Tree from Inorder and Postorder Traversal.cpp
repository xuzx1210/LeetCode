class Solution
{
public:
    TreeNode *makeTree(vector<int> &inorder, vector<int> &postorder, int inLeft, int inRight, int postLeft, int postRight)
    {
        if (inLeft == inRight)
            return nullptr;
        int mid = postorder[postRight - 1];
        int inPos = find(inorder.begin() + inLeft, inorder.begin() + inRight, mid) - inorder.begin();
        int postPos = postLeft + inPos - inLeft;
        TreeNode *result = new TreeNode(mid, makeTree(inorder, postorder, inLeft, inPos, postLeft, postPos), makeTree(inorder, postorder, inPos + 1, inRight, postPos, postRight - 1));
        return result;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        return makeTree(inorder, postorder, 0, inorder.size(), 0, postorder.size());
    }
};

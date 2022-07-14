class Solution
{
private:
    vector<int> preorder;
    vector<int> inorder;

public:
    TreeNode *dfs(int &index, int left, int right)
    {
        if (left == right)
            return nullptr;
        int cur = preorder[index++];
        int middle = find(inorder.begin() + left, inorder.begin() + right, cur) - inorder.begin();
        TreeNode *node = new TreeNode(cur);
        node->left = dfs(index, left, middle);
        node->right = dfs(index, middle + 1, right);
        return node;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        this->preorder = preorder;
        this->inorder = inorder;
        int index = 0;
        return dfs(index, 0, inorder.size());
    }
};

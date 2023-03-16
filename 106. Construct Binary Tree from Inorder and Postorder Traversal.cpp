class Solution
{
private:
    TreeNode *dfs(const vector<int>::const_iterator begin, const vector<int>::const_iterator end, vector<int> &postorder)
    {
        if (begin == end)
            return nullptr;
        const int x = postorder.back();
        postorder.pop_back();
        const vector<int>::const_iterator middle = find(begin, end, x);
        TreeNode *right = dfs(middle + 1, end, postorder);
        TreeNode *left = dfs(begin, middle, postorder);
        return new TreeNode(x, left, right);
    }

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        return dfs(inorder.begin(), inorder.end(), postorder);
    }
};

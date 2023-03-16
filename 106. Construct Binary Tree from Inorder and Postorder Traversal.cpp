class Solution
{
private:
    TreeNode *dfs(const vector<int>::const_iterator begin, const vector<int>::const_iterator end, vector<int> &postorder)
    {
        if (begin == end)
            return nullptr;
        const int val = postorder.back();
        postorder.pop_back();
        const vector<int>::const_iterator middle = find(begin, end, val);
        TreeNode *result = new TreeNode(val);
        result->right = dfs(middle + 1, end, postorder);
        result->left = dfs(begin, middle, postorder);
        return result;
    }

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        return dfs(inorder.begin(), inorder.end(), postorder);
    }
};

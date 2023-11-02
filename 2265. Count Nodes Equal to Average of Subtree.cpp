class Solution
{
private:
    int result;
    pair<int, int> dfs(TreeNode *node)
    {
        if (node == nullptr)
            return {0, 0};
        const pair<int, int> left(dfs(node->left)), right(dfs(node->right));
        const int count = left.first + right.first + 1, sum = left.second + right.second + node->val;
        if (sum / count == node->val)
            ++result;
        return {count, sum};
    }

public:
    int averageOfSubtree(TreeNode *root)
    {
        result = 0;
        dfs(root);
        return result;
    }
};

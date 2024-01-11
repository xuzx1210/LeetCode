class Solution
{
private:
    int result;
    pair<bool, int> dfs(TreeNode *node, int start)
    {
        if (node == nullptr)
            return {false, 0};
        const pair<bool, int> left(dfs(node->left, start)), right(dfs(node->right, start));
        if (node->val == start)
        {
            result = max({result, left.second, right.second});
            return {true, 1};
        }
        if (left.first)
        {
            result = max(result, left.second + right.second);
            return {true, left.second + 1};
        }
        if (right.first)
        {
            result = max(result, left.second + right.second);
            return {true, right.second + 1};
        }
        return {false, max(left.second, right.second) + 1};
    }

public:
    int amountOfTime(TreeNode *root, int start)
    {
        result = 0;
        dfs(root, start);
        return result;
    }
};

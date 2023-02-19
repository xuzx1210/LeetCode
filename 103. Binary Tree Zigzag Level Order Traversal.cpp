class Solution
{
private:
    vector<vector<int>> result;
    void dfs(const TreeNode *node, const int depth)
    {
        if (!node)
            return;
        if (depth == result.size())
            result.push_back({node->val});
        else
            result[depth].emplace_back(node->val);
        dfs(node->left, depth + 1);
        dfs(node->right, depth + 1);
    }

public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        result.clear();
        dfs(root, 0);
        for (int level = 1; level < result.size(); level += 2)
            reverse(result[level].begin(), result[level].end());
        return result;
    }
};

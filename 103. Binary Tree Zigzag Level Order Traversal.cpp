class Solution
{
public:
    vector<vector<int>> result;
    int findDepth(TreeNode *cur)
    {
        if (cur->left)
        {
            if (cur->right)
                return max(findDepth(cur->left), findDepth(cur->right)) + 1;
            else
                return findDepth(cur->left) + 1;
        }
        else
        {
            if (cur->right)
                return findDepth(cur->right) + 1;
            else
                return 1;
        }
    }
    void dfs(TreeNode *cur, int depth)
    {
        result[depth].push_back(cur->val);
        if (cur->left)
            dfs(cur->left, depth + 1);
        if (cur->right)
            dfs(cur->right, depth + 1);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        result.clear();
        if (root == nullptr)
            return result;
        int depth = findDepth(root);
        result = vector<vector<int>>(depth, vector<int>({}));
        dfs(root, 0);
        for (int i = 0; i < result.size(); ++i)
            if (i & 1)
                reverse(result[i].begin(), result[i].end());
        return result;
    }
};

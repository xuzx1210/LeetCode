class Solution
{
private:
    map<int, map<int, vector<int>>> tree;
    void dfs(TreeNode *cur, int index, int depth)
    {
        if (!cur)
            return;
        tree[index][depth].emplace_back(cur->val);
        dfs(cur->left, index - 1, depth + 1);
        dfs(cur->right, index + 1, depth + 1);
    }

public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        tree.clear();
        dfs(root, 0, 0);
        vector<vector<int>> result = {};
        for (auto &index : tree)
        {
            vector<int> tmp = {};
            for (auto &depth : index.second)
            {
                sort(depth.second.begin(), depth.second.end());
                tmp.insert(tmp.end(), depth.second.begin(), depth.second.end());
            }
            result.emplace_back(tmp);
        }
        return result;
    }
};

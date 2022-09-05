class Solution
{
private:
    map<int, vector<int>> tree;
    void dfs(const Node *cur, const int depth)
    {
        if (!cur)
            return;
        tree[depth].emplace_back(cur->val);
        for (Node *next : cur->children)
            dfs(next, depth + 1);
    }

public:
    vector<vector<int>> levelOrder(Node *root)
    {
        tree.clear();
        dfs(root, 0);
        vector<vector<int>> result = {};
        for (auto &level : tree)
            result.emplace_back(level.second);
        return result;
    }
};

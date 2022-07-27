class Solution
{
private:
    void dfs(TreeNode *cur, vector<TreeNode *> &nodes)
    {
        if (!cur)
            return;
        nodes.push_back(cur);
        dfs(cur->left, nodes);
        dfs(cur->right, nodes);
    }

public:
    void flatten(TreeNode *root)
    {
        vector<TreeNode *> nodes = {};
        dfs(root, nodes);
        int size = nodes.size();
        nodes.push_back(nullptr);
        for (int i = 0; i < size; ++i)
        {
            nodes[i]->left = nullptr;
            nodes[i]->right = nodes[i + 1];
        }
    }
};

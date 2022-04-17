class Solution
{
public:
    void dfs(TreeNode *node, vector<TreeNode *> &nodes)
    {
        if (!node)
            return;
        dfs(node->left, nodes);
        nodes.push_back(node);
        dfs(node->right, nodes);
    }
    TreeNode *increasingBST(TreeNode *root)
    {
        vector<TreeNode *> nodes({});
        dfs(root, nodes);
        int size = nodes.size();
        for (auto node : nodes)
            node->left = nullptr;
        for (int i = 0; i < size - 1; ++i)
            nodes[i]->right = nodes[i + 1];
        nodes.back()->right = nullptr;
        return nodes[0];
    }
};

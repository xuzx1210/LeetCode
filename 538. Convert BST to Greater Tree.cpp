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
    TreeNode *convertBST(TreeNode *root)
    {
        vector<TreeNode *> nodes({});
        dfs(root, nodes);
        for (int i = nodes.size() - 2; i >= 0; --i)
            nodes[i]->val += nodes[i + 1]->val;
        return root;
    }
};

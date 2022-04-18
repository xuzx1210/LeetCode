class Solution
{
public:
    void dfs(TreeNode *node, vector<int> &nodes)
    {
        if (!node)
            return;
        dfs(node->left, nodes);
        nodes.push_back(node->val);
        dfs(node->right, nodes);
    }
    int kthSmallest(TreeNode *root, int k)
    {
        vector<int> nodes({});
        dfs(root, nodes);
        return nodes[k - 1];
    }
};

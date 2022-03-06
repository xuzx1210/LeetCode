class Solution
{
public:
    void traverse(vector<TreeNode *> &nodes, TreeNode *cur)
    {
        nodes.push_back(cur);
        if (cur->left)
            traverse(nodes, cur->left);
        if (cur->right)
            traverse(nodes, cur->right);
    }
    void flatten(TreeNode *root)
    {
        if (!root)
            return;
        vector<TreeNode *> nodes({});
        traverse(nodes, root);
        for (int i = 0; i < nodes.size() - 1; ++i)
        {
            nodes[i]->left = nullptr;
            nodes[i]->right = nodes[i + 1];
        }
        nodes.back()->left = nullptr;
        nodes.back()->right = nullptr;
    }
};

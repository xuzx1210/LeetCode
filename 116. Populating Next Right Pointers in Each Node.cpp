class Solution
{
public:
    int maxDepth(Node *cur)
    {
        if (!cur)
            return 0;
        return max(maxDepth(cur->left), maxDepth(cur->right)) + 1;
    }
    void traverse(Node *cur, const int depth, vector<vector<Node *>> &tree)
    {
        if (!cur)
            return;
        tree[depth].push_back(cur);
        traverse(cur->left, depth + 1, tree);
        traverse(cur->right, depth + 1, tree);
    }
    Node *connect(Node *root)
    {
        int depth = maxDepth(root);
        vector<vector<Node *>> tree(depth, vector<Node *>({}));
        traverse(root, 0, tree);
        for (auto level : tree)
            for (int i = 0; i < level.size() - 1; ++i)
                level[i]->next = level[i + 1];
        return root;
    }
};

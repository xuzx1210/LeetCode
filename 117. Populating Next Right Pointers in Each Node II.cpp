class Solution
{
private:
    unordered_map<int, vector<Node *>> tree;
    void dfs(Node *node, int depth)
    {
        if (!node)
            return;
        tree[depth].push_back(node);
        dfs(node->left, depth + 1);
        dfs(node->right, depth + 1);
    }

public:
    Node *connect(Node *root)
    {
        tree.clear();
        dfs(root, 0);
        for (auto &level : tree)
        {
            auto &list = level.second;
            for (int i = 0; i < list.size() - 1; ++i)
                list[i]->next = list[i + 1];
            list.back()->next = nullptr;
        }
        return root;
    }
};

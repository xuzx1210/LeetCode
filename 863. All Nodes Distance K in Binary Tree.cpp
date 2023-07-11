class Solution
{
private:
    class NewTreeNode
    {
    public:
        int val;
        NewTreeNode *parent, *left, *right;
        NewTreeNode(int v, NewTreeNode *p) : val(v), parent(p) {}
    };
    TreeNode *start;
    NewTreeNode *newStart;
    NewTreeNode *makeNewTree(NewTreeNode *parent, TreeNode *node)
    {
        if (!node)
            return nullptr;
        NewTreeNode *newNode = new NewTreeNode(node->val, parent);
        newNode->left = makeNewTree(newNode, node->left);
        newNode->right = makeNewTree(newNode, node->right);
        if (start == node)
            newStart = newNode;
        return newNode;
    }

public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        start = target;
        NewTreeNode *newRoot = makeNewTree(nullptr, root);
        vector<int> result{};
        queue<pair<NewTreeNode *, NewTreeNode *>> bfs({{nullptr, newStart}});
        while (k--)
            for (int size = bfs.size(); size; --size)
            {
                const auto [prev, curr] = bfs.front();
                bfs.pop();
                if (!curr)
                    continue;
                if (curr->parent != prev)
                    bfs.emplace(curr, curr->parent);
                if (curr->left != prev)
                    bfs.emplace(curr, curr->left);
                if (curr->right != prev)
                    bfs.emplace(curr, curr->right);
            }
        while (!bfs.empty())
        {
            const NewTreeNode *node = bfs.front().second;
            bfs.pop();
            if (node)
                result.emplace_back(node->val);
        }
        return result;
    }
};

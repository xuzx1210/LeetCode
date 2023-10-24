// BFS
class Solution
{
public:
    vector<int> largestValues(TreeNode *root)
    {
        vector<int> result{};
        queue<TreeNode *> bfs({root});
        while (!bfs.empty())
        {
            TreeNode *maxNode = nullptr;
            for (int size = bfs.size(); size; --size)
            {
                TreeNode *current = bfs.front();
                bfs.pop();
                if (current == nullptr)
                    continue;
                bfs.emplace(current->left);
                bfs.emplace(current->right);
                if (maxNode == nullptr || maxNode->val < current->val)
                    maxNode = current;
            }
            if (maxNode != nullptr)
                result.emplace_back(maxNode->val);
        }
        return result;
    }
};
// DFS
class Solution
{
private:
    vector<int> result;
    int findDepth(TreeNode *node)
    {
        return node == nullptr ? 0 : max(findDepth(node->left), findDepth(node->right)) + 1;
    }
    void dfs(TreeNode *node, int depth)
    {
        if (node == nullptr)
            return;
        result[depth] = max(result[depth], node->val);
        ++depth;
        dfs(node->left, depth);
        dfs(node->right, depth);
    }

public:
    vector<int> largestValues(TreeNode *root)
    {
        const int depth = findDepth(root);
        result.resize(depth, INT_MIN);
        dfs(root, 0);
        return result;
    }
};

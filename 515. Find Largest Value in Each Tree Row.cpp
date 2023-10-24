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

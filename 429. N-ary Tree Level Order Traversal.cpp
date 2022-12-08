class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        vector<vector<int>> result{};
        queue<Node *> bfs({root});
        while (!bfs.empty())
        {
            vector<int> level{};
            const size_t size = bfs.size();
            for (size_t i = 0; i < size; ++i)
            {
                Node *cur = bfs.front();
                bfs.pop();
                if (!cur)
                    continue;
                level.emplace_back(cur->val);
                for (Node *child : cur->children)
                    bfs.emplace(child);
            }
            if (!level.empty())
                result.emplace_back(level);
        }
        return result;
    }
};

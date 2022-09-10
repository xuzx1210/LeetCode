class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        if (n == 1)
            return {0};
        vector<int> degrees(n, 0);
        vector<vector<int>> neighbors(n, vector<int>({}));
        for (auto &edge : edges)
        {
            neighbors[edge[0]].emplace_back(edge[1]);
            neighbors[edge[1]].emplace_back(edge[0]);
            ++degrees[edge[0]];
            ++degrees[edge[1]];
        }
        queue<int> leaves = {};
        for (int i = 0; i < n; ++i)
            if (degrees[i] == 1)
                leaves.emplace(i);
        while (n > 2)
        {
            int size = leaves.size();
            n -= size;
            for (int i = 0; i < size; ++i)
            {
                int leaf = leaves.front();
                leaves.pop();
                for (int &neighbor : neighbors[leaf])
                {
                    --degrees[neighbor];
                    if (degrees[neighbor] == 1)
                        leaves.emplace(neighbor);
                }
            }
        }
        vector<int> result = {};
        while (!leaves.empty())
        {
            result.emplace_back(leaves.front());
            leaves.pop();
        }
        return result;
    }
};

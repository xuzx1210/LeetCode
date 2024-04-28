class Solution
{
private:
    int n;
    vector<vector<int>> tree;
    vector<int> nodes, result;
    void countNodes(const int curr, const int prev)
    {
        for (const int next : tree[curr])
        {
            if (next == prev)
                continue;
            countNodes(next, curr);
            nodes[curr] += nodes[next];
            result[curr] += result[next] + nodes[next];
        }
    }
    void findResult(const int curr, const int prev)
    {
        for (const int next : tree[curr])
        {
            if (next == prev)
                continue;
            result[next] = result[curr] - nodes[next] + (n - nodes[next]);
            findResult(next, curr);
        }
    }

public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges)
    {
        this->n = n;
        tree.resize(n, vector<int>{});
        nodes.resize(n, 1);
        result.resize(n, 0);
        for (const vector<int> &edge : edges)
        {
            tree[edge[0]].emplace_back(edge[1]);
            tree[edge[1]].emplace_back(edge[0]);
        }
        countNodes(0, -1);
        findResult(0, -1);
        return result;
    }
};

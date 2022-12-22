class Solution
{
private:
    int n;
    vector<vector<int>> tree;
    vector<int> nodes, result;
    void countNodes(int cur, int pre)
    {
        for (const int &next : tree[cur])
        {
            if (next == pre)
                continue;
            countNodes(next, cur);
            nodes[cur] += nodes[next];
            result[cur] += result[next] + nodes[next];
        }
    }
    void findResult(int cur, int pre)
    {
        for (const int &next : tree[cur])
        {
            if (next == pre)
                continue;
            result[next] = result[cur] - nodes[next] + (n - nodes[next]);
            findResult(next, cur);
        }
    }

public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges)
    {
        this->n = n;
        tree.assign(n, {});
        nodes.assign(n, 1);
        result.assign(n, 0);
        for (vector<int> &edge : edges)
        {
            tree[edge[0]].emplace_back(edge[1]);
            tree[edge[1]].emplace_back(edge[0]);
        }
        countNodes(0, -1);
        findResult(0, -1);
        return result;
    }
};

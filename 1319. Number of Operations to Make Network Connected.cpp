class Solution
{
private:
    int groups;
    vector<int> unionFind;
    int find(int index)
    {
        if (unionFind[index] != index)
            unionFind[index] = find(unionFind[index]);
        return unionFind[index];
    }
    void join(int a, int b)
    {
        int findA = find(a), findB = find(b);
        if (findA == findB)
            return;
        unionFind[findA] = findB;
        --groups;
    }

public:
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        if (connections.size() < n - 1)
            return -1;
        unionFind.resize(n);
        iota(unionFind.begin(), unionFind.end(), 0);
        groups = n;
        for (const vector<int> &connection : connections)
            join(connection[0], connection[1]);
        return groups - 1;
    }
};

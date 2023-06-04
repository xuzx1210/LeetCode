class Solution
{
    int n, provinces;
    vector<int> root;
    vector<int> rank;
    int Find(const int city)
    {
        if (root[city] == city)
            return city;
        root[city] = Find(root[city]);
        return root[city];
    }
    void Union(const int a, const int b)
    {
        const int aRoot = Find(a), bRoot = Find(b);
        if (aRoot == bRoot)
            return;
        --provinces;
        if (rank[aRoot] < rank[bRoot])
            root[aRoot] = bRoot;
        else if (rank[aRoot] > rank[bRoot])
            root[bRoot] = aRoot;
        else
        {
            root[aRoot] = bRoot;
            ++rank[bRoot];
        }
    }

public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        n = isConnected.size();
        root.resize(n);
        iota(root.begin(), root.end(), 0);
        rank.resize(n, 0);
        provinces = n;
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                if (isConnected[i][j])
                    Union(i, j);
        return provinces;
    }
};

class Solution
{
private:
    class DSU
    {
    private:
        vector<int> parent, rank;

    public:
        DSU(const int n)
        {
            parent.resize(n);
            iota(parent.begin(), parent.end(), 0);
            rank.resize(n, 0);
        }
        int Find(const int n)
        {
            if (parent[n] == n)
                return n;
            return parent[n] = Find(parent[n]);
        }
        void Union(const int a, const int b)
        {
            const int aRoot = Find(a), bRoot = Find(b);
            if (aRoot == bRoot)
                return;
            if (rank[aRoot] > rank[bRoot])
                parent[bRoot] = aRoot;
            else if (rank[aRoot] < rank[bRoot])
                parent[aRoot] = bRoot;
            else
            {
                parent[aRoot] = bRoot;
                ++rank[bRoot];
            }
        }
    };

public:
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        DSU dsu(n);
        for (const vector<int> &edge : edges)
            dsu.Union(edge[0], edge[1]);
        return dsu.Find(source) == dsu.Find(destination);
    }
};

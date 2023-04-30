class Solution
{
private:
    class DSU
    {
    private:
        vector<int> root, rank;
        int size;

    public:
        DSU(const int size)
        {
            root.resize(size);
            iota(root.begin(), root.end(), 0);
            rank.resize(size, 0);
            this->size = size;
        }
        int Find(const int index)
        {
            if (index != root[index])
                root[index] = Find(root[index]);
            return root[index];
        }
        bool Union(const int a, const int b)
        {
            const int aRoot = Find(a), bRoot = Find(b);
            if (aRoot == bRoot)
                return false;
            if (rank[aRoot] < rank[bRoot])
                root[aRoot] = bRoot;
            else
            {
                root[bRoot] = aRoot;
                if (rank[aRoot] == rank[bRoot])
                    ++rank[aRoot];
            }
            --size;
            return true;
        }
        bool fullyTraversable()
        {
            return size == 1;
        }
    };

public:
    int maxNumEdgesToRemove(int n, vector<vector<int>> &edges)
    {
        vector<pair<int, int>> type1{}, type2{}, type3{};
        for (const vector<int> &edge : edges)
        {
            const int type = edge[0], u = edge[1] - 1, v = edge[2] - 1; // nodes were 1-indexed
            if (type == 1)
                type1.emplace_back(u, v);
            else if (type == 2)
                type2.emplace_back(u, v);
            else
                type3.emplace_back(u, v);
        }
        DSU alice(n), bob(n);
        int edgeCount = 0;
        for (const pair<int, int> &edge : type3)
            if (alice.Union(edge.first, edge.second) | bob.Union(edge.first, edge.second)) // don't use || here
                ++edgeCount;
        for (const pair<int, int> &edge : type1)
            if (alice.Union(edge.first, edge.second))
                ++edgeCount;
        for (const pair<int, int> &edge : type2)
            if (bob.Union(edge.first, edge.second))
                ++edgeCount;
        return alice.fullyTraversable() && bob.fullyTraversable() ? edges.size() - edgeCount : -1;
    }
};

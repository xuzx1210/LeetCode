class Solution
{
private:
    class DSU
    {
    private:
        vector<int> parent;
        vector<int> height;

    public:
        DSU(const int size)
        {
            parent.resize(size);
            iota(parent.begin(), parent.end(), 0);
            height.resize(size, 0);
        }
        int find(const int index)
        {
            if (parent[index] == index)
                return index;
            return parent[index] = find(parent[index]);
        }
        bool join(const int a, const int b)
        {
            const int aRoot = find(a), bRoot = find(b);
            if (aRoot == bRoot)
                return false;
            if (height[aRoot] < height[bRoot])
                parent[aRoot] = bRoot;
            else
                parent[bRoot] = aRoot;
            if (height[aRoot] == height[bRoot])
                ++height[aRoot];
            return true;
        }
    };

public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        int result = 0;
        const int size = points.size();
        vector<pair<int, pair<int, int>>> edges{};
        for (int i = 0; i < size; ++i)
            for (int j = i + 1; j < size; ++j)
                edges.push_back({abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]), {i, j}});
        sort(edges.begin(), edges.end());
        DSU dsu(size);
        for (const auto &edge : edges)
            if (dsu.join(edge.second.first, edge.second.second))
                result += edge.first;
        return result;
    }
};

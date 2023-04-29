class Solution
{
private:
    class DSU
    {
    private:
        vector<int> root, rank;

    public:
        DSU(int size)
        {
            root.resize(size);
            iota(root.begin(), root.end(), 0);
            rank.resize(size, 0);
        }
        int Find(const int index)
        {
            if (root[index] == index)
                return index;
            root[index] = Find(root[index]);
            return root[index];
        }
        void Union(const int a, const int b)
        {
            const int aRoot = Find(a), bRoot = Find(b);
            if (aRoot == bRoot)
                return;
            if (rank[aRoot] < rank[bRoot])
            {
                root[aRoot] = bRoot;
                rank[bRoot] = max(rank[bRoot], rank[aRoot] + 1);
            }
            else
            {
                root[bRoot] = aRoot;
                rank[aRoot] = max(rank[aRoot], rank[bRoot] + 1);
            }
        }
    };

public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>> &edgeList, vector<vector<int>> &queries)
    {
        DSU dsu(n);
        const int edgeListSize = edgeList.size(), queriesSize = queries.size();
        for (int i = 0; i < queriesSize; ++i)
            queries[i].emplace_back(i);
        auto compare = [](const vector<int> &a, const vector<int> &b)
        {
            return a[2] < b[2];
        };
        sort(queries.begin(), queries.end(), compare);
        sort(edgeList.begin(), edgeList.end(), compare);
        vector<bool> result(queriesSize);
        int index = 0;
        for (const vector<int> &query : queries)
        {
            while (index < edgeListSize && edgeList[index][2] < query[2])
            {
                dsu.Union(edgeList[index][0], edgeList[index][1]);
                ++index;
            }
            result[query.back()] = dsu.Find(query[0]) == dsu.Find(query[1]);
        }
        return result;
    }
};

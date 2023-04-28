class Solution
{
private:
    class DisjointSet
    {
    private:
        vector<int> root;
        int size;

    public:
        DisjointSet(const int size)
        {
            root.resize(size);
            iota(root.begin(), root.end(), 0);
            this->size = size;
        }
        int find(const int index)
        {
            if (root[index] != index)
                root[index] = find(root[index]);
            return root[index];
        }
        void unionFind(const int a, const int b)
        {
            const int aRoot = find(a), bRoot = find(b);
            if (aRoot == bRoot)
                return;
            root[aRoot] = bRoot;
            --size;
        }
        int groups()
        {
            return size;
        }
    };
    bool similar(string &a, string &b)
    {
        int diff = 0;
        for (int i = a.length() - 1; i >= 0; --i)
            if (a[i] != b[i] && ++diff > 2)
                return false;
        return true;
    }

public:
    int numSimilarGroups(vector<string> &strs)
    {
        const int size = strs.size();
        DisjointSet disjointSet(size);
        for (int i = 0; i < size; ++i)
            for (int j = i + 1; j < size; ++j)
                if (similar(strs[i], strs[j]))
                    disjointSet.unionFind(i, j);
        return disjointSet.groups();
    }
};

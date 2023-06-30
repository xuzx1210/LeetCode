class Solution
{
    class DSU
    {
    private:
        vector<int> parent, rank;
        int Find(const int index)
        {
            if (index == parent[index])
                return index;
            parent[index] = Find(parent[index]);
            return parent[index];
        }

    public:
        DSU() {}
        DSU(const int size)
        {
            parent.resize(size);
            iota(parent.begin(), parent.end(), 0);
            rank.resize(size, 0);
        }
        void Union(const int a, const int b)
        {
            const int aRoot = Find(a), bRoot = Find(b);
            if (aRoot == bRoot)
                return;
            if (rank[aRoot] < rank[bRoot])
                parent[aRoot] = bRoot;
            else if (rank[aRoot] > rank[bRoot])
                parent[bRoot] = aRoot;
            else
            {
                parent[aRoot] = bRoot;
                ++rank[bRoot];
            }
        }
        bool connected(const int a, const int b)
        {
            return Find(a) == Find(b);
        }
    };
    int row, col;
    DSU dsu;
    vector<vector<bool>> matrix;
    void connect(const int ar, const int ac, const int br, const int bc)
    {
        if (br < 0 || row <= br || bc < 0 || col <= bc || matrix[br][bc])
            return;
        dsu.Union(ar * col + ac, br * col + bc);
    }

public:
    int latestDayToCross(int row, int col, vector<vector<int>> &cells)
    {
        this->row = row;
        this->col = col;
        const int size = cells.size();
        dsu = DSU(size + 2); // size for top, size+1 for bottom
        for (int c = 0; c < col; ++c)
        {
            dsu.Union(c, size);
            dsu.Union(size - col + c, size + 1);
        }
        matrix.resize(row, vector<bool>(col, true));
        for (int latestDay = size - 1; latestDay >= 0; --latestDay)
        {
            if (dsu.connected(size, size + 1))
                return latestDay + 1;
            const vector<int> &cell = cells[latestDay];
            const int r = cell[0] - 1, c = cell[1] - 1;
            matrix[r][c] = false;
            connect(r, c, r - 1, c);
            connect(r, c, r, c - 1);
            connect(r, c, r, c + 1);
            connect(r, c, r + 1, c);
        }
        return 0;
    }
};

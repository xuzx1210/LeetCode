class Solution
{
public:
    double champagneTower(int poured, int query_row, int query_glass)
    {
        vector<vector<double>> glass(query_row + 2, vector<double>(query_row + 2, 0.0));
        glass[0][0] = poured;
        for (int i = 0; i <= query_row; ++i)
            for (int j = 0; j <= i; ++j)
                if (glass[i][j] > 1.0)
                {
                    double flow = (glass[i][j] - 1.0) / 2.0;
                    glass[i + 1][j] += flow;
                    glass[i + 1][j + 1] += flow;
                    glass[i][j] = 1.0;
                }
        return min(1.0, glass[query_row][query_glass]);
    }
};

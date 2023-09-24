class Solution
{
public:
    double champagneTower(int poured, int query_row, int query_glass)
    {
        vector<vector<double>> volume(query_row + 2, vector<double>(query_row + 2, 0.0));
        volume[0][0] = poured;
        for (int row = 0; row <= query_row; ++row)
            for (int glass = 0; glass <= row; ++glass)
                if (1.0 < volume[row][glass])
                {
                    const double flow = (volume[row][glass] - 1.0) / 2;
                    volume[row + 1][glass] += flow;
                    volume[row + 1][glass + 1] += flow;
                    volume[row][glass] = 1.0;
                }
        return min(1.0, volume[query_row][query_glass]);
    }
};

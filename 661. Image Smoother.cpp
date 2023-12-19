class Solution
{
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &img)
    {
        const int m = img.size(), n = img.front().size();
        vector<vector<int>> result(m, vector<int>(n));
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
            {
                int sum = 0, counter = 0;
                for (int dx = -1; dx <= 1; ++dx)
                    for (int dy = -1; dy <= 1; ++dy)
                    {
                        const int x = i + dx, y = j + dy;
                        if (x < 0 || m <= x || y < 0 || n <= y)
                            continue;
                        ++counter;
                        sum += img[x][y];
                    }
                result[i][j] = sum / counter;
            }
        return result;
    }
};

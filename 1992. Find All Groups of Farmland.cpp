class Solution
{
public:
    vector<vector<int>> findFarmland(vector<vector<int>> &land)
    {
        vector<vector<int>> result{};
        const int m = land.size(), n = land.front().size();
        for (int beginX = 0; beginX < m; ++beginX)
            for (int beginY = 0; beginY < n; ++beginY)
            {
                if (!land[beginX][beginY])
                    continue;
                int endX = beginX;
                while (endX < m && land[endX][beginY])
                    ++endX;
                int endY = beginY;
                while (endY < n && land[beginX][endY])
                    ++endY;
                for (int i = beginX; i < endX; ++i)
                    for (int j = beginY; j < endY; ++j)
                        land[i][j] = 0;
                result.push_back({beginX, beginY, endX - 1, endY - 1});
            }
        return result;
    }
};

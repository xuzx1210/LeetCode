class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> pathCount(m, vector<int>(n, 1));
        if (obstacleGrid[0][0] || obstacleGrid.back().back())
            return 0;
        for (int i = 1; i < m; ++i)
            pathCount[i][0] = (pathCount[i - 1][0] && !obstacleGrid[i][0]);
        for (int i = 1; i < n; ++i)
            pathCount[0][i] = (pathCount[0][i - 1] && !obstacleGrid[0][i]);
        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j)
                pathCount[i][j] = obstacleGrid[i][j] ? 0 : (pathCount[i - 1][j] + pathCount[i][j - 1]);
        return pathCount.back().back();
    }
};

class Solution
{
public:
    int calculateMinimumHP(vector<vector<int>> &dungeon)
    {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> require(m, vector<int>(n, 1));
        require[m - 1][n - 1] -= dungeon[m - 1][n - 1];
        require[m - 1][n - 1] = max(require[m - 1][n - 1], 1);
        for (int i = m - 2; i >= 0; --i)
            require[i][n - 1] = max(require[i + 1][n - 1] - dungeon[i][n - 1], 1);
        for (int j = n - 2; j >= 0; --j)
            require[m - 1][j] = max(require[m - 1][j + 1] - dungeon[m - 1][j], 1);
        for (int i = m - 2; i >= 0; --i)
            for (int j = n - 2; j >= 0; --j)
                require[i][j] = max(min(require[i + 1][j], require[i][j + 1]) - dungeon[i][j], 1);
        return require[0][0];
    }
};

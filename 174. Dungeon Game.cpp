class Solution
{
public:
    int calculateMinimumHP(vector<vector<int>> &dungeon)
    {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> require(m + 1, vector<int>(n + 1, INT_MAX));
        require[m][n - 1] = require[m - 1][n] = 1;
        for (int i = m - 1; i >= 0; --i)
            for (int j = n - 1; j >= 0; --j)
                require[i][j] = max(min(require[i + 1][j], require[i][j + 1]) - dungeon[i][j], 1);
        return require[0][0];
    }
};

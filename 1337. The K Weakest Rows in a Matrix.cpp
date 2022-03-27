class Solution
{
public:
    static bool compare(pair<int, int> &a, pair<int, int> &b)
    {
        return a.second < b.second || a.second == b.second && a.first < b.first;
    }
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        int m = mat.size(), n = mat[0].size();
        vector<pair<int, int>> table(m, {0, 0});
        for (int i = 0; i < m; ++i)
        {
            bool found = false;
            for (int j = 0; j < n; ++j)
                if (mat[i][j] != 1)
                {
                    table[i] = {i, j};
                    found = true;
                    break;
                }
            if (!found)
                table[i] = {i, n};
        }
        sort(table.begin(), table.end(), compare);
        vector<int> result(k, 0);
        for (int i = 0; i < k; ++i)
            result[i] = table[i].first;
        return result;
    }
};

class Solution
{
public:
    double knightProbability(int n, int k, int row, int column)
    {
        const vector<pair<int, int>> directions{{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
        vector<vector<double>> probabilities(n, vector<double>(n, 0.0));
        probabilities[row][column] = 1.0;
        for (int move = 0; move < k; ++move)
        {
            vector<vector<double>> temp(n, vector<double>(n, 0.0));
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                {
                    const double probability = probabilities[i][j] / 8;
                    for (const pair<int, int> direction : directions)
                    {
                        const int x = i + direction.first, y = j + direction.second;
                        if (x < 0 || n <= x || y < 0 || n <= y)
                            continue;
                        temp[x][y] += probability;
                    }
                }
            probabilities.swap(temp);
        }
        double result = 0.0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                result += probabilities[i][j];
        return result;
    }
};

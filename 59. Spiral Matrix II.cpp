class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> result(n, vector<int>(n));
        int num = 1;
        const int half = n >> 1;
        for (int i = 0; i < half; ++i)
        {
            int back = n - 1 - i;
            int length = back - i;
            for (int j = i; j < back; ++j)
                result[i][j] = num++;
            for (int j = i; j < back; ++j)
                result[j][back] = num++;
            for (int j = back; j > i; --j)
                result[back][j] = num++;
            for (int j = back; j > i; --j)
                result[j][i] = num++;
        }
        if (n & 1)
            result[half][half] = num;
        return result;
    }
};

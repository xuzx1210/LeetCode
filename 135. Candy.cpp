class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        const int n = ratings.size();
        int result = n;
        int up = 0, down = 0, peak = 0;
        for (int i = 1; i < n; ++i)
            if (ratings[i - 1] < ratings[i])
            {
                down = 0;
                peak = ++up;
                result += up;
            }
            else if (ratings[i - 1] > ratings[i])
            {
                up = 0;
                result += down + (down >= peak);
                ++down;
            }
            else
                peak = up = down = 0;
        return result;
    }
};

class Solution
{
public:
    int strangePrinter(string s)
    {
        string str{};
        char prev = ' ';
        for (const char c : s)
            if (c != prev)
            {
                str.push_back(prev);
                prev = c;
            }
        str.erase(0, 1);
        str.push_back(prev);
        const int length = str.length();
        vector<vector<int>> dp(length, vector<int>(length, INT_MAX));
        for (int i = 0; i < length; ++i)
            dp[i][i] = 1;
        for (int len = 2; len <= length; ++len)
            for (int front = 0, back = len - 1; back < length; ++front, ++back)
            {
                for (int cut = front; cut < back; ++cut)
                    dp[front][back] = min(dp[front][back], dp[front][cut] + dp[cut + 1][back]);
                if (str[front] == str[back])
                    --dp[front][back];
            }
        return dp[0][length - 1];
    }
};

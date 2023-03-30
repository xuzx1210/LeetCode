class Solution
{
public:
    bool isScramble(string s1, string s2)
    {
        const int length = s1.length();
        array<int, 26> counter = {0};
        for (int i = 0; i < length; ++i)
        {
            ++counter[s1[i] - 'a'];
            --counter[s2[i] - 'a'];
        }
        for (int i = 0; i < 26; ++i)
            if (counter[i])
                return false;
        vector<vector<vector<bool>>> dp(length + 1, vector<vector<bool>>(length, vector<bool>(length, false)));
        // dimension 0: length of string, range: 1<=len<=length
        // dimension 1: begin index of s1, range: 0<=i<length
        // dimension 2: begin index of s2, range: 0<=j<length
        for (int i = 0; i < length; ++i)
            for (int j = 0; j < length; ++j)
                dp[1][i][j] = s1[i] == s2[j];
        for (int len = 2; len <= length; ++len)
            for (int i = 0; i + len <= length; ++i)
                for (int j = 0; j + len <= length; ++j)
                    for (int left = 1, right = len - 1; left < len; ++left, --right)
                        if (dp[left][i][j] && dp[right][i + left][j + left] || dp[left][i][j + right] && dp[right][i + left][j])
                        { // xy or yx
                            dp[len][i][j] = true;
                            break;
                        }
        return dp[length][0][0];
    }
};

class Solution
{
public:
    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        size_t size1 = nums1.size(), size2 = nums2.size();
        vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1, 0));
        int length = 0;
        for (size_t i = 0; i < size1; ++i)
            for (size_t j = 0; j < size2; ++j)
                if (nums1[i] == nums2[j])
                {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                    length = max(length, dp[i + 1][j + 1]);
                }
        return length;
    }
};

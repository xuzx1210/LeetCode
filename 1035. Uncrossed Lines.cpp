class Solution
{
public:
    int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.size() > nums2.size())
            nums1.swap(nums2);
        const int size1 = nums1.size(), size2 = nums2.size();
        vector<int> dp(size1 + 1, 0);
        for (int j = 0; j < size2; ++j)
            for (int i = 0, pre = 0; i < size1; ++i)
            {
                int cur = dp[i + 1];
                dp[i + 1] = nums1[i] == nums2[j] ? pre + 1 : max(cur, dp[i]);
                pre = cur;
            }
        return dp.back();
    }
};

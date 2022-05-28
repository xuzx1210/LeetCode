class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        vector<bool> exist(n + 1, false);
        for (int num : nums)
            exist[num] = true;
        for (int i = 0; i < n; ++i)
            if (!exist[i])
                return i;
        return n;
    }
};

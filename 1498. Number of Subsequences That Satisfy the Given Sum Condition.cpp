class Solution
{
public:
    int numSubseq(vector<int> &nums, int target)
    {
        const int size = nums.size(), mod = 1000000007;
        sort(nums.begin(), nums.end());
        vector<int> powerOf2(size);
        powerOf2[0] = 1;
        for (int i = 1; i < size; ++i)
            powerOf2[i] = (powerOf2[i - 1] << 1) % mod;
        int result = 0, left = 0, right = size - 1;
        while (left <= right)
            if (target < nums[left] + nums[right])
                --right;
            else
                result = (result + powerOf2[right - left++]) % mod;
        return result;
    }
};

class Solution
{
public:
    int minMoves2(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int middle = nums[nums.size() >> 1];
        int result = 0;
        for (int num : nums)
            result += abs(num - middle);
        return result;
    }
};

class Solution
{
public:
    long long minimumReplacement(vector<int> &nums)
    {
        long long result = 0;
        for (int i = nums.size() - 2; i >= 0; --i)
        {
            const div_t d = div(nums[i], nums[i + 1]);
            const int groups = d.quot + (d.rem > 0);
            result += groups - 1;
            nums[i] /= groups;
        }
        return result;
    }
};

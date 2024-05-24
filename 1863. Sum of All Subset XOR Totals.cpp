class Solution
{
public:
    int subsetXORSum(vector<int> &nums)
    {
        return accumulate(nums.begin(), nums.end(), 0, bit_or<int>()) << (nums.size() - 1);
    }
};

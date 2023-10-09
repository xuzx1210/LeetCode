class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int>::iterator it = lower_bound(nums.begin(), nums.end(), target);
        if (it == nums.end() || *it != target)
            return {-1, -1};
        return {(int)distance(nums.begin(), it), (int)distance(nums.begin(), upper_bound(nums.begin(), nums.end(), target)) - 1};
    }
};

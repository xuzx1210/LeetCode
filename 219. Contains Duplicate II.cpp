class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_set<int> us;
        size_t size = nums.size();
        for (size_t i = 0; i < size; ++i)
        {
            int cur = nums[i];
            if (us.find(cur) != us.end())
                return true;
            us.insert(cur);
            if (i >= k)
                us.erase(nums[i - k]);
        }
        return false;
    }
};

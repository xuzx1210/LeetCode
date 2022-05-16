class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> hashmap = {};
        for (size_t i = 0; i < nums.size(); ++i)
        {
            if (hashmap[nums[i]] == 0)
                hashmap[nums[i]] = i + 1;
            else if (i - hashmap[nums[i]] < k)
                return true;
            else
                hashmap[nums[i]] = i + 1;
        }
        return false;
    }
};

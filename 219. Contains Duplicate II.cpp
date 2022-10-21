class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> last;
        for (size_t i = 0; i < nums.size(); ++i)
        {
            if (!last[nums[i]])
                last[nums[i]] = i + 1;
            else if (i - last[nums[i]] < k)
                return true;
            else
                last[nums[i]] = i + 1;
        }
        return false;
    }
};

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_map<int, bool> um = {};
        for (int num : nums)
        {
            if (um[num])
                return true;
            um[num] = true;
        }
        return false;
    }
};

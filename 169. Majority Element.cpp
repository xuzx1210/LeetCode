class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> um;
        um.clear();
        for (int i = 0; i < nums.size(); ++i)
            um[nums[i]] = 0;
        for (int i = 0; i < nums.size(); ++i)
            ++um[nums[i]];
        int threshold = nums.size() >> 1;
        for (auto it = um.begin(); it != um.end(); ++it)
            if (it->second > threshold)
                return it->first;
        return 0;
    }
};

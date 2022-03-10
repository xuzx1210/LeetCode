class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        unordered_map<int, int> counts({});
        for (auto num : nums)
            ++counts[num];
        for (auto count : counts)
            if (count.second == 1)
                return count.first;
        return 0;
    }
};

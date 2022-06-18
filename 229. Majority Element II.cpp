class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> table = {};
        for (int num : nums)
            ++table[num];
        int threshold = nums.size() / 3;
        vector<int> result = {};
        for (auto entry : table)
            if (entry.second > threshold)
                result.push_back(entry.first);
        return result;
    }
};

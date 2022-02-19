class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> hash;
        hash.clear();
        int size = nums.size();
        for (int i = 0; i < size; ++i)
            hash[nums[i]] = i;
        for (int i = 0; i < size; ++i)
        {
            unordered_map<int, int>::iterator it = hash.find(target - nums[i]);
            if (it != hash.end())
                if (it->second != i)
                {
                    vector<int> result;
                    result.clear();
                    result.push_back(i);
                    result.push_back(it->second);
                    return result;
                }
        }
        return vector<int>();
    }
};

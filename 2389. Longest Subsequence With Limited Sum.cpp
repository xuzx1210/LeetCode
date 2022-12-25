class Solution
{
public:
    vector<int> answerQueries(vector<int> &nums, vector<int> &queries)
    {
        nums.emplace_back(0);
        sort(nums.begin(), nums.end());
        const size_t numsSize = nums.size(), queriesSize = queries.size();
        for (size_t i = 1; i < numsSize; ++i)
            nums[i] += nums[i - 1];
        vector<int> result(queriesSize);
        for (size_t i = 0; i < queriesSize; ++i)
            result[i] = upper_bound(nums.begin(), nums.end(), queries[i]) - nums.begin() - 1;
        return result;
    }
};

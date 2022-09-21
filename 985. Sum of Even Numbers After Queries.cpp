class Solution
{
public:
    vector<int> sumEvenAfterQueries(vector<int> &nums, vector<vector<int>> &queries)
    {
        int size = nums.size();
        vector<int> result(size);
        int sum = 0;
        for (int &num : nums)
            if (!(num & 1))
                sum += num;
        for (int i = 0; i < size; ++i)
        {
            int value = queries[i][0], key = queries[i][1];
            if (!(nums[key] & 1))
                sum -= nums[key];
            nums[key] += value;
            if (!(nums[key] & 1))
                sum += nums[key];
            result[i] = sum;
        }
        return result;
    }
};

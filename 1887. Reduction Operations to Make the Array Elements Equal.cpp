class Solution
{
public:
    int reductionOperations(vector<int> &nums)
    {
        int result = 0;
        vector<int> counter(50001, 0);
        for (const int num : nums)
            ++counter[num];
        const int minimum = *min_element(nums.begin(), nums.end()), maximum = *max_element(nums.begin(), nums.end());
        for (int i = maximum, sum = 0; i > minimum; --i)
            if (counter[i])
            {
                sum += counter[i];
                result += sum;
            }
        return result;
    }
};

class Solution
{
public:
    int reductionOperations(vector<int> &nums)
    {
        int result = 0;
        sort(nums.rbegin(), nums.rend());
        const int size = nums.size();
        for (int i = 0, prev = 0; i < nums.size(); ++i)
            if (nums[i] != prev)
            {
                prev = nums[i];
                result += i;
            }
        return result;
    }
};

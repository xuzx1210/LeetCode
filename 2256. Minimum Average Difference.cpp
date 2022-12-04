class Solution
{
public:
    int minimumAverageDifference(vector<int> &nums)
    {
        const size_t size = nums.size();
        long long leftSum = 0, rightSum = accumulate(nums.begin(), nums.end(), (long long)0);
        pair<size_t, int> result(0, INT_MAX);
        for (size_t i = 0; i < size; ++i)
        {
            leftSum += nums[i];
            rightSum -= nums[i];
            const int leftAverage = leftSum / (i + 1), rightAverage = i + 1 == size ? 0 : rightSum / (size - i - 1);
            int difference = leftAverage - rightAverage;
            if (difference < 0)
                difference = -difference;
            if (difference < result.second)
                result = {i, difference};
        }
        return result.first;
    }
};

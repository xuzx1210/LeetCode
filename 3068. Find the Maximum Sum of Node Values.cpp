// branch
class Solution
{
public:
    long long maximumValueSum(vector<int> &nums, int k, vector<vector<int>> &edges)
    {
        long long result = accumulate(nums.begin(), nums.end(), 0LL);
        int minAbsDiff = numeric_limits<int>::max();
        bool odd = false;
        for (const int num : nums)
        {
            const int diff = (num ^ k) - num;
            if (0 < diff)
            {
                result += diff;
                odd = !odd;
            }
            minAbsDiff = min(minAbsDiff, abs(diff));
        }
        if (odd)
            result -= minAbsDiff;
        return result;
    }
};

//branchless
class Solution
{
public:
    long long maximumValueSum(vector<int> &nums, int k, vector<vector<int>> &edges)
    {
        long long result = accumulate(nums.begin(), nums.end(), 0LL);
        int minAbsDiff = numeric_limits<int>::max();
        bool odd = false;
        for (const int num : nums)
        {
            int diff = (num ^ k) - num;
            const bool positive = (0 < diff);
            result += positive * diff;
            odd = odd != positive;
            diff = positive * diff - !positive * diff;
            const bool less = (diff < minAbsDiff);
            minAbsDiff = less * diff + !less * minAbsDiff;
        }
        result -= odd * minAbsDiff;
        return result;
    }
};

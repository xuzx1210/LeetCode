class Solution
{
private:
    int n;
    long long getCost(const int middle, const vector<int> &nums, const vector<int> &cost)
    {
        long long result = 0;
        for (int i = 0; i < n; ++i)
            result += (long long)cost[i] * abs(nums[i] - middle);
        return result;
    }

public:
    long long minCost(vector<int> &nums, vector<int> &cost)
    {
        n = nums.size();
        int left = 1, right = 1000000;
        long long result = LONG_LONG_MAX;
        while (left < right)
        {
            const int middle = (left + right) >> 1;
            const long long leftCost = getCost(middle, nums, cost), rightCost = getCost(middle + 1, nums, cost);
            result = min(leftCost, rightCost);
            if (leftCost < rightCost)
                right = middle;
            else
                left = middle + 1;
        }
        return result;
    }
};

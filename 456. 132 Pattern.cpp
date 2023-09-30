class Solution
{
public:
    bool find132pattern(vector<int> &nums)
    {
        int numsK = INT_MIN;
        stack<int> monotonic{};
        for (int i = nums.size() - 1; i >= 0; --i)
        {
            if (nums[i] < numsK)
                return true;
            while (!monotonic.empty() && monotonic.top() < nums[i])
            {
                numsK = monotonic.top();
                monotonic.pop();
            }
            monotonic.emplace(nums[i]);
        }
        return false;
    }
};

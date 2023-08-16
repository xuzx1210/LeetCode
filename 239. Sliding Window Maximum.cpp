class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        const int size = nums.size();
        vector<int> result{};
        deque<int> dq{};
        for (int i = 0; i < k - 1; ++i)
        {
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            dq.emplace_back(i);
        }
        for (int i = k - 1; i < size; ++i)
        {
            if (!dq.empty() && dq.front() == i - k)
                dq.pop_front();
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            dq.emplace_back(i);
            result.emplace_back(nums[dq.front()]);
        }
        return result;
    }
};

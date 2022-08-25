class Solution
{
private:
    template <class T>
    class MonotonicQueue
    {
    private:
        deque<T> dq;

    public:
        MonotonicQueue()
        {
            dq.clear();
        }
        void push(T value)
        {
            while (!dq.empty())
                if (dq.back() < value)
                    dq.pop_back();
                else
                    break;
            dq.push_back(value);
        }
        void pop()
        {
            dq.pop_front();
        }
        T max()
        {
            return dq.front();
        }
    };

public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        MonotonicQueue<int> mq;
        for (int i = 0; i < k - 1; ++i)
            mq.push(nums[i]);
        vector<int> result = {};
        int size = nums.size();
        for (int i = k - 1; i < size; ++i)
        {
            mq.push(nums[i]);
            int maximum = mq.max();
            result.emplace_back(maximum);
            if (nums[i - k + 1] == maximum)
                mq.pop();
        }
        return result;
    }
};

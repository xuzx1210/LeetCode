class Solution
{
public:
    int minimumDeviation(vector<int> &nums)
    {
        priority_queue<int> pq{};
        int minimum = INT_MAX;
        for (int num : nums)
        {
            if (num & 1)
                num <<= 1;
            minimum = min(minimum, num);
            pq.emplace(num);
        }
        int result = pq.top() - minimum;
        while (!(pq.top() & 1))
        {
            const int cur = pq.top() >> 1;
            pq.emplace(cur);
            pq.pop();
            minimum = min(minimum, cur);
            result = min(result, pq.top() - minimum);
        }
        return result;
    }
};

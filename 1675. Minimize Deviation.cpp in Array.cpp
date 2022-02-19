class Solution
{
public:
    int minimumDeviation(vector<int> &nums)
    {
        priority_queue<int> pq;
        while (!pq.empty())
            pq.pop();
        int m = INT_MAX;
        for (auto num : nums)
        {
            if (num & 1)
                num <<= 1;
            m = min(m, num);
            pq.push(num);
        }
        int result = pq.top() - m;
        while (!(pq.top() & 1))
        {
            int M = pq.top() >> 1;
            pq.pop();
            pq.push(M);
            m = min(m, M);
            result = min(result, pq.top() - m);
        }
        return result;
    }
};

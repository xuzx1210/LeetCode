class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> pq(stones.begin(), stones.end());
        while (pq.size() > 1)
        {
            const int y = pq.top();
            pq.pop();
            const int x = pq.top();
            pq.pop();
            const int diff = y - x;
            if (diff)
                pq.emplace(diff);
        }
        return pq.empty() ? 0 : pq.top();
    }
};

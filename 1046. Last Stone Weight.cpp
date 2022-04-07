class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> pq(stones.begin(), stones.end());
        while (pq.size() > 1)
        {
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();
            int diff = y - x;
            if (diff)
                pq.push(diff);
        }
        return pq.empty() ? 0 : pq.top();
    }
};

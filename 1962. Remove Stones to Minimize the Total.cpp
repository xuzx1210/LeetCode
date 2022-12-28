class Solution
{
public:
    int minStoneSum(vector<int> &piles, int k)
    {
        priority_queue<int> pq(piles.begin(), piles.end());
        const int sum = accumulate(piles.begin(), piles.end(), 0);
        int totalRemoved = 0;
        while (k--)
        {
            const int stones = pq.top();
            pq.pop();
            const int removed = stones >> 1;
            totalRemoved += removed;
            pq.emplace(stones - removed);
        }
        return sum - totalRemoved;
    }
};

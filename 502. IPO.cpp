class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {
        const int n = profits.size();
        priority_queue<int> maxHeap{};
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap{};
        for (int i = 0; i < n; ++i)
            minHeap.emplace(capital[i], profits[i]);
        for (int i = 0; i < k; ++i)
        {
            while (!minHeap.empty())
                if (minHeap.top().first <= w)
                {
                    maxHeap.emplace(minHeap.top().second);
                    minHeap.pop();
                }
                else
                    break;
            if (maxHeap.empty())
                break;
            w += maxHeap.top();
            maxHeap.pop();
        }
        return w;
    }
};

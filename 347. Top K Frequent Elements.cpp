class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> counter{};
        for (int num : nums)
            ++counter[num];
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq{};
        for (const auto &[num, count] : counter)
        {
            pq.emplace(count, num);
            if (pq.size() > k)
                pq.pop();
        }
        vector<int> result{};
        for (; !pq.empty(); pq.pop())
            result.emplace_back(pq.top().second);
        return result;
    }
};

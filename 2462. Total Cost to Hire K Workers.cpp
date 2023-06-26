class Solution
{
public:
    long long totalCost(vector<int> &costs, int k, int candidates)
    {
        const int size = costs.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> workers{};
        int left = candidates, right = max(candidates, size - candidates);
        for (int i = 0; i < left; ++i)
            workers.emplace(costs[i], i);
        for (int i = right; i < size; ++i)
            workers.emplace(costs[i], i);
        long long result = 0;
        for (int i = 0; i < k; ++i)
        {
            const auto [cost, index] = workers.top();
            workers.pop();
            result += cost;
            if (left < right)
                if (index < left)
                    workers.emplace(costs[left], left++);
                else
                    workers.emplace(costs[--right], right);
        }
        return result;
    }
};

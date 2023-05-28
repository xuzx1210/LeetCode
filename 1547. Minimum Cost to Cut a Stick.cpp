class Solution
{
public:
    int minCost(int n, vector<int> &cuts)
    {
        cuts.emplace_back(0);
        cuts.emplace_back(n);
        const int size = cuts.size();
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> cost(size, vector<int>(size, 0));
        for (int length = 3; length <= size; ++length)
            for (int front = 0, back = length - 1; back < size; ++front, ++back)
            {
                int minimum = INT_MAX;
                for (int cut = front + 1; cut < back; ++cut)
                    minimum = min(minimum, cost[front][cut] + cost[cut][back]);
                cost[front][back] = cuts[back] - cuts[front] + minimum;
            }
        return cost.front().back();
    }
};

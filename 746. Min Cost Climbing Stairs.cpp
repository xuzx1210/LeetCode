class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        cost.emplace_back(0);
        const int size = cost.size();
        for (int i = 2; i < size; ++i)
            cost[i] += min(cost[i - 2], cost[i - 1]);
        return cost.back();
    }
};

class Solution
{
public:
    int maxIceCream(vector<int> &costs, int coins)
    {
        sort(costs.begin(), costs.end());
        const size_t n = costs.size();
        for (size_t i = 0; i < n; ++i)
            if ((coins -= costs[i]) < 0)
                return i;
        return n;
    }
};

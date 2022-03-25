class Solution
{
public:
    int twoCitySchedCost(vector<vector<int>> &costs)
    {
        int size = costs.size();
        int half = size >> 1;
        vector<int> bma(size, 0);
        for (int i = 0; i < size; ++i)
            bma[i] = costs[i][1] - costs[i][0];
        int result = 0;
        for (int i = 0; i < size; ++i)
            result += costs[i][0];
        sort(bma.begin(), bma.end());
        for (int i = 0; i < half; ++i)
            result += bma[i];
        return result;
    }
};

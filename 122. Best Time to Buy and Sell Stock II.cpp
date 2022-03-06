class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int result = 0, n = prices.size();
        for (int i = 0; i < n - 1; ++i)
            if (prices[i] < prices[i + 1])
                result += (prices[i + 1] - prices[i]);
        return result;
    }
};

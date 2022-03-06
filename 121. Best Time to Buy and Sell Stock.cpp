class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int m = INT_MAX, result = 0;
        for (int price : prices)
        {
            m = min(m, price);
            int profit = price - m;
            result = max(result, profit);
        }
        return result;
    }
};

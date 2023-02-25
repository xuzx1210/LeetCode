class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int minimum = INT_MAX, profit = 0;
        for (const int price : prices)
        {
            minimum = min(minimum, price);
            profit = max(profit, price - minimum);
        }
        return profit;
    }
};

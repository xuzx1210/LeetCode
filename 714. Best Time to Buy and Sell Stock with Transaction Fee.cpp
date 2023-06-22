class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int hold = -50000, sold = 0;
        for (const int price : prices)
        {
            const int tmp = hold;
            hold = max(hold, sold - price);
            sold = max(sold, tmp + price - fee);
        }
        return sold;
    }
};

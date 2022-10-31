class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int wait = 0, hold = -prices[0], cool = 0, size = prices.size();
        for (int i = 1; i < size; ++i)
        {
            int prevWait = wait;
            wait = max(wait, cool);
            hold = max(prevWait - prices[i], hold);
            cool = hold + prices[i];
        }
        return max(wait, cool);
    }
};

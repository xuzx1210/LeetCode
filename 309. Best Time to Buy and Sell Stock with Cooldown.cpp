class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int idle = 0, hold = INT_MIN, cool = 0;
        for (const int &price : prices)
        {
            int prevCool = cool;
            cool = hold + price;
            hold = max(hold, idle - price);
            idle = max(idle, prevCool);
        }
        return max(idle, cool);
    }
};

class Solution
{
public:
    int buyChoco(vector<int> &prices, int money)
    {
        int first = INT_MAX, second = INT_MAX;
        for (const int price : prices)
        {
            if (price < second)
                second = price;
            if (second < first)
                swap(first, second);
        }
        const int leftover = money - first - second;
        return 0 <= leftover ? leftover : money;
    }
};

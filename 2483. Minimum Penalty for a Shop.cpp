class Solution
{
public:
    int bestClosingTime(string customers)
    {
        int result = -1;
        const int n = customers.size();
        int profit = 0, maximum = 0;
        for (int j = 0; j < n; ++j)
        {
            if (customers[j] == 'Y')
                ++profit;
            else
                --profit;
            if (maximum < profit)
            {
                maximum = profit;
                result = j;
            }
        }
        return result + 1;
    }
};

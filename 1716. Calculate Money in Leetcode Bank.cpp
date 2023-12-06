class Solution
{
public:
    int totalMoney(int n)
    {
        int result = 0;
        const auto [week, day] = div(n, 7);
        result += 28 * week;
        result += 7 * week * (week - 1) >> 1;
        result += week * day;
        result += day * (day + 1) >> 1;
        return result;
    }
};

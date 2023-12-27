class Solution
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {
        int result = accumulate(neededTime.begin(), neededTime.end(), 0), maximum = 0;
        for (int i = colors.length() - 1, start = i; i >= 0; --i)
            if (colors[i] == colors[start])
                maximum = max(maximum, neededTime[i]);
            else
            {
                result -= maximum;
                start = i;
                maximum = neededTime[i];
            }
        return result - maximum;
    }
};

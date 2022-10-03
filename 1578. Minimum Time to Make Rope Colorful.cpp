class Solution
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {
        int result = 0, length = colors.length(), start = 0, maximum = 0;
        for (int i = 0; i < length; result += neededTime[i++])
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

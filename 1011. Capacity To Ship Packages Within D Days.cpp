class Solution
{
private:
    bool feasible(const int capacity, const vector<int> &weights, const int days)
    {
        int daysNeeded = 1, currentLoad = 0;
        for (const int weight : weights)
        {
            if ((currentLoad += weight) <= capacity)
                continue;
            currentLoad = weight;
            if (daysNeeded++ == days)
                return false;
        }
        return true;
    }

public:
    int shipWithinDays(vector<int> &weights, int days)
    {
        int left = 0, right = 0;
        for (const int weight : weights)
        {
            left = max(left, weight);
            right += weight;
        }
        while (left < right)
        {
            const int middle = (left + right) >> 1;
            if (feasible(middle, weights, days))
                right = middle;
            else
                left = middle + 1;
        }
        return left;
    }
};

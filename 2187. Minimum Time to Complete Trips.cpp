class Solution
{
public:
    long long minimumTime(vector<int> &time, int totalTrips)
    {
        long long left = 0, right = LONG_LONG_MAX;
        while (left < right)
        {
            const long long middle = left + ((right - left) >> 1);
            long long trips = 0;
            for (int t : time)
            {
                trips += middle / t;
                if (trips >= totalTrips)
                    break;
            }
            if (trips < totalTrips)
                left = middle + 1;
            else
                right = middle;
        }
        return left;
    }
};

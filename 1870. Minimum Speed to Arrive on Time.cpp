class Solution
{
public:
    int minSpeedOnTime(vector<int> &dist, double hour)
    {
        const int size = dist.size();
        if (hour <= size - 1)
            return -1;
        int left = 1, right = 10000001;
        while (left < right)
        {
            const int speed = (left + right) >> 1;
            int time = 0;
            for (int i = 0; i < size - 1; ++i)
            {
                div_t d = div(dist[i], speed);
                time += d.quot;
                if (d.rem)
                    ++time;
            }
            double lastTime = (double)dist.back() / speed;
            if (hour < time + lastTime)
                left = speed + 1;
            else
                right = speed;
        }
        return left;
    }
};

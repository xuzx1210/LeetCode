class Solution
{
public:
    int numberOfWays(string corridor)
    {
        const int seatsCount = count(corridor.begin(), corridor.end(), 'S');
        if ((seatsCount & 1) == 1 || seatsCount == 0)
            return 0;
        int result = 1;
        const int mod = 1000000007, n = corridor.size();
        for (int i = corridor.find('S') + 1, seats = 1, plants = 0; i < n; ++i)
            if (corridor[i] == 'P')
                ++plants;
            else
            {
                if (seats == 0)
                    result = result * (plants + 1l) % mod;
                seats = !seats;
                plants = 0;
            }
        return result;
    }
};

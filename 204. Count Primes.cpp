class Solution
{
public:
    int countPrimes(int n)
    {
        if (n < 2)
            return 0;
        vector<bool> prime(n, true);
        prime[0] = prime[1] = false;
        for (int i = 2; i * i < n; ++i)
            if (prime[i])
                for (int num = i << 1; num < n; num += i)
                    prime[num] = false;
        return count(prime.begin(), prime.end(), true);
    }
};

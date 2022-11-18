class Solution
{
public:
    bool isUgly(int n)
    {
        if (n < 1)
            return false;
        vector<int> primes{2, 3, 5};
        for (int &prime : primes)
            while (!(n % prime))
                n /= prime;
        return n == 1;
    }
};

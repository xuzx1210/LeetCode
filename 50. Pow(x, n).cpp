class Solution
{
private:
    double binaryPow(double x, long long n)
    {
        if (n == 0)
            return 1.0;
        const double half = myPow(x, n >> 1);
        double result = half * half;
        if (n & 1)
            result *= x;
        return result;
    }

public:
    double myPow(double x, int n)
    {
        long long power = n;
        return power < 0 ? 1.0 / binaryPow(x, -power) : binaryPow(x, power);
    }
};

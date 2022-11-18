class Solution
{
public:
    bool isUgly(int n)
    {
        if (n < 1)
            return false;
        vector<int> factors{2, 3, 5};
        for (int &factor : factors)
            while (!(n % factor))
                n /= factor;
        return n == 1;
    }
};

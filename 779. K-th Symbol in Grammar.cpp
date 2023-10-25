class Solution
{
public:
    int kthGrammar(int n, int k)
    {
        for (n = 0, --k; k; k &= (k - 1))
            ++n;
        return n & 1;
    }
};

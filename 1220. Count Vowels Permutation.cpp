class Solution
{
public:
    int countVowelPermutation(int n)
    {
        long long a = 1, e = 1, i = 1, o = 1, u = 1, mod = 1000000007;
        for (int j = 1; j < n; ++j)
        {
            long long tmpA = a, tmpE = e, tmpI = i, tmpO = o, tmpU = u;
            a = tmpE % mod;
            e = (tmpA + tmpI) % mod;
            i = (tmpA + tmpE + tmpO + tmpU) % mod;
            o = (tmpI + tmpU) % mod;
            u = tmpA % mod;
        }
        return (a + e + i + o + u) % mod;
    }
};

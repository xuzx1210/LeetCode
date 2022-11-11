class Solution
{
public:
    int superPow(int a, vector<int> &b)
    {
        const int mod = 1337, phi = 1140;
        a %= mod;
        int p = 0, result = 1;
        for (int &bi : b)
            p = (p * 10 + bi) % phi;
        if (!p)
            p += phi;
        for (; p; p >>= 1, a = (a * a) % mod)
            if (p & 1)
                result = (result * a) % mod;
        return result;
    }
};

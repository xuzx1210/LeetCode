class Solution
{
public:
    int knightDialer(int n)
    {
        int result = 0;
        if (n == 1)
            return 10;
        const int mod = 1000000007;
        vector<int> pad(10, 1);
        pad[5] = 0;
        while (--n)
        {
            vector<int> tmp(pad);
            pad[0] = (tmp[4] + tmp[6]) % mod;
            pad[1] = (tmp[6] + tmp[8]) % mod;
            pad[2] = (tmp[7] + tmp[9]) % mod;
            pad[3] = (tmp[4] + tmp[8]) % mod;
            pad[4] = ((tmp[3] + tmp[9]) % mod + tmp[0]) % mod;
            pad[6] = ((tmp[1] + tmp[7]) % mod + tmp[0]) % mod;
            pad[7] = (tmp[2] + tmp[6]) % mod;
            pad[8] = (tmp[1] + tmp[3]) % mod;
            pad[9] = (tmp[2] + tmp[4]) % mod;
        }
        for (int i = 0; i < 10; ++i)
            result = (result + pad[i]) % mod;
        return result;
    }
};

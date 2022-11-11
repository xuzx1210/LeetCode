class Solution
{
public:
    int superPow(int a, vector<int> &b)
    {
        a %= 1337;
        int p = 0;
        for (int &bi : b)
            p = (p * 10 + bi) % 1140;
        if (!p)
            p += 1140;
        int result = 1;
        for (; p; p >>= 1)
        {
            if (p & 1)
                result = (result * a) % 1337;
            a = (a * a) % 1337;
        }
        return result;
    }
};

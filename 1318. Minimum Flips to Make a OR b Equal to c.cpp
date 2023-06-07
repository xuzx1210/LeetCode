class Solution
{
public:
    int minFlips(int a, int b, int c)
    {
        int result = 0;
        for (int i = 0; i < 32; ++i)
        {
            switch (((a & 1) << 2) | ((b & 1) << 1) | (c & 1))
            {
            case 6:
                ++result;
            case 1:
            case 2:
            case 4:
                ++result;
            default:
                break;
            }
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        return result;
    }
};

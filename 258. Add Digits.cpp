class Solution
{
public:
    int addDigits(int num)
    {
        while (num > 9)
        {
            int tmp = 0;
            for (; num; num /= 10)
                tmp += (num % 10);
            num = tmp;
        }
        return num;
    }
};

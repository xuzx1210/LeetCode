class Solution
{
public:
    string intToRoman(int num)
    {
        int one = num % 10;
        num /= 10;
        int ten = num % 10;
        num /= 10;
        int hundred = num % 10;
        num /= 10;
        int thousand = num;
        string result;
        result.clear();
        for (int i = 0; i < thousand; ++i)
            result.push_back('M');
        if (hundred < 4)
            for (int i = 0; i < hundred; ++i)
                result.push_back('C');
        else if (hundred == 4)
        {
            result.push_back('C');
            result.push_back('D');
        }
        else if (hundred == 9)
        {
            result.push_back('C');
            result.push_back('M');
        }
        else
        {
            result.push_back('D');
            for (int i = 5; i < hundred; ++i)
                result.push_back('C');
        }
        if (ten < 4)
            for (int i = 0; i < ten; ++i)
                result.push_back('X');
        else if (ten == 4)
        {
            result.push_back('X');
            result.push_back('L');
        }
        else if (ten == 9)
        {
            result.push_back('X');
            result.push_back('C');
        }
        else
        {
            result.push_back('L');
            for (int i = 5; i < ten; ++i)
                result.push_back('X');
        }
        if (one < 4)
            for (int i = 0; i < one; ++i)
                result.push_back('I');
        else if (one == 4)
        {
            result.push_back('I');
            result.push_back('V');
        }
        else if (one == 9)
        {
            result.push_back('I');
            result.push_back('X');
        }
        else
        {
            result.push_back('V');
            for (int i = 5; i < one; ++i)
                result.push_back('I');
        }
        return result;
    }
};

class Solution
{
public:
    int maximum69Number(int num)
    {
        string numString(to_string(num));
        for (char &c : numString)
            if (c == '6')
            {
                c = '9';
                break;
            }
        return stoi(numString);
    }
};

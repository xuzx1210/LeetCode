class Solution
{
public:
    string convertToTitle(int columnNumber)
    {
        int tmp = columnNumber - 1;
        div_t d = div(tmp, 26);
        return columnNumber == 0 ? "" : convertToTitle(d.quot) + (char)(d.rem + 'A');
    }
};

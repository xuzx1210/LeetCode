class Solution
{
public:
    int reverse(int x)
    {
        long long X = x;
        if (X == 0)
            return 0;
        bool negative = false;
        if (X < 0)
        {
            negative = true;
            X = -X;
        }
        stringstream ss;
        ss.clear();
        ss << X;
        string xString;
        ss >> xString;
        std::reverse(xString.begin(), xString.end());
        ss.clear();
        if (negative)
            ss << '-';
        ss << xString;
        long long result;
        ss >> result;
        if (result > INT_MAX || result < INT_MIN)
            return 0;
        return result;
    }
};

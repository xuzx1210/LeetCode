class Solution
{
public:
    string getPermutation(int n, int k)
    {
        int factorial = 1;
        for (int i = 2; i <= n; ++i)
            factorial *= i;
        string str("");
        for (int i = 1; i <= n; ++i)
            str.push_back(i + '0');
        string result("");
        --k;
        for (int i = n; i >= 1; --i)
        {
            factorial /= i;
            int index = k / factorial;
            k %= factorial;
            result.push_back(str[index]);
            str.erase(str.begin() + index);
        }
        return result;
    }
};

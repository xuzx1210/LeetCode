class Solution
{
public:
    void string2vector(string &num, vector<int> &multiply)
    {
        for (int i = 0; i < num.length(); ++i)
            multiply.push_back(num[i] - '0');
        reverse(multiply.begin(), multiply.end());
    }
    void vectorMultiplyNumber(vector<int> &num, const int n)
    {
        int carry = 0;
        for (int i = 0; i < num.size(); ++i)
        {
            int sum = num[i] * n + carry;
            num[i] = sum % 10;
            carry = sum / 10;
        }
        if (carry)
            num.push_back(carry);
    }
    vector<int> vectorAdd(vector<int> &a, vector<int> &b)
    {
        int minLength = min(a.size(), b.size()), carry = 0;
        vector<int> result({});
        for (int i = 0; i < minLength; ++i)
        {
            int sum = a[i] + b[i] + carry;
            result.push_back(sum % 10);
            carry = sum / 10;
        }
        if (a.size() < b.size())
        {
            for (int i = minLength; i < b.size(); ++i)
            {
                int sum = b[i] + carry;
                result.push_back(sum % 10);
                carry = sum / 10;
            }
        }
        else if (a.size() > b.size())
        {
            for (int i = minLength; i < b.size(); ++i)
            {
                int sum = a[i] + carry;
                result.push_back(sum % 10);
                carry = sum / 10;
            }
        }
        if (carry)
            result.push_back(carry);
        return result;
    }
    string multiply(string num1, string num2)
    {
        if (num1 == "0" || num2 == "0")
            return "0";
        vector<int> multiplcand({}), multiplier({});
        string2vector(num1, multiplcand);
        string2vector(num2, multiplier);
        vector<vector<int>> table(8, vector<int>({}));
        for (int i = 2; i <= 9; ++i)
        {
            vector<int> cur(multiplcand);
            vectorMultiplyNumber(cur, i);
            table[i - 2] = cur;
        }
        vector<int> resultVector({});
        for (int i = 0; i < multiplier.size(); ++i)
        {
            if (multiplier[i] == 0)
                continue;
            vector<int> cur({});
            if (multiplier[i] == 1)
                cur = multiplcand;
            else
                cur = table[multiplier[i] - 2];
            cur.insert(cur.begin(), i, 0);
            resultVector = vectorAdd(resultVector, cur);
        }
        string result("");
        for (int i = resultVector.size() - 1; i >= 0; --i)
            result.push_back(resultVector[i] + '0');
        return result;
    }
};

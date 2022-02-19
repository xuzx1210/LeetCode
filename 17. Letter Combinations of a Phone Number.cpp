class Solution
{
public:
    vector<vector<char>> phone;
    vector<string> result;
    string cur;
    void dfs(string &digits, int index)
    {
        if (index == digits.length())
        {
            result.push_back(cur);
            return;
        }
        int digit = digits[index] - '2';
        for (int i = 0; i < phone[digit].size(); ++i)
        {
            cur.push_back(phone[digit][i]);
            dfs(digits, index + 1);
            cur.pop_back();
        }
    }
    vector<string> letterCombinations(string digits)
    {
        if (digits == "")
            return vector<string>();
        phone.clear();
        phone.push_back({'a', 'b', 'c'});
        phone.push_back({'d', 'e', 'f'});
        phone.push_back({'g', 'h', 'i'});
        phone.push_back({'j', 'k', 'l'});
        phone.push_back({'m', 'n', 'o'});
        phone.push_back({'p', 'q', 'r', 's'});
        phone.push_back({'t', 'u', 'v'});
        phone.push_back({'w', 'x', 'y', 'z'});
        result.clear();
        cur.clear();
        dfs(digits, 0);
        return result;
    }
};

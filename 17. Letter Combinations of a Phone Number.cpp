class Solution
{
private:
    vector<string> result, phone;
    string cur;
    vector<size_t> digits;
    size_t size;
    void dfs(size_t index)
    {
        if (index == size)
        {
            result.push_back(cur);
            return;
        }
        for (char c : phone[digits[index]])
        {
            cur.push_back(c);
            dfs(index + 1);
            cur.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        size = digits.length();
        result.clear();
        if (!size)
            return result;
        this->digits.clear();
        for (char c : digits)
            this->digits.push_back(c - '2');
        phone = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        cur.clear();
        dfs(0);
        return result;
    }
};

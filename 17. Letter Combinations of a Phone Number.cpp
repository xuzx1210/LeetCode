class Solution
{
private:
    vector<string> result;
    string combination;
    vector<string> letters;
    vector<int> number;
    int size;
    void recursive(const int index)
    {
        if (index == size)
        {
            result.emplace_back(combination);
            return;
        }
        for (const char letter : letters[number[index]])
        {
            combination.push_back(letter);
            recursive(index + 1);
            combination.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
            return {};
        result.clear();
        combination.clear();
        number.clear();
        for (const char digit : digits)
            number.emplace_back(digit - '2');
        size = number.size();
        letters = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        recursive(0);
        return result;
    }
};

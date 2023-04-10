class Solution
{
public:
    bool isValid(string s)
    {
        unordered_map<char, char> close2open{{')', '('}, {']', '['}, {'}', '{'}};
        stack<char> brackets{};
        for (char bracket : s)
            if (close2open.find(bracket) == close2open.end())
                brackets.emplace(bracket);
            else if (brackets.empty())
                return false;
            else if (brackets.top() == close2open[bracket])
                brackets.pop();
            else
                return false;
        return brackets.empty();
    }
};

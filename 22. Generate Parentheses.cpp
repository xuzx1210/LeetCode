class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<set<string>> answers(n + 1, set<string>());
        answers[0].clear();
        answers[0].insert("");
        for (int i = 1; i <= n; ++i)
        {
            answers[i].clear();
            for (string str : answers[i - 1])
            {
                for (int j = 0; j < i; ++j)
                {
                    string tmp(str);
                    tmp.insert(j, "()");
                    answers[i].insert(tmp);
                }
            }
        }
        vector<string> result({});
        for (auto str : answers[n])
            result.push_back(str);
        return result;
    }
};

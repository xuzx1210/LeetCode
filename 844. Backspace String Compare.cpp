class Solution
{
private:
    void process(string &s, vector<char> &v)
    {
        for (char c : s)
            if (c == '#')
            {
                if (!v.empty())
                    v.pop_back();
            }
            else
                v.push_back(c);
    }

public:
    bool backspaceCompare(string s, string t)
    {
        vector<char> a({}), b({});
        process(s, a);
        process(t, b);
        return a == b;
    }
};

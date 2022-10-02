class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        int length = s.length();
        vector<int> last(26, -1);
        vector<bool> visited(26);
        for (int i = 0; i < length; ++i)
            last[s[i] - 'a'] = i;
        string result = "";
        for (int i = 0; i < length; ++i)
        {
            int cur = s[i] - 'a';
            if (visited[cur])
                continue;
            while (!result.empty())
            {
                int back = result.back() - 'a';
                if (result.back() > s[i] && last[back] > i)
                {
                    visited[back] = false;
                    result.pop_back();
                }
                else
                    break;
            }
            result.push_back(s[i]);
            visited[cur] = true;
        }
        return result;
    }
};

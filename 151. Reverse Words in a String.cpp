class Solution
{
public:
    string reverseWords(string s)
    {
        stringstream ss(s);
        string tmp, result;
        vector<string> words;
        while (ss >> tmp)
            words.emplace_back(tmp);
        for (int i = words.size() - 1; i; --i)
            result += (words[i] + ' ');
        result += words[0];
        return result;
    }
};

class Solution
{
public:
    string reverseWords(string s)
    {
        stringstream ss(s);
        vector<string> words({});
        string word;
        while (ss >> word)
            words.push_back(word);
        string result("");
        for (int i = words.size() - 1; i >= 1; --i)
            result += (words[i] + ' ');
        result += words[0];
        return result;
    }
};

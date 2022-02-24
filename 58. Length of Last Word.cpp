class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        stringstream ss(s);
        string result;
        while (ss >> result)
        {
        }
        return result.length();
    }
};

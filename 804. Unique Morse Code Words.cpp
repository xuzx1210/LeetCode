class Solution
{
public:
    int uniqueMorseRepresentations(vector<string> &words)
    {
        vector<string> morse = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
        unordered_map<string, int> counter = {};
        for (string &word : words)
        {
            string morseCode = "";
            for (char &c : word)
                morseCode += morse[c - 'a'];
            counter[morseCode] = 0;
        }
        return counter.size();
    }
};

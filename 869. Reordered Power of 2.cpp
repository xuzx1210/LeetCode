class Solution
{
public:
    bool reorderedPowerOf2(int n)
    {
        string nString = to_string(n);
        int nLength = nString.length();
        vector<int> nCounter(10, 0);
        for (char &c : nString)
            ++nCounter[c - '0'];
        for (int i = 1;; i <<= 1)
        {
            string iString = to_string(i);
            int iLength = iString.length();
            if (iLength < nLength)
                continue;
            if (iLength > nLength)
                break;
            vector<int> iCounter(10, 0);
            for (char &c : iString)
                ++iCounter[c - '0'];
            if (iCounter == nCounter)
                return true;
        }
        return false;
    }
};

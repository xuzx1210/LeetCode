class Solution
{
public:
    string getHint(string secret, string guess)
    {
        int A = 0;
        const int length = secret.length();
        for (int i = 0; i < length; ++i)
            A = secret[i] == guess[i] ? A + 1 : A;
        vector<int> secretCounter(10, 0), guessCounter(10, 0);
        for (int i = 0; i < length; ++i)
        {
            ++secretCounter[secret[i] - '0'];
            ++guessCounter[guess[i] - '0'];
        }
        int B = -A;
        for (int i = 0; i <= 9; ++i)
            B += min(secretCounter[i], guessCounter[i]);
        return to_string(A) + 'A' + to_string(B) + 'B';
    }
};

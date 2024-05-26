class Solution
{
public:
    int checkRecord(int n)
    {
        int result = 0;
        const int mod = 1000000007;
        int a = 0, l1a0 = 0, l1a1 = 0, l2a0 = 0, l2a1 = 0, pa0 = 1, pa1 = 0;
        for (int i = 0; i < n; ++i)
        {
            int A = ((l1a0 + l2a0) % mod + pa0) % mod;
            int L1A0 = pa0;
            int L1A1 = (a + pa1) % mod;
            int L2A0 = l1a0;
            int L2A1 = l1a1;
            int PA0 = ((l1a0 + l2a0) % mod + pa0) % mod;
            int PA1 = ((l1a1 + l2a1) % mod + (a + pa1) % mod) % mod;
            a = A;
            l1a0 = L1A0;
            l1a1 = L1A1;
            l2a0 = L2A0;
            l2a1 = L2A1;
            pa0 = PA0;
            pa1 = PA1;
        }
        result = (result + a) % mod;
        result = (result + l1a0) % mod;
        result = (result + l1a1) % mod;
        result = (result + l2a0) % mod;
        result = (result + l2a1) % mod;
        result = (result + pa0) % mod;
        result = (result + pa1) % mod;
        return result;
    }
};

class Solution
{
private:
    int mod;
    int sum(vector<int> nums)
    {
        int result = 0;
        for (const int num : nums)
            result = (result + num) % mod;
        return result;
    }

public:
    int checkRecord(int n)
    {
        mod = 1000000007;
        int a = 0, l1a0 = 0, l1a1 = 0, l2a0 = 0, l2a1 = 0, pa0 = 1, pa1 = 0;
        for (int i = 0; i < n; ++i)
        {
            int A = sum({l1a0, l2a0, pa0});
            int L1A0 = pa0;
            int L1A1 = sum({a, pa1});
            int L2A0 = l1a0;
            int L2A1 = l1a1;
            int PA0 = sum({l1a0, l2a0, pa0});
            int PA1 = sum({a, l1a1, l2a1, pa1});
            a = A;
            l1a0 = L1A0;
            l1a1 = L1A1;
            l2a0 = L2A0;
            l2a1 = L2A1;
            pa0 = PA0;
            pa1 = PA1;
        }
        return sum({a, l1a0, l1a1, l2a0, l2a1, pa0, pa1});
    }
};

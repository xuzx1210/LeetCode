class KthLargest
{
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;

public:
    KthLargest(int k, vector<int> &nums)
    {
        pq = priority_queue<int, vector<int>, greater<int>>(nums.begin(), nums.end());
        while (pq.size() > k)
            pq.pop();
        this->k = k;
    }
    int add(int val)
    {
        pq.emplace(val);
        if (pq.size() > k)
            pq.pop();
        return pq.top();
    }
};

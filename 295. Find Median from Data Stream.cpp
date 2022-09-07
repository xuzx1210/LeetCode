class MedianFinder
{
private:
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> large;
    int size;

public:
    MedianFinder()
    {
        small = {};
        large = {};
        size = 0;
    }
    void addNum(int num)
    {
        ++size;
        small.emplace(num);
        if (small.size() > large.size())
        {
            large.emplace(small.top());
            small.pop();
        }
        if (!small.empty() && !large.empty())
            while (small.top() > large.top())
            {
                int a = small.top(), b = large.top();
                small.pop();
                large.pop();
                small.emplace(b);
                large.emplace(a);
            }
    }
    double findMedian()
    {
        return (size & 1) ? large.top() : (small.top() + large.top()) / 2.0;
    }
};

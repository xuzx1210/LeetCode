class MedianFinder
{
private:
    multiset<int> small, large;
    int size;

public:
    MedianFinder()
    {
        small.clear();
        large.clear();
        size = 0;
    }
    void addNum(int num)
    {
        ++size;
        small.emplace(num);
        if (small.size() > large.size())
        {
            auto it = small.end();
            --it;
            large.emplace(*it);
            small.erase(it);
        }
        if (!small.empty() && !large.empty())
            while (true)
            {
                auto ita = small.end();
                --ita;
                auto itb = large.begin();
                int a = *ita, b = *itb;
                if (a <= b)
                    break;
                small.erase(ita);
                small.emplace(b);
                large.erase(itb);
                large.emplace(a);
            }
    }
    double findMedian()
    {
        return (size & 1) ? *large.begin() : (*small.rbegin() + *large.begin()) / 2.0;
    }
};

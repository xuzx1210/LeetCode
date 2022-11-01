class Twitter
{
private:
    vector<pair<int, int>> tweet;
    vector<vector<bool>> following;

public:
    Twitter()
    {
        tweet.clear();
        following = vector<vector<bool>>(501, vector<bool>(501));
        for (int i = 1; i <= 500; ++i)
            following[i][i] = true;
    }
    void postTweet(int userId, int tweetId)
    {
        tweet.push_back({userId, tweetId});
    }
    vector<int> getNewsFeed(int userId)
    {
        vector<int> result;
        for (int i = tweet.size() - 1, remain = 10; i >= 0 && remain; --i)
            if (following[userId][tweet[i].first])
            {
                result.emplace_back(tweet[i].second);
                --remain;
            }
        return result;
    }
    void follow(int followerId, int followeeId)
    {
        following[followerId][followeeId] = true;
    }
    void unfollow(int followerId, int followeeId)
    {
        following[followerId][followeeId] = false;
    }
};

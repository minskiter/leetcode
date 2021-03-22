#include "header.h"

#define rep(i, f, t, s) for (int i = f; i <= (int)t; i += s)
#define repd(i, f, t, s) for (int i = f; i >= (int)t; i -= s)
#define mk(a, b) make_pair(a, b)
#define sqr(a) ((a) * (a))
template <class Ty1, class Ty2>
inline const pair<Ty1, Ty2> operator+(const pair<Ty1, Ty2> &p1, const pair<Ty1, Ty2> &p2)
{
    return mk(p1.first + p2.first, p1.second + p2.second);
}
template <class Ty1, class Ty2>
inline const pair<Ty1, Ty2> operator-(const pair<Ty1, Ty2> &p1, const pair<Ty1, Ty2> &p2)
{
    return mk(p1.first - p2.first, p1.second - p2.second);
}
template <class Ty1, class Ty2>
bool inner(pair<Ty1, Ty2> pos, pair<Ty1, Ty2> leftTop, pair<Ty1, Ty2> rightBottom)
{
    if (pos.first >= leftTop.first && pos.second >= leftTop.second)
    {
        if (pos.first < rightBottom.first && pos.second < rightBottom.second)
        {
            return true;
        }
    }
    return false;
}

struct Post
{
    Post(int timeline, int id, int author) : timeline(timeline), id(id), author(author)
    {
    }
    int timeline;
    int id;
    int author;
};


class Twitter
{
    unordered_map<int, list<Post>> user_feeds;
    unordered_map<int, unordered_set<int>> follow_users;
    unordered_map<int, list<Post>> user_twitter;
    int _timeline = 0;

public:
    /** Initialize your data structure here. */
    Twitter()
    {
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId)
    {
        Post post(_timeline++, tweetId, userId);
        if (user_twitter.find(userId)==user_twitter.end()){
            user_twitter[userId]=move(list<Post>());
        }
        user_twitter[userId].push_front(post);
        // 分发给订阅者
        if (follow_users.find(userId) == follow_users.end()){
            follow_users[userId] = move(unordered_set<int>{userId});
        }else if (follow_users[userId].find(userId)==follow_users[userId].end()){
            follow_users[userId].emplace(userId);
        }
        for (auto follows : follow_users[userId])
        {
            if (user_feeds.find(follows) == user_feeds.end())
            {
                user_feeds[follows] = move(list<Post>{post});
            }
            else
            {
                user_feeds[follows].push_front(post);
            }
        }
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId)
    {
        // 获取用户的最新文章
        if (user_feeds.find(userId) == user_feeds.end())
            return vector<int>();
        auto itor = user_feeds[userId].begin();
        auto end = user_feeds[userId].end();
        vector<int> tmp;
        for (int i = 0; itor != end && i < 10; ++i, itor = next(itor))
            tmp.emplace_back(itor->id);
        return tmp;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId)
    {
        // 按照时间线添加十篇该用户，为什么是10篇，因为后续unfollower可能导致原本正好10篇的少于10篇
        if (follow_users.find(followeeId) == follow_users.end())
        {
            follow_users[followeeId] = move(unordered_set<int>());
        }
        unordered_set<int> &s = follow_users[followeeId];
        if (s.find(followerId) != s.end())
        {
            // 已经存在
            return;
        }
        s.emplace(followerId);
        // 判断关注的人是否有文章
        if (user_twitter.find(followeeId) != user_twitter.end())
        {
            auto &twitters = user_twitter[followeeId];
            auto itor = twitters.begin();
            // 查询用户的信箱是否存在
            if (user_feeds.find(followerId) == user_feeds.end())
            {
                user_feeds[followerId] = move(list<Post>());
            }
            auto &posts = user_feeds[followerId];
            auto post_itor = posts.begin();
            for (int i = 0; i < 10 && itor != twitters.end(); ++i, itor = next(itor))
            {
                while (post_itor != posts.end() && post_itor->timeline > itor->timeline)
                {
                    post_itor = next(post_itor);
                }
                if (post_itor == posts.end())
                {
                    posts.push_back(*itor);
                    continue;
                }
                posts.insert(post_itor, *itor);
            }
        }
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId)
    {
        if (followeeId == followerId)
            return;
        if (follow_users.find(followeeId) == follow_users.end())
            return;
        unordered_set<int> &s = follow_users[followeeId];
        if (s.find(followerId) == s.end())
            return;
        s.erase(followerId);
        // 去除所有该用户的文章
        if (user_feeds.find(followerId) == user_feeds.end())
            return;
        auto &feeds = user_feeds[followerId];
        vector<list<Post>::iterator> tmp;
        for (auto itor = feeds.begin(); itor != feeds.end(); itor = next(itor))
            if (itor->author == followeeId)
                tmp.emplace_back(itor);
        for (auto itor : tmp)
            feeds.erase(itor);
    }
};

int main()
{
    return 0;
}
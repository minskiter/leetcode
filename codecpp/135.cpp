// TODO: 最优 往返两次遍历即可
#include "header.h"

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        vector<pair<int, int>> ratingSort;
        vector<int> minCandy(ratings.size() + 2, 0);
        for (int i = 0; i < ratings.size(); ++i)
            ratingSort.push_back(make_pair(ratings[i], i));
        sort(ratingSort.begin(), ratingSort.end());
        int sum = 0;
        for (int i = 0; i < ratingSort.size(); ++i)
        {
            int maxinum = 0;
            if (ratingSort[i].second != 0 && ratingSort[i].first > ratings[ratingSort[i].second - 1])
                maxinum = max(maxinum, minCandy[ratingSort[i].second]);
            if (ratingSort[i].second != ratingSort.size() - 1 && ratingSort[i].first > ratings[ratingSort[i].second + 1])
                maxinum = max(maxinum, minCandy[ratingSort[i].second + 2]);
            minCandy[ratingSort[i].second + 1] = maxinum + 1;
            sum += minCandy[ratingSort[i].second + 1];
        }
        return sum;
    }
};

int main()
{
    vector<int> ratings = {1, 2, 2};
    Solution s;
    cout << s.candy(ratings);
    return 0;
}
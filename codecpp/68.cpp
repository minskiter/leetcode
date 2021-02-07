#include "header.h"

class Solution
{
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        vector<string> ans;
        int wordCnt = 0;
        int curLen = 0;
        for (int i = 0; i < words.size(); ++i)
        {
            if (curLen + words[i].size() <= maxWidth)
            {
                curLen += words[i].size() + 1;
                wordCnt++;
            }
            else
            {
                curLen--;
                string temp = "";
                if (wordCnt != 1)
                {
                    int avg = (maxWidth - curLen) / (wordCnt - 1);
                    int extra = (maxWidth - curLen) % (wordCnt - 1);
                    for (int j = 0; j < wordCnt; ++j)
                    {
                        temp = temp + words[i - wordCnt + j];
                        if (j == wordCnt - 1)
                            break;
                        for (int k = 0; k <= avg; ++k)
                        {
                            temp += " ";
                        }
                        if (j < extra)
                        {
                            temp += " ";
                        }
                    }
                }
                else
                {
                    temp = words[i - 1];
                    for (int j = temp.size(); j < maxWidth; ++j)
                    {
                        temp += " ";
                    }
                }
                ans.push_back(temp);
                curLen = words[i].size() + 1;
                wordCnt = 1;
            }
        }
        if (wordCnt > 0)
        {
            string temp;
            for (int i = 0; i < wordCnt; ++i)
            {
                temp = temp + words[words.size() - wordCnt + i];
                if (i != wordCnt - 1)
                {
                    temp += " ";
                }
            }
            for (int i = temp.size(); i < maxWidth; ++i)
            {
                temp += " ";
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<string> words = {"NiceMeetYou","My","Friend"};
    fmt::printArray(s.fullJustify(words, 11));
    return 0;
}
#include "header.h"

class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        vector<int> ans;
        map<string, int> cnt;
        int len = words.size();
        int wordlen = 0;
        if (len)
            wordlen = words[0].size();
        else
            return ans;
        for (int i = 0; i < len; ++i)
        {
            if (cnt.find(words[i]) != cnt.end())
            {
                cnt[words[i]]++;
            }
            else
            {
                cnt[words[i]] = 1;
            }
        }
        vector<map<string, int>> offsetCnt(wordlen);
        vector<int> total(wordlen, 0);
        for (int i = 0; i  < s.size()+wordlen; ++i)
        {
            if (i + wordlen > s.size())
            {
                if (total[i % wordlen] == len)
                {
                    ans.push_back(i - len * wordlen);
                    total[i % wordlen] = 0;
                }
                continue;
            }
            else
            {
                if (total[i % wordlen] == len)
                {
                    ans.push_back(i - len * wordlen);
                }
            }
            string temp = s.substr(i, wordlen);
            int tempCnt = 1;
            cout << "i:" << i << endl
                 << "temp:" << temp << endl;
            if (offsetCnt[i % wordlen].find(temp) != offsetCnt[i % wordlen].end())
            {
                tempCnt += offsetCnt[i % wordlen][temp];
            }
            if (cnt.find(temp) == cnt.end())
            {
                total[i % wordlen] = 0;
                offsetCnt[i % wordlen].clear();
            }
            else if (cnt[temp] < tempCnt || total[i % wordlen] == len)
            {
                // 查看第一个单词是否是temp如果是，则直接加入
                int tempTotal = wordlen * total[i % wordlen];
                cout << "tempTotal:" << tempTotal << endl;
                while (tempTotal > 0 && (cnt[temp] < tempCnt || total[i % wordlen] == len))
                {
                    string temp2 = s.substr(i - tempTotal, wordlen);
                    cout << "temp2:" << temp2 << endl;
                    offsetCnt[i % wordlen][temp2]--;
                    total[i % wordlen]--;
                    tempTotal -= wordlen;
                    if (temp == temp2)
                    {
                        tempCnt--;
                    }
                }
                // 加入
                offsetCnt[i % wordlen][temp] = tempCnt;
                total[i % wordlen]++;
            }
            else
            {
                // 加入
                offsetCnt[i % wordlen][temp] = tempCnt;
                total[i % wordlen]++;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<string> words = {"bar", "foo"};
    fmt::printArray(s.findSubstring("barfoothefoobarman", words));
    return 0;
}
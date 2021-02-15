#include "header.h"

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        int ans = 0;
        int beginIndex = wordList.size(),
            endIndex = -1;
        for (int i = 0; i < wordList.size(); ++i)
        {
            if (wordList[i] == beginWord)
            {
                beginIndex = i;
            }
            if (wordList[i] == endWord)
            {
                endIndex = i;
            }
        }
        if (beginIndex == wordList.size())
            wordList.push_back(beginWord);
        // Create Graph
        vector<int> head(wordList.size(), -1);
        vector<int> edges;
        vector<int> nxt;
        auto addEdge = [&head, &edges, &nxt](int f, int t) {
            edges.push_back(t);
            nxt.push_back(head[f]);
            head[f] = edges.size() - 1;
        };

        for (int i = 0; i < wordList.size(); ++i)
        {
            for (int j = i + 1; j < wordList.size(); ++j)
            {
                int diff = 0;
                for (int l = 0; l < wordList[i].size(); ++l)
                {
                    if (wordList[i][l] != wordList[j][l])
                    {
                        ++diff;
                    }
                    if (diff > 1)
                        break;
                }
                if (diff == 1)
                {
                    addEdge(i, j);
                    addEdge(j, i);
                }
            }
        }
        if (endIndex == -1)
            return ans;
        // 双向BFS
        vector<int> frontstep(wordList.size(), -1), endstep(wordList.size(), -1);
        queue<int> frontQueue;
        queue<int> backQueue;
        frontstep[beginIndex] = endstep[endIndex] = 1;
        frontQueue.push(beginIndex);
        backQueue.push(endIndex);
        int curStep = 1;
        while (!frontQueue.empty() && !backQueue.empty())
        {
            // 将步数与curStep一样的全部出队
            while (!frontQueue.empty())
            {
                int front = frontQueue.front();
                int p = head[front];
                int step = frontstep[front];
                if (step > curStep)
                    break;
                frontQueue.pop();
                while (p != -1)
                {
                    if (frontstep[edges[p]] == -1)
                    {
                        frontstep[edges[p]] = step + 1;
                        frontQueue.push(edges[p]);
                        if (endstep[edges[p]] != -1)
                        {
                            // 找到答案
                            return step + endstep[edges[p]];
                        }
                    }
                    p = nxt[p];
                }
            }
            while (!backQueue.empty())
            {
                int back = backQueue.front();
                int p = head[back];
                int step = endstep[back];
                if (step > curStep)
                    break;
                backQueue.pop();
                while (p != -1)
                {
                    if (endstep[edges[p]] == -1)
                    {
                        endstep[edges[p]] = step + 1;
                        if (frontstep[edges[p]] != -1)
                        {
                            // 找到答案
                            return step + frontstep[edges[p]];
                        }

                        backQueue.push(edges[p]);
                    }
                    p = nxt[p];
                }
            }
            ++curStep;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<string> wordList = {
        "hot", "dot", "dog", "lot", "log", "cog"};
    cout << s.ladderLength("hit", "cog", wordList);
    return 0;
}

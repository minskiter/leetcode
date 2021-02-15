#include "header.h"

class Solution
{
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        vector<vector<string>> ans;
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
        vector<vector<vector<int>>> frontPath(wordList.size());
        vector<vector<vector<int>>> backPath(wordList.size());
        queue<int> frontQueue;
        queue<int> backQueue;
        frontstep[beginIndex] = endstep[endIndex] = 1;
        frontPath[beginIndex].push_back(vector<int>(1, beginIndex));
        backPath[endIndex].push_back(vector<int>(1, endIndex));
        frontQueue.push(beginIndex);
        backQueue.push(endIndex);
        int curStep = 1;
        vector<int> findAnswer;
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
                        frontPath[edges[p]] = frontPath[front];
                        for (int i = 0; i < frontPath[edges[p]].size(); ++i)
                        {
                            frontPath[edges[p]][i].push_back(edges[p]);
                        }
                        frontQueue.push(edges[p]);
                        if (endstep[edges[p]] != -1)
                        {
                            // 找到答案
                            findAnswer.push_back(edges[p]);
                        }
                    }
                    else if (frontstep[edges[p]] == step + 1)
                    {
                        auto temp = frontPath[front];
                        for (int i = 0; i < temp.size(); ++i)
                        {
                            temp[i].push_back(edges[p]);
                        }
                        frontPath[edges[p]].insert(frontPath[edges[p]].end(), make_move_iterator(temp.begin()), make_move_iterator(temp.end()));
                    }
                    p = nxt[p];
                }
            }
            if (findAnswer.size() > 0)
            {
                for (int i = 0; i < findAnswer.size(); ++i)
                {
                    for (int j = 0; j < frontPath[findAnswer[i]].size(); ++j)
                    {
                        vector<string> src;
                        for (int k = 0; k < frontPath[findAnswer[i]][j].size(); ++k)
                        {
                            src.push_back(wordList[frontPath[findAnswer[i]][j][k]]);
                        }
                        for (int k = 0; k < backPath[findAnswer[i]].size(); ++k)
                        {
                            vector<string> dest;
                            for (int l = 0; l < backPath[findAnswer[i]][k].size() - 1; ++l)
                            {
                                dest.push_back(wordList[backPath[findAnswer[i]][k][l]]);
                            }
                            reverse(dest.begin(), dest.end());
                            vector<string> copy = src;
                            copy.insert(copy.end(), make_move_iterator(dest.begin()), make_move_iterator(dest.end()));
                            ans.push_back(copy);
                        }
                    }
                }
                break;
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
                        backPath[edges[p]] = backPath[back];
                        for (int i = 0; i < backPath[edges[p]].size(); ++i)
                        {
                            backPath[edges[p]][i].push_back(edges[p]);
                        }
                        backQueue.push(edges[p]);
                        if (frontstep[edges[p]] != -1)
                        {
                            // 找到答案
                            findAnswer.push_back(edges[p]);
                        }
                    }
                    else if (endstep[edges[p]] == step + 1)
                    {
                        auto temp = backPath[back];
                        for (int i = 0; i < temp.size(); ++i)
                        {
                            temp[i].push_back(edges[p]);
                        }
                        backPath[edges[p]].insert(backPath[edges[p]].end(), make_move_iterator(temp.begin()), make_move_iterator(temp.end()));
                    }
                    p = nxt[p];
                }
            }
            if (findAnswer.size() > 0)
            {
                for (int i = 0; i < findAnswer.size(); ++i)
                {
                    for (int j = 0; j < frontPath[findAnswer[i]].size(); ++j)
                    {
                        vector<string> src;
                        for (int k = 0; k < frontPath[findAnswer[i]][j].size(); ++k)
                        {
                            src.push_back(wordList[frontPath[findAnswer[i]][j][k]]);
                        }
                        // 去掉最后一个同样的点
                        for (int k = 0; k < backPath[findAnswer[i]].size(); ++k)
                        {
                            vector<string> dest;
                            for (int l = 0; l < backPath[findAnswer[i]][k].size() - 1; ++l)
                            {
                                dest.push_back(wordList[backPath[findAnswer[i]][k][l]]);
                            }
                            reverse(dest.begin(), dest.end());
                            vector<string> copy = src;
                            copy.insert(copy.end(), make_move_iterator(dest.begin()), make_move_iterator(dest.end()));
                            ans.push_back(copy);
                        }
                    }
                }
                break;
            }
            ++curStep;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<string> wordlists = {
        "ted", "tex", "red", "tax", "tad", "den", "rex", "pee"};
    fmt::printArray2(s.findLadders("red", "tax", wordlists));
    return 0;
}
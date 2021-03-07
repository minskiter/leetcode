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

string rtrim(const string &s)
{
    auto tmp = s.size();
    while (tmp > 0 && s[tmp - 1] == ' ')
        --tmp;
    return s.substr(0, tmp);
}

// Solution Here
class Solution
{
    static vector<string> i3;
    static vector<string> i2;
    static vector<string> i1;
    static vector<string> i0;
    static vector<int> mod;

public:
    string numberToWords(int num)
    {
        if (num == 0)
            return "Zero";
        ostringstream os;
        for (int i = 2; i >= 0; --i)
        {
            if (num / mod[i] != 0)
                os << hundredNumberToWords(num / mod[i]) << " " << i3[i] << " ";
            num %= mod[i];
        }
        return rtrim(os.str());
    }
    string hundredNumberToWords(int hundred)
    {
        ostringstream os;
        if (hundred / 100 > 0)
        {
            os << i1[hundred / 100] << " Hundred ";
            hundred %= 100;
        }
        if (hundred < 20)
            os << i1[hundred] << " ";
        else
            os << i2[hundred / 10] << " " << i1[hundred % 10] << " ";
        return rtrim(os.str());
    }
};

vector<int> Solution::mod = {1000, 1000000, 1000000000};
vector<string> Solution::i3 = {"Thousand", "Million", "Billion"};
vector<string> Solution::i1 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
vector<string> Solution::i2 = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

int main()
{
    return 0;
}
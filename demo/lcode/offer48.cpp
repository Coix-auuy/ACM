#include <iostream>
#include <cstring>
#include <string>
#include <cassert>
using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int max = 0;
        int dp = 0;
        int dis[128];
        memset(dis, -1, sizeof(dis));
        for (int i = 0; i < s.length(); i++)
        {
            if (dis[s[i]] < 0 || dp < i - dis[s[i]])
                dp = dp + 1;
            else if (dp >= i - dis[s[i]])
                dp = i - dis[s[i]];
            dis[s[i]] = i;
            if (max < dp)
                max = dp;
        }
        return max;
    }
};

string stringToString(string input)
{
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() - 1; i++)
    {
        char currentChar = input[i];
        if (input[i] == '\\')
        {
            char nextChar = input[i + 1];
            switch (nextChar)
            {
            case '\"':
                result.push_back('\"');
                break;
            case '/':
                result.push_back('/');
                break;
            case '\\':
                result.push_back('\\');
                break;
            case 'b':
                result.push_back('\b');
                break;
            case 'f':
                result.push_back('\f');
                break;
            case 'r':
                result.push_back('\r');
                break;
            case 'n':
                result.push_back('\n');
                break;
            case 't':
                result.push_back('\t');
                break;
            default:
                break;
            }
            i++;
        }
        else
        {
            result.push_back(currentChar);
        }
    }
    return result;
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        string s = stringToString(line);

        int ret = Solution().lengthOfLongestSubstring(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
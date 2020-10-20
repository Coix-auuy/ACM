class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        auto dp = vector<bool>(s.size() + 1);
        dp[0] = true;
        
        for(int i = 1; i <= s.size(); i++)
        {
            bool flag = true;
            for(int j=0; j < i && flag; j++)
            {
                if(dp[j])
                {
                    string str = s.substr(j,i-j);
                    for(int k = 0; k < wordDict.size(); k++)
                    {
                        if(str.compare(wordDict[k]) == 0)
                        {
                            flag = false;
                            dp[i] = true;
                            break;
                        }
                    }
                }
                
            }
            if(flag)
            {
                dp[i] = false;
            }
        }
        return dp[s.size()];
    }
};
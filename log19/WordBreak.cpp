#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
class Solution {
public:
    bool wordBreak(std::string s,std::vector<std::string>& wordDict){
        std::unordered_set<std::string> wordSet(wordDict.begin(),wordDict.end());
        int n=s.length();
        std::vector<bool> dp(n+1,false);
        dp[0]=true;
        for(int i=1;i<=n;++i){
            for(int j=0;j<i;++j){
                if(dp[j]&&wordSet.count(s.substr(j,i-j))){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
int main(){
    Solution sol;
    std::string s1="takeuforward";
    std::vector<std::string> wordDict1={"take","forward","you","u"};
    std::cout<<"Example 1 (Tabulation): "<<(sol.wordBreak(s1,wordDict1)?"true":"false")<<std::endl;
    std::string s2="applepineapple";
    std::vector<std::string> wordDict2={"apple"};
    std::cout<<"Example 2 (Tabulation): "<<(sol.wordBreak(s2,wordDict2)?"true":"false")<<std::endl;
    return 0;
}

// Problem: word break
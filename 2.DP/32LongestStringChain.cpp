/*
You are given an array of words where each word consists of lowercase English letters.

wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.

For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

Return the length of the longest possible word chain with words chosen from the given list of words.

 

Example 1:

Input: words = ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: One of the longest word chains is ["a","ba","bda","bdca"].
Example 2:

Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
Output: 5
Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].
Example 3:

Input: words = ["abcd","dbqca"]
Output: 1
Explanation: The trivial word chain ["abcd"] is one of the longest word chains.
["abcd","dbqca"] is not a valid word chain because the ordering of the letters is changed.

*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static bool comp(string &s1, string s2){
        return s1.size() < s2.size();
    }

    // function to check whether two strings differ by a character
    bool checkChain(string &s1, string &s2){
        if(s2.size() != s1.size() + 1) return false;
        int first = 0;
        int second = 0;

        while(second < s2.size()){
            if(s1[first] == s2[second]){
                first++, second++;
            }
            else{
                second++;
            }
        }

        if(second == s2.size() && first == s1.size())
             return true;
        else
            return false;
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(),words.end(),comp);

        // for(string word: words)
        //     cout<<word<<" ";

        vector<int>dp(n, 1);
        int maxLen = 1;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                // bool check = checkChain(words[i], words[j]);
                // cout<<check<<" ";
                if(checkChain(words[j], words[i]) && dp[i] < 1 + dp[j]){ // lis logic
                    dp[i] = 1 + dp[j];
                }
            }
            maxLen = max(maxLen, dp[i]);
        }
        return maxLen;
    }
};

int main() {
    Solution sol;
    vector<string> words = {"a", "b", "ba", "bca", "bda", "bdca"};
    int result = sol.longestStrChain(words);
    
    cout << "Length of the longest word chain: " << result << endl; // Output: 4
    return 0;
}
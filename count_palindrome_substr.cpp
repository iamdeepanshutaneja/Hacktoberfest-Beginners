//Problem statement : string s is given. find out the number of palindromic substrings formed from the given string.
//   -> let s : "aba"   
//   -> possible substrings : "a","b,","a","ab","ba","aba"
//   -> total palindromic substrings :  "a","b","a","aba" : 4     ---> output

#include<bits/stdc++.h>
using namespace std;
//function to count total number of palindrome substrings
int countPalisubstr(string s){

    int count=0;
    int dp[s.size()][s.size()];
//    setting all values of matrix to -1
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<s.size();i++){
        int j=i;
        dp[i][j] = 1;
        count++;   
    }
    for(int i=0;i<s.size()-1;i++){
        int j=i+1;
        if(s[i]==s[j]){
            dp[i][j] = 1;
            count++;        //     condition if length of string is 1
        }
    }
       
    //     condition if length of string is greater or equal to 2.
    for(int k=2;k<s.size();k++){
        for(int i=0;i<s.size()-2;i++){
            if(dp[i+1][i+k-1]==1 && s[i]==s[i+k]){
                count++;
            }
        }
    }

    return count;    //final substrings to be counted for output
}
int main()
{
    string s;
//    input from user
    cin>>s;
    int n = countPalisubstr(s);
//    total number of count will be given as: 
    cout<<n;
}

#include<bits/stdc++.h>
using namespace std;
#define mod %1000000007
vector<int> dp;
string word;
class Trie{
    public:
    int val;
    unordered_map<int,Trie*> mp;
    bool isTerminal;
    Trie(){
        this->val = '\0';
        this->isTerminal = false;
    }
    Trie(int val){
        this->val = val;
        this->isTerminal = false;
    }
};
void insert(Trie* &t,string s){
    Trie* curr = t;
    for(int i=0;i<s.size();i++){
        if(curr->mp.count(s[i]-'a') == 0){
            curr->mp[s[i]-'a'] = new Trie(s[i]-'a');
        }
        curr = curr->mp[s[i]-'a'];
    }
    curr->isTerminal = true;
}
int search(Trie* t,int i){
    int ans = 0;
    Trie* curr = t;
    if(i>=word.size()) return 1;
    if(dp[i] != -1) return dp[i];
    for(int j=i;j<word.size();j++){
        if (curr->mp.count(word[j] - 'a') == 0) break;
        curr = curr->mp[word[j]-'a'];
        if(curr->isTerminal){
            ans = (ans mod + search(t,j+1) mod) mod;
        }
    }

    return dp[i] = ans;


}
int main(){
    cin>>word;
    int n = word.size();
    int k;
    cin>>k;
    string str;
    Trie* t = new Trie();
    for(int i=1;i<=k;i++){
        cin>>str;
        insert(t,str);
    }
    dp.assign(n+2,-1);
    cout<<search(t,0);
}
// Question link: https://leetcode.com/problems/reorganize-string/

class compare{
    public:
    bool operator()(pair<int,char> a,pair<int,char> b){
        return a.first<b.first;
    }
};
class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> mp;
        string ans="";
        priority_queue<pair<int,char>, vector<pair<int,char>>, compare> pq;
        for(const auto x: s) mp[x]++;
        for(const auto x: mp){
            if(x.second>ceil(s.size()/2.0)) return "";
            pq.push({x.second,x.first});
        }
        char prev='\0';
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            if(prev!=top.second) {
                ans.push_back(top.second);
                prev=top.second;
                top.first--;
            }
            else{
                auto nexTop=pq.top();
                pq.pop();
                ans.push_back(nexTop.second);
                prev=nexTop.second;
                nexTop.first--;
                if(nexTop.first>0)pq.push({nexTop.first,nexTop.second});
            }
            if(top.first>0)pq.push({top.first,top.second});
        }
        return ans;
    }
};

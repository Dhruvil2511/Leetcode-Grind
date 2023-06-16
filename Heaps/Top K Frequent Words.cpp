class compare{
    public:
    bool operator()(pair<int,string> &a , pair<int,string> &b){
        if(a.first==b.first){
            return a.second<b.second;
        }
        return a.first>b.first;
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        priority_queue<pair<int,string> ,vector<pair<int,string>> ,compare> pq;
        vector<string> ans(k);

        for(auto const x: words){
            mp[x]++;
        }
 
        for(auto it : mp) {
            pq.push({it.second, it.first});
            if(pq.size() > k) pq.pop();
        }
        int idx=k-1;
        while(pq.size()>0){
            ans[idx--]=pq.top().second;
            pq.pop();
        }
        return ans;
    }
};

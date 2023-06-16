class Solution {
public:
    string frequencySort(string s) {
        string ans="";
        unordered_map<char,int> mp;
        priority_queue<pair<int,char>> pq;
        for(auto x: s){
            mp[x]++;
        }
        for(auto x: mp) pq.push({x.second,x.first});

        while(!pq.empty()){
            auto pair=pq.top();
            pq.pop();
            while(pair.first--){
                ans.push_back(pair.second);
            }
        }
        return ans;
    }
};

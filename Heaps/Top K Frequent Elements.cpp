class MyComp {
public:
  bool operator()(const pair<int, int>& a, const pair<int, int>& b){
        return a.second > b.second;
  }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        priority_queue<pair<int, int>, vector<pair<int, int>>, MyComp> pq;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        auto itr = mp.begin();
        for (int i = 0; i < k; i++, itr++) {
            pq.push({itr->first, itr->second});
        }

        for (int i = k; i < mp.size(); i++, itr++) {
            if (itr->second > pq.top().second) {
                pq.pop();
                pq.push({itr->first, itr->second});
            }
        }

        while (!pq.empty()) {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};

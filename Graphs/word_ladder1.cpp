class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        // bfs algo -> because we need shortest path as given in question 
        // start from begin and keep changing single chars and check if its exits in 
        // word list so here by we will go level(from level 1,2,3...) wise and we will be sure if we find 
        // the endword it will be shortest
      
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        unordered_set<string> setCheck(wordList.begin(),wordList.end());

        if(setCheck.find(endWord)==setCheck.end())return 0;
        while(!q.empty()){
            string word = q.front().first;
            int level = q.front().second;
            q.pop();

            if(word == endWord)return level;
            setCheck.erase(word);

            for(int i=0;i<word.size();i++){
                char original = word[i];

                for(char j ='a'; j <= 'z';j++){
                    word[i]=j;
                    if(setCheck.find(word)!=setCheck.end()) q.push({word,level+1});
                }

                word[i] = original;
            }
        }
        return 0;
    }
}

class Solution {
    public:
        int ladderLength(string beginWord, string endWord, vector<string>& wordList)    
        {
            queue<pair<string,int>>q;
            q.push({beginWord,1});
            unordered_set<string>st(wordList.begin(),wordList.end());
            st.erase(beginWord);
    
            while(!q.empty())
            {
                string word = q.front().first;
                int cnt = q.front().second;
                q.pop();
    
                if(word == endWord)
                    return cnt;
                
                for(int i=0; i<word.size(); i++)
                {
                    char s = word[i];
                    for(char c='a'; c<='z'; c++)
                    {
                        word[i] = c;
                        if(st.find(word) != st.end())
                        {
                            q.push({word,cnt+1});
                            st.erase(word);
                        }
                    }
                    word[i] = s;
                }
            }
            return 0;
        }
    };
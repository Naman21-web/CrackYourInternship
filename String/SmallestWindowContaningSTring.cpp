 string smallestWindow (string s, string t)
    {
        // Your code here
       int m=s.size(), n=t.size();
        // unordered_map<char, int> mp;
        vector<char> mp(26,0);
        
        int ans = INT_MAX; 
        int start = 0; 
        int count=0;
        for(auto x:t){
            mp[x-'a']++;
            if(mp[x-'a']==1) count++;
        }
        
        int i = 0, j = 0;

        while (j < s.length()) {
            mp[s[j]-'a']--;
            if (mp[s[j]-'a'] == 0)
                count--;

            if (count == 0) {
                while (count == 0) {
                    if (ans > j - i + 1) {
                        ans = j - i + 1;
                        start = i;
                    }
                    mp[s[i]-'a']++;
                    if (mp[s[i]-'a'] > 0)
                        count++;

                    i++;
                }
            }
            j++;
        }
        if (ans != INT_MAX)
            return s.substr(start, ans);
        else
            return "-1";
    }
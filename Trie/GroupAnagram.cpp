class Solution{
  public:
    string helper(string str){
       vector<int>count(26,0);
       string s="";
       for(int i=0;i<str.size();i++){
           count[str[i]-'a']++;
       }
       for(int i=0;i<26;i++){
           s+=char(count[i]);
       }
       return s;
   }
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        vector<vector<string>>res;
       
       map<string,vector<int>>mp;
       for(int i=0;i<string_list.size();i++){
           
           mp[helper(string_list[i])].push_back(i);
           
       }
       for(auto itr:mp){
           vector<string>ans;
           for(int i=0;i<itr.second.size();i++){
               ans.push_back(string_list[itr.second[i]]);
           }
           res.push_back(ans);
       }
        return res;
    }
};
class Solution {
public:
bool check(string &source,string &word){
    if(source.size()!=word.size()) return false;
  int cnt=0;
  for(int i=0;i<word.size();i++){
    if(word[i]!=source[i]) cnt++;//tHere is diff in letter so increase cnt
    if(cnt>1) return false;//There is more than 1 character diff in 2 words
  }
  if(cnt==0) return false;//There is no diff bw 2 words
  return true;//There is only one letter diff bw 2 words
}
    int ladderLength(string source, string target, vector<string>& words) {
         if(source.size()!=target.size()) return -1;
  int n=words.size();
	unordered_map<string,vector<string>> graph;
  for(int i=0;i<n;i++){
    if(check(source,words[i])){
      graph[source].push_back(words[i]);
      // cout<<words[i]<<" ";
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(i!=j){
        if(check(words[i],words[j])){
          graph[words[i]].push_back(words[j]);
          // cout<<words[j]<<" ";
        }
      }
    }
  }
  
  unordered_set<string> vis;
  int dist=0;
  queue<string> q;
  q.push(source);
  vis.insert(source);
  
  while(!q.empty()){
    dist++;
    int sz=q.size();
    for(int i=0;i<sz;i++){
      string curr = q.front();
      q.pop();
      for(auto node:graph[curr]){
        if(vis.find(node)==vis.end()){
          vis.insert(node);
          if(node==target) return dist+1;
          q.push(node);
        }
      }
    }
  }
  return 0;
    }
};
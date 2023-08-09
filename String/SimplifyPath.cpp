class Solution {
public:
    string simplifyPath(string path) {
        int n=path.length();
        string ans;
        int i=0;
        while(i<n){
            while(i<n && path[i]=='/') i++;
            if(i<n) ans += '/';
            string res;
            while(i<n && path[i]!='/'){
                res += path[i++];
            }
            if(res==".") ans.pop_back();
            else if(res==".."){
                ans.pop_back();
                while(!ans.empty() && ans.back()!='/') ans.pop_back();
                if(ans!="")ans.pop_back();
            }
            else ans += res;
        }
        if(ans=="") return "/";
        if(ans.size()>1 && ans.back()=='/') ans.pop_back();
        return ans;
    }
};
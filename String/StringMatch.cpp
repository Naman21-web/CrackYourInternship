class Solution {
public:
    vector<int> findlps(string needle){
        int n=needle.size();
        vector<int> lps(n);
        lps[0]=0;
        int i=1,len=0;
        while(i<n){
            if(needle[i]==needle[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len==0){
                    lps[i]=len;
                    i++;
                }
                else{
                    len = lps[len-1];
                }
            }
        }
        return lps;
    }
    int strStr(string haystick, string needle) {
        //By using stl
        // size_t found = haystack.find(needle);
        // if (found != string::npos)
        //     return found;
        // else
        //     return -1;

        //by brute force approach
        // int n = haystack.length(),m=needle.length();
        // if(m>n) return -1;
        // string v=haystack.substr(0,m);
        // if(v==needle) return 0;
        // for(int i=0;i<n-m+1;i++){
        //     v = haystack.substr(i,m);
        //     if(v==needle)return i;
        // }
        // return -1;

        //By KMP algo
        vector<int> lps = findlps(needle);
        int n=haystick.size(),m=needle.size();
        int i=0,j=0;
        while(i<n){
            if(haystick[i]==needle[j]){
                i++;
                j++;
                if(j==m){
                    return i-m;
                }
            }
            else if(i<n && haystick[i]!=needle[j]){
                if(j==0) i++;
                else j=lps[j-1];
            }
        }
        return -1;
    }
};
class node{
    public:
    node* next[26];
    bool isEnd;
    node(){
        for(int i=0;i<26;i++){
            next[i]=NULL;
        }
        isEnd=false;
    }
};
class Trie{
    node* root = new node();
    public:
    void insert(string word){
        node* it=root;
        for(int i=0;i<word.size();i++){
            if(it->next[word[i]-'a']){
                it = it->next[word[i]-'a'];
            }
            else{
                node* newNode = new node();
                it->next[word[i]-'a'] = newNode;
                it = it->next[word[i]-'a'];
            }
        }
        it->isEnd = true;
    }
    bool search(string word){
        node* it=root;
        for(int i=0;i<word.size();i++){
            if(it->next[word[i]-'a']){
                it = it->next[word[i]-'a'];
            }
            else return false;
        }
        return it->isEnd;
    }
};

class Solution{
    public:
    // A : given string to search
    // B : vector of available strings
    bool check(string A,Trie* t){
        int n=A.size();
        if(n==0) return true;
        for(int i=0;i<n;i++){
            if(t->search(A.substr(0,i+1)) && check(A.substr(i+1),t)) return true;
        }
        return false;
    }
    
    int wordBreak(string A, vector<string> &B) {
        //code here
        
        int n=A.size();
        int m=B.size();
        Trie* t = new Trie();
        for(int i=0;i<m;i++){
            t->insert(B[i]);
        }
        return check(A,t);
    }
};
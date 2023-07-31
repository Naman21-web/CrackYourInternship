class Trie {
public:
    class node{
    public:
        bool end;
        node* next[26];
        node(){
            end=false;
            for(int i=0;i<26;i++) next[i]=NULL;
        }
    };
    node* trie;
    Trie() {
        trie = new node();
    }
    
    void insert(string word) {
        int i=0;
        node* it=trie;
        while(i<word.size()){
            if(it->next[word[i]-'a']==NULL){
                it->next[word[i]-'a']=new node();
            }
            it = it->next[word[i]-'a'];
            i++;
        }
        it->end=true;
    }
    
    bool search(string word) {
        int i=0;
        node* it = trie;
        while(i<word.size()){
            if(it->next[word[i]-'a']==NULL) return false;
            it = it->next[word[i]-'a'];
            i++;
        }
        return it->end;
    }
    
    bool startsWith(string prefix) {
        int i=0;
        node* it = trie;
        while(i<prefix.size()){
            if(it->next[prefix[i]-'a']==NULL) return false;
            it = it->next[prefix[i]-'a'];
            i++;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
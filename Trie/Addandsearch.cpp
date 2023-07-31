struct Trie{
    bool end;
    Trie* next[26];
    Trie(){
        for(int i=0;i<26;i++) next[i]=NULL;
        end=false;
    }
};
class WordDictionary {
private:
    bool search(const char* word,Trie* node){
        for(int i=0;word[i] && node;i++){
            if(word[i]!='.'){
                node = node->next[word[i]-'a'];
            }
            else{
                Trie* temp = node;
                for(int j=0;j<26;j++){
                    node = temp->next[j];
                    if(search(word+i+1,node)) return true;
                }
            }
        }
        return node && node->end;
    }
public:
    Trie* root;
    WordDictionary() {
        root=new Trie();
    }
    
    void addWord(string word) {
        Trie* it=root;
        int i=0;
        while(i<word.size()){
            int x = word[i]-'a';
            if(it->next[x]==NULL)it->next[x]=new Trie();
            it = it->next[x];
            i++;
        }
        it->end = true;
    }
    
    bool search(string word) {
        return search(word.c_str(),root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->isEndOfWord = true;
    }

    vector<string> search(const string& prefix) {
        TrieNode* node = root;
        vector<string> contacts;
        string currPrefix;
        for (char c : prefix) {
            if (node->children.find(c) == node->children.end()) {
                return contacts;
            }
            node = node->children[c];
            currPrefix += c;
        }
        findContacts(node, currPrefix, contacts);
        return contacts;
    }

    void findContacts(TrieNode* node, const string& prefix, vector<string>& contacts) {
        if (node->isEndOfWord) {
            contacts.push_back(prefix);
        }
        for (auto it = node->children.begin(); it != node->children.end(); ++it) {
            findContacts(it->second, prefix + it->first, contacts);
        }
    }
};

vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        Trie trie;
        for (int i = 0; i<n; i++) {
            trie.insert(contact[i]);
        }
    
        vector<vector<string>> result;
        string prefix;
        for (char c : s) {
            prefix += c;
            vector<string> contactsWithPrefix = trie.search(prefix);
            if (contactsWithPrefix.empty()) {
                result.push_back({"0"});
            } else {
                sort(contactsWithPrefix.begin(), contactsWithPrefix.end());
                result.push_back(contactsWithPrefix);
            }
        }
    
        return result;
    }
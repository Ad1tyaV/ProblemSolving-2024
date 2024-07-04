class TrieDS {
    struct TrieNode {        
        vector<TrieNode*> next;
        bool isWordEnd;
        TrieNode() : next(26, nullptr), isWordEnd(false) {}
    };

    TrieNode* root;

    public: 
    void addWord(string& word) {
        if(!root) {
            root = new TrieNode();
        }
        TrieNode* crawl = root->next[word[0]-'a'];
        if(!crawl) {
            root->next[word[0]-'a'] = new TrieNode();
            crawl = root->next[word[0]-'a'];
        }            

        for(int index=1; index<word.size(); index++) {
            crawl = crawl->next[word[index]-'a'];
            if(!crawl) {
                root->next[word[index]-'a'] = new TrieNode();
                crawl = root->next[word[index]-'a'];
            }
        }
        crawl->isWordEnd = true;
    }    
};
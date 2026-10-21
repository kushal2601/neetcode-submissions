class TrieNode{
    public: 
        bool isEnding = false;
        vector<TrieNode*> children = vector<TrieNode*>(26, nullptr);
};
class WordDictionary {
public:
        TrieNode* root = new TrieNode();
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        auto it = root;
        for(auto letter : word){
            if(it->children[letter - 'a'] == nullptr)
            it->children[letter - 'a'] = new TrieNode();
            it = it->children[letter - 'a'];
        }
        it->isEnding = true;
    }
    bool search(const string& word, int index , TrieNode*& suffix){
        if(index == word.size()){
            return suffix != nullptr and suffix->isEnding;
        }
        if(suffix == nullptr)return false;
        char current_letter = word[index];
        if(current_letter != '.')return search(word, index + 1 , suffix->children[current_letter - 'a'] );
        for(int i = 0; i < 26; i++){
            bool isPossible = search(word, index + 1 , suffix->children[i]);
            if(isPossible) return true;
        }
        return false;
    }
    bool search(string word) {
        return search(word, 0, root);
    }
};

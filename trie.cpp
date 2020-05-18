class TrieNode{
    public:
    TrieNode* children[26];
    bool isEnd;
    
    TrieNode(){
        for(int i =0;i<26;i++)
            children[i]=NULL;
        isEnd = false;
    }
};

TrieNode* makeNode(){
    TrieNode *res = new TrieNode();
    for(int i =0;i<26;i++)
            res->children[i]=NULL;
        
    res->isEnd =false;
    return res;
}
class Trie {
public:
    /** Initialize your data structure here. */
    TrieNode* root;
    
    Trie() {
        root = makeNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* curr = root;
        for(int i =0;i<word.length();i++){
            int check = word[i]-'a';
            if(!curr->children[check])
                curr->children[check] = makeNode(); 
            curr = curr->children[check];
        }
        curr->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* curr = root;
        for(int i =0;i<word.length();i++){
            int check = word[i]-'a';
            // cout << char(check+'a') << endl;
            if(!curr->children[check])
                return false;
            curr = curr->children[check];
        }
        if(curr->isEnd&&curr!=NULL)return true;
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(int i =0;i<prefix.length();i++){
            int check = prefix[i]-'a';
            if(!curr->children[check])
                return false;
            curr = curr->children[check];
        }
        return curr!=NULL;
    }
};
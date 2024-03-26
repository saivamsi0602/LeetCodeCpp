#include <vector>
#include <functional>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <unordered_map>
class Trie{
private:
    std::unordered_map<char,Trie> m;
    bool isWordEnding;
    bool searchWord(std::string &word, int index){
        if(index==word.length()) return isWordEnding;
        return m.count(word[index]) && m[word[index]].searchWord(word, index+1);
    }
    void insertWord(std::string &word, int index){
        if(index==word.length()) {
            isWordEnding=true;
            return;
        }
        if(!m.count(word[index])) m[word[index]] = Trie();
        m[word[index]].insertWord(word, index+1);
    }
    bool deleteWord(std::string& word, int index){
        if(index==word.length()) {
            isWordEnding=false;
            return m.empty();
        }
        bool canRemoveChild = m[word[index]].deleteWord(word, index+1);
        if(canRemoveChild) m.erase(word[index]);
        return m.empty() && !isWordEnding;
    }
public:
    Trie(): isWordEnding{false}{}
    void insert(std::string word){
        insertWord(word, 0);
    }
    void remove(std::string word){
        deleteWord(word, 0);
    }
    bool search(std::string word){
        return searchWord(word, 0);
    }
};
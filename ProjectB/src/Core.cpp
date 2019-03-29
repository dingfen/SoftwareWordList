
#include "Core.h"

vector<string> Core::gen_chain_word(vector<string> words, char head, char tail)
{
    WordGraph G;
    G.create(words);
    
    vector<string> ret = G.wordDFS(head, tail, -1);
    
    return ret;
}


vector<string> Core::gen_chain_char(vector<string> words, char head, char tail)
{
    WordGraph G;
    G.create(words);
    
    vector<string> ret = G.alphaDFS(head, tail, -1);
    
    return ret;
}

vector<vector<string>> Core::gen_chain_word(vector<string> words, int num, char head, char tail)
{
    WordGraph G;
    G.create(words);
    
    vector<string> ret = G.wordDFS(head, tail, num);
    
    return G.getList();
}

#include <iostream>
#include "WordGraph.h"
#include <string>
#include <vector>


using namespace std;

int main(int argc, char const *argv[])
{
    vector<string> words;
    char head;
    char tail;
    int num;

    vector<string> retWord = gen_chain_word(words, head, tail);

    vector<string> retChar = gen_chain_char(words, head, tail);

    vector<vector<string>> retList = gen_chain_word(words, num, head, tail);

    
    return 0;
}

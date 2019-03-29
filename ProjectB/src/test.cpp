#include <iostream>
#include "Core.h"
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    string input[] = {"qwe", "asd", "re", "dwe", "efs", "sfef", "cqualqwdweqq", "sad", "sdds"};
    vector<string> words(begin(input), end(input));
    vector<string> noword;

    vector<string> retWord[5];
    retWord[0] = Core::gen_chain_word(words, '\0', '\0');
    retWord[1] = Core::gen_chain_word(words, 's', '\0');
    retWord[2] = Core::gen_chain_word(words, '\0', 's');
    retWord[3] = Core::gen_chain_word(words, 's', 's');
    retWord[4] = Core::gen_chain_word(noword, '\0', '\0');

    vector<string> retChar[4];
    retChar[0] = Core::gen_chain_char(words, '\0', '\0');
    retChar[1] = Core::gen_chain_char(words, 's', '\0');
    retChar[2] = Core::gen_chain_char(words, '\0', 's');
    retChar[3] = Core::gen_chain_char(words, 's', 's');

    vector<vector<string>> retList[4];
    retList[0] = Core::gen_chain_word(words, 3, '\0', '\0');
    retList[1] = Core::gen_chain_word(words, 3, 's', '\0');
    retList[2] = Core::gen_chain_word(words, 3, '\0', 's');
    retList[3] = Core::gen_chain_word(words, 3, 's', 's');
    
    
    return 0;
}

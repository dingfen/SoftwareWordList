#include <iostream>
#include "Core.h"
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<vector<string>> wordsVec;
    string input[] = {"qwe", "asd", "re", "dwe", "efs", "sfef", "cqualqwdweqq", "sad", "sdds"};
    wordsVec.push_back(vector<string>(end(input)-1, end(input)));
    for (int i=0; i<4; i++)
        wordsVec.push_back(vector<string>(begin(input), end(input)));
    
    char head[] = {'\0', '\0', 's', '\0', 's'};
    char tail[] = {'\0', '\0', '\0', 's', 's'};
    
    //test for vector<string> Core::gen_chain_word(vector<string> words, char head, char tail);
    vector<string> retWord[5];
    
    cout << "test for API 1" << endl;
    for (int i=0; i<5; i++)
    {
        cout << "case " << i << ": ";
        retWord[i] = Core::gen_chain_word(wordsVec[i], head[i], tail[i]);
        for (auto str : retWord[i])
            cout << str << " ";
        cout << endl;
    }
    cout << endl;
    
    //test for vector<string> Core::gen_chain_char(vector<string> words, char head, char tail);
    vector<string> retChar[5];
    
    cout << "test for API 2" << endl;
    for (int i=0; i<5; i++)
    {
        cout << "case " << i << ": ";
        retChar[i] = Core::gen_chain_char(wordsVec[i], head[i], tail[i]);
        for (auto str : retChar[i])
            cout << str << " ";
        cout << endl;
    }
    cout << endl;
    
    //test for vector<vector<string>> Core::gen_chain_word(vector<string> words, int num, char head, char tail);
    vector<vector<string>> retList[5];
    
    cout << "test for API 3" << endl;
    for (int i=0; i<5; i++)
    {
        cout << "case " << i << ": ";
        retList[i] = Core::gen_chain_word(wordsVec[i], 3, head[i], tail[i]);
        cout << "number of word chains " << ":" << retList[i].size() << endl;
        
        for (auto vec : retList[i])
        {
            for (auto str : vec)
                cout << str << " ";
            cout << endl;
        }
        cout << endl;
    }
    
    return 0;
}

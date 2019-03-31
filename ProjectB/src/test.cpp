#include <iostream>
#include "Core.h"
#include <string>
#include <vector>
#include <fstream>

using namespace std;

#define MAXTESTFILES 8

vector<string> parseLine(string line)
{
    size_t pos;
    string alpha("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
    vector<string> ret;

    pos = line.find_first_not_of(alpha);
    while (pos != string::npos)
    {
        string sub = line.substr(0, pos);
        if (sub.size() > 0)
            ret.push_back(sub);
        line.erase(0, pos + 1);
        pos = line.find_first_not_of(alpha);
    }

    if (line.size() > 0)
        ret.push_back(line);

    return ret;
}

vector<string> openfile(char const *file)
{
    ifstream fin;
    vector<string> words;
    fin.open(file, ios::in);
    if (!fin) {
        cerr << "The file " << file<< " cannot be found.\n";
        exit(1);
    }
    // 对文件进行分割 一行行地进行
    string line;
    do
    {
        getline(fin, line);
        vector<string> s = parseLine(line);
        words.insert(words.end(), s.begin(), s.end());
    } while (!fin.eof());

    fin.close();
    return words;
}


bool checkIsChain(vector<string> wordchain)
{
    if(wordchain.size()< 2) {
        cout<<"Word chain does not exist. "<<endl;
        return true;
    }
    
    char head, tail;
    for(int i=0;i<wordchain.size()-1;) {
        tail = wordchain[i].back();
        i++;
        head = wordchain[i].front();
        if(head != tail) 
            return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    vector<vector<string>> wordsVec;
    vector<string> input;
    if(argc > 1) {
        for(int i=1;i<argc;i++) {
            input = openfile(argv[i]);
            wordsVec.push_back(input);
        }
    }
    else {
        cerr<<"please follow a test file name."<<endl;
        exit(1);
    }
   
    char head[]= {'\0','\0','\0','s','a'};
    char tail[]= {'\0','\0','e', '\0','g'};


    //test for vector<string> Core::gen_chain_word(vector<string> words, char head, char tail);
    vector<string> retWord[5];
    
    cout <<"***************"<< endl;
    cout << "test for API 1" << endl;
    for (int i=0; i<argc-1; i++)
    {
        cout << "case " << i+1 << ": "<<endl;
        retWord[i] = Core::gen_chain_word(wordsVec[i], head[i], tail[i]);
        cout<<"head "<<head[i]<<" tail "<<tail[i]<<" test file: "<<argv[i+1]<<endl;
        if(checkIsChain(retWord[i]))
            cout<<"Test "<<i+1<<" Success"<<endl;
        else {
            cout<<"Test "<<i+1<<" Fail!"<<endl;
            for(auto j:retWord[i])
                cout<<j<<" ";
        }
        
    }
    cout <<"***************"<< endl;
    
    //test for vector<string> Core::gen_chain_char(vector<string> words, char head, char tail);
    vector<string> retChar[MAXTESTFILES];
    
    cout << "test for API 2" << endl;
    for (int i=0; i<argc-1; i++)
    {
        cout << "case " << i+1 << ": "<<endl;
        retChar[i] = Core::gen_chain_char(wordsVec[i], head[i], tail[i]);
        cout<<"head "<<head[i]<<" tail "<<tail[i]<<" test file: "<<argv[i+1]<<endl;
        if(checkIsChain(retWord[i]))
            cout<<"Test "<<i+1<<" Success"<<endl;
        else {
            cout<<"Test "<<i+1<<" Fail!"<<endl;
        }
    }
    cout <<"***************"<< endl;
    
    //test for vector<vector<string>> Core::gen_chain_word(vector<string> words, int num, char head, char tail);
    vector<vector<string>> retList[MAXTESTFILES];
    
    cout << "test for API 3" << endl;
    for (int i=0; i<argc-1; i++)
    {
        cout << "case " << i << ": ";
        int num = rand() % 5 +2;
        cout<<"head "<<head[i]<<" tail "<<tail[i]<<" Wordchain size "<<num<<
            " test file: "<<argv[i+1]<<endl;
        retList[i] = Core::gen_chain_word(wordsVec[i], num, head[i], tail[i]);
        cout << "number of word chains " << ":" << retList[i].size() << endl;
        
        bool flag = true;
        for (auto vec : retList[i])
        {
            if(checkIsChain(vec))
                continue;
            else {
                cout<<"Test Fail"<<endl;
                flag = false;
            }
        }
        if(flag) cout<<"Test Success"<<endl;
        cout <<"***************"<< endl;
    }
    
    return 0;
}

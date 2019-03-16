#include "WordGraph.h"
#include <fstream>
#include <cctype>
#include <cstdlib>


vector<string> parseLine(string line)
{
    size_t pos;
    string alpha("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
    vector<string> ret;

    pos = line.find_first_not_of(alpha);
    while(pos!=string::npos) {
        string sub = line.substr(0, pos);
        if(sub.size()>0)
            ret.push_back(sub);
        line.erase(0, pos+1);
        pos = line.find_first_not_of(alpha);
    }
    
    if(line.size()>0)
        ret.push_back(line);

    return ret;
}


WordGraph::~WordGraph()
{
}


void WordGraph::create(string filename)
{
    ifstream fin;
    fin.open(filename.c_str(), ios::in);
    if(!fin) {
        cerr<<"The file "<<filename.c_str()<<"cannot be found.\n"<<endl;
        exit(1);
    }

    // 对文件进行分割 一行行地进行
    string line;
    do
    {
        getline(fin, line);
        vector<string> s = parseLine(line);
        this->words.insert(this->words.end(), s.begin(), s.end());
    } while (!fin.eof());
    
    // 建立图矩阵
    for(string s : this->words) {
        char head = s.front();
        char tail = s.back();
        head = tolower(head);
        tail = tolower(tail);
        // cout<<head<<" "<<tail<<endl;
        this->table[head-'a'][tail-'a'].push_back(s);
    }
    fin.close();
}


vector<string> WordGraph::wordDFS(char head='\0', char tail='\0', int num=0)
{
    
}


vector<string> WordGraph::alphaDFS(char head='\0', char tail='\0', int num=0)
{
    
}
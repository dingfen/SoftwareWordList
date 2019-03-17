#include <iostream>
#include <unistd.h>
#include <fstream>
#include <string>
#include <ctype.h>

#include "WordGraph.h"

using namespace std;


int main(int argc, char *argv[])
{
    int opt;
    // 文件名 要求的开头字母、结尾字母
    string filename;
    char head = '\0';
    char tail = '\0';
    // 要求单词链有几个单词
    int numWord = 0;
    // 统计字母时为 false 统计单词为 true
    bool wordOrLetter = true;
    int flagOfMain = 0;

    const char *optstring = "c:w:h:t:n:";
    while ((opt = getopt(argc, argv, optstring)) != -1)
    {
        switch (opt)
        {
        case 'c':
            wordOrLetter = false;
            flagOfMain ++;
            filename = optarg;
            break;
        case 'w':
            wordOrLetter = true;
            flagOfMain ++;
            filename = optarg;
            break;
        case 'h':
            if (isalpha(*optarg))
                head = *optarg;
            else
                cerr << "-h must be followed by a alpha" << endl;
                exit(1);
            break;
        case 't':
            if (isalpha(*optarg))
                tail = *optarg;
            else
                cerr << "-t must be followed by a alpha" << endl;
                exit(1);
            break;
        case 'n':
            if (isdigit(*optarg))
                numWord = *optarg - '0';
            else
                cerr << "-n must be followed by a interger" << endl;
                exit(1);
            break;
        case '?':
            cerr << "unknown option: " << (char)optopt << endl;
            cerr << "error opterr: " << opterr << endl;
            break;
        }
    }
    if(flagOfMain != 1){
        if( flagOfMain > 1 ){
            cerr << "multiple main instructions" << endl;
            exit(1);
        }
        if( flagOfMain == 0 ){
            cerr << "No main instruction" << endl;
            exit(1);
        }
    }
    // 创建图结构
    WordGraph G;
    G.create(filename);
    
    vector<string> ret;

    if(wordOrLetter)
        ret = G.wordDFS(head, tail, numWord);
    else
        ret = G.alphaDFS(head, tail, numWord);

    for(auto s : ret) 
        cout<<s<<endl;
    
    return 0;
}

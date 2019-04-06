#include <iostream>
#include <unistd.h>
#include <fstream>
#include <string>
#include <ctype.h>

#include "WordGraph.h"
#include "Core.h"

using namespace std;


int main(int argc, char *argv[])
{
    int opt;
    // 文件名 要求的开头字母、结尾字母
    string filename;
    char head = '\0';
    char tail = '\0';
    // 要求单词链有几个单词
    volatile int numWord = -1;
    // 统计字母时为 false 统计单词为 true
    bool wordOrLetter = true;
    //用于指示作为程序核心的-c和-w指令的出现次数
    int flagOfMain = 0;

    const char *optstring = "c:w:h:t:n:";
    //循环处理命令
    while ((opt = getopt(argc, argv, optstring)) != -1)
    {
        switch (opt)
        {
        case 'c'://指定最大字母总数
            wordOrLetter = false;
            flagOfMain ++;
            filename = optarg;
            break;
        case 'w'://指定最大单词数
            wordOrLetter = true;
            flagOfMain ++;
            filename = optarg;
            break;
        case 'h':
                head = *optarg;
            break;
        case 't':
                tail = *optarg;
            break;
        case 'n'://指定单词个数
            numWord = atoi(optarg);
            break;
        case '?':
            cerr << "Error: unknown option: " << (char)optopt << endl;
            cerr << "Error: opterr: " << opterr << endl;
            exit(1);
            break;
        }
    }
    if(flagOfMain != 1){//当未出现或重复出现主命令时报错退出
        if( flagOfMain > 1 ){
            cerr << "Error: multiple main instructions" << endl;
            exit(1);
        }
        if( flagOfMain == 0 ){
            cerr << "Error: No main instruction" << endl;
            exit(1);
        }
    }
    
    // 文件预处理，完成后送入word
    auto words = Core::text_preprocess(filename);

    vector<string> ret;

    ofstream fout;
    fout.open("bin/answer.txt",ios::out);

    // 进行单词链生成
    if (numWord == -1) {
        if (wordOrLetter)
            ret = Core::gen_chain_word(words, head, tail);
        else
            ret = Core::gen_chain_char(words, head, tail);
        for(auto s : ret) 
            fout<<s<<endl;
    }
    else 
    {   
        vector<vector<string>> List;
        if (wordOrLetter)
            List = Core::gen_chain_word(words, numWord, head, tail);
        else
            // 报出错误，未实现的功能
            cerr<<"Error: function that Given numbers of characters hasn't been implemented. "<<endl;

        fout<<List.size()<<endl;
        for(auto group : List) {
            for(auto s : group)
                fout<<s<<endl;
            fout<<"\n";
        }
    }

    cout<<"WordList execution Completed."<<endl;
    fout.close();
    return 0;
}
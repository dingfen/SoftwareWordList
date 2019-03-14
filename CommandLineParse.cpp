#include <iostream>
#include <unistd.h>
#include <fstream>
#include <string>
#include <ctype.h>

#include "WordGraph.h"

using namespace std;

#define MAXFILENAME 64


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

    const char *optstring = "c:w:h:t:n:";
    while ((opt = getopt(argc, argv, optstring)) != -1)
    {
        switch (opt)
        {
        case 'c':
            wordOrLetter = false;
            filename = optarg;
            break;
        case 'w':
            wordOrLetter = true;
            filename = optarg;
            break;
        case 'h':
            if (isalpha(*optarg))
                head = *optarg;
            else
                cerr << "-h must be followed by a alpha" << endl;
            break;
        case 't':
            if (isalpha(*optarg))
                tail = *optarg;
            else
                cerr << "-t must be followed by a alpha" << endl;
            break;
        case 'n':
            if (isdigit(*optarg))
                numWord = *optarg - '0';
            else
                cerr << "-n must be followed by a interger" << endl;
            break;
        case '?':
            cerr << "error optopt: " << optopt << endl;
            cerr << "error opterr: " << opterr << endl;
            break;
        }
    }
    
    // 创建图结构
    WordGraph G;
    G.create(filename);
    
    return 0;
}

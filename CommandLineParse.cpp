#include <iostream>
#include <unistd.h>
#include <fstream>
#include <ctype.h>
using namespace std;

int main(int argc, char *argv[])
{
    int opt;

    char head = '\0';
    char tail = '\0';
    // 要求单词链有几个单词
    int numWord = 0;
    // 统计字母时为 false 统计单词为 true
    bool wordOrLetter = true;

    const char *optstring = "cwh:t:n:";
    while ((opt = getopt(argc, argv, optstring)) != -1)
    {
        switch (opt)
        {
        case 'c':
            wordOrLetter = false;
            break;
        case 'w':
            wordOrLetter = true;
            break;
        case 'h':
            if (isalpha(*optarg))
                head = *optarg;
            else
                cerr << "-h must be followed by a alpha" << endl;
            // cout<<head<<endl;
            break;
        case 't':
            if (isalpha(*optarg))
                tail = *optarg;
            else
                cerr << "-t must be followed by a alpha" << endl;
            // cout<<tail<<endl;
            break;
        case 'n':
            if (isdigit(*optarg))
                numWord = *optarg - '0';
            // cout<<numWord<<endl;
            else
                cerr << "-n must be followed by a interger" << endl;
            break;
        case '?':
            cerr << "error optopt: " << optopt << endl;
            cerr << "error opterr: " << opterr << endl;
            break;
        }
    }
    // cout << optind <<endl;

    ifstream fin;
    char *q = new char[5];
    fin.open(argv[optind], ios::in);
    fin >> q;
    cout << q << endl;

    delete[] q;
    fin.close();
    return 0;
}

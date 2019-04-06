
#include "Core.h"

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

vector<string> Core::gen_chain_word(vector<string> words, char head, char tail)
{
    vector<string> ret;
    try
    {
        WordGraph G;
        G.create(words);
        ret = G.wordDFS(head, tail, -1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return ret;
}


vector<string> Core::gen_chain_char(vector<string> words, char head, char tail)
{
    vector<string> ret;
    try 
    {
        WordGraph G;
        G.create(words);
        ret = G.alphaDFS(head, tail, -1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() <<endl;
    }
    return ret;
}

vector<vector<string>> Core::gen_chain_word(vector<string> words, int num, char head, char tail)
{
    vector<string> ret;
    WordGraph G;
    try
    {
    G.create(words);
    ret = G.wordDFS(head, tail, num);
    }
    catch(const std::exception& e)
    {
        std::cerr<< e.what() <<endl;
    }
    return G.getList();
}

vector<string> Core::text_preprocess(string path)
{
    ifstream fin;
    
    vector<string> words;
    // 避免出现重复单词
    set<string> set_word;

    fin.open(path.c_str(), ios::in);
    if (!fin) {
        cerr << "The file " << path<< " cannot be found.\n";
        exit(1);
    }
    // 对文件进行分割 一行行地进行
    string line;
    do
    {
        getline(fin, line);
        vector<string> s = parseLine(line);
        set_word.insert(s.begin(), s.end());
    } while (!fin.eof());

    fin.close();

    // 单词太少 无法组成单词链
    //if(set_word.size() < 2) {
    //    cerr<< "Too few words in the file.None word list exists." <<endl;
    //    exit(1);
    //}

    for(auto s : set_word)
        words.push_back(s);
    return words;
}

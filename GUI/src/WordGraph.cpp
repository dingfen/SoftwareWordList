#include "WordGraph.h"
#include <fstream>
#include <cctype>
#include <algorithm>
#include <cstdlib>

unordered_map<string, bool> parseLine(string line)
{
    size_t pos;
    string alpha("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
    unordered_map<string, bool> ret;

    pos = line.find_first_not_of(alpha);
    while (pos != string::npos)
    {
        string sub = line.substr(0, pos);
        if (sub.size() > 0)
            ret.insert(pair<string, bool>(sub, false));
        line.erase(0, pos + 1);
        pos = line.find_first_not_of(alpha);
    }

    if (line.size() > 0)
        ret.insert(pair<string, bool>(line, false));

    return ret;
}

WordGraph::~WordGraph()
{
}

void WordGraph::create(string filename)
{
    ifstream fin;
    fin.open(filename.c_str(), ios::in);
    if (!fin)
    {
        cerr << "The file " << filename.c_str() << "cannot be found.\n"
             << endl;
        exit(1);
    }

    // 对文件进行分割 一行行地进行
    string line;
    do
    {
        getline(fin, line);
        unordered_map<string, bool> s = parseLine(line);
        words.insert(s.begin(), s.end());
    } while (!fin.eof());

    // 建立图矩阵
    for (auto s : words)
    {
        char head = s.first.front();
        char tail = s.first.back();
        head = tolower(head);
        tail = tolower(tail);
        // cout<<head<<" "<<tail<<endl;
        heads.insert(head);
        tails.insert(tail);
        this->table[head - 'a'][tail - 'a'].push_back(s.first);
    }
    fin.close();
}


vector<vector<string>> WordGraph::getList()
{
    return List;
}

vector<string> WordGraph::wordDFS(char head, char tail, int num)
{
    // 遍历所有的单词，然后DFS 求出最长的单词链 并保存
    if (head == '\0' && tail == '\0')
    {
        // 直接求最长链
        for (auto w : heads)
        {
            // 取出首字母
            ret.clear();
            findLongestWordList(w, num);
        }
        return max;
    }
    else if (head == '\0' && tail != '\0')
    {
        ret.clear();
        reverseLongestWordList(tail, num);
        reverse(max.begin(), max.end());

        if(num!=-1)
            for(auto &s : List)
                reverse(s.begin(), s.end());
        return max;
    }
    else if (head != '\0' && tail == '\0')
    {
        ret.clear();
        findLongestWordList(head, num);
        return max;
    }
    else
    {
        ret.clear();
        findLongestWordList(head, tail, num);
        return max;
    }
}


vector<string> WordGraph::alphaDFS(char head, char tail, int num)
{
    if (head == '\0' && tail == '\0')
    {
        for (auto w : heads)
        {
            ret.clear();
            findLongestAlphaList(w, num);
        }
        return max;
    }
    else if (head == '\0' && tail != '\0')
    {
        ret.clear();
        reverseLongestAlphaList(tail, num);
        reverse(max.begin(), max.end());
        return max;
    }
    else if (head != '\0' && tail == '\0')
    {
        ret.clear();
        findLongestAlphaList(head, num);
        return max;
    }
    else
    {
        ret.clear();
        findLongestAlphaList(head, tail, num);
        return max;
    }
}

bool WordGraph::isNull()
{
    return words.size() == 0;
}

void WordGraph::create(QString text)
{
    QStringList lineList = text.split("\n");

    // 对文件进行分割 一行行地进行
    for (int i=0; i<lineList.size(); i++)
    {
        string line = lineList.at(i).toStdString();
        unordered_map<string, bool> s = parseLine(line);
        words.insert(s.begin(), s.end());
    }

    // 建立图矩阵
    for (auto s : words)
    {
        char head = s.first.front();
        char tail = s.first.back();
        head = tolower(head);
        tail = tolower(tail);
        // cout<<head<<" "<<tail<<endl;
        heads.insert(head);
        tails.insert(tail);
        this->table[head - 'a'][tail - 'a'].push_back(s.first);
    }
}

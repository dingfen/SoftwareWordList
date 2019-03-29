#include "WordGraph.h"
#include <fstream>
#include <cctype>
#include <algorithm>
#include <cstdlib>


WordGraph::~WordGraph()
{
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
    }
    else if (head == '\0' && tail != '\0')
    {
        ret.clear();
        reverseLongestWordList(tail, num);
        reverse(max.begin(), max.end());
        
        if(num!=-1)
            for(auto &s : List)
                reverse(s.begin(), s.end());
    }
    else if (head != '\0' && tail == '\0')
    {
        ret.clear();
        findLongestWordList(head, num);
    }
    else
    {
        ret.clear();
        findLongestWordList(head, tail, num);
    }
    if(max.size() < 2 && List.size() == 0) {
        cerr<< "None word list exists." <<endl;
        return vector<string>();
    }
    return max;
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
    }
    else if (head == '\0' && tail != '\0')
    {
        ret.clear();
        reverseLongestAlphaList(tail, num);
        reverse(max.begin(), max.end());
    }
    else if (head != '\0' && tail == '\0')
    {
        ret.clear();
        findLongestAlphaList(head, num);
    }
    else
    {
        ret.clear();
        findLongestAlphaList(head, tail, num);
    }
    return max;
}

void WordGraph::create(vector<string> words)
{
    // 单词太少 无法组成单词链
    if(words.size() < 2) {
        cerr<< "Too few words in the file.None word list exists." <<endl;
        return;
    }

    // 建立图矩阵
    for (auto s : words)
    {
        char head = s.front();
        char tail = s.back();
        head = tolower(head);
        tail = tolower(tail);
        heads.insert(head);
        tails.insert(tail);
        this->table[head - 'a'][tail - 'a'].push_back(s);
    }
    
}

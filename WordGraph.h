#ifndef __WORD_GRAPH_H
#define __WORD_GRAPH_H

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class WordGraph
{
private:
    unordered_map<string, bool> words;           // 图的边集合
    vector<char> heads;                     // 图的开头字母集合
    vector<char> tails;                     // 图的结尾字母集合
    
    vector<string> table[26][26];   // 图的邻接矩阵 table[2][3] 指示 c->d

    // 递归方法寻找最长链
    vector<string> max;
    vector<string> ret;
    void findLongestWordList(char beg) {
        bool notfind = true;
        for(auto line : table[beg-'a']) {
            for(auto s : line) {
                if(words[s]==false) {
                    notfind =false;
                    words[s]=true;
                    ret.push_back(s);
                    findLongestWordList(s.back());
                    if(ret.size()>max.size())
                        max = ret;
                    ret.pop_back();
                }
            }
        }
    }


public:
    WordGraph() {};

    ~WordGraph();

    // 给定文件路径，创建图
    void create(string path);
    // 若求最长单词链，num=0,若不规定头尾字母，head,tail='\0'
    // 求最长的单词链
    vector<string> wordDFS(char head='\0', char tail='\0', int num=0);
    // 求最长的字母链
    vector<string> alphaDFS(char head='\0', char tail='\0', int num=0);
};


#endif
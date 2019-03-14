#ifndef __WORD_GRAPH_H
#define __WORD_GRAPH_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class WordGraph
{
private:
    vector<string> words;           // 图的边集合
    vector<string> table[26][26];   // 图的邻接矩阵 table[2][3] 指示 c->d

public:
    WordGraph() {};

    ~WordGraph();

    // 给定文件路径，创建图
    void create(string path);
};


#endif
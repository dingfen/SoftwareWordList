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

    vector<string> max;
    int alphalenth=0;
    int maxalphalength=0;
    vector<string> ret;

    // 单词： 递归方法寻找最长链
    void findLongestWordList(char beg) {
        for(auto line : table[beg-'a']) {
            for(auto s : line) {
                if(words[s]==false) {
                    words[s]=true;
                    ret.push_back(s);
                    findLongestWordList(s.back());
                    if(ret.size()>max.size())
                        max = ret;
                    ret.pop_back();
                    words[s]=false;
                }
            }
        }
    }

    // 单词： 递归方法反向寻找最长链
    void reverseLongestWordList(char end) {
        for(int i=0;i<26;i++) {
            vector<string> line = table[i][end-'a'];
            for(auto s : line) {
                if(words[s]==false) {
                    words[s]=true;
                    ret.push_back(s);
                    reverseLongestWordList(s.front());
                    if(ret.size()>max.size())
                        max = ret;
                    ret.pop_back();
                    words[s] = false;
                }
            }
        }
    }

    // 字母： 递归方法寻找最长链
    void findLongestAlphaList(char beg) {
        for(auto line : table[beg-'a']) {
            for(auto s : line) {
                if(words[s]==false) {
                    words[s]=true;
                    ret.push_back(s);
                    alphalenth += s.size();
                    findLongestAlphaList(s.back());
                    if(alphalenth > maxalphalength) {
                        maxalphalength = alphalenth;
                        max = ret;
                    }
                    alphalenth -= s.size();
                    ret.pop_back();
                    words[s]=false;
                }
            }
        }
    }

    // 字母： 
    void reverseLongestAlphaList(char end) {
        for(int i=0;i<26;i++) {
            vector<string> line = table[i][end-'a'];
            for(auto s : line) {
                if(words[s]==false) {
                    words[s]=true;
                    ret.push_back(s);
                    alphalenth += s.size();
                    reverseLongestAlphaList(s.front());
                    if(alphalenth > maxalphalength) {
                        maxalphalength = alphalenth;
                        max = ret;
                    }
                    alphalenth -= s.size();
                    ret.pop_back();
                    words[s]=false;
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
    vector<string> wordDFS(char head, char tail, int num);
    // 求最长的字母链
    vector<string> alphaDFS(char head, char tail, int num);
};


#endif
#ifndef __WORD_GRAPH_H
#define __WORD_GRAPH_H

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

class WordGraph
{
private:
    unordered_map<string, bool> words;           // 图的边集合
    set<char> heads;                     // 图的开头字母集合
    set<char> tails;                     // 图的结尾字母集合
    
    vector<string> table[26][26];   // 图的邻接矩阵 table[2][3] 指示 c->d

    vector<vector<string>> List;

    // 递归需要用到的变量
    vector<string> max;
    int alphalenth=0;
    int maxalphalength=0;
    vector<string> ret;

    // 单词： 递归方法寻找最长链
    void findLongestWordList(char beg, int num) {
        if(num == 0)
            return;

        // 没有 -n 限制
        if (num == -1)
        {
            for (auto line : table[beg - 'a'])
            {
                for (auto s : line)
                {
                    if (words[s] == false)
                    {
                        words[s] = true;
                        ret.push_back(s);
                        // 递归深搜 将 s的尾字母当下一个的开头传入
                        findLongestWordList(s.back(), num);
                        // 取出最长的单词链
                        if (ret.size() > max.size())
                            max = ret;
                        ret.pop_back();
                        words[s] = false;
                    }
                }
            }
        }
        else {
            // 有-n
            for(auto line : table[beg-'a'])
            {
                for(auto s :line)
                {
                    if(words[s] == false)
                    {
                        words[s] = true;
                        ret.push_back(s);
                        num--;
                        findLongestWordList(s.back(), num);
                        if(num == 0)
                            List.push_back(ret);
                        num++;
                        ret.pop_back();
                        words[s] = false;
                    }
                }
            }
        }
    }

    void findLongestWordList(char beg, char end, int num) {
        if(num == 0)
            return ;

        if (num == -1)
        {
            for (auto line : table[beg - 'a'])
            {
                for (auto s : line)
                {
                    if (words[s] == false)
                    {
                        words[s] = true;
                        ret.push_back(s);
                        findLongestWordList(s.back(), end, num);

                        if (ret.back().back() == end)
                            if (ret.size() > max.size())
                                max = ret;
                        ret.pop_back();
                        words[s] = false;
                    }
                }
            }
        }
        else
        {
            for(auto line : table[beg-'a'])
            {
                for(auto s :line)
                {
                    if(words[s] == false)
                    {
                        words[s] = true;
                        ret.push_back(s);
                        num--;
                        findLongestWordList(s.back(), end, num);
                        if(num == 0 && ret.back().back()==end)
                            List.push_back(ret);
                        num++;
                        ret.pop_back();
                        words[s] = false;
                    }
                }
            }
        }
    }

    // 单词： 递归方法反向寻找最长链 实现原理同上
    void reverseLongestWordList(char end, int num) {
        if(num == 0)
            return ;

        if (num == -1)
        {
            for (int i = 0; i < 26; i++)
            {
                vector<string> line = table[i][end - 'a'];
                for (auto s : line)
                {
                    if (words[s] == false)
                    {
                        words[s] = true;
                        ret.push_back(s);
                        reverseLongestWordList(s.front(), num);
                        if (ret.size() > max.size())
                            max = ret;
                        ret.pop_back();
                        words[s] = false;
                    }
                }
            }
        }
        else
        {
            for (int i = 0; i < 26; i++)
            {
                vector<string> line = table[i][end - 'a'];
                for (auto s : line)
                {
                    if (words[s] == false)
                    {
                        words[s] = true;
                        ret.push_back(s);
                        num--;
                        reverseLongestWordList(s.front(), num);
                        if (num == 0)
                            List.push_back(ret);
                        num++;
                        ret.pop_back();
                        words[s] = false;
                    }
                }
            }
        }
    }

    // 字母： 递归方法寻找最长链
    void findLongestAlphaList(char beg, int num)
    {
        for (auto line : table[beg - 'a'])
        {
            for (auto s : line)
            {
                if (words[s] == false)
                {
                    words[s] = true;
                    ret.push_back(s);
                    alphalenth += s.size();
                    findLongestAlphaList(s.back(), num);
                    if(ret.size() > 1)
                    if (alphalenth > maxalphalength)
                    {
                        maxalphalength = alphalenth;    
                        max = ret;
                    }
                    alphalenth -= s.size();
                    ret.pop_back();
                    words[s] = false;
                }
            }
        }
    }

    void findLongestAlphaList(char beg, char end, int num)
    {
        for (auto line : table[beg - 'a'])
        {
            for (auto s : line)
            {
                if (words[s] == false)
                {
                    words[s] = true;
                    ret.push_back(s);
                    alphalenth += s.size();
                    findLongestAlphaList(s.back(), end, num);

                    if (ret.back().back() == end)
                        if(ret.size() > 1)
                        if (alphalenth > maxalphalength)
                        {
                            maxalphalength = alphalenth;
                            max = ret;
                        }
                    alphalenth -= s.size();
                    ret.pop_back();
                    words[s] = false;
                }
            }
        }
    }

    // 字母： 
    void reverseLongestAlphaList(char end, int num) {
        for(int i=0;i<26;i++) {
            vector<string> line = table[i][end-'a'];
            for(auto s : line) {
                if(words[s]==false) {
                    words[s]=true;
                    ret.push_back(s);
                    alphalenth += s.size();
                    reverseLongestAlphaList(s.front(), num);
                    if(ret.size() > 1)
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

    // 若求最长单词链，num=0,若不规定头尾字母，head,tail='\0'
    // 求最长的单词链
    vector<string> wordDFS(char head, char tail, int num);
    // 求最长的字母链
    vector<string> alphaDFS(char head, char tail, int num);

    vector<vector<string>> getList();

    // ProjectB
    // 从字符数组中创建图
    void create(vector<string> words);
};


#endif

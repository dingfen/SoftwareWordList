
#ifndef Core_h
#define Core_h
#include "WordGraph.h"

namespace Core
{
    // Project B
    /* vector<string> gen_chain_word(vector<string> words, char head, char tail);
     * 这个函数接受三个参数, words 为输入的单词列表, head 为所要求的单词链的头字母,
     * tail 万所要求的单词链尾字母,函数返回值为所要求的最长单词个数的单词链 vector<string>
     */
    vector<string> gen_chain_word(vector<string> words, char head, char tail);
    
    /* vector<string> gen_chain_char(vector<string> words, char head, char tail);
     * 这个函数接受三个参数, words 为输入的单词列表, head 为所要求的单词链的头字母,
     * tail 万所要求的单词链尾字母,函数返回值为所要求的最多字母个数的单词链 vector<string>
     */
    vector<string> gen_chain_char(vector<string> words, char head, char tail);
    
    /* vector<vector<string>> gen_chain_word(vector<string> words, int num, char head, char tail);
     * 这个函数接受三个参数, words 为输入的单词列表, head 为所要求的单词链的头字母,
     * tail 万所要求的单词链尾字母,函数返回值为所要求的单词链 num 为所要求的字母链的个数
     */
    vector<vector<string>> gen_chain_word(vector<string> words, int num, char head, char tail);

    // Project C
    /* 输入处理文本API 将文件名输入，然后返回处理后的不含任何重复单词的单词集合
     */
    vector<string> text_preprocess(string path);
}

#endif /* Core_h */

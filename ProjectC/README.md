# 2019 Software Engineering Lab 1-C

## [实验要求](./Project1.md)

## [实验报告](./doc/软件工程实验报告lab1-C.md)

## 编程环境

Qt 5.12 

linux Ubuntu 16.04 or Mac

C++11

## 实现的功能

软件输出的单词链会保存在`bin/answer.txt`中。

我们的软件可以实现在给定单词链长度下的所有单词链输出查询（即`-n -w `下），在此基础上，也可以进一步限定开头首尾字母，但不能对`-n -c`的情况进行处理。对于特殊的情况:

 - 若`-n`所要求的单词链长度大于最长的单词链长度，那么程序会输出错误信息进行提示：`Error: None word list satisfies your need.`
 - 若没有单词链存在（有两个及以上的单词组成的称之为单词链），程序会返回错误信息：`Error: Too few words in the file. And none word list exists.`
 - 若用户输入了一个不存在的文件，程序会进行报错：`The file xxxx cannot be found`
 - 若用户输入了一个不存在的选项，例如 `-x` ,程序也会进行报错
 - 用户交互时，一定要在所给的输入文件前指定选项`-n`还是`-w`，否则会报错：`Error: No main instruction`
 - 由于寻找最长单词链的算法复杂度较高，因此对于上百单词数量的文件，程序运行时间会比较长。

## 如何运行

### 命令行部分
在项目目录中，打开命令行，并进行编译

`> make`

Usage:  

`> bin/WordList [ OPTIONS ] [-c] or [-w] FILE`

Example:    

`> bin/WordList -n 3 -w  FILE`


## Core类 API接口

```C++
    /* vector<string> Core::gen_chain_word(vector<string> words, char head, char tail);
    * 这个函数接受三个参数, words 为输入的单词列表, head 为所要求的单词链的头字母, 
    * tail 为所要求的单词链尾字母,函数返回值为所要求的最长单词个数的单词链 vector<string>
    */
    vector<string> Core::gen_chain_word(vector<string> words, char head, char tail);

    /* vector<string> Core::gen_chain_char(vector<string> words, char head, char tail);
    * 这个函数接受三个参数, words 为输入的单词列表, head 为所要求的单词链的头字母, 
    * tail 为所要求的单词链尾字母,函数返回值为所要求的最多字母个数的单词链 vector<string>
    */
    vector<string> Core::gen_chain_char(vector<string> words, char head, char tail);

    /* vector<vector<string>> Core::gen_chain_word(vector<string> words, int num, char head, char tail);
    * 这个函数接受三个参数, words 为输入的单词列表, head 为所要求的单词链的头字母, 
    * tail 为所要求的单词链尾字母,函数返回值为所要求的单词链 num 为所要求的字母链的个数
    */
    vector<vector<string>> Core::gen_chain_word(vector<string> words, int num, char head, char tail);

    /* 若对首尾字母不做要求，则置head, tail 为 \0, 若对单词链长度不做要求，则置num为-1
     */


    // Project C
    /* 输入处理文本API 将文件名输入，然后返回处理后的不含任何重复单词的单词集合
     */
    vector<string> text_preprocess(string path);
```


## 小组成员

组长：丁峰	 组员：谢灵江 连家诚


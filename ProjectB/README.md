# 2019 Software Engineering Lab 2

## [实验要求](doc/Project1B.pdf)

## [实验报告](doc/软件工程第二次实验.md)

## 编程环境

## 开发环境
Qt 5.12 

linux Ubuntu 16.04 or Mac

C++11

## 测试用工具

lcov

## 如何运行

在项目目录`ProjectB/`中，打开命令行，输入

`> sh make_and_run.sh`

Tips:  执行上述命令后会
1. 将`src/`下的源代码进行编译，并生成测试需要的文件
2. 运行`bin/WordList`，参数为`test/`下的一些测试文件，可以自行修改。
3. 使用`lcov`工具，在当前目录下生成`result`文件夹，
4. 使用浏览器，打开文件夹中`index.html`可以看到各文件、函数的测试覆盖率


## Core类 API接口

```C++
    /* vector<string> Core::gen_chain_word(vector<string> words, char head, char tail);
    * 这个函数接受三个参数, words 为输入的单词列表, head 为所要求的单词链的头字母, 
    * tail 万所要求的单词链尾字母,函数返回值为所要求的最长单词个数的单词链 vector<string>
    */
    vector<string> Core::gen_chain_word(vector<string> words, char head, char tail);

    /* vector<string> Core::gen_chain_char(vector<string> words, char head, char tail);
    * 这个函数接受三个参数, words 为输入的单词列表, head 为所要求的单词链的头字母, 
    * tail 万所要求的单词链尾字母,函数返回值为所要求的最多字母个数的单词链 vector<string>
    */
    vector<string> Core::gen_chain_char(vector<string> words, char head, char tail);

    /* vector<vector<string>> Core::gen_chain_word(vector<string> words, int num, char head, char tail);
    * 这个函数接受三个参数, words 为输入的单词列表, head 为所要求的单词链的头字母, 
    * tail 万所要求的单词链尾字母,函数返回值为所要求的单词链 num 为所要求的字母链的个数
    */
    vector<vector<string>> Core::gen_chain_word(vector<string> words, int num, char head, char tail);

    /* 若对首尾字母不做要求，则置head, tail 为 \0, 若对单词链长度不做要求，则置num为-1
     */
```


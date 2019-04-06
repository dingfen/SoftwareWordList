# 软件工程实验报告——最长单词链——lab1-C

小组成员：丁峰、谢灵江、连家诚

## 功能实现

软件输出的单词链会保存在`bin/answer.txt`中。

我们的软件可以实现在给定单词链长度下的所有单词链输出查询（即`-n -w `下），在此基础上，也可以进一步限定开头首尾字母，但不能对`-n -c`的情况进行处理。

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
     * stirng path 为输入的文件名路径
     */
    vector<string> text_preprocess(string path);
```

### 错误样例

 - 若`-n`所要求的单词链长度大于最长的单词链长度，那么程序会输出错误信息进行提示：

    `Error: None word list satisfies your need.`
    错误样例：`bin/WordList -w test/test_1.txt -n 10`

 - 若没有单词链存在（有两个及以上的单词组成的称之为单词链），程序会返回错误信息：

    `Error: Too few words in the file. And none word list exists.`
    错误样例：`bin/WordList -w test/test_5.txt`

 - 若用户输入了一个不存在的文件，程序会进行报错：

    `The file xxxx cannot be found`
    错误样例：`bin/WordList -w test/test_notexist.txt`

 - 当使用`-h`与`-t`指定首尾字母，但随后传入的参数并非字母时将会报错：

    `Error: -t and -h must be followed by a letter.`
    错误样例：`bin/WordList -w test/test_1.txt -h ?`

 - 当使用`-n`指定单词链长度，`-n`若后面跟上浮点数，则程序会将其强制转换为整数，若跟上字符串，则会报错（在开头没有数字的情况下），若跟上负数，会报错：

    `Error: -n must be followed by a positive integer`

    样例：`bin/WordList -n 4.2 test/test_1.txt`相当于`-n 4`

    样例：`bin/WordList -n 4ab test/test_1.txt`相当于`-n 4`

    错误样例：`bin/WordList -n as test/test_1.txt`出现错误，程序异常退出

    错误样例：`bin/WordList -n -2 test/test_1.txt`出现错误，程序异常退出


 - 当用户输入了一个不存在的选项（如 `-x`）时报错：

    ` Error: unknown option ...`
    错误样例：`bin/WordList -x test/test_1.txt`

 - 当用户输入了多次`-c`与`-w`指令时报错：

    `Error: multiple main instructions`
    错误样例：`bin/WordList -c test/test_1.txt -w test/test_1.txt`

 - 当用户并未输入`-c -w`中的任一指令时报错：

    `Error: No main instruction`
    错误样例：`bin/WordList`

 - 由于寻找最长单词链的算法复杂度较高，因此对于上百单词数量的文件，程序运行时间会比较长。

### 错误处理

```C++
// 对于 -n 后接负数的情况进行处理
class NumException : public exception
{
    virtual const char* what() const throw() {
        return "Error: -n must be followed by a positive interger.";
    };
} numException;

// 对文件中单词过少情况进行的处理
class TooFewWordException : public exception
{
    virtual const char* what() const throw() {
        return "Error: Too few words in the file. And none word list exists.";
    };
} tooFewWord;

// 对文件中找不到合法的单词的处理
class NoneWordListException : public exception
{
    virtual const char* what() const throw() {
        return "Error: None word list satisfies your need.";
    };
} noWordList;

// 对 -h -t 后没有接字母的情况的处理
class NotLetterException : public exception
{
    virtual const char* what() const throw() {
        return "Error: -t and -h must be followed by a letter.";
    };
} wrongChar;

```



## 测试用例设计思想

测试用例一共11个

* 其中test_5与test_7分别测试了当文件为空时与文件中并不包含任何单词时的情况，
* test_2测试了文件中仅有不成链的单字组成的单词（a，I）的情况，
* test_8测试了整个文件中仅有一个单词的情况，是基础的特殊情况测试;
* test_4存在4个单词形成的链以及1个比该链字母数更多的单词，以及大小写混搭的情况，此测试错误样例是为了测试在`-c`模式下是否能够区分并找到单词链（即个数大于等于2），而并非输出单个长单词。
* test_9测试了当文件中的单词组成两个连通片，且“最多单词的单词链”与“最长单词的单词链”并非同一个单词链的情况，事实上本程序能够正确的按指令搜索并且输出。
* test_1由6个单词组成的环构成，用于简单测试`-n`的正确性。在参数值位于2-6之间时，`-n`都输出正确的6个结果，证明测试过关。
* test_11由随机生成的60个单词组成，用于测试性能，在一台性能较差的笔记本电脑使用该文件的测试中，`-c`与`-w`的命令仍能在数秒之内计算出答案。
* test_3由随机生成的100个单词组成，用于最终测试。使用`-c`与`-w`指令运行该文件已完全不能在可接受的时间内计算出结果，而使用`-n`指令时，当参数值<=7时耗时在1s以内;参数值为8时能计算出所有结果（440000+），但输出耗时过高。
* test_6与test_10是普通的测试样例。

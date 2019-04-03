# 2019 Software Engineering Lab 3

## [实验要求](./Project1.md)

## 编程环境

Qt 5.12 

linux Ubuntu 16.04 or Mac

C++11

## 如何运行

### 命令行部分
在项目目录中，打开命令行，并进行编译

`> make`

Usage:  

`> bin/WordList [ OPTIONS ] [-c] or [-w] FILE`

Example:    

`> bin/WordList -n 3 -w  FILE`

## 文件夹项目内容介绍
    -- bin
        WordList 可执行文件 通过makefile生成
    -- src
        CommandLineParse.cpp 命令行处理文件
        Core.cpp  Core类封装方法
        Core.h    Core类头文件
        WordGraph.cpp  WordGraph类方法实现，主要算法在这里实现
        WordGraph.h    WordGraph类头文件，定义了WordGraph类
    -- doc
        实验报告.md

## 软件功能实现情况

我们的软件可以实现在给定单词链长度下的所有单词链输出查询（即`-n -w `下），在此基础上，也可以进一步限定开头首尾字母，但不能对`-n -c`的情况进行处理。对于特殊的情况:

 - 若`-n`所要求的单词链长度大于最长的单词链长度，那么程序会输出错误信息进行提示。
 - 若没有单词链存在（有两个及以上的单词组成的称之为单词链），程序会返回错误信息。
 - 若用户输入了一个不存在的文件，程序会进行报错
 - 由于寻找最长单词链的算法复杂度较高，因此对于上百单词数量的文件，程序运行时间会比较长。

## 小组成员

组长：丁峰	 组员：谢灵江 连家诚


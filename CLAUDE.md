# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## 仓库用途

这个目录用于保存 LeetCode 习题集。题目按照题目类型或分类建立文件夹，每一道题都有独立的子文件夹，子文件夹中包含题目说明和代码解答。

## 目录结构

预期结构如下：

```text
<题目类型>/
  <题目名称或编号>/
    README.md 或 problem.md   # 题目说明
    <解法代码文件>            # 代码解答
```

当前仓库根目录没有统一的应用入口、包管理配置、构建系统或测试框架。除非之后添加了根目录级别的工具配置，否则应将每个题目文件夹视为相互独立的练习单元。

## 常用命令

由于当前仓库没有根目录级别的构建或测试配置，请在具体题目目录中使用对应语言的命令运行代码。

C++ 解法：

```bash
g++ -std=c++17 -Wall -Wextra -O2 solution.cpp -o solution
./solution
```

Python 解法：

```bash
python3 solution.py
```

JavaScript/TypeScript 解法：

```bash
node solution.js
```

如果某个题目目录内包含自己的测试文件、构建脚本或运行说明，优先遵循该题目目录内的本地说明。

## 工作约定

- 每道 LeetCode 题目保持自包含，放在独立文件夹中。
- 新增题目时，放到合适的题目类型或分类目录下。
- 题目文件夹中应包含题目说明或简要描述。
- 不要随意添加仓库级别的通用工具配置，除非该配置确实会被多个题目共同使用。

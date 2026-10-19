# Cpractice

LeetCode C 语言练习记录。

## 文件命名

`题号.题目名.c`，例如 `0001.两数之和.c`。用 VS Code 的 LeetCode 插件下载题目时会自动按这个规则生成。

## 本地编译运行

```bash
gcc -std=c17 -Wall -g -o a.exe 0001.两数之和.c
./a.exe
```

Windows 下可执行文件是 `a.exe`，在 PowerShell 里写成 `.\a.exe`。

## 说明

- 每道题保持一个可编译的 `main()`，方便直接本地跑样例。
- 提交时用插件里的「Submit」，不要用命令行。

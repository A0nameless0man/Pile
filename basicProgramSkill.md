# What You Need For Development

[toc]

## 开发环境

### 基本概念

#### 命令行

首先**命令行也是一种软件**

简称 `shell` 或 `cmd`

它读取用户的输入，调用相应的程序来做出相应。

也可以将一个程序的输出传给其它程序做输入。

以下是两种常见的 命令行 ：

1. bash

    - 历史悠久，使用广泛。

    - 程序的输入输出都是 **字符串**。

2. powershell

   - 新生事物，功能强大，但是支持者较少。

   - 程序输出的是对象，有属性和方法。

#### 环境变量

简单理解就是具有系统生存期的变量，开机时创建，关机时销毁。

用来保存某些系统设置。

比如：

- PATH

  - 这个变量可以被看做是一个目录的列表（各项之间用 `;` 分隔）。
  - 这个变量指明了当用户在命令行下输入命令时，系统应当到哪里去找这个命令的可执行文件。
  - 如果没有配置的话，虽然这个软件已经安装，但是系统不知道到哪里找可执行文件，所以还是会找不到命令。

### winddows下的开发工具安装

#### 怎么设置环境变量

#### gcc系

##### Mingw64

##### msys2

#### clang系

### 配置vsc以运行及调试

#### coderunner法

#### launch.json+task.json法

<!-- @import "./.vscode/tasks.json"{as="json" class="line-numbers" hide=true} -->
<!-- @import "./.vscode/launch.json"{as="json" class="line-numbers" hide=true} -->
##### json的格式

##### 配置以上json的方法

## 开发工具

### 编译器常用参数

#### 通用

- 指定语言标准

```sh{.line-numbers}sh
-std=c++11
-std=c++17
-std=c++2a
```

- 开启代码速度优化

```sh
-o2
```

- 把 `warning` 视为 `error`

```sh
-Werror
```

- 开启更多 `warning`

```sh
-Wall
```

- 关闭某种 `warning`

```sh
-Wno-xxx
```

#### clang-cl

clang-cl 是个 `clang` 的修改版以兼容 `cl.exe`

因此，它的参数是和 `cl.exe` 也就是 **老版** `Visual Studio` 的默认编译器 兼容的。

参数也有些不同。

生成 `.pdb` 调试信息文件以兼容 `cl.exe`

```sh
-Zi
```

允许使用 `exception`

```sh
-EHac
```

将下一个参数用 `clang` 的参数格式解析

```sh
-xclang
```

## 文档工具

### [markdown语法](https://www.runoob.com/markdown/md-tutorial.html)

#### [mermaid插件](https://mermaid-js.github.io/mermaid/#/)

##### graph

##### classDiagram

##### gantt

#### [vsc的markdown插件:Markdown Preview Enhanced](https://shd101wyy.github.io/markdown-preview-enhanced/#/zh-cn/)

### latex语法

## 开发流程

### git

#### git的使用

#### git连接远程仓库

##### 通用远程仓库

##### github

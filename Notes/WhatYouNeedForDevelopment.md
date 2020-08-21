# What You Need For Development

<!-- @import "[TOC]" {cmd="toc" depthFrom=2 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

- [概述](#概述)
- [开发环境](#开发环境)
  - [基本概念](#基本概念)
    - [命令行](#命令行)
    - [环境变量](#环境变量)
  - [Windows下的开发工具安装](#windows下的开发工具安装)
    - [怎么设置环境变量](#怎么设置环境变量)
    - [安装 `gcc`](#安装-gcc)
      - [通过 `msys2` 安装 `GNU` 软件环境](#通过-msys2-安装-gnu-软件环境)
    - [安装 `clang`](#安装-clang)
  - [配置vsc以运行及调试](#配置vsc以运行及调试)
    - [coderunner法](#coderunner法)
    - [launch.json+task.json法](#launchjsontaskjson法)
      - [json的格式](#json的格式)
      - [配置以上json的方法](#配置以上json的方法)
- [开发工具](#开发工具)
  - [编译器常用参数](#编译器常用参数)
    - [通用](#通用)
    - [clang-cl](#clang-cl)
- [文档工具](#文档工具)
  - [markdown语法](#markdown语法httpswwwrunoobcommarkdownmd-tutorialhtml)
    - [vsc的markdown插件:Markdown Preview Enhanced](#vsc的markdown插件markdown-preview-enhancedhttpsshd101wyygithubiomarkdown-preview-enhancedzh-cn)
      - [Markdown Preview Enhanced 内嵌的 PlantUML 工具](#markdown-preview-enhanced-内嵌的-plantuml-工具)
  - [latex语法](#latex语法)
- [开发流程](#开发流程)
  - [git](#git)
    - [git的使用](#git的使用)
    - [git连接远程仓库](#git连接远程仓库)
      - [通用远程仓库](#通用远程仓库)
      - [github](#github)
- [引用](#引用)
  - [task.json](#taskjson)
  - [launch.json](#launchjson)

<!-- /code_chunk_output -->

## 概述

开发所需的东西是及其广泛的，从知识到软硬件甚至舒适的椅子，都对开发效率有相当影响。

但是，在种种繁杂的事物中，有一些东西是万物的基础，比如语言、编辑器、编译器和代码管理工具之类。

这篇文章旨在介绍一些开发需要的工具，以及正确配置它们的方法。

本文假设读者对于 `C` 或 `C++` 有可以独立完成 `Hello World!` 的程度的了解。并且熟悉基本的电脑操作及一些涉及的概念。

如果在本文中见到不认识或不了解的概念或事物，请自行 [`百度`](http://www.baidu.com) 或 [`Google`](http://www.google.com)

## 开发环境

开发的环境是一个比较宽泛的概念，包括了开发中涉及的各种软硬件及其设置。

一个恰当配置的开发环境可以提高工作的效率，节约宝贵的生命。

针对不同的开发任务，需要配置不同的开发环境。

这一部分将介绍一套用于 `C` / `C++` 的，跨平台可用的开发环境。

### 基本概念

在开始之前，为了顺利的完成配置，让我们先了解一些基本概念。

#### 命令行

首先**命令行也是一种软件**

简称 `shell` 或 `cmd`

它读取用户的输入，调用相应的程序来做出响应。

也可以将一个程序的输出传给其它程序做输入。

可以看作是其它所有程序的一层代理，转发其它程序的输入输出。

或者一种原始的 UI

以下是两种常见的 命令行 ：

1. bash

    - 历史悠久，使用广泛。

    - 程序的输入输出都是 **字符串**。

2. powershell

   - 新生事物，功能强大，但是支持者较少。

   - 程序输出的是对象，有属性和方法。

#### 环境变量

简单理解就是具有系统生存期的变量，开机时创建，关机时销毁。

由名字和值组成。

都是字符串。

用来保存某些系统设置。

比如：

- PATH

  - 这个变量可以被看做是一个目录的列表（各项之间用字符 `;` 分隔）。
  - 这个变量指明了当用户在命令行下输入命令时，系统应当到哪里去找这个命令的可执行文件。
  - 如果没有配置的话，虽然这个软件已经安装，但是系统不知道到哪里找可执行文件，所以还是会找不到命令。

### Windows下的开发工具安装

由于历史原因， Windows 下长期缺乏统一的“软件商店”。

Windows 的软件安装逻辑又与 Unix 系有许多差别，虽然多数软件有针对 Windows 的发行版，但有时需要一些调整以正常工作。

#### 怎么设置环境变量

Unix 系统下，多数软件安装在 `/usr/bin` 下，而这个目录默认是在 `PATH` 里的，所以许多软件不会自动将自己的可执行文件所在的目录加入 `PATH` ，从而无法正常调用。

不过我们可以自己完成这缺失的一步。

>1. 右击 `我的电脑` / `此电脑`
>
>    - 桌面上没有的话，文件资源管理器里的也可以。
>
>1. 选择 `属性`
>
>1. 选择左侧列表中的 `高级系统设置`
>
>1. 选择 `高级` 页
>
>1. 点击下面 `环境变量` 的按钮。
>
>1. 可以选择编辑系统变量或用户变量，区别是系统变量是全局的，用户变量只有自>己看得见。
>
>1. 找到并选中 `希望修改的环境变量` ，大小写无所谓的。
>
>1. 点击 `编辑`，然后 `新建`
>
> 1. 没有 `新建` 按钮，可以直接编辑 `值` ，和已有内容用 `;` 分隔。
>
>1. 加入你需要的路径

当我们谈到要添加 `PATH` 或者 `路径` 时，还有一个要素是被添加的路径。

这个一般要找到刚安装的可执行文件的所在地。比如说直接全盘搜索。

#### 安装 `gcc`

`GCC` 并不提供单独的安装包，因为它的依赖特别多，因此通常是直接提供整个 `GUN` 软件环境。

<!-- ##### Mingw64

这个是 经典的 `Mingw` 的后继者，也是经常被建议使用的软件。

但是有个问题，更新比较慢，`gcc` 只到 8.1。

总之，先[下载](https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win64/Personal%20Builds/mingw-builds/8.1.0/threads-posix/seh/x86_64-8.1.0-release-posix-seh-rt_v6-rev0.7z)。
或者从文件服务器下载zip版。
然后解压，放到合适的地方，比如说 `C:/mingw`。
找到里面的 `bin` 目录，把这整个目录的路径加进 `PATH`。

>安装完毕记得测试，在命令行中执行 `g++ -v` ,输出 版本号 之类的调试信息为正常。 -->

<!--Mingw 已死-->

<!--待确认，有没有gdb-->

<!--
- 安装时，第一页选项中有一个要选架构，选择 `x86_64`
- 安装路径避免中文或者空格之类的。
- 由于缺少支持，可能会提示一些下载有关的错误，再试 **~~一~~** 次就好。
-->

<!--等安个虚拟机测试一下再继续-->
<!-- 网络反复出错，体验实在辣鸡 -->

##### 通过 `msys2` 安装 `GNU` 软件环境

简单来说，下载 `msys2` 的安装包，然后直接安装即可。

由于神秘的原因，有时候会卡在 66% 进度，任务管理器杀掉安装进程重开即可。

`msys2` 带了一套包管理系统叫 `pacman`.

基本上，只需要了解如下基础命令：

```sh
pacman -Syu #检查更新并更新
#如果pacman被更新了，请在看到提示后遵循提示强行终止pacman并再次执行如上命令

pacman -S *** #安装软件或软件包，比如基础开发环境包 "base-devel"
```

一般来说，建议安装 `base-devel` ，`make` , `ssh`, `gcc`.这几个，其它的软件可以根据需求选择。

另外，既然是包管理系统，那就不可避免的有源的问题。由于 `msys2` 的默认源在国外，访问速度极其缓慢，建议更换清华大学提供的源，方法见[清华的说明](https://mirror.tuna.tsinghua.edu.cn/help/msys2/)

如果在下载过程中网络波动，导致添加在头部的清华源失败，`pacman` 会回退到默认源。这时最好直接中断（ `ctrl` + `C` ）然后重开。

如果由于下载速度慢，经常失败，可以添加参数 `--disable-download-timeout` 来禁用下载超时。

<!-- #### 安装 `clang`

这个就要~~方便~~麻烦不少了。

还是先[下载](http://releases.llvm.org/9.0.0/LLVM-9.0.0-win64.exe).
安装，界面是英文的。
中间会有一步问你是不是要添加 `PATH` ，选中就不用手动加了。

然后就是 `clang` 是不包含头文件和静态库的。需要安装 `VisualStdio`，去借用 `msvc` 的头文件。

但是有个问题，搭配 `clang` 的调试器 `lldb` 还没有 `Windows` 版，恐怕只能输出调试。 -->

### 配置vsc以运行及调试

#### coderunner法

据说直接按照这个插件即可

#### launch.json+task.json法

##### json的格式

`json` 是一种具有格式的文本，它保存着 `json` 对象。

`json` 对象具有成员，成员有名字和值。名字必是字符串，值可以为字符串、数字、`json` 对象或 `json` 对象的数组。

`json` 对象包裹在一对大括号中，`json` 对象数组则是中括号。数组的成员之间，对象的成员之间用 `,` 分隔，最后一个项目后面没有逗号。成员的名字和值之间用 `:` 分隔。

##### 配置以上json的方法

`task.json` 定义一些 *Task* ，可以在 `F1` 选单中通过 `Run Task` 来执行。

`task.json` 的根对象有两个成员，一个是 `"version"` ,其值为一个字符串，当前为 `"2.0.0"` 。另一个是 `"tasks"` ,其值为一个包含了 `task` 对象的数组。

`task` 对象的成员大部分是可选的，但是有一些是必选的，比如 `"label"` 表示这个任务的名字。 `"type"` 表示这个任务的类型（一般填 `"shell"` )。`"command"` 表示这个任务应当调用哪个程序。还有可选成员 `"args"` 表示要给这个程序传什么样的参数。

这里特别提到，vscode支持一些内置变量，可以以 `shel 变量` 的形式调用，即 `${变量名}` 形式的内容会被替换为对应的变量值。很有用的内置变量比如 ：

|变量名|内容|
|:-:|:-:|
|`file`|调用task时编辑焦点所在的文件|
|`fileBasenameNoExtension`|上述文件的无扩展名的文件名|
|`fileDirname`|上述文件所在的目录|
|`workspaceRoot`|当前使用vscode打开的文件夹|

还有 `"dependsOrder"` 和 `"dependsOn"` 成员可以制定任务的依赖关系，极大的扩展了任务的功能。

可选成员 `"group"`则定义了任务的类型，这个对于其运行没有直接影响，但是会影响这个任务被显示时的分组。

为了支持跨平台，可以用 名为 `"linux"` 、`"windows"` 或 `"macos"` 的成员对象包裹个别成员来指定这些成员只在特定系统下有效。

`launch.json` 则定义了调试的不同配置。具体选项可以自行搜索，这里提三个因人而异的成员。

成员 `"preLaunchTask"` 的值应当是 `task.json` 中某个 `task` 的 `"label"`。表示在开始调试前应当调用这个任务，通常都是编译任务之类的。

成员 `"miDebuggerPath"` 应当指向 `gdb` 的绝对路径。

成员 `"program"` 则指向要调试的程序。

具体举例见后方引用小节

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

#### [vsc的markdown插件:Markdown Preview Enhanced](https://shd101wyy.github.io/markdown-preview-enhanced/#/zh-cn/)

##### [Markdown Preview Enhanced 内嵌的 PlantUML 工具](https://plantuml.com/zh/)

### latex语法

## 开发流程

### [git](https://www.runoob.com/git/git-basic-operations.html)

请学习以下章节

- git的使用
- git连接远程仓库
- 通用远程仓库
- github

## 引用

### task.json

<!-- @import "../.vscode/tasks.json"{as="json" class="line-numbers" hide=false} -->

### launch.json

<!-- @import "../.vscode/launch.json"{as="json" class="line-numbers" hide=false} -->

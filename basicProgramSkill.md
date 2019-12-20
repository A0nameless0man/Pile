[toc]

## 开发环境

### winddows下的开发工具安装

#### gcc系

##### Mingw64

##### msys2

#### clang系

### 配置vsc以运行及调试

#### coderunner法
#### launch.json+task.json法
##### json的格式
##### 配置以上json的方法

## 开发工具

### 编译器常用参数

#### 通用

指定语言标准

```{.line-numbers}
-std=c++11
-std=c++17
-std=c++2a
```

开启代码速度优化

```
-o2
```

把 `warning` 视为 `error`

```
-Wall
```

开启更多 `warning`

```
-Werror
```

关闭某种 `warning`

```
-Wno-xxx
```

#### clang-cl

clang-cl 是个 `clang` 的修改版以兼容 `cl.exe`

生成 `.pdb` 调试信息文件以兼容 `cl.exe`

```
-Zi
```

允许使用 `exception`

```
-EHac
```

将下一个参数用 `clang` 的参数格式解析

```
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

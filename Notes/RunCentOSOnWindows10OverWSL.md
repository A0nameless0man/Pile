## 为什么

因为有一些传统的工具比如 `curl` 等等在 `PowerShell` 中的替代的参数不一样，不想学习新的参数，所以搞个这个替代一下。

不过 `PowerShell` 是确实强大。

## 环境的准备

1. 准备使用的操作系统的 `Docker` 镜像
	- 我使用的是 [CentOS8](https://github.com/CentOS/sig-cloud-instance-images/blob/CentOS-8-x86_64/docker/centos-8-container.tar.xz)
2. 开启 `WSL`

	- 可以通过 `PowerShell` 执行

```PowerShell
Enable-WindowsOptionalFeature -Online -FeatureName Microsoft-Windows-Subsystem-Linux
```

## 安装安装工具

这里我们借助一个工具软件来安装需要的安装工具
~~禁止套娃~~

### 安装 `Chocolatey`

- [Chocolatey](https://chocolatey.org/)是一个 Windows 下的包管理工具，似乎是基于 `PowerShell` 的。
- 官方提供了安装脚本 [install.ps1](https://chocolatey.org/install.ps1)
- 但是 `PowerShell` 默认禁止执行脚本，可以在有管理员权限的 `PowerShell` 中使用以下命令绕过

```PowerShell
Set-ExecutionPolicy Bypass -Scope Process -Force; iex ((New-Object System.Net.WebClient).DownloadString('https://chocolatey.org/install.ps1'))
```

### 然后利用 `Chocolatey` 安装 `LxRunOffline`

- `LxRun.exe` 曾经是系统自带的，但不知道为什么从 1804 后被删除。
- 执行以下命令
由于 `Chocolatey` 刚安装，需要重启 `PowerShell` 来载入 `PATH` 。

```PowerShell
choco install lxrunoffline
```

## 安装系统

```PowerShell
LxRunOffline install -n ${OSName} -d ${InstallPath} -f ${DockerImageFile}
```

其中

`OSName` 是你希望这个系统在 wsl 中记录的名字，是用于管理的，虽然可以随意制定，最好还是有意义的名称

`InstallPath` 是希望系统被安装的目录，最好是空的以免发生文件名的冲突

`DockerImageFile` 是下载的 `Docker` 镜像

## 运行

设置默认启动的系统（如果安装了多个 `WSL` 系统）

```PowerShell
 wslconfig.exe /setdefault ${OSName}
```

启动

```PowerShell
wsl -d ${OSName}
```

默认以 `root` 身份登陆，感觉有点不安全，到时候再研究一下。

### 颜色修正

```bash
PS1 = `\[\e]0;\u@\h: \w\a\]${debian_chroot:+($debian_chroot)}\033[38;5;3m\t \033[38;5;2m\d \[\033[38;5;88m\]\u\033[00m@\033[01;32m\h\[\033[00m\]:\[\033[01;34m\]\w\[\033[00m\]\$`
```

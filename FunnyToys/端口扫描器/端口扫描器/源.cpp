#define _CRT_SECURE_NO_WARNINGS
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <Winsock2.h>
#include <commctrl.h>
#include <queue>
#include <set>
#include <stdio.h>
#include <stdlib.h>
//#include <windows.h>  //加这个头文件后面sleep会用到
//#pragma comment(lib,"ws2_32.lib")
#pragma comment(lib, "ws2_32.lib")

#define NETWORK_ERROR -1
#define NETWORK_OK    0
#define PORT_MIN      1
#define PORT_MAX      65535
const int        ThreadCount = 16;
std::set<HANDLE> hThreads;
HANDLE           hThread;
std::set<DWORD>  hIDs;
DWORD            hID;
std::queue<int>  ports;
char             hostname[30];

int   starting_port = 0;
int   ending_port   = 0;
int   nopen         = 0;
int   ThreadOpened  = ThreadCount;
DWORD portscan();
bool  ThreadLock;  //
int   main()
{
    int ret;

    WSADATA dat;  //库版本信息结构
                  // WSADATA结构被用来储存调用AfxSocketInit全局函数返回的Windows Sockets初始化信息。
    DWORD version;

    version = MAKEWORD(2, 2);
    // MAKEWORD(2,2)表示使用WINSOCK2版本.wsaData用来存储系统传回的关于WINSOCK的资料.

    ret = WSAStartup(version, &dat);
    //此函数在应用程序中初始化winsockDLL,格式：int PASCAL FAR WSAStartup( WORD wVersionRequested,
    //LPWSADATA lpWSAData );

    if(ret != 0)
    {
        printf("加载套接字失败!\n");
        WSACleanup();
        return NETWORK_ERROR;
    }
    if(ret == 0)
    {

        printf("Enter hostname:");
        scanf("%s", hostname);

        printf("Enter starting port:");
        scanf("%d", &starting_port);

        if(starting_port < PORT_MIN)
        {
            printf("起始端口出错\n");
            WSACleanup();
            return NETWORK_ERROR;
        }

        printf("Enter ending port:");
        scanf("%d", &ending_port);

        if(ending_port > PORT_MAX)
        {
            printf("终点端口出错\n");
            WSACleanup();
            return NETWORK_ERROR;
        }

        printf("\nScanning [%s]...\n", hostname);
        for(int i = starting_port; i <= ending_port; i++)
        {
            ports.push(int(i));
        }  //将任务加入队列
        ThreadLock = false;
        for(int i = 0; i < ThreadCount; i++)
        {
            hThread = CreateThread(0, 0, (LPTHREAD_START_ROUTINE) portscan, 0, 0, &hID);
            // Thread1 = CreateThread(  0, 默认线程堆栈大小 0(2M) ThreadProc,线程入口函数 0,创建标识
            // 0代表立即执行,&Thread1ID获得线程ID);

            if(hThread == 0)
            {
                printf("创建线程失败\n");
                WSACleanup();
                return NETWORK_ERROR;
            }
            else
            {
                hThreads.insert(hThread);
                hIDs.insert(hID);
            }
        }
        // Sleep(-1);//进程挂起
        while(ThreadOpened)
            ;  //等到所有进程结束后
        printf("Number of ports opened = %d\n", nopen);
    }
    WSACleanup();
    // WSAStartup应该与WSACleanup成对使用，WSAStartup的功能是初始化Winsock DLL，
    // WSACleanup是来解除与Socket库的绑定并且释放Socket库所占用的系统资源。

    return NETWORK_OK;
}

DWORD portscan()
{
    // printf("\nScanning [%s]...\n", hostname);
    int i, nret;

    SOCKET    thesocket;  //定义服务器套接字
    LPHOSTENT hostent;

    thesocket =
      socket(AF_INET,
             SOCK_STREAM,
             IPPROTO_TCP);  //第一个变量为协议簇，第二个变量为套接字类型，第三个变量为使用的通信协议
    hostent = gethostbyname((
      hostname));  // gethostbyname()返回对应于给定主机名的包含主机名字和地址信息的hostent结构指针。

    // for (i = (int)ports.front(),ports.pop(); !ports.empty(); i=(int)ports.front(),ports.pop())
    while(!ports.empty())
    {
        if(!ThreadLock)
        {
            ThreadLock = true;
            i          = ports.front();  //提取队列中第一个元素
            ports.pop();                 //从队列中删去第一个元素
            ThreadLock = false;
        }  //进程锁防止读取冲突
        else
        {
            continue;
        }

        if(i < 0)
        {
            break;
        }
        // printf("port:%dscaning\n", i);
        SOCKADDR_IN hostinfo;  //服务器地址信息结构

        hostinfo.sin_family = AF_INET;
        hostinfo.sin_addr = *((LPIN_ADDR) *hostent->h_addr_list);  // sin.addr储存IP地址
        hostinfo.sin_port = htons(i);                              // sin_port储存端口号

        // htons 是将整型变量从主机字节顺序转变成网络字节顺序，
        // 就是整数在地址空间存储方式变为：高位字节存放在内存的低地址处。

        nret = connect(thesocket,
                       (LPSOCKADDR) &hostinfo,
                       sizeof(hostinfo));  // connect（）函数：发送一个连接请求，返回值为 0成功。
        // TCP是面向连接的、可靠的传输协议。
        //参数一：套接字描述符
        //参数二：指向数据机构sockaddr的指针，其中包括目的端口和IP地址
        //参数三：参数二sockaddr的长度，可以通过sizeof（struct sockaddr）获得
        //返回值为0代表成功
        if(nret == 0)
        {
            printf("\n\t%d\n", i);
            ++nopen;
        }
    }

    printf("\nScan complete.\n\n");
    // printf("Number of ports opened = %d\n", nopen);
    ThreadOpened--;
    closesocket(thesocket);

    return 0;
}

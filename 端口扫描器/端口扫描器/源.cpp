#define _CRT_SECURE_NO_WARNINGS
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include<stdio.h>
#include<Winsock2.h>
#include<windows.h>//�����ͷ�ļ�����sleep���õ� 
#include<commctrl.h>
#include<stdlib.h>
#include<set>
#include<queue>
//#pragma comment(lib,"ws2_32.lib")
#pragma comment(lib,"ws2_32.lib")

#define NETWORK_ERROR -1
#define NETWORK_OK 0
#define PORT_MIN 1
#define PORT_MAX 65535
const int ThreadCount = 16;
std::set<HANDLE> hThreads;
HANDLE hThread;
std::set<DWORD> hIDs;
DWORD hID;
std::queue<int> ports;
char hostname[30];

int starting_port = 0;
int ending_port = 0;
int nopen = 0;
int ThreadOpened = ThreadCount;
DWORD portscan();
bool ThreadLock;//
int main()
{
	int ret;

	WSADATA dat;  //��汾��Ϣ�ṹ   
//WSADATA�ṹ�������������AfxSocketInitȫ�ֺ������ص�Windows Sockets��ʼ����Ϣ��
	DWORD version;

	version = MAKEWORD(2, 2);
	//MAKEWORD(2,2)��ʾʹ��WINSOCK2�汾.wsaData�����洢ϵͳ���صĹ���WINSOCK������.

	ret = WSAStartup(version, &dat);
	//�˺�����Ӧ�ó����г�ʼ��winsockDLL,��ʽ��int PASCAL FAR WSAStartup( WORD wVersionRequested,  LPWSADATA lpWSAData );

	if (ret != 0)
	{
		printf("�����׽���ʧ��!\n");
		WSACleanup();
		return NETWORK_ERROR;
	}
	if (ret == 0)
	{

		printf("Enter hostname:");
		scanf("%s", hostname);

		printf("Enter starting port:");
		scanf("%d", &starting_port);

		if (starting_port < PORT_MIN)
		{
			printf("��ʼ�˿ڳ���\n");
			WSACleanup();
			return NETWORK_ERROR;
		}

		printf("Enter ending port:");
		scanf("%d", &ending_port);

		if (ending_port > PORT_MAX)
		{
			printf("�յ�˿ڳ���\n");
			WSACleanup();
			return NETWORK_ERROR;
		}

		printf("\nScanning [%s]...\n", hostname);
		for (int i = starting_port; i <= ending_port; i++)
		{
			ports.push(int(i));
		}//������������
		ThreadLock = false;
		for (int i = 0; i < ThreadCount; i++)
		{
			hThread = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)portscan, 0, 0, &hID);
			//Thread1 = CreateThread(  0, Ĭ���̶߳�ջ��С 0(2M) ThreadProc,�߳���ں���  0,������ʶ 0��������ִ��,&Thread1ID����߳�ID);

			if (hThread == 0)
			{
				printf("�����߳�ʧ��\n");
				WSACleanup();
				return NETWORK_ERROR;
			}
			else
			{
				hThreads.insert(hThread);
				hIDs.insert(hID);
			}

		}
		//Sleep(-1);//���̹��� 
		while (ThreadOpened);//�ȵ����н��̽�����
		printf("Number of ports opened = %d\n", nopen);
	}
	WSACleanup();
	//WSAStartupӦ����WSACleanup�ɶ�ʹ�ã�WSAStartup�Ĺ����ǳ�ʼ��Winsock DLL��
	//WSACleanup���������Socket��İ󶨲����ͷ�Socket����ռ�õ�ϵͳ��Դ��   

	return NETWORK_OK;
}

DWORD portscan()
{
	//printf("\nScanning [%s]...\n", hostname);
	int i, nret;

	SOCKET thesocket;//����������׽��� 
	LPHOSTENT hostent;

	thesocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);//��һ������ΪЭ��أ��ڶ�������Ϊ�׽������ͣ�����������Ϊʹ�õ�ͨ��Э��
	hostent = gethostbyname((hostname));            //gethostbyname()���ض�Ӧ�ڸ����������İ����������ֺ͵�ַ��Ϣ��hostent�ṹָ�롣

	//for (i = (int)ports.front(),ports.pop(); !ports.empty(); i=(int)ports.front(),ports.pop())
	while (!ports.empty())
	{
		if (!ThreadLock)
		{
			ThreadLock = true;
			i = ports.front();//��ȡ�����е�һ��Ԫ��
			ports.pop();//�Ӷ�����ɾȥ��һ��Ԫ��
			ThreadLock = false;
		}//��������ֹ��ȡ��ͻ
		else
		{
			continue;
		}

		if (i < 0)
		{
			break;
		}
		//printf("port:%dscaning\n", i);
		SOCKADDR_IN hostinfo;//��������ַ��Ϣ�ṹ 

		hostinfo.sin_family = AF_INET;
		hostinfo.sin_addr = *((LPIN_ADDR)*hostent->h_addr_list);   //sin.addr����IP��ַ
		hostinfo.sin_port = htons(i);                            //sin_port����˿ں�

		//htons �ǽ����ͱ����������ֽ�˳��ת��������ֽ�˳�� ���������ڵ�ַ�ռ�洢��ʽ��Ϊ����λ�ֽڴ�����ڴ�ĵ͵�ַ����

		nret = connect(thesocket, (LPSOCKADDR)&hostinfo, sizeof(hostinfo)); //connect��������������һ���������󣬷���ֵΪ 0�ɹ��� 
		//TCP���������ӵġ��ɿ��Ĵ���Э�顣  
		//����һ���׽���������
		//��������ָ�����ݻ���sockaddr��ָ�룬���а���Ŀ�Ķ˿ں�IP��ַ
		//��������������sockaddr�ĳ��ȣ�����ͨ��sizeof��struct sockaddr�����
		//����ֵΪ0����ɹ�
		if (nret == 0)
		{
			printf("\n\t%d\n", i);
			++nopen;
		}
	}

	printf("\nScan complete.\n\n");
	//printf("Number of ports opened = %d\n", nopen);
	ThreadOpened--;
	closesocket(thesocket);

	return 0;

}

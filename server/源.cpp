#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <stdio.h>
#include <winsock2.h>
#include <string>
#pragma comment (lib, "ws2_32.lib")  //���� ws2_32.dll
int main() {
	//��ʼ�� DLL
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);
	//�����׽���
	SOCKET servSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	//���׽���
	sockaddr_in sockAddr;
	memset(&sockAddr, 0, sizeof(sockAddr));  //ÿ���ֽڶ���0���
	sockAddr.sin_family = PF_INET;  //ʹ��IPv4��ַ
	sockAddr.sin_addr.s_addr = inet_addr("192.168.125.1");  //�����IP��ַ
	sockAddr.sin_port = htons(1234);  //�˿�
	bind(servSock, (SOCKADDR*)& sockAddr, sizeof(SOCKADDR));
	//�������״̬
	listen(servSock, 20);
	//���տͻ�������
	SOCKADDR clntAddr;
	int nSize = sizeof(SOCKADDR);
	SOCKET clntSock = accept(servSock, (SOCKADDR*)& clntAddr, &nSize);
	//��ͻ��˷�������
	const char str1[] = "the first word:Hello World";
	send(clntSock, str1, strlen(str1) + sizeof(char), NULL);
	//�ر��׽���
	closesocket(clntSock);
	closesocket(servSock);
	//��ֹ DLL ��ʹ��
	WSACleanup();
	return 0;
}
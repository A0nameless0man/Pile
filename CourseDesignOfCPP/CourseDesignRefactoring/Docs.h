#pragma once
#include<string>
namespace Docs
{
	using S = const std::string;
	S hashSalt = "mySpecialSalt";
	S help = R"()";
	S argForLoginType = "-t";
	S loginTypeNote = R"(��ѡ���½�û�����:
a:	����Ա
s:	ѧ��)";
	S unKnowLoginTypeNote = R"(��½�û����ʹ���,������)";
	S sexTypeNote = R"(�������Ա�:
m:	��
f:	Ů
u:	����)";
	S unKnowSexTypeNote = R"(�Ա����ʹ���,������)";
}
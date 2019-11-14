#include"Server.h"

PWD hash(const PWD& in)
{
	return MD5(in + Docs::hashSalt).md5();
}
#include<cstdlib>
#include"BigInt.h"
int main(void)
{
	bit::BigInt a(bit::DEC, -10);
	bit::BigInt b(bit::DEC, 10);
	bit::BigInt c(bit::DEC, -5);
	bit::BigInt d(bit::DEC, 5);
	bit::BigInt e(bit::DEC, 12);
	//std::cout << a + b << std::endl;
	//std::cout << a - a << std::endl;
	//std::cout << b - b << std::endl;
	//Check(a * 0);
	//Check(b * 14);
	//Check(c * 14);
	//Check(d * 14);
	//Check(a*b);
	//Check(b*c);
	int k;
	std::cin >> k;
	while (std::cin>>a>>b)
	{
		//std::cin >> a >> b;
		//Check(a);
		//Check(b);
		//Check(a*b);
		//Check(b*a);
		//Check(a + b);
		//Check(b + a);
		//Check(a - b);
		//Check(b - a);
		//Check(a / b);
		//Check(b / a);
		std::cout << a / b << std::endl;
	}
	//system("pause");
	return 0;
}
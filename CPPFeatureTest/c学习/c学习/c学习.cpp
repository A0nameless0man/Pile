// c学习.cpp: 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include<filesystem>
#include <iostream>
#include<sstream>
#include<fstream>
#include<iomanip>
#include <math.h>
#include<string>
#include<queue>
#include<stack>
#include<vector>
#include<list>
#include<map>
#include<algorithm>
#include<time.h>
#define START(x) std::cout<<"\tStart:"<<#x<<std::endl;{using namespace x;
#define END(x) }std::cout<<"\tEnd:"<<(#x)<<std::endl<<std::endl;
#define CHECK(x) std::cout<<#x<<" is : "<<(x)<<std::endl;
#define TIMING(x) {clock_t start = clock();(x);clock_t end = clock();std::cout<<"It takes "<<(((double)end-start)/CLOCKS_PER_SEC)<<" seconds to exec "<<#x<<std::endl;}
template<typename T>
std::ostream& operator<<(std::ostream& s, const std::list<T>& v) {
	s.put('[');
	char comma[3] = { '\0', ' ', '\0' };
	for (const auto& e : v) {
		s << comma << e;
		comma[0] = ',';
	}
	return s << ']';
}
template<typename T1, typename T2>
std::ostream& operator<<(std::ostream& s, const std::map<T1, T2>& v) {
	s << "[\n";
	char comma[3] = { '\0', '\0', '\0' };
	for (const auto& e : v) {
		s << comma << '{' << e.first << "," << e.second << "}";
		comma[0] = '\n';
	}
	return s << "\n]";
}
namespace Section10
{
	namespace Question3
	{

	}
	namespace Question5
	{
		template<typename T, class Container = std::vector<T> >
		[[nodiscard]] Container josephQuestion(T n, T m)
		{
			Container container, result;
			for (T i = 1; i <= n; i++)
			{
				container.push_back(i);
			}
			while (!container.empty())
			{
				Container::iterator iter = container.begin();
				for (T i = 0; i < m; i++)
				{
					++iter;
					if (iter == container.end())
					{
						iter = container.begin();
					}
				}
				result.push_back(*iter);
				iter = container.erase(iter);
			}
			return result;
		}
	}
	namespace Question6
	{
		template<class Container, class iter = Container::iterator >
		void exchange(Container & c1, iter iter1, Container & c2, iter iter2)
		{
			Container temp1(iter1, c1.end());
			Container temp2(iter2, c2.end());
			c1.erase(iter1, c1.end());
			c2.erase(iter2, c2.end());
			c1.insert(c1.end(), temp2.begin(), temp2.end());
			c2.insert(c2.end(), temp1.begin(), temp1.end());
			return;
		}
	}
	namespace Question7
	{
		template<class Container = std::priority_queue<int> >
		void test(void)
		{
			std::vector vec1{ 5,1,4,6 }, vec2{ 2,3 };
			Container container;
			std::cout << std::endl;
			for (auto u : vec1) { container.push(u); }
			for (int i = 0; i < 2; i++)
			{
				CHECK(container.top());
				container.pop();
			}
			for (auto u : vec2) { container.push(u); }
			for (int i = 0; i < 2; i++)
			{
				CHECK(container.top());
				container.pop();
			}
		}
		template<>
		void test<std::queue<int> >(void)
		{
			std::vector vec1{ 5,1,4,6 }, vec2{ 2,3 };
			std::queue<int> container;
			std::cout << std::endl;
			for (auto u : vec1) { container.push(u); }
			for (int i = 0; i < 2; i++)
			{
				CHECK(container.front());
				container.pop();
			}
			for (auto u : vec2) { container.push(u); }
			for (int i = 0; i < 2; i++)
			{
				CHECK(container.front());
				container.pop();
			}
		}
	}
	namespace Question8
	{
		[[nodiscard]] std::map<std::string, int> count(std::istream& in)
		{
			std::string buffer;
			std::map<std::string, int> result;
			while (in >> buffer)
			{
				++result[buffer];
			}
			return result;
		}
	}
}
namespace Section11
{
	namespace Question3
	{

	}
	namespace Question4
	{

	}
	namespace Question5
	{

	}
	namespace Question6
	{
		class Dog
		{
		public:
			Dog(int age = 0, double weight = 0) :age(age), weight(weight) { ; }
			friend std::ostream& operator<<(std::ostream& os, const Dog& dog) { return os << dog.age << " " << dog.weight; }
			friend std::istream& operator>>(std::istream& is, Dog& dog) { return is >> dog.age >> dog.weight; }
		private:
			int age;
			double weight;
		};
	}
	namespace Question8
	{

	}
	namespace Question9
	{
		void addLineCount(std::filesystem::path from, std::filesystem::path to = "")
		{
			bool needMoveBack = false;
			if (to.empty())
			{
				to = std::filesystem::temp_directory_path() / from.filename();
				needMoveBack = true;
			}
			std::fstream in(from, std::ios_base::in), out(to, std::ios_base::out);
			size_t lineCount = 0;
			std::string buffer;
			while (std::getline(in, buffer))
			{
				out << std::to_string(lineCount) + " " + buffer << std::endl;
				lineCount++;
			}
			out.close();
			in.close();
			if (needMoveBack)
			{
				std::filesystem::rename(to, from);
			}
			return;
		}
	}
	namespace Question10
	{
		std::map<wchar_t, size_t> count(std::filesystem::path target)
		{
			std::wfstream in(target, std::ios_base::in);
			std::map<wchar_t, size_t> result;
			wchar_t buffer;
			while (in >> buffer)
			{
				if (buffer == '\n')
				{
					continue;
				}
				else
				{
					++result[buffer];
				}
			}
			return result;
		}
	}
}
namespace Section12
{
	namespace Question4
	{
		class Exception
		{
		public:
			Exception(std::string reason = "Unknow Error") :reason(reason) { ; }
			virtual const std::string what(void)const { return reason; }
		private:
			std::string reason;
		};
		class OutofMemory :public Exception
		{
			const std::string what(void)const { return "Not have enough Memory"; }
		};
	}
	namespace Question5
	{
		using Exc = Section12::Question4::Exception;
		using OutofMemory = Section12::Question4::OutofMemory;
	}
}
int _main(void)
{
	START(std);
	{
		/*START(Section10);
		{
			START(Question3);
			{
				std::vector<int> vec;
				for (int i = 0; i < 10; i++)
				{
					CHECK((vec.push_back(i), vec.back()));
					CHECK(vec.capacity());
				}
			}
			END(Question3);
			START(Question5);
			{
				TIMING((josephQuestion(10000, 10)));
				TIMING((josephQuestion<int, std::deque<int> >(10000, 10)));
				TIMING((josephQuestion<int, std::list<int> >(10000, 10)));
			}
			END(Question5);
			START(Question6);
			{
				std::list<int> list1 = { 1,1,1 }, list2 = { 2,2,2 };
				CHECK(list1);
				CHECK(list2);
				exchange(list1, ++list1.begin(), list2, ++list2.begin());
				CHECK(list1);
				CHECK(list2);
			}
			END(Question6);
			START(Question7);
			{
				CHECK((test<std::stack<int> >(),""));
				CHECK((test<std::queue<int> >(), ""));
				CHECK((test<std::priority_queue<int> >(), ""));
			}
			END(Question7);
			START(Question8);
			{
				cout <<"Result is : "<< count(std::stringstream("a aa b bb aa b")) << std::endl;
				//count(std::cin);
			}
			END(Question8);
		}
		END(Section10);*/
		START(Section11);
		{
			std::filesystem::path testFile[] = { "test1.txt" ,"test2.txt","sample.txt","sampleOut.txt","sampleOut2.txt" };
			START(Question3);
			{
				{
					std::fstream fs(testFile[0], std::ios_base::out);
					fs << "Writed!" << std::endl;
					fs.close();
				}
				{
					std::fstream fs(testFile[0]);
					std::string readBuffer;
					if (getline(fs, readBuffer))
					{
						std::cout << readBuffer << std::endl;
					}
					else
					{
						std::cout << "Failed" << std::endl;
					}
				}
			}
			END(Question3);
			START(Question4);
			{
				(std::fstream(testFile[0], std::ios_base::app | std::ios_base::out) << "Added!").close();
			}
			END(Question4);
			START(Question5);
			{
				std::fstream fs(testFile[0]);
				std::string readBuffer;
				while (getline(fs, readBuffer))
				{
					std::cout << readBuffer << std::endl;
				}

			}
			END(Question5);
			START(Question6);
			{
				(std::fstream(testFile[1], std::ios_base::out) << Dog(10, 11)).close();
				Dog dog;
				(std::fstream(testFile[1], std::ios_base::in) >> dog).close();
				CHECK(dog);
			}
			END(Question6);
			START(Question8);
			{
				int theNum = 123;
				std::cout << std::setiosflags(std::ios_base::dec) << theNum
					<< std::resetiosflags(std::ios_base::dec) << std::endl
					<< std::setiosflags(std::ios_base::oct) << theNum
					<< std::resetiosflags(std::ios_base::oct) << std::endl
					<< std::setiosflags(std::ios_base::hex) << theNum
					<< std::resetiosflags(std::ios_base::hex) << std::endl;
			}
			END(Question8);
			START(Question9);
			{
				addLineCount(testFile[2], testFile[3]);
			}
			END(Question9);
			START(Question10);
			{
				(std::wfstream(testFile[4], std::ios_base::out) << count(testFile[2]));
			}
			END(Question10);
		}
		END(Section11);
		START(Section12);
		{
			START(Question4);
			{
				try
				{
					throw Exception();
				}
				catch (const Exception& e)
				{
					std::cout << e.what() << std::endl;
				}
				try
				{
					throw OutofMemory();
				}
				catch (const Exception& e)
				{
					std::cout << e.what() << std::endl;
				}
			}
			END(Question4);
			START(Question5);
			{
				try
				{
					int* ptrInt = new int[0xfffffff];
					if (ptrInt == nullptr)
					{
						throw OutofMemory();
					}
				}
				catch (const Exc& e)
				{
					std::cout << e.what() << std::endl;
				}
			}
			END(Question5);
		}
		END(Section12);
	}
	END(std);
	return 0;
}
int main(void)
{
	return _main();
}
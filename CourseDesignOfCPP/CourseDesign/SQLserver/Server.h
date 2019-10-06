#pragma once
#include<iostream>
#include<stack>
#include<map>
#include<vector>
#include<set>
#include<string>
#include<sstream>
#include<functional>
#include"Format.h"
#include"Format.cpp"

using ExamPoint = double;
using ClassHour = double;
using ID = std::string;
using PWD = std::string;
using Name = std::string;
using StuClass = std::string;
using StuGrade = size_t;
using SubjectName = std::string;
enum Sex :char;
//class RWlock;//giveup thread safety
class User;
class Student;
using IDVec = std::vector<ID>;
using IDset = std::set<ID>;
using StudentVec = std::vector<Student>;
class StudentList;
class Score;
class Point;//data class
using ScoreMap = std::map<SubjectName, Point>;
using SingleScore = std::pair<SubjectName, Point>;

//class BaseIndex;
//class MapIndex;
//class IDindex;
class Key;
using KeyName = std::string;
class KeyWord;
class KeyWordType;//index class

class SQLrequest;
class Column;
class ColumnFilter;
class WhereFilter;
class Result;
using Record = std::vector<KeyWord>;
class GoodResult;
class SuccessResult;
class FailResult;
class RefuleResult;//SQL class

enum Sex :char
{
	male, female, unKnown
};
template<>
std::string format(const Sex sex);
template<class Is = std::istream>
Is& deFormat(Is& is, Sex& sex);

class User
{
private:
	Name name;
	ID id;
	Sex sex;
	PWD pwd;
public:
	User(ID id, PWD pwd, Name name = "John Doe", Sex sex = unKnown);
	Name getName()const;
	//bool setName(Name newName);
	bool login(PWD token)const;
	bool setPWD(PWD newPWD);
	ID getID()const;
	Sex getSex()const;
};
template<>
std::string format(const User user);
template<class Is = std::istream>
Is& deFormat(Is& is, User& user);
PWD hash(const PWD& in);

class Point
{
private:
	ExamPoint point;
	ClassHour classHour;
public:
	Point(ExamPoint point, ClassHour classHour = 1);
	bool setPoint(ExamPoint newPoint);
	ExamPoint getPoint()const;
	ClassHour getClassHour()const;
	bool operator<(const Point& b)const;
};
template<class vec = std::vector<Point> >
ExamPoint getGPA(const vec);
template<class vec = std::vector<Point> >
ExamPoint getTotalClassHour(const vec);
template<>
std::string format(const Point point);
template<class Is = std::istream>
Is& deFormat(Is& is, Point& point);

class Score
{
private:
	ScoreMap Points;
public:
	Score();
	Score(SingleScore sig);
	ExamPoint getPoint(SubjectName subjectName)const;
	bool setPoint(SubjectName subjectName, ExamPoint newPoint);
	bool setPoint(const Score& newScore);
	ClassHour getClassHour(SubjectName subjectName)const;
	bool contains(SubjectName subjectName)const;
	bool contains(const Score& newScore)const;
	bool addSubject(SubjectName subjectName, Point point);
	bool addSubject(const Score& newScore);
	bool removeSubject(SubjectName subjectName);
	bool removeSubject(const Score& newScore);
	template<class OP = std::equal_to<ExamPoint> >
	bool compare(const Score& stand)const;
	ExamPoint getGPA()const;
	ClassHour getTotalClassHour()const;
	operator ScoreMap()const;
};
bool operator<(const SingleScore& a, const SingleScore& b);
bool operator==(const Score& stu, const Score& stand);
bool operator>=(const Score& stu, const Score& stand);
bool operator<=(const Score& stu, const Score& stand);
bool operator!=(const Score& stu, const Score& stand);
bool operator<(const Score& stu, const Score& stand);
bool operator>(const Score& stu, const Score& stand);
template<>
std::string format(const Score score);
template<class Is = std::istream>
Is& deFormat(Is& is, Score& score);


class Student :public User, public Score
{
private:
	StuClass stuClass;
	StuGrade stuGrade;
public:
	Student(User user, StuGrade stuGrade = 1960, StuClass stuClass = "");
	StuClass getStuClass();
	bool setStuClass(StuClass newStuClass);
	StuGrade getStuGrade();
};
template<>
std::string format(const Student Student);
template<class Is = std::istream>
Is& deFormat(Is& is, Student& Student);

class StudentList
{
private:
	std::map<ID, Student> data;
	std::map<KeyName, BaseIndex> indexs;
public:
	StudentList();
	bool addStudent(const StudentVec& vec);
	//bool addStudent(Student stu);
	bool removeStudent(const IDVec& vec);
	bool buildIndexOn(KeyName name);
	bool contains(ID id)const;
	const Student& operator[](ID id)const;
	Student& getStu(ID id);
	template<class OP = std::equal_to<KeyWord> >
	IDVec getByKey(KeyName name, KeyWord keyWord)const;
};

IDVec operator&(const IDVec& a, const IDVec& b);
IDVec operator|(const IDVec& a, const IDVec& b);

class Key
{
private:
	KeyWordType type;
	KeyWord data;
	//SubjectName subjectName;
public:
	Key(KeyWordType type);
	~Key();
	KeyWord getKey(const Student& stu)const;
	//bool setKey(Student& stu,const KeyWord val)const;
	bool setKey(Student& stu)const;
	KeyWordType getType()const;
};

class KeyWordType
{
public:
	enum BasicType :char
	{
		name, id, sex, stuClass, stuGrade, score
	};
private:
	BasicType basicType;
	SubjectName subjectName;
public:
	KeyWordType(BasicType bType, SubjectName sName = "");
	KeyWordType(std::string name);
	operator std::string()const;
	operator BasicType()const;
	operator SubjectName()const;
	bool operator==(const KeyWordType& b)const;
};


class KeyWord
{
private:
	KeyWordType type;
	Name name;
	ID id;
	Sex sex;
	StuClass stuClass;
	StuGrade stuGrade;
	SingleScore singleScore;
public:
	KeyWord(Name name);
	KeyWord(ID id);
	KeyWord(Sex sex);
	KeyWord(StuClass stuClass);
	KeyWord(StuGrade stuGrade);
	KeyWord(SingleScore singleSore);
	~KeyWord();
	operator Name()const;
	operator ID()const;
	operator Sex()const;
	operator StuClass()const;
	operator SingleScore()const;
	operator KeyWordType()const;
	friend bool operator<(const KeyWord& a, const KeyWord& b);
};
template<>
std::string format(const KeyWord keyWord);

//class BaseIndex
//{
//private:
//
//public:
//	const virtual IDVec getEqByKey(KeyWord keyWord) = 0;
//	const virtual IDVec getGeByKey(KeyWord keyWord) = 0;
//	const virtual IDVec getLeByKey(KeyWord keyWord) = 0;
//	virtual bool trackStu(const Student& stu) = 0;
//	virtual bool untrackStu(const Student& stu) = 0;
//};
//
//class MapIndex : virtual public BaseIndex
//{
//private:
//	std::map<KeyWord, ID> rec;
//public:
//	const virtual IDVec getEqByKey(KeyWord keyWord);
//	const virtual IDVec getGeByKey(KeyWord keyWord);
//	const virtual IDVec getLeByKey(KeyWord keyWord);
//	virtual bool trackStu(const Student& stu);
//	virtual bool untrackStu(const Student& stu);
//};
//
//class SexIndex : virtual public BaseIndex
//{
//private:
//	std::unordered_map<Sex, std::set<ID> > rec;
//public:
//	const virtual IDVec getEqByKey(KeyWord keyWord);
//	const virtual IDVec getGeByKey(KeyWord keyWord);
//	const virtual IDVec getLeByKey(KeyWord keyWord);
//	virtual bool trackStu(const Student& stu);
//	virtual bool untrackStu(const Student& stu);
//};
//
class SQLrequest
{
private:
	ColumnFilter columnFilter;
	WhereFilter whereFilter;
	enum RequestType
	{
		select, set, remove, insert
	};
public:
	SQLrequest(std::string request);
	GoodResult exec(StudentList& list);
};

class ColumnFilter
{
private:
	std::vector<Key> columns;
public:
	ColumnFilter(std::string filter);
	std::vector<KeyName> getHeads()const;
	GoodResult getVal(const IDVec& vec, const StudentList& list)const;
	bool applyVal(const IDVec& vec, StudentList& list)const;

};

class WhereFilter
{
private:
	std::string expr;
public:
	WhereFilter(std::string expr);
	IDVec filt(const StudentList& list);
};

class Result
{
public:
	virtual operator bool()const = 0;
	virtual operator std::string()const = 0;
};

class GoodResult :virtual public Result
{
private:
	std::vector<KeyName> head;
	std::vector<Record > rec;
public:
	GoodResult(std::vector<KeyName> names);
	virtual operator bool()const;
	bool addRec(Record& newRec);
	virtual operator std::string()const;
};

class SuccessResult :public Result
{
	std::string msg;
public:
	SuccessResult(const std::string& msg = "Operation succeded");
	virtual operator bool()const;
	virtual operator std::string()const;
};

std::string form(Record kwyWord, std::vector<size_t>& width);//empty width or insufficent length means auto(2times  avg of top 5)

template<>
inline std::string format(const Sex sex)
{
	return std::string();
}

template<class Is>
inline Is& deFormat(Is& is, Sex& sex)
{
	throw gcnew System::NotImplementedException();
	// TODO: 在此处插入 return 语句
}

template<class OP>
inline bool Score::compare(const Score& stand)const
{
	return false;
}

template<>
inline std::string format(const User user)
{
	return std::string();
}

template<class Is>
inline Is& deFormat(Is& is, User& user)
{
	throw gcnew System::NotImplementedException();
	// TODO: 在此处插入 return 语句
}

template<class vec>
inline ExamPoint getGPA(vec)
{
	return ExamPoint();
}

template<class vec>
inline ExamPoint getTotalClassHour(vec)
{
	return ExamPoint();
}

template<>
inline std::string format(const Point point)
{
	return std::string();
}

template<class Is>
inline Is& deFormat(Is& is, Point& point)
{
	throw gcnew System::NotImplementedException();
	// TODO: 在此处插入 return 语句
}

template<>
inline std::string format(const Score score)
{
	return std::string();
}

template<class Is>
inline Is& deFormat(Is& is, Score& score)
{
	throw gcnew System::NotImplementedException();
	// TODO: 在此处插入 return 语句
}

template<>
inline std::string format(const Student Student)
{
	return std::string();
}

template<class Is>
inline Is& deFormat(Is& is, Student& Student)
{
	throw gcnew System::NotImplementedException();
	// TODO: 在此处插入 return 语句
}

template<>
inline std::string format(const KeyWord keyWord)
{
	return std::string();
}

template<class OP>
inline IDVec StudentList::getByKey(KeyName name, KeyWord keyWord)const
{
	return IDVec();
}

#pragma once
#include<iostream>
#include<map>
#include<vector>
#include<set>
#include<string>
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
enum Sex;
//class RWlock;//giveup thread safety
class User;
class Student;
using IDVec = std::vector<ID>;
using StudentVec = std::vector<Student>;
class StudentList;
class Score;
class Point;//data class
using SingleScore = std::pair<SubjectName, Point>;

class BaseIndex;
class MapIndex;
class IDindex;
class Key;
using KeyName = std::string;
class KeyWord;
enum KeyWordType;//index class

class SQLrequest;
class Column;
class ColumnFilter;
class WhereFilter;
class Result;
using Record = std::vector<KeyWord>;
class GoodResult;
class FailResult;
class RefuleResult;//SQL class

enum Sex
{
	male, female, unKnown
};
template<>
std::string format(Sex sex);
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
	User(ID id, Name name = "John Doe", Sex sex = unKnown);
	Name getName();
	//bool setName(Name newName);
	bool login(PWD token);
	ID getID();
	Sex getSex();
};
template<>
std::string format(User user);
template<class Is = std::istream>
Is& deFormat(Is& is, User& user);

class Point
{
private:
	ExamPoint point;
	ClassHour classHour;
public:
	Point(ExamPoint point, ClassHour classHour = 1);
	bool setPoint(ExamPoint newPoint);
	ExamPoint getPoint();
	ClassHour getClassHour();
};
template<class vec = std::vector<Point> >
ExamPoint getGPA(vec);
template<class vec = std::vector<Point> >
ExamPoint getTotalClassHour(vec);
template<>
std::string format(Point point);
template<class Is = std::istream>
Is& deFormat(Is& is, Point& point);

class Score
{
private:
	std::map<SubjectName, Point> Points;
public:
	Score();
	Score(SingleScore sig);
	ExamPoint getPoint(SubjectName subjectName);
	bool setPoint(SubjectName subjectName, ExamPoint newPoint);
	bool setPoint(Score newScore);
	ClassHour getClassHour(SubjectName subjectName);
	bool contains(SubjectName subjectName);
	bool addSubject(SubjectName subjectName, Point point);
	bool addSubject(Score newScore);
	bool removeSubject(SubjectName subjectName);
	bool removeSubject(Score newScore);
	template<class OP = std::equal_to<ExamPoint> >
	bool compare(const Score& stand);
	ExamPoint getGPA();
	ClassHour getTotalClassHour();
};
bool operator==(const Score& stu, const Score& stand);
bool operator>=(const Score& stu, const Score& stand);
bool operator<=(const Score& stu, const Score& stand);
bool operator!=(const Score& stu, const Score& stand);
bool operator<(const Score& stu, const Score& stand);
bool operator>(const Score& stu, const Score& stand);
template<>
std::string format(Score score);
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
std::string format(Student Student);
template<class Is = std::istream>
Is& deFormat(Is& is, Student& Student);

class StudentList
{
private:
	std::map<ID, Student> data;
	std::map<KeyName, BaseIndex> indexs;
public:
	StudentList();
	bool addStudent(StudentVec vec);
	//bool addStudent(Student stu);
	bool removeStudent(IDVec vec);
	bool buildIndexOn(KeyName name);
	template<class OP = std::equal_to<KeyWord> >
	IDVec getByKey(KeyName name, KeyWord keyWord);

};

IDVec operator&(const IDVec& a, const IDVec& b);
IDVec operator|(const IDVec& a, const IDVec& b);

class Key
{
private:
	std::function<KeyWord(const Student&)> get;
	std::function<bool(Student&, KeyWord)> set;
	KeyWordType type;
public:
	Key(KeyWordType type, KeyWord(*howToGet)(const Student&), bool(*howToSet)(Student&, KeyWord));
	KeyWord getKey(Student& stu);
	operator KeyWordType();
	KeyWordType getType();
	bool getKey(Student& stu, KeyWord keyWord);
};

Key keyByName(KeyName name);

enum KeyWordType
{
	name, id, sex, stuClass, stuGrade, score
};


class KeyWord
{
private:
	KeyWordType type;
	union Data
	{
		Name name;
		ID id;
		Sex sex;
		StuClass stuClass;
		StuGrade stuGrade;
		Score score;
	}data;
public:
	KeyWord(Name name);
	KeyWord(ID id);
	KeyWord(Sex sex);
	KeyWord(StuClass stuClass);
	KeyWord(StuGrade stuGrade);
	KeyWord(Score score);
	operator Name();
	operator ID();
	operator Sex();
	operator StuClass();
	operator Score();
	operator KeyWordType();
	friend bool operator<(const KeyWord& a, const KeyWord& b);
};
template<>
std::string format(KeyWord keyWord);

class BaseIndex
{
private:

public:
	const virtual IDVec getEqByKey(KeyWord keyWord) = 0;
	const virtual IDVec getGeByKey(KeyWord keyWord) = 0;
	const virtual IDVec getLeByKey(KeyWord keyWord) = 0;
	virtual bool trackStu(const Student& stu) = 0;
	virtual bool untrackStu(const Student& stu) = 0;
};

class MapIndex : virtual public BaseIndex
{
private:
	std::map<KeyWord, ID> rec;
public:
	const virtual IDVec getEqByKey(KeyWord keyWord);
	const virtual IDVec getGeByKey(KeyWord keyWord);
	const virtual IDVec getLeByKey(KeyWord keyWord);
	virtual bool trackStu(const Student& stu);
	virtual bool untrackStu(const Student& stu);
};

class SexIndex : virtual public BaseIndex
{
private:
	std::unordered_map<Sex, std::set<ID> > rec;
public:
	const virtual IDVec getEqByKey(KeyWord keyWord);
	const virtual IDVec getGeByKey(KeyWord keyWord);
	const virtual IDVec getLeByKey(KeyWord keyWord);
	virtual bool trackStu(const Student& stu);
	virtual bool untrackStu(const Student& stu);
};

class SQLrequest
{
private:
	ColumnFilter columnFilter;
	WhereFilter whereFilter;
public:
	SQLrequest(std::string request);
	GoodResult exec(StudentList &list);
};

class ColumnFilter
{
private:
	std::vector<Key> columns;
public:
	ColumnFilter(std::string filter);
	GoodResult filt(IDVec vec);
};

class WhereFilter
{
private:
	std::string expr;
public:
	WhereFilter(std::string expr);
	IDVec filt(StudentList list);
};

class Result
{
public:
	virtual operator bool()const = 0;

};

class GoodResult:virtual public Result
{
private:
	std::vector<KeyName> head;
	std::vector<Record > rec;
public:
	GoodResult(std::vector<KeyName> names);
	bool addRec(Record& newRec);
	operator std::string();
};

std::string form(Record kwyWord, std::vector<size_t>& width);//empty width or insufficent length means auto(2times  avg of top 5)

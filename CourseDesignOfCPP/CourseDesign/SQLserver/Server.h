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
using Name = std::string;
using StuClass = std::string;
using StuGrade = size_t;
using SubjectName = std::string;
enum Sex;
//class RWlock;//giveup thread safety
class User;
class Student;
class StudentList;
class Score;
class Point;
class BaseIndex;
class MapIndex;
class IDindex;
class Key;
class SQLrequest;
class Result;
class GoodResult;
class FailResult;
class RefuleResult;

enum Sex
{
	male, female, unKnown
};
template<>
std::string format(Sex sex);
template<class Is = std::istream>
Is& deFormat(Is& is, Sex sex);

class User
{
private:
	Name name;
	ID id;
	Sex sex;
public:
	User(ID id, Name name = "John Doe", Sex sex = unKnown);
	Name getName();
	//bool setName(Name newName);
	ID getID();
	Sex getSex();
};
template<>
std::string format(User user);
template<class Is = std::istream>
Is& deFormat(Is& is, User user);

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
Is& deFormat(Is& is, Point point);

class Score
{
private:
	std::map<SubjectName, Point> Points;
public:
	ExamPoint getPoint(SubjectName subjectName);
	bool setPoint(SubjectName subjectName, ExamPoint newPoint);
	ClassHour getClassHour(SubjectName subjectName);
	bool contains(SubjectName subjectName);
	bool addSubject(SubjectName subjectName, Point point);
	bool removeSubject(SubjectName subjectName);
	ExamPoint getGPA();
	ClassHour getTotalClassHour();
};
template<>
std::string format(Score score);
template<class Is = std::istream>
Is& deFormat(Is& is, Score score);


class Student:public User
{
private:

	
};
template<>
std::string format(Student Student);
template<class Is = std::istream>
Is& deFormat(Is& is, Student Student);
#pragma once
#include "Format.h"
#include "md5.h"
#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
const double ex = 0.0000006;
using ExamPoint = double;
using ClassHour = double;
// using ID = std::string;
class ID;
using PWD = std::string;
// using Name = std::string;
class Name;
// using StuClass = std::string;
class StuClass;
using StuGrade = size_t;
// using SubjectName = std::string;
class SubjectName;
enum Sex : char;
// class RWlock;//giveup thread safety
class User;
class Student;
using IDVec      = std::vector<ID>;
using IDset      = std::set<ID>;
using StudentVec = std::vector<Student>;
class StudentList;
class Score;
class Point;  // data class
using ScoreMap    = std::map<SubjectName, Point>;
using SingleScore = std::pair<SubjectName, Point>;

// class BaseIndex;
// class MapIndex;
// class IDindex;
class Key;
using KeyName = std::string;
class KeyWord;
class KeyWordType;  // index class

class SQLrequest;
class Column;
class ColumnFilter;
class WhereFilter;
class Result;
using Record = std::vector<KeyWord>;
class GoodResult;
class SuccessResult;
class FailResult;
class RefuleResult;  // SQL class

enum Sex : char
{
    male,
    female,
    unKnown
};
template <>
std::string format(const Sex &sex);
template <class Is = std::istream>
Is &deFormatSex(Is &is, Sex &sex);

class Name: public std::string
{
public:
    Name() {}
    Name(std::string str): std::string(str) {}
};
class ID: public std::string
{
public:
    ID() {}
    ID(std::string str): std::string(str) {}
};
class StuClass: public std::string
{
public:
    StuClass() {}
    StuClass(std::string str): std::string(str) {}
};
class SubjectName: public std::string
{
public:
    SubjectName() {}
    SubjectName(std::string str): std::string(str) {}
};
class User
{
private:
    Name name;
    ID   id;
    Sex  sex;
    PWD  hashedPWD;

public:
    User(ID id = ID(""), PWD pwd = "", Name name = Name("John Doe"), Sex sex = unKnown);
    Name getName() const;
    // bool setName(Name newName);
    bool login(PWD token) const;
    bool setPWD(PWD newPWD);
    PWD  getHashedPwd() const;
    ID   getID() const;
    Sex  getSex() const;
    template <class Is>
    friend Is &        deFormatUser(Is &is, User &user);
    friend std::string formatUser(const User &user);
};
std::string formatUser(const User &user);
template <class Is = std::istream>
Is &deFormatUser(Is &is, User &user);
PWD hash(const PWD &in);

class Point
{
private:
    ExamPoint point;
    ClassHour classHour;

public:
    Point(ExamPoint point = 0, ClassHour classHour = 1);
    bool      setPoint(ExamPoint newPoint);
    ExamPoint getRawPoint() const;
    ClassHour getClassHour() const;
    bool      operator<(const Point &b) const;
    template <class Is>
    friend Is &deFormat(Is &is, Point &point);
    ;
};
template <class vec = std::vector<Point> >
ExamPoint getGPA(const vec);
template <class vec = std::vector<Point> >
ExamPoint getTotalClassHour(const vec);
template <>
std::string format(const Point &point);
template <class Is = std::istream>
Is &deFormat(Is &is, Point &point);

class Score
{
private:
    ScoreMap points;

public:
    Score();
    Score(SingleScore sig);
    Point     getPoint(SubjectName subjectName) const;
    bool      setPoint(SubjectName subjectName, ExamPoint newPoint);
    bool      setPoint(SubjectName subjectName, Point newPoint);
    bool      setPoint(const Score &newScore);
    ClassHour getClassHour(SubjectName subjectName) const;
    bool      contains(SubjectName subjectName) const;
    bool      contains(const Score &newScore) const;
    bool      addSubject(SubjectName subjectName, Point point);
    bool      addSubject(const Score &newScore);
    bool      removeSubject(SubjectName subjectName);
    bool      removeSubject(const Score &newScore);
    template <class OP = std::equal_to<ExamPoint> >
    bool               compare(const Score &stand) const;
    ExamPoint          getGPA() const;
    ClassHour          getTotalClassHour() const;
                       operator ScoreMap() const;
    friend std::string formatScore(const Score &score);
    template <class Is>
    friend Is &deFormatScore(Is &is, Score &score);
};
std::string formatScore(const Score &score);
template <class Is = std::istream>
Is &deFormatScore(Is &is, Score &score);

class Student: public User, public Score
{
private:
    StuClass stuClass;
    StuGrade stuGrade;

public:
    Student(User user = User(), StuGrade stuGrade = 1960, StuClass stuClass = StuClass(""));
    StuClass getStuClass() const;
    bool     setStuClass(StuClass newStuClass);
    StuGrade getStuGrade() const;
    template <class Is>
    friend Is &deFormat(Is &is, Student &Student);
};
template <>
std::string format(const Student &Student);
template <class Is = std::istream>
Is &deFormat(Is &is, Student &Student);

class StudentList
{
private:
    std::map<ID, Student> data;
    // std::map<KeyName, BaseIndex> indexs;
public:
    StudentList();
    bool addStudent(const StudentVec &vec);
    // bool addStudent(Student stu);
    bool           removeStudent(const IDVec &vec);
    bool           buildIndexOn(KeyName name);
    bool           contains(ID id) const;
    const Student &operator[](ID id) const;
    Student &      getStu(ID id);
    template <class OP = std::equal_to<KeyWord> >
    IDVec getByKey(KeyName name, KeyWord keyWord) const;
};

IDVec operator&(const IDVec &a, const IDVec &b);
IDVec operator|(const IDVec &a, const IDVec &b);

class KeyWordType
{
public:
    enum BasicType : char
    {
        name,
        id,
        sex,
        stuClass,
        stuGrade,
        score
    };

private:
    BasicType   basicType;
    SubjectName subjectName;

public:
    KeyWordType(BasicType bType, SubjectName sName = SubjectName(""));
    KeyWordType(std::string name = "");
    static BasicType stringToBasicType(const std::string &name);
                     operator std::string() const;
                     operator BasicType() const;
                     operator SubjectName() const;
    bool             operator==(const KeyWordType &b) const;
};

class KeyWord
{
private:
    KeyWordType type;
    Name        name;
    ID          id;
    Sex         sex;
    StuClass    stuClass;
    StuGrade    stuGrade;
    Point       point;

public:
    KeyWord(Name name);
    KeyWord(ID id);
    KeyWord(Sex sex);
    KeyWord(StuClass stuClass);
    KeyWord(StuGrade stuGrade);
    KeyWord(Point singleSore);
    KeyWord();
    KeyWord(KeyWordType type, std::string str);
    ~KeyWord();
    std::string form(size_t width) const;
                operator Name() const;
                operator ID() const;
                operator Sex() const;
                operator StuClass() const;
                operator Point() const;
                operator KeyWordType() const;
                operator std::string() const;
    friend bool operator<(const KeyWord &a, const KeyWord &b);
};
template <>
std::string format(const KeyWord &keyWord);

class Key
{
private:
    KeyWordType type;
    KeyWord     data;
    // SubjectName subjectName;
public:
    Key(KeyWordType type, KeyWord data);
    Key(std::string str);
    ~Key();
    KeyWord getKey(const Student &stu) const;
    // bool setKey(Student& stu,const KeyWord val)const;
    bool setKey(Student &stu) const;
    // bool removeKey(Student& stu)const;
    KeyWordType getType() const;
};

class ColumnFilter
{
private:
    std::vector<Key> columns;

public:
    ColumnFilter(std::string filter = "");
    std::vector<KeyName> getHeads() const;
    GoodResult           getVal(const IDVec &vec, const StudentList &list) const;
    bool                 applyVal(const IDVec &vec, StudentList &list) const;
};

class WhereFilter
{
private:
    std::string expr;

public:
    WhereFilter(std::string expr = "");
    IDVec filt(const StudentList &list);
};

class SQLrequest
{
private:
    ColumnFilter columnFilter;
    WhereFilter  whereFilter;
    std::string  insertBuffer;
    enum RequestType
    {
        select,
        set,
        remove,
        insert
    } type;

public:
    SQLrequest(std::string request);
    std::string exec(StudentList &list);
};

class Result
{
public:
    virtual operator bool() const        = 0;
    virtual operator std::string() const = 0;
};

class GoodResult: virtual public Result
{
private:
    std::vector<KeyName> head;
    std::vector<Record>  rec;

public:
    GoodResult(std::vector<KeyName> names);
    virtual operator bool() const;
    bool    addRec(Record &newRec);
    virtual operator std::string() const;
};

class SuccessResult: public Result
{
    std::string msg;

public:
    SuccessResult(const std::string &msg = "Operation succeded");
    virtual operator bool() const;
    virtual operator std::string() const;
};

std::string form(Record kwyWord,
                 std::vector<size_t>
                   &width);  // empty width or insufficent length means auto(2times  avg of top 5)

std::string formatSex(const Sex &sex)
{
    switch(sex)
    {
        case male:
            return "male";
            break;
        case female:
            return "female";
            break;
        default:
            return "";
            break;
    }
}

template <class Is>
Is &deFormatSex(Is &is, Sex &sex)
{
    std::string str;
    is >> str;
    if(str == "male")
    {
        sex = male;
    }
    else
    {
        sex = female;
    }
    return is;
}

template <class OP>
inline bool Score::compare(const Score &stand) const
{
    return false;
}

std::string formatUser(const User &user)
{
    return "{ name : " + user.getName() + " , id : " + user.getID() +
           " , sex : " + format<Sex>(user.getSex()) + " , pwd : " + user.getHashedPwd() + " }";
}

template <class Is>
Is &deFormatUser(Is &is, User &user)
{
    enum NextObj
    {
        unknown,
        name,
        id,
        sex,
        pwd,
    };
    std::map<std::string, NextObj> map = { { "name", name },
                                           { "id", id },
                                           { "sex", sex },
                                           { "pwd", pwd } };
    while(true)
    {
        while(isspace(is.peek()) || is.peek() == '{' || is.peek() == ',')
            is.get();
        std::string buf[2];
        is >> buf[0];
        while(isspace(is.peek()) || is.peek() == ':')
            is.get();
        is >> buf[1];
        if(map.contains(buf[0]))
        {
            NextObj           next = map[buf[0]];
            std::stringstream s(buf[1]);
            switch(next)
            {
                case unknown:
                    break;
                case name:
                    user.name = buf[1];
                    break;
                case id:
                    user.id = buf[1];
                    break;
                case sex:
                    deFormatSex(s, user.sex);
                    break;
                case pwd:
                    user.hashedPWD = buf[1];
                    break;
                default:
                    break;
            }
        }
        while(isspace(is.peek()))
            is.get();
        if(is.peek() == '}')
        {
            is.get();
            break;
        }
    }
    return is;
}

template <class vec>
inline ExamPoint getGPA(vec v)
{
    ExamPoint sumP = 0;
    ClassHour sumC = 0;
    for(auto p: v)
    {
        sumP += p.getClassHour() * p.getRawPoint();
        sumC += p.getClassHour();
    }
    if(sumC > ex)
    {
        return sumP / sumC;
    }
    else
    {
        return 0;
    }
}

template <class vec>
inline ExamPoint getTotalClassHour(vec v)
{
    // return ExamPoint();
    ClassHour sumC;
    for(auto p: v)
    {
        sumC += p.getClassHour();
    }
    return sumC;
}

template <>
std::string format(const Point &point)
{
    // return std::string();
    return "{ point : " + std::to_string(point.getRawPoint()) +
           " , classHour : " + std::to_string(point.getClassHour()) + " }";
}

template <class Is>
Is &deFormat(Is &is, Point &point)
{
    enum NextObj
    {
        points,
        classHour,
        unKnown
    };
    std::map<std::string, NextObj> map = { { "point", NextObj::points },
                                           { "classHour", classHour } };
    while(true)
    {
        while(isspace(is.peek()) || is.peek() == '{' || is.peek() == ',')
            is.get();
        std::string buf[2];
        is >> buf[0];
        while(isspace(is.peek()) || is.peek() == ':')
            is.get();
        is >> buf[1];
        if(map.contains(buf[0]))
        {
            NextObj           next = map[buf[0]];
            std::stringstream ss(buf[1]);
            switch(next)
            {
                case NextObj::points:
                    ss >> (point.point);
                    break;
                case classHour:
                    ss >> point.classHour;
                    break;
                case unKnown:
                    break;
                default:
                    break;
            }
        }
        while(isspace(is.peek()))
            is.get();
        if(is.peek() == '}')
        {
            is.get();
            break;
        }
    }
    return is;
}

std::string formatScore(const Score &score)
{
    // return std::string();
    return formatMap<SubjectName, Point, std::map<SubjectName, Point> >(score.operator ScoreMap());
}

template <class Is>
Is &deFormatScore(Is &is, Score &score)
{
    deFormatMap<SubjectName, Point>(is, score.points);
    return is;
}

template <>
std::string format(const Student &student)
{
    // return std::string();
    return "{ User : " + formatUser((User) student) + " , Score : " + formatScore(student) +
           " , StuClass : " + student.getStuClass() +
           " , StuGrade : " + std::to_string(student.getStuGrade()) + " }";
}

template <class Is>
Is &deFormat(Is &is, Student &student)
{
    enum NextObj
    {
        user,
        score,
        stuClass,
        stuGrade,
        unknow
    };
    std::unordered_map<std::string, NextObj> map = { { "User", user },
                                                     { "Score", score },
                                                     { "StuClass", stuClass },
                                                     { "StuGrade", stuGrade } };
    while(true)
    {
        while(isspace(is.peek()) || is.peek() == '{' || is.peek() == ',')
            is.get();
        std::string buf[2];
        is >> buf[0];
        while(isspace(is.peek()) || is.peek() == ':')
            is.get();
        is >> buf[1];
        if(map.contains(buf[0]))
        {
            NextObj next = map[buf[0]];
            switch(next)
            {
                case user:
                {
                    // User u;
                    deFormatUser(is, student);
                    // student = u;
                }
                break;
                case score:
                {
                    Score s;
                    deFormatScore(is, student);
                    // student = s;
                }
                break;
                case stuClass:
                    student.setStuClass(buf[1]);
                    break;
                case stuGrade:
                {
                    StuGrade s;
                    std::stringstream(buf[1]) >> s;
                    student.stuGrade = s;
                }
                break;
                case unknow:
                    break;
                default:
                    break;
            }
        }
        while(isspace(is.peek()))
            is.get();
        if(is.peek() == '}')
        {
            is.get();
            break;
        }
    }
    return is;
}

template <>
std::string format(const KeyWord &keyWord)
{
    return keyWord.operator std::string();
}
template <>
std::string format(const SubjectName &name)
{
    return name;
}
template <class OP>
inline IDVec StudentList::getByKey(KeyName name, KeyWord keyWord) const
{
    KeyWordType requestType(name);
    Key         requestKey(requestType, keyWord);
    IDVec       ans;
    OP          cmper;
    for(auto s: data)
    {
        if(cmper(requestKey.getKey(s.second), keyWord))
        {
            ans.push_back(s.first);
        }
    }
    return ans;
}

// bool operator<(const SingleScore& a, const SingleScore& b);
// bool operator==(const Score& stu, const Score& stand);
// bool operator>=(const Score& stu, const Score& stand);
// bool operator<=(const Score& stu, const Score& stand);
// bool operator!=(const Score& stu, const Score& stand);
// bool operator<(const Score& stu, const Score& stand);
// bool operator>(const Score& stu, const Score& stand);

// class BaseIndex
//{
// private:
//
// public:
//	const virtual IDVec getEqByKey(KeyWord keyWord) = 0;
//	const virtual IDVec getGeByKey(KeyWord keyWord) = 0;
//	const virtual IDVec getLeByKey(KeyWord keyWord) = 0;
//	virtual bool trackStu(const Student& stu) = 0;
//	virtual bool untrackStu(const Student& stu) = 0;
//};
//
// class MapIndex : virtual public BaseIndex
//{
// private:
//	std::map<KeyWord, ID> rec;
// public:
//	const virtual IDVec getEqByKey(KeyWord keyWord);
//	const virtual IDVec getGeByKey(KeyWord keyWord);
//	const virtual IDVec getLeByKey(KeyWord keyWord);
//	virtual bool trackStu(const Student& stu);
//	virtual bool untrackStu(const Student& stu);
//};
//
// class SexIndex : virtual public BaseIndex
//{
// private:
//	std::unordered_map<Sex, std::set<ID> > rec;
// public:
//	const virtual IDVec getEqByKey(KeyWord keyWord);
//	const virtual IDVec getGeByKey(KeyWord keyWord);
//	const virtual IDVec getLeByKey(KeyWord keyWord);
//	virtual bool trackStu(const Student& stu);
//	virtual bool untrackStu(const Student& stu);
//};
//

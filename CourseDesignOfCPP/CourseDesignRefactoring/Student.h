#pragma once
#include "SerializationAid.h"
#include "User.h"
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <vector>

class Student: public User
{
public:
    using StudentClassLogicalID = unsigned long long;
    using StudentClassName      = std::string;
    using StudentGrade          = size_t;
    Student(User user, StudentClassLogicalID className, StudentGrade startYear);
    Student(const json &js);
    Student::StudentClassLogicalID getClass() const;
    void                           setClassName(Student::StudentClassLogicalID newClass);
    Student::StudentGrade          getStartYear() const;
    json                           serialize() const;

private:
    StudentClassLogicalID myClass;
    StudentGrade          myStartYear;
};

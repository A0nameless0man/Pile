#pragma once
#include "Course.h"
#include "User.h"
class CourseSelectionRecord
{
public:
    using CourseSelectionRecordID = unsigned long long;
    using GradeOfCourse           = double;
    CourseSelectionRecord(User::LogicID                        student,
                          CourseSelectionRecord::GradeOfCourse grade,
                          Course::CourseID                     course);
    CourseSelectionRecord(const json &js);
    CourseSelectionRecord::GradeOfCourse getGrade() const;
    void                                 setGrade(CourseSelectionRecord::GradeOfCourse newGrade);
    Course::CourseID                     getCourseID() const;
    User::LogicID                        getStudent() const;
    json                                 serialize() const;

private:
    User::LogicID    student;
    GradeOfCourse    grade;
    Course::CourseID courseID;
};



```mermaid
classDiagram
class Student
class StudentList
class BaseIndex
class MapIndex
class OtherIndex
class preBuildHashFun
class Point
class Grade
Student : name
Student : stuID
Student : class
Student : grade
Student : ...
Student o-- Grade
StudentList : private students : map hashStuID Student
StudentList : private indexs : map indexName BaseIndex
StudentList : public StudentList()
StudentList : public addStudent(list)//single is list with one element
StudentList : public removeStuent(list)
StudentList : public buildIndex(name)
StudentList o-- Student
StudentList o-- BaseIndex
StudentList --* preBuildHashFun : buildIndex(name)
BaseIndex : fun GetKey
BaseIndex : public pure virtual vec of hashStuID search(key)
BaseIndex : public pure virtual BaseIndex(StudentList,getKey(Student))
BaseIndex : public getKey(Student)
BaseIndex : public indexStu(Student)
BaseIndex : public unindexStu(Student)
BaseIndex <|-- MapIndex
BaseIndex <|-- OtherIndex
preBuildHashFun : map : name getKey
MapIndex : private map key hashStuID
Point : grade
Point : classHour
Point : public Point(classHour = 0,grade = 0)
Point : public setGrade(newGrade)
Point : public setClassHour(newClassHour)
Point : public grade getGrade()
Point : public classHour getClassHour()
Point : stastic Point gpa(vec of Point)
Point : stastic classHour getSumClassHour(vec of Point)
Grade : private map : objectName Point
Grade : public setGrade(objecName,Point)
Grade : public Point getGrade(objecName)
Grade : public Point operator[](objectName)
Grade : public Point gpa()
Grade : public classHour getClassHour
Grade o-- Point
```


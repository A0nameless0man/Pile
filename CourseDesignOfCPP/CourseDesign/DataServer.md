
```mermaid
classDiagram
class Student
class StudentList
class Key
class BaseIndex
class MapIndex
class OtherIndex
class preBuildHashFun
class Point
class Grade
class User
class UserServer
class SQLserver
class SQLrequest
class columnFilter
class whereFilter
class BaseResult

Student : name
Student : stuID
Student : class
Student : grade
Student : ...
Student : get...()
Student : set...()
Student o-- Grade

StudentList : private students : map hashStuID Student
StudentList : private indexs : map indexName BaseIndex
StudentList : public StudentList()
StudentList : public addStudent(list)
StudentList : //single is list with one element
StudentList : public removeStuent(list)
StudentList : public buildIndex(name)
StudentList : public list searchEqualBy(KeyName,KeyVal)
StudentList : public list searchGreaterBy(KeyName,KeyVal)
StudentList : public list searchLesserBy(KeyName,KeyVal)
StudentList o-- Student
StudentList o-- BaseIndex
StudentList --> preBuildHashFun : buildIndex(name)

Key : name
Key : pure virtual getKey(Student)
Key : pure virtual setKey(Student,val)
Key : //key is't Student's friend class ,it get&set via Student's public method

BaseIndex : Key myKey
BaseIndex : public vec of hashStuID  search(key)
BaseIndex : public pure virtual BaseIndex(StudentList,getKey(Student))
BaseIndex : public getKey(Student)
BaseIndex : public indexStu(Student)
BaseIndex : public unindexStu(Student)
BaseIndex <|-- MapIndex
BaseIndex <|-- OtherIndex
BaseIndex o-- Key

preBuildHashFun : map : name Key

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

User : ID
User : Token
User : public exec(cmd)
User : public User(ID,pwd)
User ..> UserServer : User() login()

UserServer : private HOST
UserServer : private map ID,token
UserServer : private studentList
UserServer : public token login(ID,pwd)
UserServer : private string execByHost(cmd,ID,token)
UserServer <..> SQLserver : put request and than return the result
UserServer ..> SQLrequest : generate when needed

SQLserver : private queue of SQLrequest
SQLserver : private StudentList data
SQLserver : public pushSQLrequest(SQLrequest)
SQLserver o-- StudentList
SQLserver <--> SQLrequest : manage and call at right time and reutrn result after call

SQLrequest : cloumFilter
SQLrequest : whereFilter
SQLrequest : exec()
SQLrequest *-- columnFilter
SQLrequest *-- whereFilter
SQLrequest ..> BaseResult : generate after exec

columnFilter : vec of columnName
columnFilter : vec of Value

whereFilter : vec of hashStuID getList()

BaseResult : templete< OS = std::cout>display(OS os)
```


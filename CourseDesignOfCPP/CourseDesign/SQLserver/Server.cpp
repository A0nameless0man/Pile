#include"Server.h"

User::User(ID id, PWD pwd = "", Name name, Sex sex) :name(name), id(id), sex(sex), pwd(pwd)
{
}

Name User::getName()
{
	return name;
}

bool User::login(PWD token)
{
	return pwd == hash(token);
}

ID User::getID()
{
	return id;
}

Sex User::getSex()
{
	return sex;
}

Score::Score()
{
}

Score::Score(SingleScore sig)
{
	Points.insert(sig);
}

ExamPoint Score::getPoint(SubjectName subjectName)const
{
	if (Points.contains(subjectName))
	{
		return Points.find(subjectName)->second.getPoint();
	}
	else
	{
		return 0;
	}
}

bool Score::setPoint(SubjectName subjectName, ExamPoint newPoint)
{
	if (Points.contains(subjectName))
	{
		return Points.find(subjectName)->second.setPoint(newPoint);
	}
	else
	{
		return false;
	}
}

bool Score::setPoint(Score newScore)
{
	bool haveThenAll = true;
	for (auto p : (ScoreMap)newScore)
	{
		if (haveThenAll = haveThenAll && Points.contains(p.first))
		{
			continue;
		}
		else
		{
			break;
		}
	}
	if (haveThenAll)
	{

	}
}

ClassHour Score::getClassHour(SubjectName subjectName)const
{
	return ClassHour();
}

bool Score::contains(SubjectName subjectName)const
{
	return false;
}

bool Score::addSubject(SubjectName subjectName, Point point)
{
	return false;
}

bool Score::addSubject(Score newScore)
{
	return false;
}

bool Score::removeSubject(SubjectName subjectName)
{
	return false;
}

bool Score::removeSubject(Score newScore)
{
	return false;
}

ExamPoint Score::getGPA()const
{
	return ExamPoint();
}

ClassHour Score::getTotalClassHour()const
{
	return ClassHour();
}

Score::operator ScoreMap() const
{
	return Points;
}

Point::Point(ExamPoint point, ClassHour classHour)
{
}

bool Point::setPoint(ExamPoint newPoint)
{
	return false;
}

ExamPoint Point::getPoint()const
{
	return ExamPoint();
}

ClassHour Point::getClassHour()const
{
	return ClassHour();
}

PWD hash(const PWD& in)
{
	return in;
}

bool operator==(const Score& stu, const Score& stand)
{
	return false;
}

bool operator>=(const Score& stu, const Score& stand)
{
	return false;
}

bool operator<=(const Score& stu, const Score& stand)
{
	return false;
}

bool operator!=(const Score& stu, const Score& stand)
{
	return false;
}

bool operator<(const Score& stu, const Score& stand)
{
	return false;
}

bool operator>(const Score& stu, const Score& stand)
{
	return false;
}

IDVec operator&(const IDVec& a, const IDVec& b)
{
	return IDVec();
}

IDVec operator|(const IDVec& a, const IDVec& b)
{
	return IDVec();
}

Key keyByName(KeyName name)
{
	return Key();
}

bool operator<(const KeyWord& a, const KeyWord& b)
{
	return false;
}

std::string form(Record kwyWord, std::vector<size_t>& width)
{
	return std::string();
}

StudentList::StudentList()
{
}

bool StudentList::addStudent(StudentVec vec)
{
	return false;
}

bool StudentList::removeStudent(IDVec vec)
{
	return false;
}

bool StudentList::buildIndexOn(KeyName name)
{
	return false;
}

Student::Student(User user, StuGrade stuGrade, StuClass stuClass)
{
}

StuClass Student::getStuClass()
{
	return StuClass();
}

bool Student::setStuClass(StuClass newStuClass)
{
	return false;
}

StuGrade Student::getStuGrade()
{
	return StuGrade();
}

GoodResult::GoodResult(std::vector<KeyName> names)
{
}

GoodResult::operator bool() const
{
}

bool GoodResult::addRec(Record& newRec)
{
	return false;
}

GoodResult::operator std::string() const
{
}



WhereFilter::WhereFilter(std::string expr)
{
}

IDVec WhereFilter::filt(StudentList list)
{
	return IDVec();
}

ColumnFilter::ColumnFilter(std::string filter)
{
}

GoodResult ColumnFilter::filt(IDVec vec)
{
	return GoodResult();
}

SQLrequest::SQLrequest(std::string request)
{
}

GoodResult SQLrequest::exec(StudentList& list)
{
	return GoodResult();
}

const IDVec SexIndex::getEqByKey(KeyWord keyWord)
{
	return IDVec();
}

const IDVec SexIndex::getGeByKey(KeyWord keyWord)
{
	return IDVec();
}

const IDVec SexIndex::getLeByKey(KeyWord keyWord)
{
	return IDVec();
}

bool SexIndex::trackStu(const Student& stu)
{
	return false;
}

bool SexIndex::untrackStu(const Student& stu)
{
	return false;
}

const IDVec MapIndex::getEqByKey(KeyWord keyWord)
{
	return IDVec();
}

const IDVec MapIndex::getGeByKey(KeyWord keyWord)
{
	return IDVec();
}

const IDVec MapIndex::getLeByKey(KeyWord keyWord)
{
	return IDVec();
}

bool MapIndex::trackStu(const Student& stu)
{
	return false;
}

bool MapIndex::untrackStu(const Student& stu)
{
	return false;
}

KeyWord::KeyWord(Name name)
{
}

KeyWord::KeyWord(ID id)
{
}

KeyWord::KeyWord(Sex sex)
{
}

KeyWord::KeyWord(StuClass stuClass)
{
}

KeyWord::KeyWord(StuGrade stuGrade)
{
}

KeyWord::KeyWord(Score score)
{
}

KeyWord::operator Name()
{
}

KeyWord::operator ID()
{
}

KeyWord::operator Sex()
{
}

KeyWord::operator StuClass()
{
}

KeyWord::operator Score()
{
}

KeyWord::operator KeyWordType()
{
}

Key::Key(KeyWordType type, KeyWord(*howToGet)(const Student&), bool(*howToSet)(Student&, KeyWord))
{
}

KeyWord Key::getKey(Student& stu)
{
	return KeyWord();
}

Key::operator KeyWordType()
{
}

KeyWordType Key::getType()
{
	return KeyWordType();
}

bool Key::getKey(Student& stu, KeyWord keyWord)
{
	return false;
}

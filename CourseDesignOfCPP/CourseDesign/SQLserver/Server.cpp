#include"Server.h"
#include"md5.h"
User::User(ID id, PWD pwd = "", Name name, Sex sex) :name(name), id(id), sex(sex), pwd(pwd)
{
}

Name User::getName()const
{
	return name;
}

bool User::login(PWD token)const
{
	return pwd == hash(token);
}

ID User::getID()const
{
	return id;
}

Sex User::getSex()const
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
	if (contains(subjectName))
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
	if (contains(subjectName))
	{
		return Points.find(subjectName)->second.setPoint(newPoint);
	}
	else
	{
		return false;
	}
}

bool Score::setPoint(const Score& newScore)
{
	bool haveThenAll = contains(newScore);
	if (haveThenAll)
	{
		for (auto p : (ScoreMap)newScore)
		{
			Points.find(p.first)->second.setPoint(p.second.getPoint());
		}
	}
	return haveThenAll;
}

ClassHour Score::getClassHour(SubjectName subjectName)const
{
	if (contains(subjectName))
	{
		return Points.find(subjectName)->second.getClassHour();
	}
	else
	{
		return 0;
	}
}

bool Score::contains(SubjectName subjectName)const
{
	return Points.contains(subjectName);
}

bool Score::contains(const Score& newScore) const
{
	bool haveThenAll = true;
	for (auto p : (ScoreMap)newScore)
	{
		if (contains(p.first))
		{
			continue;
		}
		else
		{
			haveThenAll = false;
			break;
		}
	}
	return haveThenAll;
}

bool Score::addSubject(SubjectName subjectName, Point point)
{
	try
	{
		Points.insert(SingleScore(subjectName, point));
	}
	catch (...)
	{
		return false;
	}
	return true;
}

bool Score::addSubject(const Score& newScore)
{
	try
	{
		for (auto p : (ScoreMap)newScore)
		{
			Points.insert(p);
		}
	}
	catch (...)
	{
		return false;
	}
	return true;
}

bool Score::removeSubject(SubjectName subjectName)
{
	if (contains(subjectName))
	{
		Points.erase(subjectName);
		return true;
	}
	else
	{
		return false;
	}
}

bool Score::removeSubject(const Score& newScore)
{
	if (contains(newScore))
	{
		for (auto p : (ScoreMap)newScore)
		{
			Points.erase(p.first);
		}
		return true;
	}
	else
	{
		return false;
	}
}

ExamPoint Score::getGPA()const
{
	double sum = 0;
	for (auto p : Points)
	{
		sum += p.second.getPoint() * p.second.getClassHour();
	}
	sum /= getTotalClassHour();
}

ClassHour Score::getTotalClassHour()const
{
	double sum = 0;
	for (auto p : Points)
	{
		sum += p.second.getClassHour();
	}
	return sum;
}

Score::operator ScoreMap() const
{
	return Points;
}

Point::Point(ExamPoint point, ClassHour classHour) :point(point), classHour(classHour)
{
}

bool Point::setPoint(ExamPoint newPoint)
{
	point = newPoint;
	return true;
}

ExamPoint Point::getPoint()const
{
	return point;
}

ClassHour Point::getClassHour()const
{
	return classHour;
}

bool Point::operator<(const Point& b) const
{
	return point < b.point;
}

PWD hash(const PWD& in)
{
	return MD5(in + "salt").md5();
}

bool operator<(const SingleScore& a, const SingleScore& b)
{
	if (a.first == b.first)
	{
		return a.second < b.second;
	}
	else
	{
		throw std::invalid_argument("not same subject");
	}
}

bool operator==(const Score& stu, const Score& stand)
{
	return (stu.contains(stand) && stu.compare(stand));
}

bool operator>=(const Score& stu, const Score& stand)
{
	return (stu.contains(stand) && stu.compare<std::greater_equal<ExamPoint> >(stand));
}

bool operator<=(const Score& stu, const Score& stand)
{
	return (stu.contains(stand) && stu.compare<std::less_equal<ExamPoint> >(stand));
}

bool operator!=(const Score& stu, const Score& stand)
{
	return (stu.contains(stand) && stu.compare<std::not_equal_to<ExamPoint> >(stand));
}

bool operator<(const Score& stu, const Score& stand)
{
	return (stu.contains(stand) && stu.compare<std::less<ExamPoint> >(stand));
}

bool operator>(const Score& stu, const Score& stand)
{
	return (stu.contains(stand) && stu.compare<std::greater<ExamPoint> >(stand));
}

IDVec operator&(const IDVec& a, const IDVec& b)
{
	IDVec aa = a, bb = b;
	std::sort(aa.begin(), aa.end());
	std::sort(bb.begin(), bb.end());
	auto ai = aa.begin();
	auto bi = bb.begin();
	IDVec ans;
	while (ai != aa.end() && bi != bb.end())
	{
		if (*ai == *bi)
		{
			ans.push_back(*ai);
			ai++;
			bi++;
		}
		else
		{
			if (*ai > * bi)
			{
				bi++;
			}
			else
			{
				ai++;
			}
		}

	}
	return ans;
}

IDVec operator|(const IDVec& a, const IDVec& b)
{
	IDset aa(a.begin(), a.end());
	for (auto p : b)
	{
		aa.insert(p);
	}
	IDVec ans(aa.begin(), aa.end());
	return ans;
}

bool operator<(const KeyWord& a, const KeyWord& b)
{
	if (a.type == b.type)
	{
		switch ((KeyWordType::BasicType)a.type)
		{
		case KeyWordType::BasicType::name:
			return a.name < b.name;
			break;
		case KeyWordType::BasicType::id:
			return a.id < b.id;
			break;
		case KeyWordType::BasicType::sex:
			return a.sex < b.sex;
			break;
		case KeyWordType::BasicType::stuClass:
			return a.stuClass < b.stuClass;
			break;
		case KeyWordType::BasicType::stuGrade:
			return a.stuGrade < b.stuGrade;
			break;
		case KeyWordType::BasicType::score:
			return a.singleScore < b.singleScore;
		default:
			throw std::invalid_argument("unknow type");
			break;
		}
	}
	else
	{
		throw std::invalid_argument("bad type match");
	}
}

std::string form(Record kwyWord, std::vector<size_t>& width)//TODO
{
	return std::string();
}

StudentList::StudentList()
{
}

bool StudentList::addStudent(const StudentVec& vec)
{
	for (auto s : vec)
	{
		data.insert({ s.getID(),s });
	}
	return true;
}

bool StudentList::removeStudent(const IDVec& vec)
{
	for (auto s : vec)
	{
		if (!data.contains(s))
		{
			return false;
		}
	}
	for (auto s : vec)
	{
		data.erase(s);
	}
	return true;
}

bool StudentList::buildIndexOn(KeyName name)
{
	return false;
}

inline bool StudentList::contains(ID id)const
{
	return data.contains(id);
}

const Student& StudentList::operator[](ID id)const
{
	return data.find(id)->second;
}

Student& StudentList::getStu(ID id)
{
	return data[id];
}

Student::Student(User user, StuGrade stuGrade, StuClass stuClass) :User(user), stuGrade(stuGrade), stuClass(stuClass)
{
}

StuClass Student::getStuClass()
{
	return stuClass;
}

bool Student::setStuClass(StuClass newStuClass)
{
	stuClass = newStuClass;
	return true;
}

StuGrade Student::getStuGrade()
{
	return stuGrade;
}

GoodResult::GoodResult(std::vector<KeyName> names) :head(names)
{
}

GoodResult::operator bool() const
{
	return true;
}

bool GoodResult::addRec(Record& newRec)
{
	rec.push_back(newRec);
	return true;
}

SuccessResult::SuccessResult(const std::string& msg):msg(msg)
{
}

SuccessResult::operator bool() const
{
	return true;
}

GoodResult::operator std::string() const//TODO
{
}

WhereFilter::WhereFilter(std::string expr) :expr(expr)
{
}

IDVec WhereFilter::filt(const StudentList& list)
{
	try
	{
		enum LogicOp
		{
			left, right, logicAnd, logicOr
		};
		std::unordered_map<std::string, LogicOp> ops =
		{
			{"and",logicAnd},
			{"or",logicOr},
			{"(",left},
			{")",right}
		};
		std::stack<IDVec> IDs;
		std::stack<LogicOp> Ops;
		std::stringstream cmd(expr);
		std::string buf;
		auto pop = [&Ops, &IDs]() {
			if (Ops.top() > right&& IDs.size() >= 2)
			{
				LogicOp nextOp = Ops.top();
				Ops.pop();
				IDVec a = IDs.top();
				IDs.pop();
				IDVec b = IDs.top();
				IDs.pop;
				switch (nextOp)
				{
				case left:
					break;
				case right:
					break;
				case logicAnd:
					IDs.push(a & b);
					break;
				case logicOr:
					IDs.push(a | b);
					break;
				default:
					break;
				}
			}
			else
			{
				throw std::invalid_argument("in sufficent arg");
			}
		};
		while (cmd >> buf)
		{
			if (!ops.contains(buf))
			{
				IDVec num = {};//TODO
				IDs.push(num);
			}
			else
			{
				LogicOp nextOp = ops[buf];
				if (nextOp == left)
				{
					Ops.push(nextOp);
				}
				else
				{
					if (nextOp == right)
					{
						while (!Ops.empty() && Ops.top() != left)
						{
							pop();
						}
					}
					else
					{
						while (!Ops.empty() && Ops.top() <= nextOp)
						{
							pop();
						}
						Ops.push(nextOp);
					}
				}
			}
		}
		while (!Ops.empty())
		{
			pop();
		}
		if (IDs.size() != 1)
		{
			return {};
		}
		else
		{
			return IDs.top();
		}
	}
	catch (const std::exception&)
	{
		return {};
	}
}

ColumnFilter::ColumnFilter(std::string filter)
{
	std::stringstream ss(filter);
	std::string buf;
	while (ss >> buf)
	{
		try
		{
			columns.push_back(Key(KeyWordType(buf)));
		}
		catch (...)
		{
			columns.clear();
			return;
		}
	}
}

std::vector<KeyName> ColumnFilter::getHeads() const
{
	std::vector<KeyName> names;
	for (auto k = columns.begin(); k != columns.end(); k++)
	{
		names.push_back((k->getType()));
	}
	return names;
}

GoodResult ColumnFilter::getVal(const IDVec& vec, const StudentList& list)const
{
	GoodResult result(getHeads());
	for (auto id : vec)
	{
		Record rec;
		const Student& thisStu = list[id];
		for (auto k = columns.begin(); k != columns.end(); k++)
		{
			rec.push_back(k->getKey(thisStu));
		}
		result.addRec(rec);
	}
	return result;
}

SQLrequest::SQLrequest(std::string request)//TODO
{
	
}

GoodResult SQLrequest::exec(StudentList& list)
{
	return GoodResult();
}

//const IDVec SexIndex::getEqByKey(KeyWord keyWord)
//{
//	return IDVec();
//}
//
//const IDVec SexIndex::getGeByKey(KeyWord keyWord)
//{
//	return IDVec();
//}
//
//const IDVec SexIndex::getLeByKey(KeyWord keyWord)
//{
//	return IDVec();
//}
//
//bool SexIndex::trackStu(const Student& stu)
//{
//	return false;
//}
//
//bool SexIndex::untrackStu(const Student& stu)
//{
//	return false;
//}
//
//const IDVec MapIndex::getEqByKey(KeyWord keyWord)
//{
//	return IDVec();
//}
//
//const IDVec MapIndex::getGeByKey(KeyWord keyWord)
//{
//	return IDVec();
//}
//
//const IDVec MapIndex::getLeByKey(KeyWord keyWord)
//{
//	return IDVec();
//}
//
//bool MapIndex::trackStu(const Student& stu)
//{
//	return false;
//}
//
//bool MapIndex::untrackStu(const Student& stu)
//{
//	return false;
//}

KeyWord::KeyWord(Name name) :type(KeyWordType::BasicType::name), name(name),singleScore("",0)
{

}

KeyWord::KeyWord(ID id) :type(KeyWordType::BasicType::id), id(id), singleScore("", 0)
{

}

KeyWord::KeyWord(Sex sex) : type(KeyWordType::BasicType::sex),sex(sex), singleScore("", 0)
{

}

KeyWord::KeyWord(StuClass stuClass) : type(KeyWordType::BasicType::stuClass), stuClass(stuClass), singleScore("", 0)
{
}

KeyWord::KeyWord(StuGrade stuGrade) : type(KeyWordType::BasicType::stuGrade), stuGrade(stuGrade), singleScore("", 0)

{
}

KeyWord::KeyWord(SingleScore singleSore): type(KeyWordType::BasicType::score)
{
}

KeyWord::~KeyWord()
{


}

KeyWord::operator Name()const
{
}

KeyWord::operator ID()const
{
}

KeyWord::operator Sex()const
{
}

KeyWord::operator StuClass()const
{
}

KeyWord::operator SingleScore()const
{
}

KeyWord::operator KeyWordType()const
{
}

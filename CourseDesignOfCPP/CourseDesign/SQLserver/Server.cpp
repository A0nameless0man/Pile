#include"Server.h"
User::User(ID id, PWD pwd, Name name, Sex sex) :name(name), id(id), sex(sex), hashedPWD(pwd)
{
}

Name User::getName()const
{
	return name;
}

bool User::login(PWD token)const
{
	return hashedPWD == hash(token);
}

bool User::setPWD(PWD newPWD)
{
	hashedPWD = hash(newPWD);
	return true;
}

PWD User::getHashedPwd() const
{
	return hashedPWD;
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
	points.insert(sig);
}

Point Score::getPoint(SubjectName subjectName)const
{
	if (contains(subjectName))
	{
		return points.find(subjectName)->second;
	}
	else
	{
		if (subjectName == "GPA")//consider GPA as a subjectName
		{
			return Point(getGPA());
		}
		else
		{
			return 0;
		}
	}
}

bool Score::setPoint(SubjectName subjectName, ExamPoint newPoint)
{
	if (contains(subjectName))
	{
		return points.find(subjectName)->second.setPoint(newPoint);
	}
	else
	{
		return false;
	}
}

bool Score::setPoint(SubjectName subjectName, Point newPoint)
{
	if (contains(subjectName))
	{
		points[subjectName] = newPoint;
		return true;
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
			points.find(p.first)->second.setPoint(p.second.getRawPoint());
		}
	}
	return haveThenAll;
}

ClassHour Score::getClassHour(SubjectName subjectName)const
{
	if (contains(subjectName))
	{
		return points.find(subjectName)->second.getClassHour();
	}
	else
	{
		return 0;
	}
}

bool Score::contains(SubjectName subjectName)const
{
	return points.contains(subjectName);
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
		points.insert(SingleScore(subjectName, point));
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
			points.insert(p);
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
		points.erase(subjectName);
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
			points.erase(p.first);
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
	for (auto p : points)
	{
		sum += p.second.getRawPoint() * p.second.getClassHour();
	}
	sum /= getTotalClassHour();
}

ClassHour Score::getTotalClassHour()const
{
	double sum = 0;
	for (auto p : points)
	{
		sum += p.second.getClassHour();
	}
	return sum;
}

Score::operator ScoreMap() const
{
	return points;
}

Point::Point(ExamPoint point, ClassHour classHour) :point(point), classHour(classHour)
{
}

bool Point::setPoint(ExamPoint newPoint)
{
	point = newPoint;
	return true;
}

ExamPoint Point::getRawPoint()const
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
			return a.point < b.point;
			break;
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

std::string form(Record keyWord, std::vector<size_t>& width)
{
	if (width.size() == keyWord.size())
	{
		std::string ans = "|";
		for (size_t i = 0; i < keyWord.size(); i++)
		{
			ans += keyWord[i].form(width[i]) + "|";
		}
		return ans;
	}
	else
	{
		throw std::invalid_argument("different length");
	}
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

StuClass Student::getStuClass()const
{
	return stuClass;
}

bool Student::setStuClass(StuClass newStuClass)
{
	stuClass = newStuClass;
	return true;
}

StuGrade Student::getStuGrade()const
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

KeyWordType::KeyWordType(BasicType bType, SubjectName sName) :basicType(bType), subjectName(sName)
{
}

KeyWordType::KeyWordType(std::string name) : basicType(stringToBasicType(name))
{
	if (basicType == score)
	{
		subjectName = name;
	}
}

KeyWordType::BasicType KeyWordType::stringToBasicType(const std::string& name)
{
	using Type = KeyWordType::BasicType;
	std::unordered_map<std::string, BasicType> map =
	{
		{"name",Type::name},
		{"id",Type::id},
		{"sex",Type::sex},
		{"class",Type::stuClass},
		{"grade",Type::stuGrade}
	};
	if (map.contains(name))
	{
		return map.find(name)->second;
	}
	else
	{
		return Type::score;
	}
}

GoodResult::operator std::string() const
{
	if (head.size() == 1)
	{
		std::sort
		(
			rec.begin(),
			rec.end(),
			[](const Record& a, const Record& b)->bool
			{
				return a[0] < b[0];
			}
		);
	}
	const size_t FIXED_WIDTH = 8;
	std::vector<size_t> width(head.size(), FIXED_WIDTH);
	std::string res;
	res += "|rank    |";
	for (auto h : head)
	{
		if (h.length() < FIXED_WIDTH)
		{
			res += std::string(FIXED_WIDTH - h.length(),' ');
		}
		res += h+"|";
	}
	res += '\n';
	size_t cnt = 0;
	for (auto r : rec)
	{
		auto i = std::to_string(++cnt);
		if (i.length() < FIXED_WIDTH)
		{
			res += std::string(FIXED_WIDTH - i.length(), ' ');
		}
		res += i;
		res += form(r, width);
		res += "\n";
	}
	return res;
}

KeyWordType::operator BasicType() const
{
	return basicType;
}

KeyWordType::operator SubjectName() const
{
	return subjectName;
}

bool KeyWordType::operator==(const KeyWordType& b) const
{
	if (basicType == b.basicType)
	{
		if (basicType == score)
		{
			return subjectName == b.subjectName;
		}
		else
		{
			return true;
		}
	}
	else
	{
		return false;
	}
}

SuccessResult::SuccessResult(const std::string& msg) :msg(msg)
{
}

SuccessResult::operator bool() const
{
	return true;
}

SuccessResult::operator std::string()const
{
	return "It was a SuccessResult :\n" + msg;
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
				IDs.pop();
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
				std::string keyName = buf;
				std::string op, keyVal;
				enum compareOp
				{
					eq,
					neq,
					ge,
					geq,
					le,
					leq
				};
				std::map<std::string, compareOp> Cmap =
				{
					{"==",eq},
					{"!=",neq},
					{">",ge},
					{">=",geq},
					{"<",le},
					{"<=",eq}
				};
				cmd >> op >> keyVal;
				if (!Cmap.contains(op))
				{
					throw std::invalid_argument
					(
						"UnKnown opewrator " + op + " in express\n"
						+ keyName + " " + op + " " + keyVal
					);
				}
				else
				{
					compareOp p = Cmap[op];
					switch (p)
					{
					case eq:
						IDs.push(list.getByKey(keyName, KeyWord(KeyWordType(keyName), keyVal)));
						break;
					case neq:
						IDs.push(list.getByKey<std::not_equal_to<KeyWord>>(keyName, KeyWord(KeyWordType(keyName), keyVal)));
						break;
					case ge:
						IDs.push(list.getByKey<std::greater<KeyWord>>(keyName, KeyWord(KeyWordType(keyName), keyVal)));
						break;
					case geq:
						IDs.push(list.getByKey<std::greater_equal<KeyWord>>(keyName, KeyWord(KeyWordType(keyName), keyVal)));
						break;
					case le:
						IDs.push(list.getByKey<std::less<KeyWord>>(keyName, KeyWord(KeyWordType(keyName), keyVal)));
						break;
					case leq:
						IDs.push(list.getByKey<std::less_equal<KeyWord>>(keyName, KeyWord(KeyWordType(keyName), keyVal)));
						break;
					default:
						throw std::invalid_argument
						(
							"UnKnown opewrator " + op + " after explan express\n"
							+ keyName + " " + op + " " + keyVal
						);
						break;
					}
				}
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
			columns.push_back(Key(buf));
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

bool ColumnFilter::applyVal(const IDVec& vec, StudentList& list) const
{
	for (auto id : vec)
	{
		if (list.contains(id))
		{
			Student& thisStu = list.getStu(id);
			for (auto k : columns)
			{
				k.setKey(thisStu);
			}
		}
		else
		{
			continue;
		}
	}
	return true;
}

SQLrequest::SQLrequest(std::string request)
{
	std::string cmd, c, w, i, buf;
	std::stringstream ss(request);
	while (ss >> buf)
	{
		if (buf == "set" || buf == "select" || buf == "remove")
		{
			if (buf == "set")
			{
				type = set;
			}
			else if (buf == "select")
			{
				type = select;
			}
			else
			{
				type = remove;
			}
			while (ss && buf != "where")
			{
				ss >> buf;
				if (buf != "where")
					c += buf + " ";
			}
			while (ss >> buf)
			{
				w += buf + " ";
			}
			columnFilter = ColumnFilter(c);
			whereFilter = WhereFilter(w);
		}
		else if (buf == "insert")
		{
			type = insert;
			while (ss >> buf)
			{
				i += buf + " ";
			}
			insertBuffer = i;
		}
	}
}

std::string SQLrequest::exec(StudentList& list)
{
	IDVec Where = whereFilter.filt(list);
	switch (type)
	{
	case SQLrequest::set:
		if (columnFilter.applyVal(Where, list))
		{
			return "applied";
		}
		else
		{
			return "failed";
		}
		break;
	case SQLrequest::select:
		return columnFilter.getVal(Where, list).operator std::string();
		break;
	case SQLrequest::insert:
	{
		Student buffer;
		std::stringstream ss(insertBuffer);
		StudentVec vec;
		while (deFormat(ss, buffer))
		{
			vec.push_back(buffer);
		}
		list.addStudent(vec);
	}
	break;
	case SQLrequest::remove:
		if (list.removeStudent(Where))

		{
			return "applied";
		}
		else
		{
			return "failed";
		}
	default:
		throw std::invalid_argument("unknow sql type");
		break;
	}
}

KeyWord::KeyWord(Name name) :type(KeyWordType::BasicType::name), name(name)
{

}

KeyWord::KeyWord(ID id) : type(KeyWordType::BasicType::id), id(id)
{

}

KeyWord::KeyWord(Sex sex) : type(KeyWordType::BasicType::sex), sex(sex)
{

}

KeyWord::KeyWord(StuClass stuClass) : type(KeyWordType::BasicType::stuClass), stuClass(stuClass)
{

}

KeyWord::KeyWord(StuGrade stuGrade) : type(KeyWordType::BasicType::stuGrade), stuGrade(stuGrade)
{

}

KeyWord::KeyWord(Point singleSore) : type(KeyWordType::BasicType::score), point(singleSore)
{

}

KeyWord::KeyWord()
{
}

KeyWord::KeyWord(KeyWordType type, std::string str)
{
	std::stringstream ss(str);
	switch ((KeyWordType::BasicType)type)
	{
	case KeyWordType::BasicType::id:
		id = ID(str);
		break;
	case KeyWordType::BasicType::sex:
		deFormat(ss, sex);
	case KeyWordType::BasicType::stuClass:
		stuClass = StuClass(str);
		break;
	case KeyWordType::BasicType::stuGrade:
		ss >> stuGrade;
		break;
	case KeyWordType::BasicType::score:
		deFormat(ss, point);
		break;
	case KeyWordType::BasicType::name:
		name = Name(str);
		break;
	default:
		throw std::invalid_argument("unknow type");
		break;
	}
}

KeyWord::~KeyWord()
{

}

std::string KeyWord::form(size_t width) const
{
	std::string ans = operator std::string();
	ans += std::string((ans.length() < width ? (width - ans.length()) : 0), ' ');
	return ans;
}

KeyWord::operator Name()const
{
	return name;
}

KeyWord::operator ID()const
{
	return id;
}

KeyWord::operator Sex()const
{
	return sex;
}

KeyWord::operator StuClass()const
{
	return stuClass;
}

KeyWord::operator Point()const
{
	return point;
}

KeyWord::operator KeyWordType()const
{
	return type;
}

KeyWord::operator std::string()const
{
	switch ((KeyWordType::BasicType)type)
	{
	case KeyWordType::BasicType::id:
		return id;
		break;
	case KeyWordType::BasicType::sex:
		return format(sex);
		break;
	case KeyWordType::BasicType::stuClass:
		return stuClass;
		break;
	case KeyWordType::BasicType::stuGrade:
		return std::to_string(stuGrade);
		break;
	case KeyWordType::BasicType::score:
		return format(point);
		break;
	case KeyWordType::BasicType::name:
		return name;
		break;
	default:
		throw std::invalid_argument("unknow type");
		return "";
		break;
	}
}

Key::Key(KeyWordType type, KeyWord data) :type(type), data(data)
{
}

Key::Key(std::string str)
{
	std::string name = str.substr(0, str.find('='));
	type = KeyWordType(name);
	if (str.find('=') != std::string::npos)
	{
		data = KeyWord(type, str.substr(str.find('=') + 1, str.size()));
	}
}

Key::~Key()
{
}

KeyWord Key::getKey(const Student& stu) const
{
	using Type = KeyWordType::BasicType;
	switch (type.operator KeyWordType::BasicType())
	{
	case Type::id:
		return KeyWord(stu.getID());
		break;
	case Type::name:
		return KeyWord(stu.getName());
		break;
	case Type::score:
		return KeyWord(stu.getPoint(type.operator SubjectName()));
		break;
	case Type::sex:
		return KeyWord(stu.getSex());
		break;
	case Type::stuClass:
		return KeyWord(stu.getStuClass());
		break;
	case Type::stuGrade:
		return KeyWord(stu.getStuGrade());
	default:
		throw std::invalid_argument("unknowType");
		break;
	}
}

bool Key::setKey(Student& stu) const
{
	using Type = KeyWordType::BasicType;
	switch (type.operator KeyWordType::BasicType())
	{
	case Type::id:
		return false;
		break;
	case Type::name:
		return false;
		break;
	case Type::score:
		if (stu.contains(type.operator SubjectName()))
		{
			return stu.setPoint(type.operator SubjectName(), (data.operator Point()));
		}
		else
		{
			return stu.addSubject(type.operator SubjectName(), data.operator Point());
		}
		break;
	case Type::sex:
		return false;
		break;
	case Type::stuClass:
		return stu.setStuClass(data.operator StuClass());
		break;
	case Type::stuGrade:
		//return stu.setStuGrade((StuGrade)data);
		return false;
	default:
		throw std::invalid_argument("unknowType");
		break;
	}
}

KeyWordType Key::getType() const
{
	return type;
}
//
//bool operator==(const Score& stu, const Score& stand)
//{
//	return (stu.contains(stand) && stu.compare(stand));
//}
//
//bool operator>=(const Score& stu, const Score& stand)
//{
//	return (stu.contains(stand) && stu.compare<std::greater_equal<ExamPoint> >(stand));
//}
//
//bool operator<=(const Score& stu, const Score& stand)
//{
//	return (stu.contains(stand) && stu.compare<std::less_equal<ExamPoint> >(stand));
//}
//
//bool operator!=(const Score& stu, const Score& stand)
//{
//	return (stu.contains(stand) && stu.compare<std::not_equal_to<ExamPoint> >(stand));
//}
//
//bool operator<(const Score& stu, const Score& stand)
//{
//	return (stu.contains(stand) && stu.compare<std::less<ExamPoint> >(stand));
//}
//
//bool operator>(const Score& stu, const Score& stand)
//{
//	return (stu.contains(stand) && stu.compare<std::greater<ExamPoint> >(stand));
//}

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


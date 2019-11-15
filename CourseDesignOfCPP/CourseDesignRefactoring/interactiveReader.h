#pragma once
#include<string>
#include<set>
namespace iReader
{
	using stdIstream = std::basic_istream<char, std::char_traits<char> >;
	using stdOstream = std::basic_ostream<char, std::char_traits<char> >;

	//可能应当拆解


	//序列化器
	template<class T>
	class ToString
	{
	public:
		std::string operator()(const T& t)const;
	};
	//反序列化器
	template<class T, class Is = stdIstream>
	class StdIstreamReader
	{
	public:
		T	read(Is& is)const;
	};

	//限制器
	template<class T, class Serializer = ToString<T> >
	class Restricter
	{
	public:
		virtual bool operator()(const T&)const = 0;
		virtual std::string explainRestriction()const = 0;
	};

	template<class T, class Serializer = ToString<T>>
	class NoRestrict :public Restricter<T, Serializer>
	{
	public:
		bool operator()(const T&)const;
		std::string explainRestriction()const;
	};

	template<class T, class Serializer = ToString<T>, class Compare = std::less<T>>
	class InRange :public Restricter<T, Serializer>
	{
	private:
		const T lowerBound;
		const T upperBound;
		const Compare cmp;
		const Serializer serializer;
	public:
		InRange
		(
			const T& lowerBound,
			const T& upperBound,
			const Serializer serializer = Serializer(),
			const Compare cmp = Compare()
		);
		bool operator()(const T& t)const;
		std::string explainRestriction()const;
	};

	template<
		class T,
		class Serializer = ToString<T>,
		class Compare = std::less<T>,
		class Allocator = std::allocator<T>
	>
		class WithIn :public Restricter<T, Serializer>
	{
	public:
		WithIn(
			const std::set<T, Compare, Allocator>& set = {},
			const Serializer serializer = Serializer()
		);
		bool operator()(const T& t)const;
		std::string explainRestriction()const;
		void add(const T& t);
	private:
		std::set<T, Compare, Allocator> set;
		const Serializer serializer;
	};


	//读取器
	template
		<
		class T,
		class Restriction = NoRestrict<T, ToString<T>>,
		class Serializer = ToString<T>,
		class UnSerializer = StdIstreamReader<T>
		>
		class InteractiveReader
	{
	private:
		const Restriction restriction;
		const std::string variableNameRequired;
		const bool voidAble;
		const UnSerializer unSerializer;
		const Serializer serializer;
	public:
		InteractiveReader
		(
			const std::string& variableNameRequired,
			const Restriction& restriction = NoRestrict(),
			const UnSerializer& unSerializer = UnSerializer(),
			const Serializer& serializer = Serializer(),
			bool voidAble = false
		);
		template<class Is = stdIstream, class Os = stdOstream>
		T read(Is& is, Os& os)const;
	};


	//以下为实现
	//序列化器

	template<class T>
	inline std::string ToString<T>::operator()(const T& t)const
	{
		return std::to_string(t);
	}

	template<>
	inline std::string ToString<std::string>::operator()(const std::string& t)const
	{
		return t;
	}

	//反序列化器

	template<class T, class Is>
	inline T StdIstreamReader<T, Is>::read(Is& is)const
	{
		T t;
		is >> t;
		return t;
	}

	//限制器

	template<class T, class Serializer>
	inline bool NoRestrict<T, Serializer>::operator()(const T&)const
	{
		return true;
	}

	template<class T, class Serializer>
	inline std::string NoRestrict<T, Serializer>::explainRestriction()const
	{
		return "除了类型应当为" + typeid(T).name() + "以外,没有其它限制";
	}

	template<class T, class Serializer, class Compare>
	inline InRange<T, Serializer, Compare>::InRange
	(
		const T& lowerBound,
		const T& upperBound,
		const Serializer serializer,
		const Compare cmp
	) :
		lowerBound(lowerBound),
		upperBound(upperBound),
		serializer(serializer),
		cmp(cmp)
	{

	}

	template<class T, class Serializer, class Compare>
	inline bool InRange<T, Serializer, Compare>::operator()(const T& t)const
	{
		return (!cmp(t, lowerBound)) && cmp(t, upperBound);
	}

	template<class T, class Serializer, class Compare>
	inline std::string InRange<T, Serializer, Compare>::explainRestriction()const
	{
		return
			"类型应当为" + std::string(typeid(T).name()) +
			",且范围在" + serializer(lowerBound) +
			"到" + serializer(upperBound) + "之间";
	}

	template<class T, class Serializer, class Compare, class Allocator>
	inline WithIn<T, Serializer, Compare, Allocator>::WithIn
	(
		const std::set<T, Compare, Allocator>& set,
		const Serializer serializer
	) :
		set(set),
		serializer(serializer)
	{
	}

	template<class T, class Serializer, class Compare, class Allocator>
	inline bool WithIn<T, Serializer, Compare, Allocator>::operator()(const T& t)const
	{
		return set.contains(t);
	}

	template<class T, class Serializer, class Compare, class Allocator>
	inline std::string WithIn<T, Serializer, Compare, Allocator>::explainRestriction() const
	{
		std::string ans("输入应当为:\n");
		for (auto i = set.begin(); i != set.end(); ++i)
		{
			ans.append("\t" + serializer(*i) + ",\n");
		}
		ans.append("之一");
		return ans;
	}

	template<class T, class Serializer, class Compare, class Allocator>
	inline void WithIn<T, Serializer, Compare, Allocator>::add(const T& t)
	{
		set.insert(t);
	}

	//读取器

	template<class T, class Restriction, class Serializer, class UnSerializer>
	inline InteractiveReader<T, Restriction, Serializer, UnSerializer>::InteractiveReader
	(
		const std::string& variableNameRequired,
		const Restriction& restriction,
		const UnSerializer& unSerializer,
		const Serializer& serializer,
		bool voidAble
	) :
		variableNameRequired(variableNameRequired),
		restriction(restriction),
		unSerializer(unSerializer),
		serializer(serializer),
		voidAble(voidAble)
	{
	}

	template<class T, class Restriction, class Serializer, class UnSerializer>
	template<class Is, class Os>
	inline T InteractiveReader<T, Restriction, Serializer, UnSerializer>::read(Is& is, Os& os) const
	{
		while (true)
		{
			os << "请输入" << variableNameRequired << ":\n";
			os << restriction.explainRestriction() << std::endl;
			T t = (unSerializer.read(is));
			if (restriction(t))
			{
				return t;
			}
			else
			{
				os << "输入不符合要求,请重试" << std::endl;
			}
		}
	}

}

#ifndef _VARIABLE_DEF_H_
#define _VARIABLE_DEF_H_
#include <string>

namespace Constraints {
	class Variable {
	private:
		std::string _name;
		int _index;
	public:
		Variable();
		Variable(std::string const& name, unsigned int index);
		~Variable();
		unsigned int getIndex() const;
		std::string toString() const;
	};
}

#endif //_VARIABLE_DEF_H_

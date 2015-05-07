#ifndef _SOLVER_CONSTRAINT_DEF_H_
#define _SOLVER_CONSTRAINT_DEF_H_
#include "variable.h"
#include "tableau.h"
#include <vector>
#include <string>

namespace Constraints {

	typedef std::pair<Variable,double> ConstraintItem;

	typedef enum {
		Invalid = 0,
		Equal,
		NotEqual,
		LessThan,
		GreaterThan,
		GreaterThanOrEqual,
		LessThanOrEqual,
		NumComparisonTypes
	} ComparisonType;

	class Constraint {
	private:
		static const char* ComparisonTypeStrings[];
		std::vector<ConstraintItem> _items;
		ComparisonType _type;
		double _value;
	public:
		Constraint();
		Constraint(double value);
		~Constraint();

		void addItem(Variable const& var, double multiplier);
		void setResult(double endValue);
		void setComparisonType(ComparisonType const& type);
		ComparisonType getComparisonType() const;

		std::string toString() const;
		
		/**
		 * Add this constraint to a simplex table, if typeOverride is anything other than
		 * invalid then it will be used instead of the constraints
		 */
		void addToTable(Simplex::Table& table, ComparisonType typeOverride = ComparisonType::Invalid) const;
	};
};

#endif //_SOLVER_CONSTRAINT_DEF_H_

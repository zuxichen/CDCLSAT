#ifndef __VALUATUION_H__
#define __VALUATUION_H__ 1

#include <iostream>
#include <vector>
#include <cassert>
#include "representation.h"

class Valuation {
public:
  Valuation(unsigned num_of_vars)
    : _values(num_of_vars, B_UNDEFINED), _curr_level(0)
  {}

  unsigned current_level() const;
  void push(Literal l, bool decide = false);
  void backjumpToLiteral(const Literal & l, std::vector<Literal> & literals);
  bool findFirstUndefined(Variable &v) const;
  ExtendedBoolean variableValue(Variable v) const;
  ExtendedBoolean literalValue(Literal l) const;
  bool isClauseFalse(const Clause &c) const;
  bool isClauseUnit(const Clause &c, Literal &l) const;
  void printValuation(std::ostream &out) const;
  void printStack(std::ostream &out) const;
  void lastAssertedLiteral(const Clause & c, Literal & l, bool & empty) const;
  unsigned numberOfTopLevelLiterals(const Clause & c) const;
  void clear();

private:
  std::vector<ExtendedBoolean> _values;
  std::vector<std::pair<Literal, unsigned>> _stack;
  unsigned _curr_level;
};

#endif
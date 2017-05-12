#include "representation.h"

Literal litFromVar (Variable v, Polarity p) {
  return p == P_POSITIVE ? v << 1 :  (v << 1) | 1;
}

Variable varFromLit(Literal l) {
  return l >> 1;
}

bool isPositive(Literal l) {
  return !(l & 1);
}

bool isNegative(Literal l) {
  return l & 1;
}

Literal oppositeLiteral(Literal l) {
  return l ^ 1;
}

int intFromLit(Literal l) {
  return isPositive(l) ? (int) varFromLit(l) + 1 : -(int) (varFromLit(l) + 1);
}

Literal litFromInt(int i) {
  return i > 0 ? litFromVar(i - 1, P_POSITIVE) : litFromVar(-i - 1, P_NEGATIVE);
}

void printClause(const Clause &c, std::ostream &out) {
  out << "[";
  for (auto i = c.cbegin(); i != c.cend(); i++) {
    out << intFromLit(*i) << " ";
  }
  out << "]";

  out << std::endl;
}

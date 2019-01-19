#include "Triangle.h"

Triangle & Triangle::operator = (const Triangle &opd) {
	if (&opd != this) {
		_p1 = opd._p1;
		_p2 = opd._p2;
		_p3 = opd._p3;
	}
	return *this;
}

/*Triangle Triangle::operator + (const Triangle &opd) const {
	return Triangle(_p1 + opd._p1, _p2 + opd._p2, _p3 + opd._p3);
}

Triangle Triangle::operator - (const Triangle &opd) const {
	return Triangle(_p1 - opd._p1, _p2 - opd._p2, _p3 - opd._p3);
}

Triangle Triangle::operator * (const int & i) const {
	return Triangle(_p1 * i, _p2 * i, _p3 * i);
}

const Triangle operator * (const int & i, const Triangle &opd) {
	return opd * i;
}*/

/*const bool Triangle::operator == (Triangle &opd) {
	return opd._p1 == _p1 && opd._p2 == _p2 && opd._p3 == _p3;
}*/

/*ostream & operator << (ostream &s, const Triangle &opd) {
	return s << "Triangle," << opd.getP1() << "," << opd.getP2() << "," << opd.getP3() << "," << opd.getColor() << endl;
}*/

Triangle::operator string() const {
	ostringstream s;
	s << "Triangle," << getP1() << "," << getP2() << "," << getP3() << "," << getColor();
	string msg = s.str();
	return msg;
}

#include "Segment.h"

Segment & Segment::operator = (const Segment &opd) {
	if (&opd != this) {
		_p1 = opd._p1;
		_p2 = opd._p2;
	}
	return *this;
}

/*Segment Segment::operator + (const Segment &opd) const {
	return Segment(_p1 + opd._p1, _p2 + opd._p2);
}

Segment Segment::operator - (const Segment &opd) const {
	return Segment(_p1 - opd._p1, _p2 - opd._p2);
}

Segment Segment::operator * (const int &i) const {
	return Segment(_p1 * i, _p2 * i);
}

const Segment operator * (const int & i, const Segment &opd) {
	return opd * i;
}*/

/*const bool Segment::operator == (Segment &opd) {
	return opd._p1 == _p1 && opd._p2 == _p2;
}*/

/*ostream & operator << (ostream &s, const Segment &opd) {
	return s << "Segment," << opd.getP1() << "," << opd.getP2() << "," << opd.getColor() << endl;
}*/

Segment::operator string() const {
	ostringstream s;
	s << "Segment," << getP1() << "," << getP2() << "," << getColor();
	string msg = s.str();
	return msg;
}

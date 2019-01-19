#include "Cercle.h"

Cercle & Cercle::operator = (const Cercle &opd) {
	if (&opd != this) {
		_p1 = opd._p1;
		_p2 = opd._p2;
	}
	return *this;
}

/*Cercle Cercle::operator + (const Cercle &opd) const {
	return Cercle(_p1 + opd._p1, _p2 + opd._p2);
}

Cercle Cercle::operator - (const Cercle & opd) const {
	return Cercle(_p1 - opd._p1, _p2 - opd._p2);
}

Cercle Cercle::operator * (const int &i) const {
	return Cercle(_p1 * i, _p2 * i);
}

const Cercle operator * (const int & i, const Cercle &opd) {
	return opd * i;
}*/

/*const bool Cercle::operator == (Cercle &opd) {
	return opd._p1 == _p1 && opd._p2 == _p2;
}*/

Cercle::operator string() const {
	ostringstream s;
	s << "Cercle," << getP1() << "," << getP2() << "," << getColor();
	string msg = s.str();
	return msg;
}

#include "Vecteur2D.h"

const Vecteur2D Vecteur2D::operator - () const {
	return Vecteur2D(-_x, -_y);
}

const Vecteur2D Vecteur2D::operator + (const Vecteur2D &opd) const {
	return Vecteur2D(_x + opd._x, _y + opd._y);
}

const Vecteur2D Vecteur2D::operator * (const double & i) const {
	return Vecteur2D(_x*i, _y*i);
}

Vecteur2D::operator string() const {
	ostringstream os;
	os << "Vecteur2D," << _x << "," << _y << ",";
	return os.str();
}

const Vecteur2D operator * (const double & i, const Vecteur2D &opd) {
	return opd * i;
}

ostream & operator << (ostream &s, const Vecteur2D &opd) {
	s << opd.getX() << "," << opd.getY();
	return s;
}

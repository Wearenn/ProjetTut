//
// Created by sebas on 10/10/2018.
//

#include "Composite.h"

/*Composite Composite::operator*(const int & opd)
{
	return Composite();
}

Composite operator*(const int & i, Composite & opd)
{
	return Composite();
}*/

/*ostream & operator<<(ostream & s, Composite & opd) {
	vector<Forme *>::iterator it;
	vector<Forme *> d = opd.getList();
	s << "Composite : \n";
	for (it = d.begin(); it != d.end(); it++) {
		s << **it;
	}
	s << "Couleur du composite : " << opd.getColor();
	return s;
}*/

Composite::operator string() const {
	ostringstream s;
	vector<Forme *>::iterator it;
	vector<Forme *> d = getList();
	s << "Composite,";
	for (it = d.begin(); it != d.end(); it++) {
		s << **it << ",";
	}
	s << getColor();
	string msg = s.str();
	return msg;
}

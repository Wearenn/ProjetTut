using namespace std;

#include "Polygone.h"

/*ostream & operator << (ostream & s, Polygone & opd) {
	vector<Segment>::iterator it;
	vector<Segment> d = opd.getList();
	s << "Polygone : \n";
	for (it = d.begin(); it != d.end(); it++) {
		s << *it;
	}
	s << "Couleur du polygone : " << opd.getColor();
	return s;
}*/

/*Polygone Polygone::operator * (const int & i) {
	vector<Segment>::iterator it;
	for (it = _list.begin(); it != _list.end(); it++) {
		*it = *it * i;
	}
	return Polygone(_list);
}

Polygone operator * (const int & i, Polygone & opd) {
	vector<Segment>::iterator it;
	vector<Segment> d = opd.getList();
	for (it = d.begin(); it != d.end(); it++) {
		*it = *it * i;
	}
	return Polygone(d);
}*/

Polygone::operator string() const {
	ostringstream s;
	vector<Vecteur2D>::iterator it;
	vector<Vecteur2D> d = getList();
	s << "Polygone,";
	for (it = d.begin(); it != d.end(); it++) {
		s << *it << ",";
	}
	s << getColor();
	string msg = s.str();
	return msg;
}

#pragma once
#include <iostream>
#include <vector>
#include "Forme.h"
#include "Segment.h"
#include "Triangle.h"

using namespace std;

class Polygone : public Forme {
private:
	vector<Vecteur2D> _list;

public:

	/*virtual*/void acceptDessin(DessinVisitor &v);
	/*virtual*/void acceptSave(const string file, SaveVisitor &v);

	Polygone() {
		setColor(Forme::GREEN);
		_list = vector<Vecteur2D>();
	}

	Polygone(vector<Vecteur2D> list) {
		_list = list;
	}

	Polygone(const string color, vector<Vecteur2D> list) {
		setColor(color);
		_list = list;
	}

	Polygone(const Polygone &poly) : Forme(poly) {
		_list = poly._list;
	}

	vector<Vecteur2D> getList() const{
		return _list;
	}

	void setList(vector<Vecteur2D> list) {
		_list = list;
	}

	void afficher(ostream & os) const {
		os << "Polygone,";
		for (vector<Vecteur2D>::const_iterator  it = _list.begin(); it != _list.end(); it++) {
			os << (string)*it;
		}
		os << getColor();
	}

	virtual Forme * clone() const {
		return new Polygone(*this);
	}

	void translation(const double & a) {

	}

	void homothétie(Vecteur2D pointinvarient, const double & a) {

	}

	void rotation(Vecteur2D pointinvarient, const double & a) {

	}

	double getAire() {
		double aire = -1;
		if (_list.size() > 2) {
			aire = 0;
			Vecteur2D u1 = _list.at(0);
			Vecteur2D u2 = _list.at(1);
			Vecteur2D milieu = 0.5 * (u1 + u2);
			for (vector<Vecteur2D>::iterator it = _list.begin(); it != (_list.end()-1); it++) {
				Triangle t(Forme::BLACK, *it, *it+1, milieu);
				aire = aire + t.getAire();
			}
		}/* else if (_list.size() == 3) {		//si c'est un triangle
			Triangle t(Forme::BLACK, _list.at(0).getP1(), _list.at(1).getP1(), _list.at(2).getP1());
			aire = t.getAire();
		}*/
		return aire;
	}

	virtual ~Polygone() {}

	/*virtual*/ operator string() const;

	//Polygone operator * (const int &opd);
};

//extern Polygone operator * (const int & i, Polygone & opd);
//extern ostream & operator << (ostream &s, Polygone &opd);

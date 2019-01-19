#pragma once
#include <iostream>
#include <vector>
#include "Forme.h"

using namespace std;

class Composite : public Forme {
private:
	vector<Forme *> _list;

public:

	/*virtual*/void acceptDessin(DessinVisitor &v);
	/*virtual*/void acceptSave(const string file, SaveVisitor &v);

	Composite() {
		setColor(Forme::GREEN);
	}

	Composite(vector<Forme *> list) {
		_list = list;
	}

	Composite(const string color, vector<Forme *> list) {
		setColor(color);
		_list = list;
	}

	Composite(const Composite &comp) : Forme(comp) {
		_list = comp._list;
	}

	virtual Forme * clone() const {
		return new Composite(*this);
	}

	vector<Forme *> getList() const {
		return _list;
	}

	void setList(vector<Forme *> list) {
		_list = list;
	}

	void afficher(ostream & os) const {
		os << "Composite,";
		for (vector<Forme *>::const_iterator  it = _list.begin(); it != _list.end(); it++) {
			os << (string)**it << ",";
		}
		os << getColor();
	}

	void translation(const double & a) {

	}

	void homothétie(Vecteur2D pointinvarient, const double & a) {

	}

	void rotation(Vecteur2D pointinvarient, const double & a) {

	}

	double getAire() {
		double aire = 0;
		for (vector<Forme *>::iterator it = _list.begin(); it != _list.end(); it++) {
			Forme *f = *it;
			aire = aire + f->getAire();
		}
		return aire;
	}

	virtual ~Composite() {}

	/*virtual*/ operator string() const;

	//Composite operator * (const int &opd);
};

//extern Composite operator * (const int & i, Composite & opd);
//extern ostream & operator << (ostream &s, Composite &opd);

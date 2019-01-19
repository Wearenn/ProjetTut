#pragma once
#include "Forme.h"

class Cercle : public Forme {
private:
	Vecteur2D _p1, _p2;

public:

	/*virtual*/void acceptDessin(DessinVisitor &v);
	/*virtual*/void acceptSave(const string file, SaveVisitor &v);

	Cercle() {
		setColor(Forme::GREEN);
		_p1 = 0;
		_p2 = 0;
	}

	Cercle(const Vecteur2D &p1, const Vecteur2D &p2) {
		_p1 = p1;
		_p2 = p2;
	}

	Cercle(const string &color, const Vecteur2D &p1, const Vecteur2D &p2) {
		setColor(color);
		_p1 = p1;
		_p2 = p2;
	}

	Cercle(const Cercle &s) : Forme(s) {
		_p1 = s._p1;
		_p2 = s._p2;
	}

	Vecteur2D getP1() const {
		return _p1;
	}

	Vecteur2D getP2() const {
		return _p2;
	}

	void setP1(const Vecteur2D &p1) {
		_p1 = p1;
	}

	void setP2(const Vecteur2D &p2) {
		_p2 = p2;
	}

	void afficher(ostream & os) const {
		os << "Cercle," << _p1 << "," << _p2 << "," << getColor() << endl;
		//os << "p1  =>  " << _p1 << "p2  =>  " << _p2 << endl;
	}

	virtual Forme * clone() const {
		return new Cercle(*this);
	}

	void translation(const double & a) {

	}

	void homothétie(Vecteur2D pointinvarient, const double & a) {

	}

	void rotation(Vecteur2D pointinvarient, const double & a) {

	}

	double getAire() {
		double r = sqrt((_p1.getX() - _p2.getX())*(_p1.getX() - _p2.getX()) + (_p1.getY() - _p2.getY())*(_p1.getY() - _p2.getY()));
		return 3.14 * (r * r);
	}

	~Cercle() {}

	/*virtual*/ operator string() const;

	Cercle & operator = (const Cercle &opd);

	//Cercle operator + (const Cercle &opd) const;

	//Cercle operator - (const Cercle &opd) const;

	//Cercle operator * (const int &i) const;

	//const bool operator == (Cercle &opd);
};

//extern const Cercle operator * (const int & i, const Cercle &opd);
//extern ostream & operator << (ostream &s, const Cercle &opd);
#pragma once
#include "Forme.h"

class Segment : public Forme {
private:
	Vecteur2D _p1, _p2;

public:

	/*virtual*/void acceptDessin(DessinVisitor &v);
	/*virtual*/void acceptSave(const string file, SaveVisitor &v);

	Segment() {
		setColor(Forme::GREEN);
		_p1 = 0;
		_p2 = 0;
	}

	Segment(const string color, const Vecteur2D &p1, const Vecteur2D &p2) {
		setColor(color);
		_p1 = p1;
		_p2 = p2;
	}

	Segment(const Vecteur2D &p1, const Vecteur2D &p2) {
		_p1 = p1;
		_p2 = p2;
	}

	Segment(const Segment &s) : Forme(s) {
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
		os << "Segment," << _p1 << "," << _p2 << "," << getColor() << endl;
		//os << "p1  =>  " << _p1 << "p2  =>  " << _p2 << endl;
	}

	virtual Forme * clone() const {
		return new Segment(*this);
	}

	void translation(const double & a) {

	}

	void homothétie(Vecteur2D pointinvarient, const double & a) {

	}

	void rotation(Vecteur2D pointinvarient, const double & a) {

	}

	double getAire() {
		return 0;
	}

	~Segment() {}

	/*virtual*/ operator string() const;

    Segment & operator = (const Segment &opd);

	//Segment operator + (const Segment &opd) const;

	//Segment operator - (const Segment &opd) const;

	//Segment operator * (const int &i) const;

	//const bool operator == (Segment &opd);
};

//extern const Segment operator * (const int & i, const Segment &opd);
//extern ostream & operator << (ostream &s, const Segment &opd);
#pragma once
#include "Forme.h"

class Triangle : public Forme {
private:
	Vecteur2D _p1, _p2, _p3;
	
public:

	/*virtual*/void acceptDessin(DessinVisitor &v);
	/*virtual*/void acceptSave(const string file, SaveVisitor &v);

	Triangle() {
		setColor(Forme::GREEN);
		_p1 = 0;
		_p2 = 0;
		_p3 = 0;
	}

	Triangle(const string color, const Vecteur2D &p1, const Vecteur2D &p2, const Vecteur2D &p3) {
		setColor(color);
		_p1 = p1;
		_p2 = p2;
		_p3 = p3;
	}

	Triangle(const Vecteur2D &p1, const Vecteur2D &p2, const Vecteur2D &p3) {
		_p1 = p1;
		_p2 = p2;
		_p3 = p3;
	}

	Triangle(const Triangle &t) : Forme(t) {
		_p1 = t._p1;
		_p2 = t._p2;
		_p3 = t._p3;
	}

	Vecteur2D getP1() const {
		return _p1;
	}

	Vecteur2D getP2() const {
		return _p2;
	}

	Vecteur2D getP3() const {
		return _p3;
	}

	void setP1(const Vecteur2D &p1) {
		_p1 = p1;
	}

	void setP2(const Vecteur2D &p2) {
		_p2 = p2;
	}

	void setP3(const Vecteur2D &p3) {
		_p3 = p3;
	}

	void afficher(ostream & os) const {
		os << "Triangle," << _p1 << "," << _p2 << "," << _p3 << "," << getColor() << endl;
		//os << "p1  =>  " << _p1 << "p2  =>  " << _p2 << "p3  =>  " << _p3 << endl;
	}

	virtual Forme * clone() const {
		return new Triangle(*this);
	}

	void translation(const double & a) {

	}

	void homothétie(Vecteur2D pointinvarient, const double & a) {

	}

	void rotation(Vecteur2D pointinvarient, const double & a) {

	}

	double getAire() {
		//déclaration des variables de la fonction
		double P = 0;
		double Aire = 0;
		double a = 0; //coté AB
		double b = 0; // coté BC
		double c = 0; //coté CA

		// calcule des longueurs des cotés du triangle
		a = sqrt((_p1.getX() - _p2.getX())*(_p1.getX() - _p2.getX()) + (_p1.getY() - _p2.getY())*(_p1.getY() - _p2.getY()));
		b = sqrt((_p2.getX() - _p3.getX())*(_p2.getX() - _p3.getX()) + (_p2.getY() - _p3.getY())*(_p2.getY() - _p3.getY()));
		c = sqrt((_p3.getX() - _p1.getX())*(_p3.getX() - _p1.getX()) + (_p3.getY() - _p1.getY())*(_p3.getY() - _p1.getY()));

		// formule de Néron WIKIPEDIA
		P = a + b + c;
		P = (P / 2);
		Aire = sqrt(P * (P - a) * (P - b) * (P - c));

		return Aire;
	}

	~Triangle() {}

	/*virtual*/ operator string() const;

	Triangle & operator = (const Triangle &opd);

	//Triangle operator + (const Triangle &opd) const;

	//Triangle operator - (const Triangle &opd) const;

	//Triangle operator * (const int &opd) const;

	//const bool operator == (Triangle &opd);
};

//extern const Triangle operator * (const int & i, const Triangle &opd);
//extern ostream & operator << (ostream &s, const Triangle &opd);


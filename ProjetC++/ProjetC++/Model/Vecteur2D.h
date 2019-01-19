#pragma once
#include <iostream>
#include <sstream>
using namespace std;

template <class T> inline const T operator - (const T & u, const T & v) {
	return u + -v;
}

class Vecteur2D {
	private:
		double _x;
		double _y;

	public:
		Vecteur2D(const double &x = 0, const double &y = 0) {
			_x = x;
			_y = y;
		}

		double getX() const {
			return _x;
		}

		void setX(const double x) {
			_x = x;
		}

		double getY() const{
			return _y;
		}

		void setY(const double y) {
			_y = y;
		}

		void afficher(ostream & os) const {
			cout << _x << "," << _y;
		}

		const Vecteur2D operator + (const Vecteur2D &opd) const;

		const Vecteur2D operator - () const;

		const Vecteur2D operator * (const double &i) const;

		operator string() const;
};

extern const Vecteur2D operator * (const double &i, const Vecteur2D &opd);
extern ostream & operator << (ostream &s, const Vecteur2D &opd);
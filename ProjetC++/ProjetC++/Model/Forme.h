#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Vecteur2D.h"
#include "../Connexion/EnvoyeurReceveur.h"

using namespace std;

class Forme {
private:
	string _color;

public:

	static const string BLUE;
	static const string BLACK;
	static const string RED;
	static const string YELLOW;
	static const string CYAN;
	static const string GREEN;

	string getColor() const {
		return _color;
	}

	void setColor(string color) {
		_color = color;
	}

	virtual void acceptDessin(class DessinVisitor &v) = 0;
	virtual void acceptSave(const string file, class SaveVisitor &v) = 0;

	virtual Forme* clone() const = 0;
	virtual operator string() const = 0;
	virtual void afficher(ostream & os) const = 0;
	virtual void translation(const double & a) = 0;
	virtual void homothétie(Vecteur2D pointinvarient, const double & a) = 0;
	virtual void rotation(Vecteur2D pointinvarient,  const double & a) = 0;
	virtual double getAire() = 0;

	void sauvegarder(const string &fichier) {
		filebuf fb;
		fb.open(fichier, std::ios::out);
		ostream os(&fb);
		//os << (string)*this;
		afficher(os);
		fb.close();
	}

	string dessiner() {
		EnvoyeurReceveur * envoyeurReceveur = EnvoyeurReceveur::getInstance();
		string msg = (string)*this;
		envoyeurReceveur->envoyer(msg.c_str());
		msg.assign(envoyeurReceveur->recevoir());
		delete(envoyeurReceveur);
		return msg;
	}
};

extern ostream & operator << (ostream &s, const Forme &opd);
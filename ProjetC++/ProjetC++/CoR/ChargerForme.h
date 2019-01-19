#pragma once
#include <string>

#include "../Model/Forme.h"

using namespace std;

class ChargerForme {
public:
	ChargerForme *next;
	
	ChargerForme() {
		next = 0;
	}

	void setNext(ChargerForme *n) {
		next = n;
	}

	void add(ChargerForme *n) {
		if (next)
			next->add(n);
		else
			next = n;
	}

	virtual Forme * load(const string line) = 0;
};
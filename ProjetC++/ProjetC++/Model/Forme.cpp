#include "Forme.h"

const string Forme::BLACK = "black";
const string Forme::BLUE = "blue";
const string Forme::RED = "red";
const string Forme::GREEN = "green";
const string Forme::YELLOW= "yellow";
const string Forme::CYAN = "cyan";

ostream & operator << (ostream & s, const Forme & opd) {
	return s << (string)opd;
}

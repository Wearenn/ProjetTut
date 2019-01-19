#include "SaveVisitor.h"

void Triangle::acceptSave(const string file, SaveVisitor &v) {
	v.visitSave(file,this);
}

void Segment::acceptSave(const string file, SaveVisitor &v) {
	v.visitSave(file, this);
}

void Cercle::acceptSave(const string file, SaveVisitor &v) {
	v.visitSave(file, this);
}

void Composite::acceptSave(const string file, SaveVisitor &v) {
	v.visitSave(file, this);
}

void Polygone::acceptSave(const string file, SaveVisitor &v) {
	v.visitSave(file, this);
}

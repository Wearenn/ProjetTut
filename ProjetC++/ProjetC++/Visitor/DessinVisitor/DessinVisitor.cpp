#include "DessinVisitor.h"

void Triangle::acceptDessin(DessinVisitor &v) {
	v.visitDessin(this);
}

void Segment::acceptDessin(DessinVisitor &v) {
	v.visitDessin(this);
}

void Cercle::acceptDessin(DessinVisitor &v) {
	v.visitDessin(this);
}

void Polygone::acceptDessin(DessinVisitor &v) {
	v.visitDessin(this);
}

void Composite::acceptDessin(DessinVisitor &v) {
	v.visitDessin(this);
}
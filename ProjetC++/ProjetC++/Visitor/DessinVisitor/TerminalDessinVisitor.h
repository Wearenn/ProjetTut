#pragma once
#include "DessinVisitor.h"

class TerminalDessinVisitor : public DessinVisitor {
public:
	void visitDessin(Cercle *e) {
		e->dessiner();
	}

	void visitDessin(Triangle *e) {
		e->dessiner();
	}

	void visitDessin(Segment *e) {
		e->dessiner();
	}

	void visitDessin(Composite *e) {
		e->dessiner();
	}

	void visitDessin(Polygone *e) {
		e->dessiner();
	}
};


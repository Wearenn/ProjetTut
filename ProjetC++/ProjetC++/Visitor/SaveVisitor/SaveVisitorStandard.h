#pragma once
#include "SaveVisitor.h"

class SaveVisitorStandard : public SaveVisitor {
public:
	void visitSave(const string file, Triangle *e) {
		e->sauvegarder(file);
	}

	void visitSave(const string file, Segment *e) {
		e->sauvegarder(file);
	}

	void visitSave(const string file, Cercle *e) {
		e->sauvegarder(file);
	}

	void visitSave(const string file, Polygone *e) {
		e->sauvegarder(file);
	}

	void visitSave(const string file, Composite *e) {
		e->sauvegarder(file);
	}
};
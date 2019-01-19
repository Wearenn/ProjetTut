#pragma once
#include "../../Model/Triangle.h"
#include "../../Model/Segment.h"
#include "../../Model/Cercle.h"
#include "../../Model/Polygone.h"
#include "../../Model/Composite.h"

class SaveVisitor {
public:
	virtual void visitSave(const string file, Triangle *e) = 0;
	virtual void visitSave(const string file, Segment *e) = 0;
	virtual void visitSave(const string file, Cercle *e) = 0;
	virtual void visitSave(const string file, Polygone *e) = 0;
	virtual void visitSave(const string file, Composite *e) = 0;
};


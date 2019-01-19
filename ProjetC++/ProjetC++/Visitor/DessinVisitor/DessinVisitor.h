#pragma once
#include "../../Model/Cercle.h"
#include "../../Model/Segment.h"
#include "../../Model/Triangle.h"
#include "../../Model/Composite.h"
#include "../../Model/Polygone.h"

class DessinVisitor {
public:
	virtual void visitDessin(Cercle *e) = 0;
	virtual void visitDessin(Segment *e) = 0;
	virtual void visitDessin(Triangle *e) = 0;
	virtual void visitDessin(Composite *e) = 0;
	virtual void visitDessin(Polygone *e) = 0;
};

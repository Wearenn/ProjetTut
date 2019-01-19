#include <iostream>
#include "Model/Vecteur2D.h"
#include "Model/Cercle.h"
#include "Model/Segment.h"
#include "Model/Triangle.h"
#include "Model/Polygone.h"
#include "Model/Composite.h"
#include "Visitor/DessinVisitor/TerminalDessinVisitor.h"
#include "Visitor/SaveVisitor/SaveVisitorStandard.h"
#include "CoR/ChargerForme.h"
#include "CoR/CoRFormes/ChargerFormeCercle.h"
#include "CoR/CoRFormes/ChargerFormeSegment.h"
#include "CoR/CoRFormes/ChargerFormeTriangle.h"
#include "CoR/CoRFormes/ChargerFormePolygone.h"
#include "CoR/CoRFormes/ChargerFormeComposite.h"

using namespace std;

int main() {
	Forme * formeLoad = nullptr;
	TerminalDessinVisitor tdv;	
	SaveVisitorStandard slvs;
	const string file = "sauvegarder.txt";
	ChargerForme *chargerSegment = new ChargerFormeSegment();
	ChargerForme *chargerCercle = new ChargerFormeCercle();
	ChargerForme *chargerTriangle = new ChargerFormeTriangle();
	ChargerForme *chargerPolygone = new ChargerFormePolygone();
	ChargerForme *chargerComposite = new ChargerFormeComposite();
	chargerSegment->setNext(chargerCercle);
	chargerCercle->setNext(chargerTriangle);
	chargerTriangle->setNext(chargerPolygone);
	chargerPolygone->setNext(chargerComposite);
	//chargerComposite->setNext(chargerSegment);

	filebuf fb;
	if (fb.open(file, ios::in)) {
		istream is(&fb);
		string line;
		while (getline(is, line)) {
			formeLoad = chargerSegment->load(line);
		}
		fb.close();
	}

	if (formeLoad != nullptr) {
		cout << "Forme Load : " << *formeLoad << endl;
	} else {
		cout << "Forme Load NULL" << endl;
	}	
	
	Forme *t1, *t2, *s1, *s2, *s3, *s4, *c1, *c2, *poly, *comp;

	cout << "ESSAI DES VECTEURS 2D \n" << endl;
	Vecteur2D u1(0, 0), u2(0, 2), v1(2, 2), u3(2, 0), u4(3, -4), v(5);
	cout << "Vecteur u1  ==>  " << u1 << endl;
	cout << "Vecteur u2  ==>  " << u2 << endl;
	cout << "Vecteur u1 + Vecteur u2  ==>  " << u1 + u2 << endl;
	cout << "Vecteur u1 - Vecteur u2  ==>  " << u1 - u2 << endl;
	cout << "5 * Vecteur u1  =>  " << 5 * u1 << endl;

	cout << "--------------------------------------\n" << endl;

	cout << "ESSAI DES TRIANGLES \n" << endl;
	t1 = new Triangle(Forme::BLUE,u1, u2, u3);
	t2 = new Triangle(Forme::CYAN,u2, u4, v1);
	cout << "Triangle t1  ==>  " << *t1 << endl;
	cout << "Triangle t2  ==>  " << *t2 << endl;
	cout << "Aire de t1 = " << t1->getAire() << endl;
	cout << "Aire de t2 = " << t2->getAire() << endl;
	//t1->acceptSave(file,slvs);
	//t1->acceptDessin(tdv);
	//cout << "Triangle t1 + Triangle t2  ==>  \n" << t1 + t2 << endl;
	//cout << "Triangle t1 - Triangle t2  ==>  \n" << t1 - t2 << endl;
	//cout << "5 * Triangle t1  ==>  \n" << 5 * t1 << endl;

	cout << "--------------------------------------\n" << endl;

	cout << "ESSAI DES SEGMENTS \n" << endl;
	s1 = new Segment(Forme::BLUE, u1, u3);
	s2 = new Segment(Forme::BLACK, u3, v1);
	s3 = new Segment(Forme::CYAN, v1, u2);
	s4 = new Segment(Forme::YELLOW, u2, u1);
	cout << "Segments s1  ==>  " << *s1 << endl;
	cout << "Segments s2  ==>  " << *s2 << endl;
	cout << "Aire de s1 = " << s1->getAire() << endl;
	//s1.sauvegarder();
	//cout << "Segments s1 + Segments s2  ==>  \n" << s1 + s2 << endl;
	//cout << "Segments s1 - Segments s2  ==>  \n" << s1 - s2 << endl;
	//cout << "5 * Segments s1  ==>  \n" << 5 * s1 << endl;

	cout << "--------------------------------------\n" << endl;

	cout << "ESSAI DES CERCLES \n" << endl;
	c1 = new Cercle(Forme::GREEN, u1, u3);
	c2 = new Cercle(Forme::YELLOW, u2, v1);
	cout << "Cercle c1  ==>  " << *c1 << endl;
	cout << "Cercle c2  ==>  " << *c2 << endl;
	cout << "Aire de c1 = " << c1->getAire() << endl;
	//c1.sauvegarder();
	//cout << "Cercle c1 + Cercle c2  ==>  \n" << c1 + c2 << endl;
	//cout << "Cercle c1 - Cercle c2  ==>  \n" << c1 - c2 << endl;
	//cout << "5 * Cercle c1  ==>  \n" << 5 * c1 << endl;

	cout << "--------------------------------------\n" << endl;

	cout << "ESSAI DES POLYGONES \n" << endl;
	vector<Vecteur2D> listeSeg;
	listeSeg.push_back(u1);
	listeSeg.push_back(u2);
	listeSeg.push_back(u3);
	listeSeg.push_back(u4);
	poly = new Polygone(Forme::BLACK,listeSeg);
	cout << "liste Segments  ==>  \n" << *poly << endl;
	cout << "Aire de poly = " << poly->getAire() << endl;
	//poly->sauvegarder(file);
	//cout << "liste Segments  ==>  \n" << poly * 2 << endl;

	cout << "--------------------------------------\n" << endl;

	cout << "ESSAI DES COMPOSITES \n" << endl;
	vector<Forme *> listForme;
	listForme.push_back(t1->clone());
	listForme.push_back(t2->clone());
	comp = new Composite(Forme::BLACK,listForme);
	comp->sauvegarder(file);
	cout << "liste Formes  ==>  \n" << *comp << endl;
	cout << "Aire de comp = " << comp->getAire() << endl;

	system("PAUSE");
}
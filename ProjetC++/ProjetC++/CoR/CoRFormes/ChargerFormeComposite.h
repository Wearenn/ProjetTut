#pragma once
#include "../../Model/Composite.h";

class ChargerFormeComposite : public ChargerForme {
public:
	/*virtual*/Forme * load(const string line) {
		size_t foundComp = line.find("Composite");
		Forme * forme = nullptr;
		if (foundComp != string::npos) {	//on test si c'est un cercle
			//si oui on charge le cercle
			try {
				char delimiter = ',';
				vector<string> tokens;
				string token;
				istringstream tokenStream(line);
				while (getline(tokenStream, token, delimiter)) {
					tokens.push_back(token);
				}
				vector<Forme *> list;
				for (int i = 0; i < tokens.size(); i++) {
					if (tokens.at(i).compare("Cercle") == 0) {
						Vecteur2D v1(stod(tokens.at(i + 1)), stod(tokens.at(i + 2)));
						Vecteur2D v2(stod(tokens.at(i + 3)), stod(tokens.at(i + 4)));
						list.push_back(new Cercle(v1,v2));
					} else if (tokens.at(i).compare("Segment") == 0) {
						Vecteur2D v1(stod(tokens.at(i + 1)), stod(tokens.at(i + 2)));
						Vecteur2D v2(stod(tokens.at(i + 3)), stod(tokens.at(i + 4)));
						list.push_back(new Segment(v1, v2));
					} else if (tokens.at(i).compare("Triangle") == 0) {
						Vecteur2D v1(stod(tokens.at(i + 1)), stod(tokens.at(i + 2)));
						Vecteur2D v2(stod(tokens.at(i + 3)), stod(tokens.at(i + 4)));
						Vecteur2D v3(stod(tokens.at(i + 5)), stod(tokens.at(i + 6)));
						list.push_back(new Triangle(v1, v2, v3));
					} else if (tokens.at(i).compare("Polygone") == 0) {
						vector<Vecteur2D> liste;
						for (int i = 0; i < tokens.size(); i++) {
							if (tokens.at(i).compare("Vecteur2D") == 0) {
								liste.push_back(Vecteur2D(stoi(tokens.at(i + 1)), stoi(tokens.at(i + 2))));
							}
						}
						list.push_back(new Polygone(liste));
					} else if (tokens.at(i).compare("Composite") == 0) {
						//TODO Composite dans composite
					}
				}
				return new Composite(tokens.back(), list);
			}
			catch (const exception&) {
				cout << "Erreur lors de la lecture du fichier" << endl;
			}
		}
		else if (next) {
			//s'il y a un suivant
			forme = next->load(line);
		}
		else {
			//pas de suivant error
			cout << "Aucune forme correspondante a la ligne : " << line << endl;
		}
		return forme;
	}
};
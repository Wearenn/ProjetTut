#pragma once
#include "../../Model/Polygone.h";

class ChargerFormePolygone : public ChargerForme {
public:
	/*virtual*/Forme * load(const string line) {
		size_t foundComp = line.find("Composite");
		size_t foundPoly = line.find("Polygone");
		Forme * forme = nullptr;
		if (foundComp == string::npos && foundPoly != std::string::npos) {	//on test si c'est un composite
			//si oui on charge le composite
			try {
				char delimiter = ',';
				vector<string> tokens;
				string token;
				istringstream tokenStream(line);
				while (getline(tokenStream, token, delimiter)) {
					tokens.push_back(token);
				}
				vector<Vecteur2D> list;
				for (int i = 0; i < tokens.size(); i++) {
					if (tokens.at(i).compare("Vecteur2D") == 0) {
						list.push_back(Vecteur2D(stoi(tokens.at(i+1)), stoi(tokens.at(i+2))));
					}
				}				
				return new Polygone(tokens.back(),list);
			} catch (const exception&) {
				cout << "Erreur lors de la lecture du fichier" << endl;
			}
		}
		else if (next) {
			//s'il y a un suivant
			forme = next->load(line);
		}
		else {
			//pas de suivant error
			cout << "Aucune forme correspondante à la ligne : " << line << endl;
		}
		return forme;
	}
};
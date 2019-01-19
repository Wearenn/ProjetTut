#pragma once
#include "../../Model/Triangle.h";

class ChargerFormeTriangle : public ChargerForme {
public:
	/*virtual*/Forme * load(const string line) {
		size_t foundComp = line.find("Composite");
		size_t foundTri = line.find("Triangle");
		Forme * forme = nullptr;
		if (foundComp == string::npos && foundTri != std::string::npos) {	//on test si c'est un triangle
			//si oui on charge le triangle
			try {
				char delimiter = ',';
				vector<string> tokens;
				string token;
				istringstream tokenStream(line);
				while (getline(tokenStream, token, delimiter)) {
					tokens.push_back(token);
				}
				Vecteur2D p1(stoi(tokens.at(1)), stoi(tokens.at(2)));
				Vecteur2D p2(stoi(tokens.at(3)), stoi(tokens.at(4)));
				Vecteur2D p3(stoi(tokens.at(5)), stoi(tokens.at(6)));
				return new Triangle(tokens.at(7), p1, p2, p3);
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
			cout << "Aucune forme correspondante à la ligne : " << line << endl;
		}
		return forme;
	}
};
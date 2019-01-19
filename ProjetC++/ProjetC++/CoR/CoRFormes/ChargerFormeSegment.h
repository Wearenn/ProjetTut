#pragma once
#include "../../Model/Segment.h"

using namespace std;

class ChargerFormeSegment : public ChargerForme {
public:
	/*virtual*/Forme * load(const string line) {
		size_t foundComp = line.find("Composite");
		size_t foundSeg = line.find("Segment");
		Forme * forme = nullptr;
		if (foundComp == string::npos && foundSeg != std::string::npos) {	//on test si c'est un segment
			//si oui on charge le segment
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
				return new Segment(tokens.at(5), p1, p2);
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
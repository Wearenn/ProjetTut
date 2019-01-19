#pragma once
#include <iostream>
#include <string>
#include <winsock2.h>
#include <sstream>
#include "../Controller/Erreur.h" 

using namespace std;

#define ADRESSE_IP "192.168.0.18"
#define PORT_SERVEUR 9111

const static int L = 500;

/**
*class EnvoyeurReceveur
*
* La classe permet la connexion à un socket distant à partir
* de ses champs
*/
class EnvoyeurReceveur {
private:

	static EnvoyeurReceveur * Singleton;
	SOCKET sock;

	EnvoyeurReceveur(const char* adresseIP, short portServeur);

public:
	~EnvoyeurReceveur();

	void init() const;

	void close() const;

	void envoyer(const char* message) const;

	string recevoir() const;

	static EnvoyeurReceveur * getInstance();

};

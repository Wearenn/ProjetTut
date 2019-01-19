#include "EnvoyeurReceveur.h"
#include <Ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib") // sp�cifique � VISUAL C++


using namespace std;

/*static*/
EnvoyeurReceveur * EnvoyeurReceveur::Singleton = NULL;

/**
* \brief    Permet de r�cup�rer l'instance du singleton \e EnvoyeurReceveur ou de le cr�er si il n'existe pas encore
* \return   Un pointeur sur l'instance de \e EnvoyeurReceveur
*/
EnvoyeurReceveur * EnvoyeurReceveur::getInstance()
{
	if (Singleton == NULL)
	{
		Singleton = new EnvoyeurReceveur(ADRESSE_IP, PORT_SERVEUR);
	}

	return Singleton;
}

static int active = 0; // Si les DLL sont ouvertes ou non


/**
* \brief    \b Constructeur de \e ReceveurEnvoyeur
* \details	Ouvre les DLL si elles ne sont pas ouvertes, ouvre un socket si possible
*			et se connecte au serveur si possible
*/
EnvoyeurReceveur::EnvoyeurReceveur(const char* adresseIP, const short portServeur) {

	try {

		if (!active)	this->init(); // Pour ouvrir les dll qu'une fois

									  //---------------------- cr�ation socket -------------------------------------------------

		int familleAdresses = AF_INET;			// IPv4
		int typeSocket = SOCK_STREAM;           // mode connect� TCP
		int protocole = IPPROTO_TCP;            // protocole. On peut aussi mettre 0 et la fct choisit le protocole en fct des 2 1ers param�tres
												// pour les valeurs des param�tres : cf. fct socket dans la doc sur winsock

		sock = socket(familleAdresses, typeSocket, protocole);

		if (sock == INVALID_SOCKET)
		{
			ostringstream oss;
			oss << "la creation du socket a echoue : code d'erreur = " << WSAGetLastError() << endl;	// pour les valeurs renvoy�es par WSAGetLastError() : cf. doc r�f winsock
			throw Erreur(oss.str().c_str());
		}

		SOCKADDR_IN sockaddr; // informations concernant le serveur avec lequel on va communiquer

		sockaddr.sin_family = AF_INET;
		sockaddr.sin_addr.s_addr = InetPton(AF_INET, adresseIP, &sockaddr);   // inet_addr() convertit de l'ASCII en entier
		sockaddr.sin_port = htons(portServeur);                 //htons() assure que le port est bien inscrit dans le format du r�seau (little-endian ou big-endian)

																//-------------- connexion du client au serveur ---------------------------------------

		int r = connect(sock, (SOCKADDR *)&sockaddr, sizeof(sockaddr));     // renvoie une valeur non nulle en cas d'�chec.
																			// Le code d'erreur peut �tre obtenu par un appel � WSAGetLastError()

		if (r == SOCKET_ERROR)
			throw Erreur("La connexion a echoue");
	}
	catch (Erreur erreur) {
		cerr << erreur << endl;
	}
}

/**
* \brief    \b Destructeur de \e ReceveurEnvoyeur
*/
EnvoyeurReceveur::~EnvoyeurReceveur() {}

/**
* \brief    Initialisation des ressources de la librairie winsock
*/
void EnvoyeurReceveur::init() const {

	try {
		//-------------- initialisation ressources librairie winsock -------------------------------

		WSADATA wsaData; //structure contenant les donn�es de la librairie winsock � initialiser

		int r;

		r = WSAStartup(MAKEWORD(2, 0), &wsaData);       // MAKEWORD(2,0) sert � indiquer la version de la librairie � utiliser : 1 pour winsock et 2 pour winsock2

														/* en cas de succ�s, wsaData a �t� initialis�e et l'appel a renvoy� la valeur 0 */

		if (r) throw Erreur("L'initialisation a echoue");

		active = 1;

	}
	catch (Erreur erreur) {
		cerr << erreur << endl;
	}
}

/**
* \brief    Coupe la connexion et ferme le socket. Ne fait rien si le \e ReceveurEnvoyeur est d�j� ferm�
*/
void EnvoyeurReceveur::close() const {

	try {

		int r = shutdown(sock, SD_BOTH);							// on coupe la connexion pour l'envoi et la r�ception
																	// renvoie une valeur non nulle en cas d'�chec. Le code d'erreur peut �tre obtenu par un appel � WSAGetLastError()
		if (r == SOCKET_ERROR)
			throw Erreur("la coupure de connexion a echoue");


		r = closesocket(sock);                          // renvoie une valeur non nulle en cas d'�chec. Le code d'erreur peut �tre obtenu par un appel � WSAGetLastError()
		if (r) throw Erreur("La fermeture du socket a echoue");

		WSACleanup();

		active = 0;
	}
	catch (Erreur erreur) {
		cerr << erreur << endl;
	}
}

/**
* \brief    Envoie \e message au serveur sur lequel le \e ReceveurEnvoyeur est connect�
* \param	Le message � envoyer
*/
void EnvoyeurReceveur::envoyer(const char* message) const {

	try {

		int l = strlen(message);
		int r = send(sock, message, l, 0);             //------------------ envoi de la requ�te au serveur -------------------------------
													   // envoie au plus  l octets
		if (r == SOCKET_ERROR)
			throw Erreur("echec de l'envoi de la requete");
	}
	catch (Erreur erreur) {
		cerr << erreur << endl;
	}
}

/**
* \brief    Permet de recevoir un message du serveur. Cette fonction est bloquante si le serveur n'envoie rien
* \return	Le message que le serveur � envoyer
*/
string EnvoyeurReceveur::recevoir() const {

	char reponse[L];

	try {

		int r = recv(sock, reponse, L, 0);             //----------- r�ception de la r�ponse du serveur -----------------------------
													   // re�oit au plus L octets
													   // en cas de succ�s, r contient le nombre d'octets re�us
		if (r == SOCKET_ERROR)
			throw Erreur("La reception de la reponse a echoue");

		char * p = strchr(reponse, '\n');
		*(p + 1) = '\0';

	}
	catch (Erreur erreur) {
		cerr << erreur << endl;
	}
	string msg(reponse);
	return msg;
}
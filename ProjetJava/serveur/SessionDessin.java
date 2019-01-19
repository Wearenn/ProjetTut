package serveur;

/**
 * repr�sente la session de dessin entreprise par un client distant.
 * 
 * Effectue principalement les op�rations suivantes :
 * 
 * ouvre une fen�tre awt (Frame) pour dessiner dessus (les coordonn�es de la fen�tre sont indiqu�es par le client).
 * puis ex�cute sur la fen�tre ouverte tous les ordres de trac� du client distant.
 * 
 * fonctionne dans un thread s�par� du thread principal.
 * 
 * */
import java.net.Socket;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.SocketException;
import serveur.*;
import dessiner.*;


public class SessionDessin extends Thread
{
Socket socket;                  // pour dialoguer avec le client distant. Peut-on se passer de cet attribut ?
BufferedReader fluxEntrant;     // flux entrant pour recevoir les requ�tes du client

/**
 * cr�e la session de dessin avec le client distant connect� sur socket
 * @throws IOException 
 * 
 * */
public SessionDessin(Socket socket) throws IOException
{
this.socket = socket;
this.fluxEntrant = new BufferedReader(new InputStreamReader(this.socket.getInputStream()));
}

@Override
public void run()
{
String requ�te;

try
    {
	requ�te = this.fluxEntrant.readLine();  // lit le titre et les 4 coordonn�es Ox, Oy, largeur et hauteur de la fen�tre, les arguments sont s�par�s par des ","
	System.out.println("requ�te re�ue : " + requ�te);
	String arguments[] = requ�te.split(",");            // redondance de code � �liminer
	
	String titre;
	int Ox, Oy, largeur, hauteur;
	
	titre = arguments[0].trim();
	Ox = Integer.parseInt(arguments[1].trim());         // redondance de code � �liminer pour 8 lignes !!!! cf. lignes suivantes
	Oy = Integer.parseInt(arguments[2].trim());
	largeur = Integer.parseInt(arguments[3].trim());
	hauteur = Integer.parseInt(arguments[4].trim());
    
    CadreDessin cadreDessin = new CadreDessin(titre,Ox,Oy,largeur,hauteur);
    
    // preparation du COR pour dessiner
    Dessiner dessin1 = new DessinerSegment();
    Dessiner dessin2 = new DessinerRond();
    Dessiner dessin3 = new DessinerPolygone();
    dessin1.setDessiner(dessin2);
    dessin2.setDessiner(dessin3);
    
    while (true)
        {
    	
        requ�te = this.fluxEntrant.readLine();  // lit l'instruction de trac� et les 4 param�tres entiers du trac�, les arguments sont s�par�s par des ","
        
        if(requ�te != null) {
        	System.out.println("requ�te re�ue : " + requ�te);
        	dessin1.dessinerForme(cadreDessin, requ�te);
        }
        
        } // while
    }

catch (SocketException e)
    {
    System.out.println("session de dessin termin�e par le client");
    }
catch (NumberFormatException e)
    {
    e.printStackTrace();
    }
catch (IOException e)
    {
    e.printStackTrace();
    }
catch (InterruptedException e)
    {
    e.printStackTrace();
    }
}


}


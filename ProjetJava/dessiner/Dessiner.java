package dessiner;

import java.util.ArrayList;
import java.awt.Color;
import serveur.CadreDessin;

public abstract class Dessiner {
	
	private Dessiner suivant;
	
	// pour mettre en place le COR
	public void setDessiner(Dessiner dSuivant){
		suivant = dSuivant;
	}
	
	public boolean dessinerForme(CadreDessin cadreDessin, String arguments){
		StringBuffer type = new StringBuffer();
		StringBuffer coltype = new StringBuffer();
		ArrayList<Integer> arL = extraireArg(arguments, type, coltype);
		String coul = coltype.toString();
		
		// le mieux aurait ete d'utiliser un COR mais ce n'est pas précisé dans l'ennonce que le choix des couleurs est suceptible d'evoluer
		Color couleur = Color.BLACK;
		if(coul.equalsIgnoreCase("RED")){
			couleur = Color.RED;
	    } else if (coul.equalsIgnoreCase("BLUE")) {
	    	couleur = Color.BLUE;
	    } else if (coul.equalsIgnoreCase("GREEN")) {
	    	couleur = Color.GREEN;
	    } else if (coul.equalsIgnoreCase("YELLOW")) {
	    	couleur = Color.YELLOW;
	    } else if (coul.equalsIgnoreCase("CYAN")) {
	    	couleur = Color.CYAN;
	    }
		
		String str = type.toString();
		if(dessinFormeSpec(cadreDessin, str, arL, couleur)){
			return true;
		}
		if(suivant != null){
			return suivant.dessinFormeSpec(cadreDessin, str, arL, couleur);
		}
		return false;
	}
	
	// pour les classes filles
	public abstract boolean dessinFormeSpec(CadreDessin cadreDessin, String type, ArrayList<Integer> arguments, Color couleur);
	
	public ArrayList<Integer> extraireArg(String arguments, StringBuffer type, StringBuffer couleur){
		ArrayList<Integer> result = new ArrayList<Integer>();
		String[] temp = arguments.split(",");
	    type.append(temp[0].trim());
	    couleur.append((temp[1].trim()).toUpperCase());	    
		for(int i = 2 ; i < temp.length ; i++){
		    result.add(Integer.parseInt(temp[i].trim()));
		}
		return result;
	}
}
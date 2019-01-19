package dessiner;

import java.util.ArrayList;
import java.awt.Color;

import serveur.CadreDessin;

public class DessinerPolygone extends Dessiner {
	public boolean dessinFormeSpec(CadreDessin cadreDessin, String type, ArrayList<Integer> arguments, Color couleur){
		if(type.equalsIgnoreCase("drawPolygon")){
			cadreDessin.graphics.setColor(couleur);
			int xpoints[] = new int[arguments.size()/2];
		    int ypoints[] = new int[arguments.size()/2];
		    for (int i=0; i < arguments.size()/2; i++)
		    {
		        xpoints[i] = arguments.get(i);
		    }
		    for (int i=arguments.size()/2; i < arguments.size(); i++)
		    {
		        ypoints[i-arguments.size()/2] = arguments.get(i);
		    }
			cadreDessin.graphics.drawPolygon(xpoints, ypoints, arguments.size()/2);
			return true;
		}
		return false;
	}
}
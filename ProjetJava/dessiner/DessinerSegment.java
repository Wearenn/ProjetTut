package dessiner;


import java.awt.Color;
import java.util.ArrayList;

import serveur.CadreDessin;

public class DessinerSegment extends Dessiner {
	public boolean dessinFormeSpec(CadreDessin cadreDessin, String type, ArrayList<Integer> arguments, Color couleur){
		if(type.equalsIgnoreCase("drawLine")){
			cadreDessin.graphics.setColor(couleur);
			cadreDessin.graphics.drawLine(arguments.get(0),arguments.get(1),arguments.get(2),arguments.get(3));
			cadreDessin.getBufferStrategy().show();
			return true;
		}
		return false;
	}
}
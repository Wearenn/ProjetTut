package dessiner;

import java.util.ArrayList;
import java.awt.Color;

import serveur.CadreDessin;

public class DessinerRond extends Dessiner {
	public boolean dessinFormeSpec(CadreDessin cadreDessin, String type, ArrayList<Integer> arguments, Color couleur){
		if(type.equalsIgnoreCase("fillOval")){
			cadreDessin.graphics.setColor(couleur);
			cadreDessin.graphics.fillOval(arguments.get(0),arguments.get(1),arguments.get(2),arguments.get(3));
			cadreDessin.getBufferStrategy().show();
			return true;
		}
		return false;
	}
}

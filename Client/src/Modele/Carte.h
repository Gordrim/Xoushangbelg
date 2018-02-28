#pragma once
#include "Case.h"
#include "Vecteur2.h"
#include <vector>

namespace Modele {

	class Carte {

	public :

		Carte();

		void genererEau(int tailleMax);

		void genererPlage(int circonferenceMax);

		void genererRocheux(int tailleMax, int epaisseur);

		void genererObstacles();

		Case getCase(int x, int y);
		
		void setUnite(Unite* unite, int x, int y);
		bool d�placerUnite(int x, int y, int a, int b); //renvoie true si le d�placement est r�ussi, deux ccordonn�es d�part ( x, y ) et deux coordonn�es arriv�e ( a, b ) 

	private :

		Case carte[32][32];
		std::vector<Vecteur2<int>> listeUnite;

		std::vector<Vecteur2<int>> tabAquatique;
		std::vector<Vecteur2<int>> tabRocheux;

	};

}
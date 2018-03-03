#pragma once

#include "../Combat/Curseur.h"
#include <iostream>
#include "../Combat/Unite.h"
#include "../Combat/InterFaceUnite.h"
#include "GameState.h"
#include "../../modele/Outils/Vecteur2.h"
#include "../Combat/CarteGUI.h"
#include "../Outils/MenuChoix.h"
#include "../../Modele/Tank.h"
#include "../../Modele/Archer.h"

namespace Vue {

	class Combat : public GameState
	{
	public:

		Combat(Controleur::Fenetre* window);
		virtual ~Combat();

		int run() override;
		
		void ajouterUnite(std::string nom, std::string cheminTexture, Modele::Vecteur2<int> position);
		void deplacerUnite(std::string nom, Modele::Vecteur2<int> position);
		

	protected:

		std::map<std::string, sf::Texture*> textures_;

		const int LONGUEUR_GRILLE = 10;
		const int LARGEUR_GRILLE = 10;

		std::vector<std::vector<sf::Sprite>> grille_;

		std::vector<Unite> unites_;
		Curseur curseur_;
		InterfaceUnite interfaceUnite;
		sf::Texture textureSol_;

		CarteGUI carte;
		MenuChoix* menuAction_;

	};
}

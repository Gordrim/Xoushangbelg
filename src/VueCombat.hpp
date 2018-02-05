#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

inline int vueCombatRun()
{

	const int LONGUEUR_GRILLE = 10;
	const int LARGEUR_GRILLE = 10;

	// cr�ation de la fen�tre
	sf::RenderWindow window(sf::VideoMode(800, 600), "Xoushangbeleg : Vue Combat");
	window.setFramerateLimit(1);

	sf::Texture textureSol;
	textureSol.loadFromFile("ressources/sprite/ground_tiles.png");
	textureSol.setSmooth(true);
	
	std::vector<std::vector<sf::Sprite>> grille(LONGUEUR_GRILLE, std::vector<sf::Sprite>(LARGEUR_GRILLE, sf::Sprite()));
	for(int i(0); i < LONGUEUR_GRILLE; i++)
	{
		for(int j(0); j < LARGEUR_GRILLE; j++)
		{
			sf::Sprite* sprite = &grille[i][j];
			sprite->setTexture(textureSol);
			sprite->setTextureRect(sf::IntRect(32, 64, 32, 32));
			sprite->setPosition(i*32, j*32);
		}
	}

	// on fait tourner le programme tant que la fen�tre n'a pas �t� ferm�e
	while (window.isOpen())
	{
		// on traite tous les �v�nements de la fen�tre qui ont �t� g�n�r�s depuis la derni�re it�ration de la boucle
		sf::Event event;
		while (window.pollEvent(event))
		{
			// fermeture de la fen�tre lorsque l'utilisateur le souhaite
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// effacement de la fen�tre en noir
		window.clear(sf::Color::Black);

		for (auto colone : grille)
		{
			for (sf::Sprite sprite : colone)
			{
				window.draw(sprite);
			}
		}

		// fin de la frame courante, affichage de tout ce qu'on a dessin�
		window.display();
	}

	return 0;
}

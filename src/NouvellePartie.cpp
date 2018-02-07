#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>

inline int NouvellePartieRun() {

	int choix(1);
	sf::RenderWindow fenetre(sf::VideoMode(1000, 700), "Nouvelle partie");
	//fenetre.setVerticalSyncEnabled(true);
	fenetre.setFramerateLimit(12);
	sf::Sprite sprite;
	std::string str;
	sf::Text titreCrea;

	int frame(-1);

	sf::Texture titre;
	if (!titre.loadFromFile("ressources/sprite/titre.png"))
	{
		std::cout << "error img titre" << std::endl;
	}
	titre.setSmooth(false);
	sprite.setTexture(titre);

	sf::IntRect animation[11];
	animation[0] = sf::IntRect(0, 0, 256, 512);
	animation[1] = sf::IntRect(256, 0, 256, 512);
	animation[2] = sf::IntRect(512, 0, 256, 512);
	animation[3] = sf::IntRect(1024, 0, 256, 512);
	animation[4] = sf::IntRect(2048, 0, 256, 512);
	animation[5] = sf::IntRect(2048 * 2, 0, 256, 512);
	animation[6] = sf::IntRect(2048 * 4, 0, 256, 512);
	animation[7] = sf::IntRect(2048 * 8, 0, 256, 512);
	animation[8] = sf::IntRect(2048 * 16, 0, 256, 512);
	animation[9] = sf::IntRect(2048 * 32, 0, 256, 512);
	animation[10] = sf::IntRect(2048 * 64, 0, 256, 512);

	sprite.setPosition(270, -50);

	sf::Font font; // GESTION DE L'ECRITURE
	if (!font.loadFromFile("ressources/VCR_OSD_MONO_1.001.ttf"))
	{
		std::cout << "error font" << std::endl;
	}

	sf::Text TabMenu[3];
	TabMenu[0].setString("Jouer");
	TabMenu[1].setString("Entrer un nom");
	TabMenu[2].setString("Retour");
	titreCrea.setString("Creation de la partie");
	for (int i = 0; i < 3; i++)
	{
		TabMenu[i].setFont(font);// choix de la police � utiliser
		TabMenu[i].setCharacterSize(24);// choix de la taille des caract�res
		TabMenu[i].setFillColor(sf::Color::White);
		TabMenu[i].setPosition(450, i * 50 + 300);
	}

	boolean toucheLache(true);   //FIN GESTION DE L'ECRITURE

	while (fenetre.isOpen())
	{
		// on inspecte tous les �v�nements de la fen�tre qui ont �t� �mis depuis la pr�c�dente it�ration
		sf::Event event;
		while (fenetre.pollEvent(event))
		{
			// �v�nement "fermeture demand�e" : on ferme la fen�tre
			if (event.type == sf::Event::Closed)
				fenetre.close();
		}
		fenetre.clear(sf::Color::Black);

		frame = frame + 1;
		if (frame == 11)
		{
			frame = 0;
			//std::cout << std::endl;
		}
		//std::cout << frame;

		sprite.setTextureRect(sf::IntRect(0, 256 * frame, 512, 256));

		TabMenu[choix].setFillColor(sf::Color::White);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && toucheLache)
		{
			if (choix > 0)
			{
				choix -= 1;
			}
			toucheLache = false;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && toucheLache)
		{
			if (choix < 2)
			{
				choix += 1;
			}
			toucheLache = false;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && toucheLache)
		{
			if (choix == 1)
			{
				
			}
			toucheLache = false;
		}

		if (event.type == sf::Event::KeyReleased)
		{
			toucheLache = true;
		}
		titreCrea.setFont(font);// choix de la police � utiliser
		titreCrea.setCharacterSize(36);// choix de la taille des caract�res
		titreCrea.setFillColor(sf::Color::White);
		titreCrea.setPosition(290, 230);
		fenetre.draw(titreCrea);


		TabMenu[choix].setFillColor(sf::Color::Yellow);
		// c'est ici qu'on dessine tout
		// window.draw(...);
		for (int i(0); i<3; i++)
		{
			fenetre.draw(TabMenu[i]);
		}

		fenetre.draw(sprite);

		sprite.setTextureRect(animation[frame]);
		// fin de la frame courante, affichage de tout ce qu'on a dessin�
		fenetre.display();
	}
	return 0;
}
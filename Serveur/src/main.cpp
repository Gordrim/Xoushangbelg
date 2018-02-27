#include "pugixml.hpp"
#include <iostream>
#include "SFML/Network.hpp"

int main()
	{

	std::cout << "Serveur" << std::endl;

	sf::TcpListener listener;

	// lie l'�couteur � un port
	if (listener.listen(53000) != sf::Socket::Done)
	{
		std::cout << "impossible de se lier au port" << std::endl;
	}

	// accepte une nouvelle connexion
	sf::TcpSocket client1;
	if (listener.accept(client1) != sf::Socket::Done)
	{
		std::cout << "impossible d'obtenir le premier client" << std::endl;
	}

	char deplacement[255];
	std::size_t recus;

	// socket TCP:
	if (client1.receive(deplacement, 255, recus) != sf::Socket::Done)
	{
		std::cout << "impossible de recevoir des donn�es du premier client" << std::endl;
	}
	std::cout << recus << " octes re�u depuis client 1 : " << deplacement << std::endl;

	sf::TcpSocket client2;
	if (listener.accept(client2) != sf::Socket::Done)
	{
		std::cout << "impossible d'obtenir le second client" << std::endl;
	}

	// utilisez la socket "client" pour communiquer avec le client connect�,
	// et continuez � attendre de nouvelles connexions avec l'�couteur
	
	if (client2.send(deplacement, 255) != sf::Socket::Done)
	{
		std::cout << "impossible d'enviyer les donn�es au second client" << std::endl;
	}
}

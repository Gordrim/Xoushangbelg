#include "pugixml.hpp"
#include <iostream>
#include "SFML/Network.hpp"

int main()
	{
	sf::TcpListener listener;

	// lie l'�couteur � un port
	if (listener.listen(53000) != sf::Socket::Done)
	{
		// erreur...
	}

	// accepte une nouvelle connexion
	sf::TcpSocket client;
	if (listener.accept(client) != sf::Socket::Done)
	{
		// erreur...
	}

	// utilisez la socket "client" pour communiquer avec le client connect�,
	// et continuez � attendre de nouvelles connexions avec l'�couteur
	
	char data[100];
	std::size_t received;

	// socket TCP:
	if (client.receive(data, 100, received) != sf::Socket::Done)
	{
		// erreur...
	}
	std::cout << "Received " << received << " "<< data <<" bytes" << std::endl;

	}

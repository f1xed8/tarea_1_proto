all:
		g++ -o receptor receptor.cpp funciones.cpp
		g++ -o emisor emisor.cpp funciones.cpp
		./receptor
		./emisor
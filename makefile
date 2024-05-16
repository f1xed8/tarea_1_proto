all:
		g++ -o receptor receptor.cpp funciones.cpp
		g++ -o emisor emisor.cpp funciones.cpp
ejecutar_emisor:
		g++ -o emisor emisor.cpp funciones.cpp
		./emisor
		rm emisor
ejecutar_receptor:
		g++ -o receptor receptor.cpp funciones.cpp
		./receptor
		rm receptor
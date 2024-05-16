all:
		g++ -o receptor receptor.cpp funciones.cpp
		g++ -o emisor emisor.cpp funciones.cpp
ejecutar_emisor:
		./emisor
		rm emisor
ejecutar_receptor:
		./receptor
		rm receptor
all:
		g++ emisor.cpp -o emisor funciones.cpp -L/usr/local/lib -lwiringPi
		g++ receptor.cpp -o receptor funciones.cpp -L/usr/local/lib -lwiringPi
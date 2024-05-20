all:
		g++ receptor.cpp -o receptor funciones.cpp -lwiringPi
		g++ emisor.cpp -o emisor funciones.cpp -lwiringPi
		g++ clock.cpp -o clock -lwiringPi
emisor:
		g++ -o emisor emisor.cpp funciones.cpp
		./emisor
receptor:
		g++ -o receptor receptor.cpp funciones.cpp
		./receptor
reloj:
		sudo ./clock
todo:
		sudo ./clock &
		sudo ./receptor &
		sudo ./emisor
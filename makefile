all:
		g++ -o receptor receptor.cpp funciones.cpp
		g++ -o emisor emisor.cpp funciones.cpp
		g++ clock.cpp -o clock lwiringPi
solo_emisor:
		g++ -o emisor emisor.cpp funciones.cpp
		./emisor
solo_receptor:
		g++ -o receptor receptor.cpp funciones.cpp
		./receptor
reloj:
		sudo ./clock
todo:
		sudo ./clock &
		sudo ./receptor &
		sudo ./emisor
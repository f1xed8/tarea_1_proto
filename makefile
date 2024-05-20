all:
		g++ receptor.cpp -o receptor funciones.cpp -lwiringPi
		g++ emisor.cpp -o emisor funciones.cpp -lwiringPi
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
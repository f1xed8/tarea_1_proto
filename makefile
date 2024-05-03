CC = g++
CFLAGS = -Wall -Wextra -std=c++11
LIBS = -lwiringPi

# Lista de archivos fuente
SRCS = main.cpp emisor.cpp receptor.cpp funciones.cpp

# Lista de archivos objeto
OBJS = $(SRCS:.cpp=.o)

# Nombre del ejecutable
TARGET = programa

# Regla de compilación
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LIBS)

# Regla de compilación para cada archivo
%.o: %.cpp funciones.h protocolo.h
	$(CC) $(CFLAGS) -c $<

# Limpia los archivos generados
clean:
	rm -f $(OBJS) $(TARGET)
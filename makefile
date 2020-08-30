#https://oregonstate.instructure.com/courses/1738874/files/76040054

CXX = g++

CXXFLAGS = -std=c++11
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
CXXFLAGS += -c


PROJ = output

SRC  = main.cpp
SRC += space.cpp
SRC += ceo.cpp
SRC += conf.cpp
SRC += cube.cpp
SRC += garage.cpp
SRC += hr.cpp
SRC += lunch.cpp
SRC += worker.cpp
SRC += game.cpp


HEADER = space.hpp
HEADER += ceo.hpp
HEADER += conf.hpp
HEADER += cube.hpp
HEADER += garage.hpp
HEADER += hr.hpp
HEADER += lunch.hpp
HEADER += worker.hpp
HEADER += game.hpp


OBJ  = main.o
OBJ += space.o
OBJ += ceo.o
OBJ += conf.o
OBJ += cube.o
OBJ += garage.o
OBJ += hr.o
OBJ += lunch.o
OBJ += worker.o
OBJ += game.o

${PROJ}: ${OBJ} ${HEADER}
	${CXX} ${LDFLAGS} ${OBJ} -o ${PROJ}

${OBJ}: ${SRC}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o ${PROJ}

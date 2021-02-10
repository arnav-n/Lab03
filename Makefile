CXX=clang++
#CXX=g++

#CXXFLAGS= -Wall  -std=c++14
CXXFLAGS= -Wall  -std=c++14

BINARIES=dataProj testStates sortTest

all: ${BINARIES}

tests: ${BINARIES}
	./testStates
	./sortTest

dataProj: hospitalData.o rating.o dataAQ.o stateHosp.o stateDemog.o demogData.o parse.o main.o
	${CXX} $^ -o $@

testStates: hospitalData.o rating.o stateHosp.o testStates.o dataAQ.o stateDemog.o demogData.o parse.o  tddFuncs.o
	${CXX} $^ -o $@

sortTest: hospitalData.o rating.o stateHosp.o testSort1.o dataAQ.o stateDemog.o demogData.o parse.o  tddFuncs.o
	${CXX} $^ -o $@

clean:
	/bin/rm -f ${BINARIES} *.o 


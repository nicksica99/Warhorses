CXX = g++
CXXFLAGS = -Wall

proj4: Heavy.o Medium.o Light.o Warhorse.o Untrained.o Horse.o War.o driver.cpp
	$(CXX) $(CXXFLAGS) Heavy.o Medium.o Light.o Warhorse.o Untrained.o Horse.o War.o driver.cpp -o proj4

War.o: Horse.o Untrained.o Warhorse.o Light.o Medium.o Heavy.o War.cpp War.h 
	$(CXX) $(CXXFLAGS) -c War.cpp

Horse.o: Horse.cpp Horse.h 
	$(CXX) $(CXXFLAGS) -c Horse.cpp

Untrained.o: Horse.o Untrained.cpp Untrained.h
	$(CXX) $(CXXFLAGS) -c Untrained.cpp

Warhorse.o: Horse.o Warhorse.cpp Warhorse.h
	$(CXX) $(CXXFLAGS) -c Warhorse.cpp

Light.o: Warhorse.o Horse.o Light.cpp Light.h
	$(CXX) $(CXXFLAGS) -c Light.cpp

Medium.o: Warhorse.o Horse.o Medium.cpp Medium.h
	$(CXX) $(CXXFLAGS) -c Medium.cpp

Heavy.o: Warhorse.o Horse.o Heavy.cpp Heavy.h
	$(CXX) $(CXXFLAGS) -c Heavy.cpp

clean:
	rm *.o*
	rm*~

run:
	./proj4 proj4_data.txt

val1:
	valgrind ./proj4 proj4_data.txt

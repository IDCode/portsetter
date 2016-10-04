all: portsetter tests

%: %.cpp
	g++ -std=c++11 $< -o $@

%: %.cpp
	g++ -std=c++11 $< -o $@
CXX = g++
CXXFLAGS = -Wall -g

all: testbst test_intbst

testbst: testbst.cpp intbst.cpp intbst.h
	$(CXX) $(CXXFLAGS) -o testbst testbst.cpp intbst.cpp

test_intbst: test_intbst.cpp intbst.cpp intbst.h
	$(CXX) $(CXXFLAGS) -o test_intbst test_intbst.cpp intbst.cpp

clean:
	rm -f testbst test_intbst

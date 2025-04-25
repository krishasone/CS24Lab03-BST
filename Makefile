#Makefile
all: testbst test_intbst

testbst: testbst.o intbst.o
	$(CXX) $(CXX_FLAGS) testbst.o intbst.o -o testbst

test_intbst: test_intbst.o intbst.o
	$(CXX) $(CXX_FLAGS) test_intbst.o intbst.o -o test_intbst

testbst.o: testbst.cpp intbst.h
	$(CXX) -c $(CXX_FLAGS) testbst.cpp

test_intbst.o: test_intbst.cpp intbst.h
	$(CXX) -c $(CXX_FLAGS) test_intbst.cpp

intbst.o: intbst.cpp intbst.h
	$(CXX) -c $(CXX_FLAGS) intbst.cpp

clean:
	rm -f testbst test_intbst *.o
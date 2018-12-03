# AUTHOR: Netanel Hugi 203553490

CXX=g++

a.out:
	$(CXX) -std=c++0x  *.cpp
	./a.out

clean:
	rm a.out
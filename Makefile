all:
	g++ -o Bloom    Bloom.cc
	g++ -o BloomSHA BloomSHA.cc 

tar:
	tar zcvf G01.tar.gz *.cc Makefile 

clean:
	rm *.o 
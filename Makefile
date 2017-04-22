#	
#	Para ir probando, ejecutad en terminal
#	$ make clean ; make ; ./Bloom{E|M|Q}
#	
all: modular


modular: 
	g++ -std=c++11 -o main main.cc basic_Bloom.cc couting_Bloom.cc spectral_Bloom.cc keyGenerator.cc
	
tar:
	tar zcvf G01.tar.gz *.cc Makefile 

clean:
	rm basic_Bloom couting_Bloom spectral_Bloom main

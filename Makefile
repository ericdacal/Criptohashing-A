#	
#	Para ir probando, ejecutad en terminal
#	$ make clean ; make ; ./Bloom{E|M|Q}
#	
all: Bloom BloomSHA couting_Bloom spectral_Bloom


Bloom:
	g++ -o Bloom  Bloom.cc

BloomSHA:
	g++ -o BloomSHA	 BloomSHA.cc sha1.cc sha256.cc
	
couting_Bloom:
	g++ -o couting_Bloom couting_Bloom.cc 
	
spectral_Bloom:
	g++ -std=c++11 -o spectral_Bloom spectral_Bloom.cc
	
modular: 
	g++ -std=c++11 -o main main.cc basic_Bloom.cc couting_Bloom.cc spectral_Bloom.cc
	
tar:
	tar zcvf G01.tar.gz *.cc Makefile 

clean:
	rm Bloom BloomSHA couting_Bloom spectral_Bloom main

#	
#	Para ir probando, ejecutad en terminal
#	$ make clean ; make ; ./Bloom{E|M|Q}
#	
all: modular modular2 modular3


modular: 
	g++ -std=c++11 -o main     main.cc basic_Bloom.cc keyGenerator.cc
	g++ -std=c++11 -o main_SHA main_SHA.cc basic_Bloom.cc keyGenerator.cc sha256.cc
	
modular2: 
	g++ -std=c++11 -o main_C     mainCount.cc couting_Bloom.cc keyGenerator.cc
	g++ -std=c++11 -o main_SHA_C main_SHACount.cc couting_Bloom.cc keyGenerator.cc sha256.cc

modular3: 
	g++ -std=c++11 -o main_S     mainSpec.cc spectral_Bloom.cc keyGenerator.cc
	g++ -std=c++11 -o main_SHA_L mainSHACount.cc spectral_Bloom.cc keyGenerator.cc sha256.cc
	
tar:
	tar zcvf G01.tar.gz *.cc *.h *.txt Makefile 

clean:
	rm main mainC mainS mainSHA main_SHA_C main_SHA_L 

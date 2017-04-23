#	
#	Para ir probando, ejecutad en terminal
#	$ make clean ; make ; ./Bloom{E|M|Q}
#	
all: modular modular2


modular: 
	g++ -std=c++11 -o main     main.cc basic_Bloom.cc keyGenerator.cc
	g++ -std=c++11 -o main_SHA main_SHA.cc basic_Bloom.cc keyGenerator.cc sha256.cc
	
modular2: 
	g++ -std=c++11 -o main_C     main_Count.cc couting_Bloom.cc keyGenerator.cc
	g++ -std=c++11 -o main_SHA_C main_SHACount.cc couting_Bloom.cc keyGenerator.cc sha256.cc

	
tar:
	tar zcvf G01.tar.gz *.cc *.h claus* tests* README.txt Makefile 

clean:
	rm main main_C main_SHA main_SHA_C 

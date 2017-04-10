#	
#	Para ir probando, ejecutad en terminal
#	$ make clean ; make ; ./Bloom{E|M|Q}
#	
all: Bloom BloomSHA

Bloom:
	g++ -o Bloom    Bloom.cc
	g++ -o BloomE    Bloom_Eric.cc
	g++ -o BloomM    Bloom_Mike.cc
	g++ -o BloomQ    Bloom_Quim.cc

BloomSHA:
	g++ -o BloomSHA 	 BloomSHA.cc
	g++ -o BloomSHA_E    BloomSHA_Eric.cc
	g++ -o BloomSHA_M    BloomSHA_Mike.cc
	g++ -o BloomSHA_Q    BloomSHA_Quim.cc

tar:
	tar zcvf G01.tar.gz *.cc Makefile 

clean:
	rm Bloom BloomE BloomM BloomQ BloomSHA_E BloomSHA_M BloomSHA_Q BloomSHA
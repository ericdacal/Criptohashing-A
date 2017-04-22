#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "basic_Bloom.h"
#include "keyGenerator.h"
#include <map>
using namespace std;




int main ()  {
  
  for (int i = 50; i < 250; i += 50) {
    for (int j = 0;j < 25;++j) {
     
      basic_Bloom filter(j,i,500);
      for (int k = 2;k <= 10;++k) {
        string key;
        string fileName = "claus";
        map <string,bool> claus;
        fileName.append(to_string(k)).append(".txt");
        ifstream addFile(fileName);
        while (getline(addFile,key)) {
            filter.insert(key);
            claus.insert(make_pair(key,true));
        }
        for (int l = 0;l < 4;++l) {
           int perc = l*33;
           int contFalse = 0;
           fileName = "test";
           file.append(to_string(l)).append(perc).append(".txt");
           ifstream queryFile;
           queryFile.open(fileName);
           while (getline(queryFile,key)) {
             bool member = filter.contains(key);
             if (member) {
               if (claus.find(key) != claus.end()) ++contFalse;
             }
           }
           cout << i << "\t" << j << "\t" << k << "\t" << perc
        }
      }
    }
    
  } 
  

  
  
  
  
  
  
  
  
  
  /*for(int i = 2; i <= 10; ++i) {
      keyGenerator generador(500,i);
      vector <string> keys = generador.generateKeys();
      ofstream fitxer;
      string fileName = "claus";
      fileName.append(to_string(i)).append(".txt");
      fitxer.open(fileName,ios::app);
      for (int l = 0; l < 500;++l) {
          fitxer << keys[l] << "\n";
      }
      fitxer.close();
      
      for(int j = 0; j < 4; ++j) {
        int perc = j*33;
          vector <string> percentKeys;
          for (int h = 0;h < keys.size()*(perc/100);++h) {
            percentKeys.push_back(keys[h]);
          }
          cout << i << " " << j << endl;
          keyGenerator generador2(500-percentKeys.size(),i);
          vector <string> others = generador.generateKeys();
          ofstream fitxer;
          string fileName = "tests";
          fileName.append(to_string(i)).append(to_string(perc)).append(".txt");
          fitxer.open(fileName,ios::app);
          for (int y = 0; y < percentKeys.size();++y) {
            fitxer << percentKeys[y] << "\n";
          }
          for (int z = 0;z < others.size();++z) {
            fitxer << others[z] << "\n";
          }
          fitxer.close();
      }*/
      
      
      
      
      
      

      /*for(int j = 1; j < 500; j += 50) {
        int filterSize = j;
        for(int k = 1; k < 25; ++k) {
          int numHashFunctions = k;
          int numFitxers = 2;
          basic_Bloom filter(numHashFunctions, filterSize);
          string key;
          ifstream addFile("claus.txt");
          while (getline(addFile,key)) {
              filter.insert(key);
          }
          addFile.close();
          for (int l = 1;l <= numFitxers;++l) {
            string file = "test";
            file.append(to_string(l));
            file.append(".txt");
            ifstream queryFile;
            queryFile.open(file);
            int count = 0;
            while (getline(queryFile,key)) {
                bool member = filter.contains(key);
                if (member == true) ++count;
                //else cout << "key " << key << " maybe is in the set." << endl;
            }
            cout << i << "\t" << j << "\t" << k << "\t" << l << "\t" << count << "\t" << endl;
            queryFile.close();
            
        }
      }
    }
  } */
}
      
      
      
      //int filterSize,numHashFunctions, keysNum, maxKeys, numFitxers;
        
        
    //cout << "Introdueix el tamany del filtre" << endl;
    //cin >> filterSize;
    //cout << "Introdueix el nombre de funcions de Hash" << endl;
    //cin >> numHashFunctions;
    
    //cout << "Introdueix el nombre de fitxers de test a probar" << endl;
    //cin >> numFitxers;
  
    
   
    
    
    
    //BloomFilter filter (filterSize,numHashFunctions,5, 40);
  
   
    



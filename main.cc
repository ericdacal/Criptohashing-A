#include <iostream>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "basic_Bloom.h"
#include "keyGenerator.h"
#include <set>
using namespace std;




int main ()  {
  
  cout << "Filter Size" << "\t" << "Num Hash Functions" << "\t" << "Key Size" << "\t" << "Keys Percentage" << "\t" << "False Positive Count" <<  endl;  
  srand(time(NULL));
  for (int i = 500; i <= 10000; i += 50) {
    for (int j = 1;j <= 25;++j) {
      for (int k = 2;k <= 10;++k) {
       
        basic_Bloom filter(i,j);
        string key;
        string fileName = "claus";
        set <string> claus;
        fileName.append(to_string(k)).append(".txt");
        ifstream addFile(fileName);
        while (getline(addFile,key)) {
            filter.insert(key);
            claus.insert(key);
        }
        for (int l = 0;l < 4;++l) {
           int perc = l*33;
           int contFalse = 0;
           fileName = "tests";
           fileName.append(to_string(k)).append(to_string(perc)).append(".txt");
           ifstream queryFile(fileName);
           while (getline(queryFile,key)) {
             bool member = filter.contains(key);
             if (member) {
               if (claus.find(key) == claus.end()) ++contFalse;
             }
           }
           cout << i << "\t" << j << "\t" << k << "\t" << perc << "\t" << contFalse <<  endl;
        }
      }
    }
    
  } 
  

  
  
  /*
  
  srand(time(NULL));
  
  for(int i = 2; i <= 10; ++i) {
      keyGenerator generador(500,i);
      vector <string> keys = generador.generateKeys();
      ofstream fitxer;
      string fileName = "claus";
      fileName.append(to_string(i)).append(".txt");
      fitxer.open(fileName,ios::out);
      for (int l = 0; l < 500;++l) {
          fitxer << keys[l] << "\n";
      }
      fitxer.close();

      for(int j = 0; j < 4; ++j) {
          int perc = j*33;
          vector <string> percentKeys;
          int aux = (keys.size()*perc)/100;
          //cout << aux << endl;
          for (int h = 0;h < aux;++h) {
            percentKeys.push_back(keys[h]);
          }
          //cout << i << " " << j << endl;
          keyGenerator generador2(500-percentKeys.size(),i);
          vector <string> others = generador2.generateKeys();
          ofstream fitxer;
          string fileName = "tests";
          fileName.append(to_string(i)).append(to_string(perc)).append(".txt");
          fitxer.open(fileName,ios::out);
          for (int y = 0; y < percentKeys.size();++y) {
            fitxer << percentKeys[y] << "\n";
          }
          for (int z = 0;z < others.size();++z) {
            fitxer << others[z] << "\n";
          }
          fitxer.close();
      }
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
  
   
    




Per executar aquest programa, simplement cal executar l'script:

	$ ./Run.sh

Aquest fitxer s'encarrega per sí sol tant de compilar com d'executar tots els programes, i de generar els fitxers de dades per a cada programa. 

En cas de voler fer-ho manualment, es pot executar la comanda:

	$ make

Seguit es poden executar els programes. Per defecte la seva sortida és per consola, però sempre es pot redireccionar a un fitxer de text; per exemple, si es vol la sortida del programa bàsic en un fitxer anomenat MAIN_OUTPUT.txt, cal fer:

	$ ./main >MAIN_OUTPUT.txt


---------------------------------------------------------

NOTA: És un requisit mínim disposar de C++11 instal.lat, però generalment qualsevol versió recent d'un sistema operatiu GNU/Linux ho té instal.lat; de fet, hem provat i desenvolupat tot el nostre codi amb distribucions de GNU/Linux, i esperem que també el proveu en aquestes condicions.

Si per alguna raó no teniu permisos per executar-lo (no hauria de ser el cas, però), cal executar prèviament la comanda:

	$ chmod +x Run.sh




clear
echo "PRACTICA ALGORISMIA | G01 | QP 2017"
echo "-----------------------------------"
# Si ja existeixen outputs, els esborro
if [ -d "Outputs" ]; then
  rm -rf Outputs/
fi
mkdir Outputs
echo "making..."
make
echo "Aquest fitxer executarà programes i guardarà les seves sortides en un directori Outputs."
echo "Degut a la naturalesa de backtracking dels programes, trigarà molt en generar les sortides!"
echo " "
echo "Executant programes..."
./main     >Outputs/outMain.txt
echo "  [1/4] Main amb filtre bàsic OK!"
./main_SHA >Outputs/outMainSHA.txt
echo "  [2/4] Mains amb filtre bàsic + SHA-256 OK!"
./main_C     >Outputs/outMainC.txt
echo "  [3/4] Mains amb filtre de conteig OK!"
./main_SHA_C >Outputs/outMainSHAC.txt
echo "  [4/4] Mains amb filtre de conteig + SHA-256 OK!"
echo "-----------------------------------"
echo "Programes executats amb èxit. Per veure els resultats dels programes, entra al directori Outputs"
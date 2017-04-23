# Si ja existeixen outputs, els esborro
if [ -d "Outputs" ]; then
  rm -rf Outputs/
fi
mkdir Outputs
clear
echo "PRACTICA ALGORISMIA | G01 | QP 2017"
echo "-----------------------------------"
echo "Aquest fitxer executarà programes i guardarà les seves sortides en un directori Outputs."
echo "Degut a la naturalesa de backtracking dels programes, trigarà molt en generar les sortides!"
echo " "
echo "Executant programes..."
./main     >Outputs/outMain.txt
echo "  [1/6]"
./main_SHA >Outputs/outMainSHA.txt
echo "  [2/6] Mains amb filtre bàsic OK!"
./main_C     >Outputs/outMainC.txt
echo "  [3/6]"
./main_SHA_C >Outputs/outMainSHAC.txt
echo "  [4/6] Mains amb filtre de conteig OK!"
./main_S     >Outputs/outMainS.txt
echo "  [5/6]"
./main_SHA_S >Outputs/outMainSHAS.txt
echo "  [6/6] Mains amb filtre espectral OK!"
echo "-----------------------------------"
echo "Programes executats amb èxit. Per veure els resultats dels programes, entra al directori Outputs"
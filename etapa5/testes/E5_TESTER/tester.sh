#!/bin/bash
COMPILER_PATH=$1
TESTES=(
    "dec_atrib"
    "aritmetica"
)
TESTE="logicas"
$COMPILER_PATH < ./$TESTE/codigo.txt > $TESTE/iloc.txt
while [ $? != 0 ]; do
    $COMPILER_PATH < ./$TESTE/codigo.txt > ./$TESTE/iloc.txt
done
python3 ./ilocsim.py -m $TESTE/iloc.txt > $TESTE/resultado_sim.txt
if cmp -s ./$TESTE/resultado_sim.txt ./$TESTE/gabarito.txt; then
    echo "Teste $TESTE passou"
else
    echo "Teste $TESTE falhou"
fi
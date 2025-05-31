#!/bin/bash
COMPILER_PATH=$1
TESTES=(
    "dec_atrib"
    "aritmetica"
    "logicas"
    "if"
    "if_else"
    "while"
    "if_vazio"
)
for TESTE in "${TESTES[@]}"; do
    $COMPILER_PATH < ./$TESTE/codigo.txt > $TESTE/iloc.txt 2>/dev/null
    while [ $? != 0 ]; do
        $COMPILER_PATH < ./$TESTE/codigo.txt > $TESTE/iloc.txt 2>/dev/null
    done
    python3 ./ilocsim.py -m $TESTE/iloc.txt > $TESTE/resultado_sim.txt
    if cmp -s ./$TESTE/resultado_sim.txt ./$TESTE/gabarito.txt; then
        echo "Teste $TESTE passou"
    else
        echo "Teste $TESTE falhou"
    fi
done
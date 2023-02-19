#!/bin/bash
#
# Script to run the greedy algorithm for all the input files and modes
# Limpando arquivos de saida
echo "Limpando arquivos de saida..."
echo "" > saida_1.csv
echo "" > saida_2.csv
echo "Executando modo 1 para todos os arquivos..."
./script.sh 1
echo "Executando modo 2 para todos os arquivos..."
./script.sh 2

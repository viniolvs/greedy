#!/bin/bash
#
# Script to run the greedy algorithm for all the input files and modes
# Limpando arquivos de saida
echo "Limpando arquivos de saida..."
echo "" > saida_start.csv
echo "" > saida_2.csv
echo "Executando modo start para todos os arquivos..."
./script.sh start
echo "Executando modo 2 para todos os arquivos..."
./script.sh 2

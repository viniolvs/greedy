#!/bin/bash
DIRETORIO="entradas"
MODO=$1

for ((i = 10; i <= 1000000; i*=10))
  do
    echo "N = $i :" >> saida_$MODO.txt
  ./greedy.x $DIRETORIO/Aula$i.txt $MODO >> saida_$MODO.txt
  echo >> saida_$MODO.txt
  done

for ((i = 150; i <= 150000; i*=10))
  do
    echo "N = $i" >> saida_$MODO.txt
  ./greedy.x $DIRETORIO/Aula$i.txt $MODO >> saida_$MODO.txt
  echo >> saida_$MODO.txt
  done

for ((i = 200; i <= 20000; i*=10))
  do
    echo "N = $i" >> saida_$MODO.txt
  ./greedy.x $DIRETORIO/Aula$i.txt $MODO >> saida_$MODO.txt
  echo >> saida_$MODO.txt
  done

for ((i = 250; i <= 250000; i*=100))
  do
    echo "N = $i" >> saida_$MODO.txt
  ./greedy.x $DIRETORIO/Aula$i.txt $MODO >> saida_$MODO.txt
  echo >> saida_$MODO.txt
  done

for ((i = 300; i <= 30000; i*=100))
  do
    echo "N = $i" >> saida_$MODO.txt
  ./greedy.x $DIRETORIO/Aula$i.txt $MODO >> saida_$MODO.txt
  echo >> saida_$MODO.txt
  done

./greedy.x $DIRETORIO/Aula350000.txt $MODO >> saida_$MODO.txt

for ((i = 50; i <= 500000; i*=10))
  do
    echo "N = $i" >> saida_$MODO.txt
  ./greedy.x $DIRETORIO/Aula$i.txt $MODO >> saida_$MODO.txt
  echo >> saida_$MODO.txt
  done

for ((i = 750; i <= 750000; i*=10))
  do
    echo "N = $i" >> saida_$MODO.txt
  ./greedy.x $DIRETORIO/Aula$i.txt $MODO >> saida_$MODO.txt
  echo >> saida_$MODO.txt
  done

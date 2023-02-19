#!/bin/bash
DIR="entradas"
MODO=$1

echo "Aulas,Salas,Tempo(s)" > saida_$MODO.csv
for ((i = 10; i <= 1000000; i*=10))
  do
    echo -n "$i,"  >> saida_$MODO.csv
    ./greedy.x $DIR/Aula$i.txt $MODO >> saida_$MODO.csv
    echo >> saida_$MODO.csv
  done

for ((i = 150; i <= 150000; i*=10))
  do
    echo -n "$i,"  >> saida_$MODO.csv
    ./greedy.x $DIR/Aula$i.txt $MODO >> saida_$MODO.csv
    echo >> saida_$MODO.csv
  done

for ((i = 200; i <= 20000; i*=10))
  do
    echo -n "$i," >> saida_$MODO.csv
    ./greedy.x $DIR/Aula$i.txt $MODO >> saida_$MODO.csv
    echo >> saida_$MODO.csv
  done

for ((i = 25; i <= 250000; i*=100))
  do
    echo -n "$i," >> saida_$MODO.csv
    ./greedy.x $DIR/Aula$i.txt $MODO >> saida_$MODO.csv
    echo >> saida_$MODO.csv
  done

for ((i = 300; i <= 30000; i*=100))
  do
    echo -n "$i," >> saida_$MODO.csv
    ./greedy.x $DIR/Aula$i.txt $MODO >> saida_$MODO.csv
    echo >> saida_$MODO.csv
  done

echo -n "350000,"  >> saida_350000.csv
./greedy.x $DIR/Aula350000.txt $MODO >> saida_350000.csv

for ((i = 50; i <= 500000; i*=10))
  do
    echo -n "$i," >> saida_$MODO.csv
    ./greedy.x $DIR/Aula$i.txt $MODO >> saida_$MODO.csv
    echo >> saida_$MODO.csv
  done

for ((i = 750; i <= 750000; i*=10))
  do
    echo -n "$i,"  >> saida_$MODO.csv
    ./greedy.x $DIR/Aula$i.txt $MODO >> saida_$MODO.csv
    echo >> saida_$MODO.csv 
  done

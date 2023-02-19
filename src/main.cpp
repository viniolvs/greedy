#include "greedy.hpp"
#include <cstdio>
#include <iostream>
#include <time.h>

using namespace std;

int main(int argc, char *argv[]) {

  if (argc < 2) {
    cerr << "./greedy.x <entrada> <modo>" << endl;
    exit(EXIT_FAILURE);
  }
  string mode = argv[2];

  FILE *file = fopen(argv[1], "rb+");
  if (!file) {
    cerr << "Falha ao abrir arquivo " << string(argv[1]) << endl;
    exit(EXIT_FAILURE);
  }

  vector<Task> tasks = getTasks(file);
  fclose(file);

  clock_t start, end;
  unsigned m = 0;
  vector<Machine> machines;

  start = clock();
  if (argc == 3) {
    mergeSortTasks(tasks, 0, tasks.size() - 1);
    // print tasks
    /* for (unsigned i = 0; i < tasks.size(); i++) */
    /*   cout << tasks[i].start << " " << tasks[i].end << endl; */

    if (mode == "1") {
      m = greedy(tasks);
      // printTasks(tasks, m);
      // cout << "Número de Máquinas: " << m << endl;
      cout << m; // saida script
    } else if (mode == "2") {
      machines = greedy2(tasks);
      // printMachines(machines);
      // cout << "Número de Máquinas: " << machines.size() << endl;
      cout << machines.size(); // saida script
    } else {
      cerr << "Modo inválido!" << endl << "<modo> 1 | 2 " << endl;
      exit(EXIT_FAILURE);
    }
  } else {
    cerr << "./greedy.x <entrada> <modo>" << endl << "<modo> 1 | 2 " << endl;
    exit(EXIT_FAILURE);
  }
  end = clock();
  double time = ((static_cast<double>(end - start) + 0.0) / CLOCKS_PER_SEC);
  // cout << "Tempo: " << time << endl;
  cout << "," << time; // saida script
  return 0;
}

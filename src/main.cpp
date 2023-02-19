#include "greedy.hpp"
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
    cerr << "Falha ao abrir arquivo de entrada!" << endl;
    exit(EXIT_FAILURE);
  }

  vector<Task> tasks = getTasks(file);
  fclose(file);

  clock_t start, end;
  unsigned m = 0;
  vector<Machine> machines;

  start = clock();
  if (argc == 3) {
    if (mode == "start") {
      sortTasks(tasks);
      m = greedy(tasks);
      /* printTasks(tasks, m); */
      cout << "Número de Máquinas: " << m << endl;
    } else if (mode == "2") {
      sortTasks(tasks);
      machines = greedy2(tasks);
      /* printMachines(machines); */
      cout << "Número de Máquinas: " << machines.size() << endl;
    } else {
      cerr << "Modo inválido!" << endl << "<modo> start | 2 " << endl;
      exit(EXIT_FAILURE);
    }
  } else {
    cerr << "./greedy.x <entrada> <modo>" << endl
         << "<modo> start | 2 " << endl;
    exit(EXIT_FAILURE);
  }
  end = clock();

  cout << "Tempo: "
       << ((static_cast<double>(end - start) + 0.0) / CLOCKS_PER_SEC) << "s"
       << endl;

  return 0;
}

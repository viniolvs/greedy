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
  string validate = "";
  if (argc == 4)
    validate = argv[3];

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
  if (argc == 3 || argc == 4) {
    mergeSortTasks(tasks, 0, tasks.size() - 1);
    if (mode == "1") {
      if (validate == "v")
        m = greedy_validate(tasks); // função que valida a solução
      else {
        m = greedy(tasks);
        cout << m; // saida script
      }
    } else if (mode == "2") {
      unsigned limit = 4;
      if (validate == "v")
        m = greedy2_validate(tasks, limit); // função que valida a solução
      else {
        m = greedy2(tasks, limit);
        cout << m; // saida script
      }
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
  if (validate == "v")
    cout << "Tempo: " << time << endl;
  else
    cout << "," << time; // saida script
  return 0;
}

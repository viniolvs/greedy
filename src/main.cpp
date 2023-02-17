#include "greedy.hpp"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {

  if (argc < 2) {
    cerr << "./greedy.x <entry-file>" << endl;
    exit(EXIT_FAILURE);
  }

  FILE *file = fopen(argv[1], "rb+");
  if (!file) {
    cerr << "Falha ao abrir arquivo de entrada!" << endl;
    exit(EXIT_FAILURE);
  }

  vector<Task> tasks = getTasks(file);
  sortTasks(tasks);
  for (auto task : tasks) {
    cout << task.start << " " << task.end << endl;
  }

  fclose(file);
  return 0;
}

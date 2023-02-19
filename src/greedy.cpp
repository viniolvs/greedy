#include "greedy.hpp"
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

static int seekIdleMachine(vector<Task> &machines, int time) {
  for (unsigned long i = 0; i < machines.size(); i++) {
    if (machines[i].end == time) {
      return static_cast<int>(i);
    }
  }
  return -1;
}

unsigned greedy(std::vector<Task> &tasks) {
  vector<Task> machines;
  unsigned m = 0;
  int time = 0;
  for (unsigned long i = 0; i < tasks.size(); i++) {
    time = tasks[i].start;
    int idle = seekIdleMachine(machines, time);
    if (idle != -1) {
      tasks[i].machine = idle;
      machines[static_cast<unsigned long>(idle)] = tasks[i];
    } else {
      tasks[i].machine = static_cast<int>(machines.size());
      machines.push_back(tasks[i]);
      m++;
    }
  }
  return m;
}

// Verifica se o começo da segunda tarefa é maior que o fim da primeira
static int diff_start_end(int start_next, int end_prev) {
  return (start_next - end_prev);
}

// Procura a melhor tarefa para a máquina baseada no tempo de término da tarefa
// anterior e o tempo de início da próxima tarefa
static int seekBestTask(vector<Task> &tasks, int end) {
  int best = -1;
  int aux = diff_start_end(tasks[0].start, end);
  for (unsigned long i = 1; i < tasks.size(); i++) {
    if (diff_start_end(tasks[i].start, end) == 0) {
      return static_cast<int>(i);
    } else if ((aux < 0) || ((diff_start_end(tasks[i].start, end) >= 0) &&
                             (diff_start_end(tasks[i].start, end) < aux))) {
      best = static_cast<int>(i);
    }
  }
  return best;
}

vector<Machine> greedy2(std::vector<Task> &tasks) {
  vector<Machine> machines;
  int best = 0;
  unsigned i = 0;
  while (tasks.size() > 0) {
    // insere a primeira tarefa na nova máquina
    machines.push_back(Machine());
    machines[i].push_back(tasks[0]);
    // remove a tarefa da lista de tarefas
    tasks.erase(tasks.begin());
    // executa enquanto existe uma tarefa que caiba na máquina
    for (unsigned long j = 1;; j++) {
      // se não existir mais tarefas para a máquina, sai do loop
      if (machines[i][j - 1].end > tasks.end()->start)
        break;
      // busca a melhor tarefa para a máquina na lista de tarefas
      if (tasks.size() > 1)
        best = seekBestTask(tasks, machines[i][j - 1].end);
      else {
        machines[i].push_back(tasks[0]);
        tasks.erase(tasks.begin());
      }
      if (best == -1)
        break;
      // insere a melhor tarefa na máquina
      machines[i].push_back(tasks[static_cast<unsigned long>(best)]);
      // remove a tarefa da lista de tarefas
      tasks.erase(tasks.begin() + best);
    }
    i++;
  }
  return machines;
}

void printMachines(vector<Machine> &machines) {
  for (unsigned long i = 0; i < machines.size(); i++) {
    std::cout << "Máquina " << i << ": ";
    for (unsigned long j = 0; j < machines[i].size(); j++) {
      std::cout << machines[i][j].start << " " << machines[i][j].end << " | ";
    }
    std::cout << std::endl;
  }
}

void printTasks(vector<Task> &tasks, unsigned m) {
  for (unsigned long i = 0; i < m; i++) {
    std::cout << "Máquina " << i << ": ";
    for (unsigned long j = 0; j < tasks.size(); j++) {
      if (tasks[j].machine == static_cast<int>(i))
        std::cout << tasks[j].start << " " << tasks[j].end << " | ";
    }
    std::cout << std::endl;
  }
}

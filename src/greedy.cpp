#include "greedy.hpp"
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

// procura uma tarefa que já terminou
static int seekIdleMachine(vector<Task> &running, int time) {
  for (unsigned long i = 0; i < running.size(); i++) {
    if (running[i].end == time) {
      return static_cast<int>(i);
    }
  }
  return -1;
}

// Solução gulosa 1
unsigned greedy(std::vector<Task> &tasks) {
  // ordena as tarefas por tempo de início
  mergeSortTasks(tasks, 0, tasks.size() - 1);
  // vetor com as tarefas em execução
  vector<Task> running;
  // número de máquinas
  unsigned m = 0;
  int idle = -1;
  int time = 0;
  for (unsigned long i = 0; i < tasks.size(); i++) {
    // tempo atual = início da tarefa atual
    time = tasks[i].start;
    // procura uma tarefa que já terminou
    idle = seekIdleMachine(running, time);
    // se existir uma tarefa que já terminou, a tarefa atual é executada nessa
    if (idle != -1) {
      running[static_cast<unsigned long>(idle)] = tasks[i];
    }
    // se não existir uma tarefa que já terminou, uma nova máquina é criada
    else {
      running.push_back(tasks[i]);
      m++;
    }
  }
  return m;
}

// modifica o vetor de tarefas para exibir qual máquina executou qual tarefa
unsigned greedy_validate(std::vector<Task> &tasks) {
  // ordena as tarefas por tempo de início
  mergeSortTasks(tasks, 0, tasks.size() - 1);
  // vetor com as tarefas em execução
  vector<Task> running;
  // número de máquinas
  unsigned m = 0;
  int idle = -1;
  int time = 0;
  for (unsigned long i = 0; i < tasks.size(); i++) {
    // tempo atual = início da tarefa atual
    time = tasks[i].start;
    // procura uma tarefa que já terminou
    idle = seekIdleMachine(running, time);
    // se existir uma tarefa que já terminou, a tarefa atual é executada nessa
    if (idle != -1) {
      tasks[i].machine = idle;
      running[static_cast<unsigned long>(idle)] = tasks[i];
    }
    // se não existir uma tarefa que já terminou, uma nova máquina é criada
    else {
      tasks[i].machine = static_cast<int>(running.size());
      running.push_back(tasks[i]);
      m++;
    }
  }
  printTasks(tasks, m);
  cout << "Numero de maquinas: " << m << endl;
  return m;
}

// Procura a melhor tarefa para a máquina baseada no tempo de término da tarefa
// anterior e o tempo de início da próxima tarefa
static int seekBestTask(vector<Task> &tasks, int end) {
  int best = -1;
  int aux = (tasks[0].start - end);
  for (unsigned long i = 1; i < tasks.size(); i++) {
    if ((tasks[i].start - end) == 0) {
      return static_cast<int>(i);
    } else if ((aux < 0) || (best < 0) ||
               (((tasks[i].start - end) >= 0) &&
                ((tasks[i].start - end) < aux))) {
      best = static_cast<int>(i);
    }
  }
  return best;
}

// Solução gulosa 2
// limit define o número máximo de tarefas que uma máquina pode executar
unsigned greedy2(std::vector<Task> &tasks, unsigned limit) {
  // ordena as tarefas por tempo de início
  mergeSortTasks(tasks, 0, tasks.size() - 1);
  int best = -1;
  unsigned i = 0;
  for (i = 0; tasks.size() > 0; i++) {
    Machine machine;
    // insere a primeira tarefa na nova máquina e a remove da lista
    machine.push_back(tasks[0]);
    tasks.erase(tasks.begin());

    for (unsigned long j = 1; tasks.size() > 0; j++) {
      // se não existir mais tarefas para a máquina, sai do loop
      if (j >= limit || machine[j - 1].end > tasks.end()->start)
        break;
      // caso a tarefa caiba na máquina e seja a última da lista de tarefas
      else if (tasks.size() == 1) {
        machine.push_back(tasks[0]);
        tasks.erase(tasks.begin());
        break;
      }
      // caso a tarefa caiba na máquina e não seja a última da lista de tarefas
      else {
        // busca a melhor tarefa para a máquina na lista de tarefas
        best = seekBestTask(tasks, machine[j - 1].end);
        // insere a melhor tarefa na máquina
        machine.push_back(tasks[static_cast<unsigned long>(best)]);
        // remove a tarefa da lista de tarefas
        tasks.erase(tasks.begin() + best);
      }
    }
  }
  return i;
}

// modifica o vetor de tarefas para exibir qual máquina executou qual tarefa
unsigned greedy2_validate(std::vector<Task> &tasks, unsigned limit) {
  // ordena as tarefas por tempo de início
  mergeSortTasks(tasks, 0, tasks.size() - 1);
  // vetor auxiliar
  vector<Task> aux;
  copy(tasks.begin(), tasks.end(), back_inserter(aux));
  tasks.clear();

  int best = -1;
  unsigned i = 0;
  for (i = 0; aux.size() > 0; i++) {
    Machine machine;

    // insere a máquina que foi utilizada
    aux[0].machine = static_cast<int>(i);
    tasks.push_back(aux[0]);
    // insere a primeira tarefa na nova máquina e a remove da lista
    machine.push_back(aux[0]);
    aux.erase(aux.begin());

    for (unsigned long j = 1; aux.size() > 0; j++) {
      // se não existir mais tarefas para a máquina ou se a maquina
      // atingir o limite de tarefas sai do loop
      if (j >= limit || machine[j - 1].end > aux.end()->start)
        break;
      // caso a tarefa caiba na máquina e seja a última da lista de tarefas
      else if (aux.size() == 1) {
        aux[0].machine = static_cast<int>(i);
        tasks.push_back(aux[0]);
        machine.push_back(aux[0]);
        aux.erase(aux.begin());
        break;
      }
      // caso a tarefa caiba na máquina e não seja a última da lista de tarefas
      else {
        // busca a melhor tarefa para a máquina na lista de tarefas
        best = seekBestTask(aux, machine[j - 1].end);
        aux[static_cast<unsigned long>(best)].machine = static_cast<int>(i);
        tasks.push_back(aux[static_cast<unsigned long>(best)]);
        // insere a melhor tarefa na máquina
        machine.push_back(aux[static_cast<unsigned long>(best)]);
        // remove a tarefa da lista de tarefas
        aux.erase(aux.begin() + best);
      }
    }
  }
  printTasks(tasks, i);
  cout << "Numero de maquinas: " << i << endl;
  return i;
}

void printTasks(vector<Task> &tasks, unsigned m) {
  std::vector<int> count_tasks(m, 0);
  for (unsigned long i = 0; i < m; i++) {
    std::cout << "Máquina " << i << ": ";
    for (unsigned long j = 0; j < tasks.size(); j++) {
      if (tasks[j].machine == static_cast<int>(i)) {
        std::cout << tasks[j].start << " " << tasks[j].end << " | ";
        count_tasks[i]++;
      }
    }
    std::cout << "Total = " << count_tasks[i] << std::endl;
  }
}

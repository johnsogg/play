/*

  linked_list_main.cpp

  This file contains the main() method. It should be supplied along
  with the other code, including a big fat comment saying that it
  should not be blended with the other C++ source file. The RetroGrade
  system has its own 'main' implementation, and if the student puts a
  'main' function in their implementation file, confusion will ensue.

 */

#include "linked_list.h"

using namespace std;

int main() {
  cout << "Word up " << endl;
  node* root = init_node(0);
  cout << "Empty list contains " << size(root) << " items." << endl;
  insert_data(root, 3);
  insert_data(root, 7);
  insert_data(root, 4);
  insert_data(root, 9);
  insert_data(root, 3);
  insert_data(root, 2);
  cout << "Should report 2, 3, 3, 4, 7, 9" << endl;
  report(root);
  report_membership(root, 1, 10);
  cout << "List contains " << size(root) << " items." << endl;
  remove_data(root, 4);
  cout << "Should report 2, 3, 3, 7, 9" << endl;
  report(root);
  cout << "List contains " << size(root) << " items." << endl;
  remove_data(root, 5);
  cout << "Should report 2, 3, 3, 7, 9 (again)" << endl;
  report(root);
  cout << "List contains " << size(root) << " items." << endl;
  remove_data(root, 2);
  cout << "Should report 3, 3, 7, 9" << endl;
  report(root);
  cout << "List contains " << size(root) << " items." << endl;
  remove_data(root, 9);
  cout << "Should report 3, 3, 7" << endl;
  report(root);
  cout << "List contains " << size(root) << " items." << endl;
  report_membership(root, 1, 10);
}

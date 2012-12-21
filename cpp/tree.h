#ifndef __cpp__tree__
#define __cpp__tree__

class Node {

protected:
  Node* left;
  Node* right;
  int data;
public:
  Node* find(int num);
  void insert(int num);
  int getData() { return data; }
  Node(int num);
  ~Node();
};

class Tree {
protected:
  Node* root;
public:
  Tree();
  void insert(int num);
  bool contains(int num);
};


#endif /* defined(__cpp__tree__) */


// #ifndef DATE_H
// #define DATE_H
 
// class Date
// {
// private:
//     int m_nMonth;
//     int m_nDay;
//     int m_nYear;
 
//     Date() { } // private default constructor
 
// public:
//     Date(int nMonth, int nDay, int nYear);
 
//     void SetDate(int nMonth, int nDay, int nYear);
 
//     int GetMonth() { return m_nMonth; }
//     int GetDay()  { return m_nDay; }
//     int GetYear() { return m_nYear; }
// };
 
// #endif

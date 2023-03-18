#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class students {
public:
  string name;
  vector<int> courses;
  double average;

public:
  void makeAverage();
  void reset();
};

/*Definition of the max and min functions*/
template <typename N> N minimum(N a, N b) { return a > b ? b : a; }
template <typename N> N maximum(N a, N b) { return a > b ? a : b; }

void students::makeAverage() {
  double sum = 0;
  int cnt = 0;
  for (int i = 0; i < this->courses.size(); i++){
    if(this ->courses[i] != -1){
      sum += this->courses[i];
      cnt ++;
    }
  }
  this->average = sum / cnt;
}

void students::reset() {
  this->name = "";
  this->average = 0;
  this->courses.clear();
}

int main(int argv, char *argc[]) {
  /*==================================*/
  /*Check if the input CLI is correct.*/
  /*==================================*/

  /*Check if target file is a single file.*/
  if (argv > 2) {
    cout << "Wrongly input." << endl;
    cout << "This program can only afford 1 file." << endl;
    return 1;
  }
  
  /*===========================*/
  /*Read the target input file.*/
  /*===========================*/
  ifstream FILE(argc[1]);

  /*Check if target file exists.*/
  if (!FILE) {
    cout << "404: Wrong path or an not existing file." << endl;
    cout << "Please check you input path." << endl;
    return 2; //Error quitting situation 2;
  }

  string tmp;
  vector<string> info;
  while (getline(FILE, tmp)) {
    info.push_back(tmp);
  }
  FILE.close();

  /*====================================*/
  /*Make info vectors into students info*/
  /*====================================*/

  vector<students> list;
  students stu;
  int courseID;
  double grade;

  for (int i = 0; i < info.size(); i++) {
    istringstream iss(info[i]);
    iss >> stu.name;
    while (!iss.fail()) {
      iss >> courseID;
      iss >> grade;
      if (stu.courses.size() <= courseID) {
        stu.courses.resize(courseID + 1, -1);
      }
      stu.courses[courseID] = grade;
    }
    list.push_back(stu);
    stu.reset();
  }

  /*===========================================*/
  /*Make operations to existing students array.*/
  /*===========================================*/

  for (int i = 0; i < list.size(); i++) {
    list[i].makeAverage();
  }

  /*=====================================*/
  /*Get the average, maximum and minimum.*/
  /*=====================================*/

  vector<int> minScore;
  vector<int> maxScore;
  vector<pair<int, double> > Sum(1000, make_pair(0, 0));
  for (int i = 0; i < list.size(); i++) {
    for (int j = 0; j < list[i].courses.size(); j++) {
      if (j >= minScore.size()) {
        minScore.resize(j + 1, 5);
        maxScore.resize(j + 1, 0);
      }
      if (list[i].courses[j] == -1)
        continue;
      Sum[j].first++;
      Sum[j].second += list[i].courses[j];
      minScore[j] = minimum(minScore[j], list[i].courses[j]);
      maxScore[j] = maximum(maxScore[j], list[i].courses[j]);
    }
  }

  vector<double> Average(maxScore.size(), 0);
  for (int i = 0; i < Average.size(); i++) {
    Average[i] = Sum[i].second / (double)Sum[i].first;
  }

  /*===========================*/
  /*Print out the result table.*/
  /*===========================*/

  /*Table head.*/
  cout << "no\tname\t";
  for (int i = 1; i < Average.size(); i++) {
    cout << "Course" << i << "\t";
  }
  cout << "Average" << endl;

  /*Students infomation and grades.*/
  for (int i = 0; i < list.size(); i++) {
    cout << i + 1 << "\t" << list[i].name << "\t";
    for (int j = 1; j < list[i].courses.size(); j++) {
      if (list[i].courses[j] == -1) {
        cout << "NaN\t";
        continue;
      }
      cout << list[i].courses[j] << "\t";
    }
    cout << list[i].average << endl;
  }

  /*Courses' averages.*/
  cout << "\taverage\t";
  for(int i = 1; i < Average.size(); i++){
    cout << Average[i] << "\t";
  }
  cout << endl;

  /*Courses' minimum.*/
  cout << "\tmin\t";
  for (int i = 1; i < minScore.size(); i++) {
    cout << minScore[i] << "\t";
  }
  cout << endl;

  /*Courses' maximum.*/
  cout << "\tmax\t";
  for(int i = 1; i < maxScore.size(); i++){
    cout << maxScore[i] << "\t";
  }
  cout << endl;

  /*Default quitting situation 0;*/
  return 0;
}
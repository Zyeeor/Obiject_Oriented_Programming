#include <iostream>
#include <string>
#include <vector>

using namespace std;

class students{
public:
    string name;
    int course1;
    int course2;
    int course3;
    double average;
public:
    void makeAverage();
    void getScores();
    void Print();
};

void students::makeAverage(){
    this->average = (double)(this->course1 + this->course2 + this->course3)/3;
}

void students::getScores(){
    cin >> this->name >> this->course1 >> this->course2 >> this->course3;
}

void students::Print(){
    cout << this->name << '\t' << this->course1 << '\t' << this->course2 << '\t' << this->course3 << '\t' << this->average << endl;
}

int main(){
    vector<students> list(10);
    vector<double> sums(3, 0);
    vector<int> mina(3, 5);
    vector<int> maxa(3, 0); 
    for(int i = 0; i < 10; i++){
        list[i].getScores();
        list[i].makeAverage();
        mina[0] = min(list[i].course1, mina[0]);
        mina[1] = min(list[i].course2, mina[1]);
        mina[2] = min(list[i].course3, mina[2]);
        maxa[0] = max(list[i].course1, maxa[0]);
        maxa[1] = max(list[i].course2, maxa[1]);
        maxa[2] = max(list[i].course3, maxa[2]);
        sums[0] += list[i].course1;
        sums[1] += list[i].course2;
        sums[2] += list[i].course3;
    }
    for(int i = 0; i < 3; i++) sums[i] /= 10;
    cout << "no\tname\tscore1\tscore2\tscore3\taverage" << endl;
    for(int i = 0; i < 10; i++){
        cout << i+1 << '\t';
        list[i].Print();
    }
    cout << "\taverage\t" << sums[0] << "\t" << sums[1] << "\t" << sums[2] << "\t" << endl;
    cout << "\tmin\t" << mina[0] << "\t" << mina[1] << "\t" << mina[2] << "\t" << endl;
    cout << "\tmax\t" << maxa[0] << "\t" << maxa[1] << "\t" << maxa[2] << "\t" << endl;
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include "student.h"

using namespace std;

int main ()
{
    int selection =0;
    vector<Student>studentList;

    do
    {
        cout<<endl;
        cout<<"Select"<<endl;
        cout<<"Add students = 0"<<endl;
        cout<<"Print all students = 1"<<endl;
        cout<<"Sort and print students according to Name = 2"<<endl;
        cout<<"Sort and print students according to Age = 3"<<endl;
        cout<<"Find and print student = 4"<<endl;
        cout<<"Exit = 5" << endl;
        cin>>selection;

        switch(selection)
        {
        case 0: {
            // Kysy käyttäjältä uuden opiskelijan nimi ja ikä
            string name;
            int age;
            cout << "Opiskelijan nimi: " << endl;
            cin >> name;
            cout << "Opiskelijan ika: " << endl;
            cin >> age;
            // Lisää uusi student StudentList vektoriin.
            studentList.push_back(Student(name, age));
            break;
        }
        case 1: {
            // Tulosta StudentList vektorin kaikkien opiskelijoiden
            // nimet.
            cout << "StudentList: " << endl;
            for (const auto& student : studentList) {
                student.printStudentInfo();
            }
            break;
        }
        case 2: {
            // Järjestä StudentList vektorin Student oliot nimen mukaan
            // algoritmikirjaston sort funktion avulla
            // ja tulosta printStudentInfo() funktion avulla järjestetyt
            // opiskelijat
            sort(studentList.begin(), studentList.end(), [](const Student& a, const Student& b) {
                return a.getName() < b.getName();
            });
            cout << "Sorted by name: " << endl;
            for (const auto& student : studentList) {
                student.printStudentInfo();
            }
            break;
        }
        case 3: {
            // Järjestä StudentList vektorin Student oliot iän mukaan
            // algoritmikirjaston sort funktion avulla
            // ja tulosta printStudentInfo() funktion avulla järjestetyt
            // opiskelijat
            sort(studentList.begin(), studentList.end(), [](const Student&a, const Student& b) {
                return a.getAge() < b.getAge();
            });
            cout << "Sorted by age: " << endl;
            for (const auto& student : studentList) {
                student.printStudentInfo();
            }
            break;
        }
        case 4: {
            // Kysy käyttäjältä opiskelijan nimi
            // Etsi studentListan opiskelijoista algoritmikirjaston
            // find_if funktion avulla löytyykö käyttäjän antamaa nimeä
            // listalta. Jos löytyy, niin tulosta opiskelijan tiedot.
            string searchName;
            cout << "Opiskelijan nimi: " << endl;
            cin >> searchName;

            auto it = find_if(studentList.begin(), studentList.end(), [&searchName](const Student student) {
                return student.getName() == searchName;
            });

            if (it != studentList.end()) {
                cout << "Opiskelija loydetty: " << endl;
                it->printStudentInfo();
            } else {
                cout << "Opiskelijaa ei loydetty." << endl;
            }
            break;
        }
        case 5: {
            cout << "Exiting..." << endl;
            break;
        }
        default:
            cout<< "Wrong selection, stopping..."<<endl;
            break;
        }
    } while(selection != 5);
    return 0;
}

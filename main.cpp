#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <uzdfunkcijos.h>

using namespace std;

struct Student
{
    string name;
    string lastname;
    double average;
    double exam;
    double rez;
};

vector<Student> studentList;

void PrintResult (vector<Student> studentList)
{
    for (int i = 0; i < studentList.size(); i++)
    {
        cout << setw(14) << studentList[i].name << setw(14) << studentList[i].lastname << "   " << studentList[i].rez << endl;
    }
}

int main()
{
    int n = 0, students = 2, ndLength = 0;
    vector<double> nd;
    char isMedian = 'N';
    double egz;
    char status;
    string name, lastname;

    cout << "Skaityti is .txt failo?Y/N" << endl;
    cin >> status;
    cout << "Skaiciuoti mediana? Y/N" << endl;
    cin >> isMedian;

    vector<string> list2;

    if (status == 'Y')
    {
        ndLength = GetNDLength();

        ifstream input("kursiokai.txt");
        input.ignore(256,'\n');

        if (isMedian == 'Y')
            cout << setw(16) << "Pavarde" << setw(16) << "Vardas" << setw(22) << "Mediana / Galutinis(Vid.)" << endl;
        else
            cout << setw(16) << "Pavarde" << setw(16) << "Vardas" << setw(22) << "Galutinis(Vid.)" << endl;

        while (!input.eof())
        {
            nd.clear();
            Student student;
            input >> student.name >> student.lastname;
            int temp;

            for (int i = 0; i < ndLength; i++)
            {
                input >> temp;
                nd.push_back(temp);
            }

            input >> student.exam;

            double rez;

            if (isMedian == 'Y')
            {
                if (ndLength%2 == 0)
                    rez = (double)(nd[ndLength/2] + 0.6 * student.exam);
                else
                    rez = (double)(0.4 * ((nd[ndLength/2] + nd[ndLength/2 + 1])/2) + 0.6 * student.exam);
            }
            else
                rez = (double)(0.4 * Average(ndLength, nd) + 0.6 * student.exam);

            student.rez = rez;

            studentList.push_back(student);

            cout << setw(16) << student.name << setw(16) << student.lastname << setw(22) << rez << endl;
        }

    }
    else if (status == 'N')
    {
    }
    else
        return 0;

    cout << "   " << endl;
    cin >> students;
    cout << endl;
    cin.clear();
    cin.ignore(256,'\n');

    for (int a = 0; a < students; a++)
    {
        egz = -1;
        cout << "Iveskite varda: " << endl;
        getline(cin, name);
        cout << "Iveskite pavarde: " << endl;
        getline(cin, lastname);
        cout << name << " " << lastname << endl;
        cout << "Iveskite namu darbu skaiciu: " << endl;
        cin >> n;

        while(cin.fail()) {
            cout << "Klaida, namu darbu skaicius gali buti tik sveikasis skaicius" << endl;
            cin.clear();
            cin.ignore(256,'\n');
            cin >> n;
        }

        double temp = 0;

        for (int i = 0; i < n; i++)
        {
            cout << i + 1 << " Pazymys: ";
            cin >> temp;
            nd.push_back(temp);
            while (nd[i] < 0 || nd[i] > 10 || cin.fail())
            {
                cin.clear();
                cin.ignore(256,'\n');
                cout << "Klaida, namu darbu pazymys gali buti tik nuo 0-10" << endl;
                cin >> nd[i];
            }
            cout << endl;

        }

        while(egz < 0 || egz > 10 || cin.fail())
        {
            cout << "Iveskite egzamino rezultata: ";
            cin.clear();
            cin.ignore(256,'\n');
            cin >> egz;
            cout << endl;
        }

        double rez = (double)(0.4 * Average(n, nd) + 0.6 * egz);

        Student stud;
        stud.name = name;
        stud.lastname = lastname;
        stud.average = Average(n, nd);
        stud.exam = egz;
        stud.rez = rez;

        studentList.push_back(stud);

        cout << "Bendras rezultatas - " << rez << endl;

        cin.clear();
        cin.ignore(256,'\n');

    }

    PrintResult(studentList);


    return 0;
}

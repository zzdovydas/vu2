#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <uzdfunkcijos.h>
#include <time.h>
#include <list>
#include <deque>

using namespace std;

class Student2
{
public:
    Student2(string n, string l) : name {n}, lastname {l} {}

    string getName() { return name; }
    string getLName() { return lastname; }
    double getResult() { return rez; }

    void setGrades (double avg, double result)
    {
        average = avg;
        rez = result;
    }
private:
    string name;
    string lastname;
    double average;
    double rez;
};

struct Student
{
    string name;
    string lastname;
    double average;
    double exam;
    double rez;
    Student *studNext;
};

vector<Student> studentList;
vector<Student2> studentList2;

void PrintResult (vector<Student2> studentList)
{
    for (int i = 0; i < studentList2.size(); i++)
        cout << setw(14) << studentList2[i].getName() << setw(14) << studentList2[i].getLName() << "   " << studentList2[i].getResult() << endl;
}

void SortStudentsVector(string inputFile)
{
    vector<double> nd;
    int sizeList = 0, ndLength = GetNDLength();

    ifstream input;

    try
    {
    input.open(inputFile.c_str());
    }
    catch (std::exception& e)
    {
        exit(0);
    }

    input.ignore(256, '\n');

    clock_t begin_time = clock();

    while (!input.eof())
        {
            nd.clear();
            string name, lastname;
            input >> name >> lastname;

            Student2 stud (name, lastname);

            int temp;

            for (int i = 0; i < ndLength; i++)
            {
                input >> temp;
                nd.push_back(temp);
            }

            double exam = 0;

            input >> exam;

            double rez = (double)(0.4 * Average(ndLength, nd) + 0.6 * exam);

            stud.setGrades(Average(ndLength, nd), rez);

            studentList2.push_back(stud);

            sizeList++;
        }

        input.close();

        cout << "Failo nuskaitymo vykdymo laikas: " << float( clock () - begin_time ) /  CLOCKS_PER_SEC << "s" << endl;

        begin_time = clock();

        ofstream output ("vargsiukai.txt");

        for(int i = 0; i < studentList2.size(); i++)
        {
            if (studentList2[i].getResult() < 5)
            {
                output << setw(16) << studentList2[i].getLName() << setw(16) << studentList2[i].getName() << setw(22) << studentList2[i].getResult() << endl;
            }
        }

        output.close();
        cout << "Nelaiminguju surusiavimo vykdymo laikas: " << float( clock () - begin_time ) /  CLOCKS_PER_SEC << "s" << endl;

        begin_time = clock();

        ofstream output2 ("kietiakai.txt");

        for(int i = 0; i < studentList2.size(); i++)
        {
            if (studentList2[i].getResult() >= 5)
                {
                    output << setw(16) << studentList2[i].getLName() << setw(16) << studentList2[i].getName() << setw(22) << studentList2[i].getResult() << endl;
                }
        }

        output2.close();

        cout << "Kietiaku surusiavimo vykdymo laikas: " << float( clock () - begin_time ) /  CLOCKS_PER_SEC << "s" << endl;

}

void SortStudentsDeque(string inputFile)
{
    deque<Student2> studList;
    vector<double> nd;
    int sizeList = 0, ndLength = GetNDLength();

    ifstream input;

    try
    {
    input.open(inputFile.c_str());
    }
    catch (std::exception& e)
    {
        exit(0);
    }

    input.ignore(256, '\n');

    clock_t begin_time = clock();

    while (!input.eof())
        {
            nd.clear();
            string name, lastname;
            input >> name >> lastname;
            Student2 stud(name, lastname);
            int temp;

            for (int i = 0; i < ndLength; i++)
            {
                input >> temp;
                nd.push_back(temp);
            }

            double exam = 0;

            input >> exam;

            double rez = (double)(0.4 * Average(ndLength, nd) + 0.6 * exam);

            stud.setGrades(Average(ndLength, nd), rez);

            studList.push_back(stud);

            sizeList++;
        }

        input.close();

        cout << "Failo nuskaitymo vykdymo laikas: " << float( clock () - begin_time ) /  CLOCKS_PER_SEC << "s" << endl;

        begin_time = clock();

        ofstream output ("vargsiukai.txt");

        deque<Student2>::iterator it;

        /*for(it = studList.begin(); it != studList.end(); it++)
        {
            if (it->getGrades() < 5)
            {
                output << setw(16) << it-> << setw(16) << it->name << setw(22) << it->rez << endl;
            }
        }

        output.close();
        cout << "Nelaiminguju surusiavimo vykdymo laikas: " << float( clock () - begin_time ) /  CLOCKS_PER_SEC << "s" << endl;

        begin_time = clock();

        ofstream output2 ("kietiakai.txt");

        for(it = studList.begin(); it != studList.end(); it++)
        {
            if (it->rez >= 5)
                {
                    output2 << setw(16) << it->lastname << setw(16) << it->name << setw(22) << it->rez << endl;
                }
        }

        output2.close();

        cout << "Kietiaku surusiavimo vykdymo laikas: " << float( clock () - begin_time ) /  CLOCKS_PER_SEC << "s" << endl;

        */

}

/*
void SortStudentsList(string inputFile)
{
    list<Student> studList;
    vector<double> nd;
    int sizeList = 0, ndLength = GetNDLength();

    ifstream input;

    try
    {
    input.open(inputFile.c_str());
    }
    catch (std::exception& e)
    {
        exit(0);
    }

    input.ignore(256, '\n');

    clock_t begin_time = clock();

    while (!input.eof())
        {
            Student stud;
            nd.clear();
            string name, lastname;
            input >> name >> lastname;
            Student2 stud(name, lastname);
            int temp;

            for (int i = 0; i < ndLength; i++)
            {
                input >> temp;
                nd.push_back(temp);
            }

            input >> stud.exam;

            double rez = (double)(0.4 * Average(ndLength, nd) + 0.6 * stud.exam);

            stud.rez = rez;

            studList.push_back(stud);

            sizeList++;
        }

        input.close();

        cout << "Failo nuskaitymo vykdymo laikas: " << float( clock () - begin_time ) /  CLOCKS_PER_SEC << "s" << endl;

        begin_time = clock();

        ofstream output ("vargsiukai.txt");

        list<Student>::iterator it;

        for(it = studList.begin(); it != studList.end(); it++)
        {
            if (it->exam < 5)
            {
                output << setw(16) << it->lastname << setw(16) << it->name << setw(22) << it->rez << endl;
            }
        }

        output.close();
        cout << "Nelaiminguju surusiavimo vykdymo laikas: " << float( clock () - begin_time ) /  CLOCKS_PER_SEC << "s" << endl;

        begin_time = clock();

        ofstream output2 ("kietiakai.txt");

        for(it = studList.begin(); it != studList.end(); it++)
        {
            if (it->rez >= 5)
                {
                    output2 << setw(16) << it->lastname << setw(16) << it->name << setw(22) << it->rez << endl;
                }
        }

        output2.close();

        cout << "Kietiaku surusiavimo vykdymo laikas: " << float( clock () - begin_time ) /  CLOCKS_PER_SEC << "s" << endl;

}
*/

void SortStudentsDynamic(string inputFile)
{
    Student *dynStudList = new Student();
    Student *firstItem = dynStudList;
    vector<double> nd;
    int sizeList = 0, ndLength = GetNDLength();

    ifstream input;

    try
    {
    input.open(inputFile.c_str());
    }
    catch (std::exception& e)
    {
        exit(0);
    }

    input.ignore(256, '\n');

    clock_t begin_time = clock();

    while (!input.eof())
        {
            nd.clear();
            input >> dynStudList->name >> dynStudList->lastname;
            int temp;

            for (int i = 0; i < ndLength; i++)
            {
                input >> temp;
                nd.push_back(temp);
            }

            input >> dynStudList->exam;

            double rez = (double)(0.4 * Average(ndLength, nd) + 0.6 * dynStudList->exam);

            dynStudList->rez = rez;

            dynStudList->studNext = new Student();
            dynStudList = dynStudList->studNext;

            sizeList++;
        }

        input.close();

        cout << "Failo nuskaitymo vykdymo laikas: " << float( clock () - begin_time ) /  CLOCKS_PER_SEC << "s" << endl;

        begin_time = clock();

        Student *writeStud = firstItem;
        ofstream output ("vargsiukai.txt");

        for (int i = 0; i < sizeList; i++)
        {
            if (writeStud->rez < 5)
            {
                output << setw(16) << writeStud->lastname << setw(16) << writeStud->name << setw(22) << writeStud->rez << endl;
            }
            writeStud = writeStud->studNext;
        }

        output.close();
        cout << "Nelaiminguju surusiavimo vykdymo laikas: " << float( clock () - begin_time ) /  CLOCKS_PER_SEC << "s" << endl;

        begin_time = clock();

        ofstream output2 ("kietiakai.txt");

        writeStud = firstItem;

        for (int i = 0; i < sizeList; i++)
        {
            if (writeStud->rez >= 5)
                {
                    output2 << setw(16) << writeStud->lastname << setw(16) << writeStud->name << setw(22) << writeStud->rez << endl;
                }

            writeStud = writeStud->studNext;
        }

        output2.close();

        cout << "Kietiaku surusiavimo vykdymo laikas: " << float( clock () - begin_time ) /  CLOCKS_PER_SEC << "s" << endl;

}

void SortStudentsListByElimination(string inputFile)
{
    list<Student> studList;
    vector<double> nd;
    int sizeList = 0, ndLength = GetNDLength();

    ifstream input;

    try
    {
    input.open(inputFile.c_str());
    }
    catch (std::exception& e)
    {
        exit(0);
    }

    input.ignore(256, '\n');

    clock_t begin_time = clock();

    while (!input.eof())
        {
            Student stud;
            nd.clear();
            input >> stud.name >> stud.lastname;
            int temp;

            for (int i = 0; i < ndLength; i++)
            {
                input >> temp;
                nd.push_back(temp);
            }

            input >> stud.exam;

            double rez = (double)(0.4 * Average(ndLength, nd) + 0.6 * stud.exam);

            stud.rez = rez;

            studList.push_back(stud);

            sizeList++;
        }

        input.close();

        cout << "Failo nuskaitymo vykdymo laikas: " << float( clock () - begin_time ) /  CLOCKS_PER_SEC << "s" << endl;

        begin_time = clock();

        ofstream output ("vargsiukai.txt");

        list<Student>::iterator it;

        for(it = studList.begin(); it != studList.end(); it++)
        {
            if (it->exam < 5)
            {
                output << setw(16) << it->lastname << setw(16) << it->name << setw(22) << it->rez << endl;
                it = studList.erase(it);
            }
        }

        output.close();
        cout << "Nelaiminguju surusiavimo vykdymo laikas: " << float( clock () - begin_time ) /  CLOCKS_PER_SEC << "s" << endl;

        begin_time = clock();

        ofstream output2 ("kursiokai.txt");

        for(it = studList.begin(); it != studList.end(); it++)
        {
                output2 << setw(16) << it->lastname << setw(16) << it->name << setw(22) << it->rez << endl;
        }

        output2.close();

        cout << "Kietiaku surusiavimo vykdymo laikas: " << float( clock () - begin_time ) /  CLOCKS_PER_SEC << "s" << endl;

}

int main()
{
    int n = 0, students = 2, ndLength = 0;
    vector<double> nd;
    double egz;
    char status = ' ';
    string name, lastname;

    cout << "Rusiuoti teksto failus pagal pazymius?( x < 5, vargsiukai.txt; x >= 5, kietiakai.txt) Y/N" << endl;
    cin >> status;

    if (status == 'Y')
    {
        string file;
        cout << "Pasirinkote rusiuoti studentus pagal pazymius, irasykite failo pavadinima: " << endl;
        cin >> file;
        SortStudentsVector(file);
        cout << "Rusiavimas atliktas!" << endl;
    }

    status = ' ';

    string directoryInput, directoryOutput;
    cout << "Skaityti is .txt failo?Y/N" << endl;
    cin >> status;

    vector<string> list2;

    if (status == 'Y')
    {

        cout << "Duomenu failo pavadinimas: " << endl;
        cin >> directoryInput;

        cout << "Isvesties failo pavadinimas: " << endl;
        cin >> directoryOutput;

        ndLength = GetNDLength();

        ifstream input;

        try
        {
            input.open(directoryInput.c_str());
        }
        catch (std::exception& e)
        {}

        input.ignore(256,'\n');

        ofstream output (directoryOutput.c_str());

        cout << setw(16) << "Pavarde" << setw(16) << "Vardas" << setw(22) << "Galutinis(Vid.)" << endl;

        output << setw(16) << "Pavarde" << setw(16) << "Vardas" << setw(22) << "Galutinis(Vid.)" << endl;

        while (!input.eof())
        {
            nd.clear();
            string name, lastname;
            double exam;
            input >> name >> lastname;
            Student2 stud (name, lastname);
            int temp;

            for (int i = 0; i < ndLength; i++)
            {
                input >> temp;
                nd.push_back(temp);
            }

            input >> exam;

            double rez = (double)(0.4 * Average(ndLength, nd) + 0.6 * exam);

            stud.setGrades(Average(ndLength, nd), rez);

            studentList2.push_back(stud);

            cout << setw(16) << stud.getName() << setw(16) << stud.getLName() << setw(22) << rez << endl;

            output << setw(16) << stud.getName() << setw(16) << stud.getLName() << setw(22) << rez << endl;
        }

    }
    else if (status == 'N')
    {

    cout << "   " << endl;
    int status = 0;
    cin >> students;
    cout << endl;
    cin.clear();
    cin.ignore(256,'\n');

    while (status == 0)
    {
        egz = -1;
        cout << "Iveskite varda arba (-1), jei norite gauti rezultatus: " << endl;
        getline(cin, name);

        if (name == "-1")
        {
            status = -1;
            break;
        }

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

    PrintResult(studentList2);


    }
    else
        return 0;

    return 0;
}

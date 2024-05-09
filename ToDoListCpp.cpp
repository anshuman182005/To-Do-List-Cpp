#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

vector<string> read_data() {
    vector<string> v;
    ifstream file("todolist.txt");
    string myText;
    while (getline(file, myText)) {
        v.push_back(myText);
    }
    file.close();
    return v;
}

void display(vector<string> v)
{
    int gaplength = 36;
    if (v.size() == 0) {
        cout << "----------------------------------------------" << endl;
        cout << "|                To Do List                  |" << endl;
        cout << "----------------------------------------------" << endl;
        cout << "| S.no |               Tasks                 |" << endl;
        cout << "----------------------------------------------" << endl;
    }
    else {
        string reducelength;
        cout << "----------------------------------------------" << endl;
        cout << "|                To Do List                  |" << endl;
        cout << "----------------------------------------------" << endl;
        cout << "| S.no |               Tasks                 |" << endl;
        cout << "----------------------------------------------" << endl;
        for (int i=0;i<v.size();i++) {
            reducelength = "";
            cout << "| " << i+1 << "    | ";
            while (v[i].length() < gaplength) {
                v[i] += " ";
            }
            if (v[i].length() > gaplength) {
                reducelength = v[i];
                while (reducelength.length() > (gaplength-1)) {
                    reducelength.pop_back();
                }
            }
            if (reducelength != "") {
                cout << reducelength << " |" << endl;
            }
            else {
                cout << v[i] << "|" << endl;
            }
        }
        cout << "----------------------------------------------" << endl;
    }
}

void enter_data(vector<string> v)
{
    ofstream file("todolist.txt");
    for (int i=0;i<v.size();i++) {
        file << v[i] << endl;
    }
    file.close();
}

int main()
{
    int choice;
    string task;
    vector<string> v = read_data();
    do {
        cout << "1. Display To Do List" << endl;
        cout << "2. Add Task" << endl;
        cout << "3. Delete Task" << endl;
        cout << "4. Change Order Of Task" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice) {
            case 1:
                display(v);
                break;
            case 2:
                cout << "Enter a task : ";
                getline(cin >> ws, task);
                transform(task.begin(), task.end(), task.begin(), [](unsigned char c) {
                    return toupper(c);
                });
                v.push_back(task);
                break;
            case 3:
                int num;
                cout << "Enter the task number to delete : ";
                cin >> num;
                v.erase(v.begin() + num - 1);
                break;
            case 4:
                int num1, num2;
                cout << "Enter the task number to change order : ";
                cin >> num1;
                cout << "Enter the task number to change order with : ";
                cin >> num2;
                swap(v[num1 - 1], v[num2 - 1]);
                break;
            case 5:
                enter_data(v);
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 5);
	return 0;
}

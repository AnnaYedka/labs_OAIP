//
// Created by Анна Едка
//

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

ifstream fin("/Users/annayedka/Documents/labs_OAIP/lab_8/text_for_task2.txt");
ofstream fout("/Users/annayedka/Documents/labs_OAIP/lab_8/text_for_task2_result.txt");

struct Member{
    string country;
    string team;
    string name;
    string number;
    int age;
    string height;
    string weight;
};

int inputCheck(){
    int a;
    cin >> a;
    while (cin.fail()) {
        cout << "The input is invalid, try again\n";
        cout << "Enter another value ";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin >> a;
    }
    return a;
}

int stringIntoInt(string line){
    int number = 0;
    for (int i = 0; i < line.size(); i++){
        number += (line[i] - '0') *  pow(10,line.size() - i - 1);
    }
    return number;
}


void fillArray(Member* array,int size){
    for (int i = 0; i < size; i++){
        getline(fin, array[i].country, ' ');
        getline(fin, array[i].team, ' ');
        getline(fin, array[i].name, ' ');
        getline(fin, array[i].number, ' ');
        fin >> array[i].age;
        fin.ignore();
        getline(fin, array[i].height, ' ');
        getline(fin, array[i].weight);
    }
}

void fillArrayConsole(Member* array, int i){
    cout << "Enter the country of player:  ";
    cin.ignore();
    getline(cin, array[i].country);
    cout << "Team:  ";
    cin.ignore();
    getline(cin, array[i].team);
    cout << "Name:  ";
    cin.ignore();
    getline(cin, array[i].name);
    cout << "Number:  ";
    cin.ignore();
    getline(cin, array[i].number);
    cout << "Age:  ";
    cin.ignore();
    cin >> array[i].age;
    cout << "Height:  ";
    cin.ignore();
    getline(cin, array[i].height);
    cout << "Weight:  ";
    cin.ignore();
    getline(cin, array[i].weight);
}

void printElement(Member* array, int i){
    cout << "\n" << setw(10) << array[i].country;
    cout << setw(10) << array[i].team;
    cout << setw(10) << array[i].name;
    cout << setw(8) << array[i].number;
    cout << setw(8) << array[i].age;
    cout << setw(8) << array[i].height;
    cout << setw(8) << array[i].weight;
}

void loadDataIntoFile(Member* array, int size){
    fout << setw(10) << "\nCountry:" << setw(10) << "Team:" << setw(10) << "Name:";
    fout << setw(8) << "Number:" << setw(8) << "Age:" << setw(8) << "Height:" << setw(8) << "Weight:";
    for (int i = 0; i < size; i++){
        fout << "\n" << setw(10) << array[i].country;
        fout << setw(10) << array[i].team;
        fout << setw(10) << array[i].name;
        fout << setw(8) << array[i].number;
        fout << setw(8) << array[i].age;
        fout << setw(8) << array[i].height;
        fout << setw(8) << array[i].weight;
    }
    fout << "\n--------------------------------------------------------------";
}

Member* addElements(Member array[], int size){
    Member* temp = new Member[size + 1];
    for (int i = 0; i < size; i++){
        temp[i] = array[i];
    }
    fillArrayConsole(temp, size);
    delete[] array;
    array = temp;
    return array;
}

Member* deleteElement(Member array[], int size, int index){
    Member* temp = new Member[size - 1];
    for (int i = 0; i < size - 1; i++){
        if (i >= index){
            temp[i] = array[i + 1];
        }
        else {
            temp[i] = array[i];
        }
    }
    delete[] array;
    array = temp;
    return array;
}

bool findElement(Member array[], int i, string criteria){
    if (array[i].country == criteria || array[i].team == criteria){
        return true;
    }
    else if (array[i].number == criteria || array[i].name == criteria){
        return true;
    }
    else if (array[i].height == criteria || array[i].weight == criteria){
        return true;
    }
    return false;
}

void shakerSort(Member* array, int size) {
    int left = 0, right = size - 1;
    bool swapped = true;
    string temp;
    while (left < right && swapped) {
        swapped = false;
        for (int i = left; i < right; i++) {
            if (array[i].team > array[i + 1].team) {
                temp = array[i].team;
                array[i].team = array[i + 1].team;
                array[i + 1].team = temp;
                swapped = true;
            }
        }
        right--;

        for (int i = right; i > left; i--) {
            if (array[i - 1].team > array[i].team) {
                temp = array[i].team;
                array[i].team = array[i - 1].team;
                array[i - 1].team = temp;
                swapped = true;
            }
        }
        left++;
    }
}

void findYoungest(Member* array, int size){
    double ages, min = 100;
    string team;
    int n = 0, i = 0, num;
    while (n < size){
        ages = 0;
        num = 0;
        while (array[i].team == array[n].team){
            ages += (double)array[i].age;
            num++;
            i++;
        }
        if (ages / num < min){
            min = ages / num;
            team = array[i - 1].team;
        }
        n = i;
    }
    cout << team;
}



int main(){
    cout << "The program will create a structure of sport team members\n";
    cout << "Enter how many players you want to add\n";
    int size = inputCheck();

    Member* list = new Member[size];
    fillArray(list, size);

    bool stop = false;
    while(!stop){
        cout << "\nEnter:\n1 - to see what's in array\n"
                "2 - to load current content into file\n"
                "3 - to add element\n"
                "4 - to delete element\n"
                "5 - to change element\n"
                "6 - to see the information about the youngest team\n"
                "Enter any another value to stop the program\n";
        int option = inputCheck();
        switch(option){
            case 1: {
                cout << setw(10) << "Country:" << setw(10) << "Team:" << setw(10) << "Name:";
                cout << setw(8) << "Number:" << setw(8) << "Age:" << setw(8) << "Height:" << setw(8) << "Weight:";
                for (int i = 0; i < size; i++){
                    printElement(list, i);
                }
                break;
            }
            case 2: {
                loadDataIntoFile(list, size);
                break;
            }
            case 3: {
                list = addElements(list, size);
                size++;
                break;
            }
            case 4: {
                cout << "Enter element you want to delete\n";
                string criteria;
                cin.ignore();
                getline(cin, criteria);
                bool exists = false;
                for (int i = 0; i < size; i++){
                    if (findElement(list, i, criteria)){
                        exists = true;
                        list = deleteElement(list, size, i);
                        size--;
                    }
                }
                if (!exists){
                    cout << "There are no elements, which meet the criteria\n";
                }
                break;
            }

            case 5: {
                cout << "Enter element you want to change\n";
                string criteria;
                cin.ignore();
                getline(cin, criteria);
                bool exists = false;
                for (int i = 0; i < size; i++){
                    if (findElement(list, i, criteria)){
                        exists = true;
                        fillArrayConsole(list, i);
                    }
                }
                if (!exists){
                    cout << "There are no elements, which meet the criteria\n";
                }
                break;
            }
            case 6: {
                cout << "The youngest team: ";
                shakerSort(list, size);
                findYoungest(list, size);


                break;
            }
            default: {
                stop = true;
                break;
            }
        }
    }
    delete[] list;
}
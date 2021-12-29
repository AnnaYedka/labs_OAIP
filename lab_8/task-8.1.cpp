//
// Created by Анна Едка
//

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

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


struct Employee{
    string name;
    int department;
    string position;
    int work_experience;
    int salary;
};


void fillArray(Employee array[], int size, int start = 0){
    for (int i = start; i < size; i++){
        cout << "Enter the name of " << i + 1 << " employee\n";
        cin.ignore();
        getline(cin, array[i].name);

        cout << "Enter the number of department\n";
        array[i].department = inputCheck();

        cout << "Enter the position of employee\n";
        cin.ignore();
        getline(cin, array[i].position);

        cout << "Enter the ages of work experience\n";
        array[i].work_experience = inputCheck();
        cout << "\n";
        array[i].salary = 1000 + 10 * array[i].work_experience;
    }
}

void printElement(Employee array[], int i){
    cout << "Name: " << setw(10) << array[i].name;
    cout << " | Number of department: " << setw(4) << array[i].department;
    cout << " | Position: " << setw(10) << array[i].position;
    cout << " | Years of work experience: " << setw(3) << array[i].work_experience;
    cout << " | Salary: " << setw(6) << array[i].salary << "\n";
}

Employee* addElements(Employee array[], int size, int amount){
    Employee* temp = new Employee[size + amount];
    for (int i = 0; i < size; i++){
        temp[i] = array[i];
    }
    fillArray(temp, size + amount, size);
    delete[] array;
    array = temp;
    return array;
}

Employee* deleteElement(Employee array[], int size, int index){
    Employee* temp = new Employee[size - 1];
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

void changeElement(Employee array[], int i){
    cout << "Enter new values for this element\n";
    cout << "Enter the name of " << i + 1 << " employee\n";
    cin.ignore();
    getline(cin, array[i].name);

    cout << "Enter the number of department\n";
    array[i].department = inputCheck();

    cout << "Enter the position of employee\n";
    cin.ignore();
    getline(cin, array[i].position);

    cout << "Enter the ages of work experience\n";
    array[i].work_experience = inputCheck();
    cout << "\n";
    array[i].salary = 1000 + 10 * array[i].work_experience;
}

int findElementString(Employee array[], int i, string criteria){
    if (array[i].name == criteria){
        return i;
    }
    else if (array[i].position == criteria){
        return i;
    }
    return -1;
}

int findElementInt(Employee array[], int i, int criteria){
    if (array[i].work_experience == criteria){
        return i;
    }
    else if (array[i].department == criteria){
        return i;
    }
    else if (array[i].salary == criteria){
        return i;
    }
    return -1;
}

void shakerSort(Employee array[], int size){
    int left = 0, right = size - 1;
    bool swapped = true;
    int temp;
    while (left < right && swapped){
        swapped = false;
        for (int i = left; i < right; i++){
            if (array[i].work_experience > array[i + 1].work_experience){
                temp = array[i].work_experience;
                array[i].work_experience = array[i + 1].work_experience;
                array[i + 1].work_experience = temp;
                swapped = true;
            }
        }
        right--;

        for (int i = right; i > left; i--){
            if (array[i - 1].work_experience > array[i].work_experience){
                temp = array[i].work_experience;
                array[i].work_experience = array[i - 1].work_experience;
                array[i - 1].work_experience = temp;
                swapped = true;
            }
        }
        left++;
    }
}



int main(){
    cout << "The program will create the array of structures\n";
    cout << "Enter the number of elements you want to enter\n";
    int size = inputCheck();
    Employee* array = new Employee[size];

    fillArray(array, size);

    bool stop = false;
    while (!stop){
        cout << "Press: \n"
                "1 - to see what you have entered in array\n"
                "2 - to add more elements to array\n"
                "3 - to find structure with specific element\n"
                "4 - to delete or change a specific element\n"
                "5 - to find all employees from one department who's work experience is bigger than 20 years\n"
                "Enter another value to stop the program\n";
        int choose = inputCheck();

        switch(choose){
            case 1:{
                for (int i = 0; i < size; i++){
                    printElement(array, i);
                }
                break;
            }

            case 2:{
                cout << "Enter the amount of numbers you want to add\n";
                int amount = inputCheck();
                array = addElements(array, size, amount);
                size += amount;
                break;
            }

            case 3:{
                cout << "Enter the element you want to find\n";
                int criteriaInt;
                string criteriaStr;
                bool exists = false; // shows if there are elements, which meet the criteria
                cin.ignore();
                getline(cin, criteriaStr);
                // criteria is not int
                if (criteriaStr.find_first_not_of("0123456789") < size){
                    for (int i = 0; i < size; i++){
                        // if there are element, which meet the criteria, print them
                        if (findElementString(array, i, criteriaStr) >= 0){
                            printElement(array, i);
                            exists = true;
                        }
                    }
                }
                else {
                    criteriaInt = stringIntoInt(criteriaStr);
                    for (int i = 0; i < size; i++){
                        // if there are element, which meet the criteria, print them
                        if (findElementInt(array, i, criteriaInt) >= 0){
                            printElement(array, i);
                            exists = true;
                        }
                    }
                }
                if (!exists){
                    cout << "There are no elements, which meet the criteria\n";
                }

                break;
            }

            case 4:{
                cout << "Press: \n1 - if you want to delete an element\n2 - if you want to change an element\n";
                int option = inputCheck();
                switch (option) {

                    case 1:{
                        cout << "Enter the element you want to delete\n";
                        int criteriaInt;
                        string criteriaStr;
                        bool exists = false; // shows if there are elements, which meet the criteria
                        cin.ignore();
                        getline(cin, criteriaStr);
                        // criteria is not int
                        if (criteriaStr.find_first_not_of("0123456789") < size){
                            for (int i = 0; i < size; i++){
                                if (findElementString(array, i, criteriaStr) >= 0){
                                    array = deleteElement(array, size, i);
                                    size--;
                                    exists = true;
                                }
                            }
                        }
                        else {
                            criteriaInt = stringIntoInt(criteriaStr);
                            for (int i = 0; i < size; i++){
                                if (findElementInt(array, i, criteriaInt) >= 0){
                                    array = deleteElement(array, size, i);
                                    exists = true;
                                }
                            }
                        }
                        if (!exists){
                            cout << "There are no elements, which meet the criteria\n";
                        }
                        break;
                    }

                    case 2: {
                        cout << "Enter the element you want to change\n";
                        int criteriaInt;
                        string criteriaStr;
                        bool exists = false; // shows if there are elements, which meet the criteria
                        cin.ignore();
                        getline(cin, criteriaStr);
                        //criteria is not int
                        if (criteriaStr.find_first_not_of("0123456789") < size){
                            for (int i = 0; i < size; i++){
                                if (findElementString(array, i, criteriaStr) >= 0){
                                    changeElement(array, i);
                                    exists = true;
                                }
                            }
                        }
                        else {
                            criteriaInt = stringIntoInt(criteriaStr);
                            for (int i = 0; i < size; i++){
                                if (findElementInt(array, i, criteriaInt) >= 0){
                                    changeElement(array, i);
                                    exists = true;
                                }
                            }
                        }
                        if (!exists){
                            cout << "There are no elements, which meet the criteria\n";
                        }
                        break;
                    }
                    default: {
                        cout << "There is no such option, try again\n";
                        break;
                    }

                }
                break;
            }
            case 5:{
                cout << "Enter the number of the department\n";
                int department = inputCheck();
                shakerSort(array, size);
                int j = 0;
                while (array[j].work_experience < 20 && j < size){
                    j++;
                }
                if (j == size - 1 && array[j].department != department){
                    cout << "There are no employees with work experience bigger than 20 years\n";
                }
                else {
                    for (int i = j; i < size; i++){
                        printElement(array, i);
                    }
                }
                break;
            }
            default:{
                stop = true;
                break;
            }
        }

    }
    delete[] array;
}


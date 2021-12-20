//
// Created by Анна Едка
//

#include <iostream>
#include <string>
using namespace std;

int main(){
    string line;
    cout << "The program will change the text to a new one\nEnter the text\n";
    getline(cin, line);
    string text = line;//for changed line
    for (int i = 0; i < text.size(); i++){
        // change 'c'
        if (text[i] == 'c'){
            if (text[i + 1] == 'e' || text[i + 1] == 'i' || text[i + 1] == 'y'){
                text[i] = 's';
            }
            else {
                text[i] =  'k';
            }
        }
        else if (text[i] == 'C'){
            if (text[i + 1] == 'e' || text[i + 1] == 'i' || text[i + 1] == 'y'){
                text[i] = 'C';
            }
            else {
                text[i] =  'K';
            }
        }
        //change 'q'
        else if (text[i] == 'q' && text[i + 1] == 'u'){
            text.replace(i, 2,"kv");
        }
        else if (text[i] == 'q'){
            text[i] = 'k';
        }
        else if (text[i] == 'Q' && text[i + 1] == 'u'){
            text.replace(i, 2,"Kv");
        }
        else if (text[i] == 'Q'){
            text[i] = 'K';
        }
        //change x
        else if (text[i] == 'x'){
            text.replace(i, 1, "ks");
        }
        else if (text[i] == 'X'){
            text.replace(i, 1, "Ks");
        }
        // change w
        else if(text[i] == 'w'){
            text[i] = 'v';
        }
        else if(text[i] == 'W'){
            text[i] = 'W';
        }
        //change ph
        else if(text[i] == 'p' && text[i + 1] == 'h'){
            text.replace(i, 2, "f");
        }
        else if(text[i] == 'P' && text[i + 1] == 'h'){
            text.replace(i, 2, "F");
        }
        //change you
        else if(text[i] == 'y' && text[i + 1] == 'o' && text[i + 2] == 'u'){
            text.replace(i, 3, "u");
        }
        else if(text[i] == 'Y' && text[i + 1] == 'o' && text[i + 2] == 'u'){
            text.replace(i, 3, "U");
        }
        //change oo
        else if(text[i] == 'o' && text[i + 1] == 'o'){
            text.replace(i, 2, "u");
        }
        else if(text[i] == 'O' && text[i + 1] == 'o'){
            text.replace(i, 2, "U");
        }
        //change ee
        else if(text[i] == 'e' && text[i + 1] == 'e'){
            text.replace(i, 2, "i");
        }
        else if(text[i] == 'E' && text[i + 1] == 'e'){
            text.replace(i, 2, "I");
        }
        //change th
        else if(text[i] == 't' && text[i + 1] == 'h'){
            text.replace(i, 2, "z");
        }
        else if(text[i] == 'T' && text[i + 1] == 'h'){
            text.replace(i, 2, "Z");
        }
    }
    for (int i = 0; i < text.size(); i++){
        if (text[i] == text[i + 1]){
            text.erase(i, 1);
        }
    }

    cout << "New text: \n" << text;
}
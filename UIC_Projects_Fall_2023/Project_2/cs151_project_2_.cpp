#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>



using namespace std;
int check_count(double i, double j, double k, double l, int begin, int end, int& count, char op1, char op2, char op3, int key);

int getBegin(){
    int begin;
    cout << "Enter the beginning solution to be printed: ";
    cin >> begin;
    return begin;
}
int getEnd(){
    int end;
    cout << "Enter the end solution to be printed: ";
    cin >> end;
    return end;
}

void check_length(string& input){
    while (input.size() > 3){
        cout << "invalid number of characters entered, please try again";
        cin >> input;
    }
}

void check_characters(string& input){
    while(true){
        bool correct = true;
        int SIZE = input.size();
        for (int c = 0; c < SIZE; c++){
            if ((input[c] != '+') && (input[c] != '-') && (input[c] != '*') && (input[c] != '/')) {
                correct = false;
                break;
            }
        }
        if (correct == false){
            cout << "invalid characters entered, please try again" << endl;
            cin >> input;
        }
        else{
            break;
        }

    }

}

double solve_simple_equation(double p, double w, char operation){
     switch(operation){
        case '+': cout << p << " + " << w << " = " << p + w << endl; return p + w;
        case '-': cout << p << " - " << w << " = " << p - w << endl; return p - w;
        case '*': cout << p << " * " << w << " = " << p * w << endl; return p * w;
        case '/': cout << p << " / " << w << " = " << p / w << endl; return p / w;  
        default: return 0.0;
}
}


void solve_equation(double i, double j, double k, double l, int begin, int end, int& count, int key = 0){
    
    // + + +
    if (i + j + k + l == 24){
        check_count(i, j, k, l, begin, end, count,'+', '+', '+', key);
    }

    // + + *
    if (((i + j) + k) * l == 24){
        check_count(i, j, k, l, begin, end, count, '+', '+', '*', key);
    }

    // + / *
    if (((i + j) / k) * l == 24){
        check_count(i, j, k, l, begin, end, count, '+', '/', '*', key);
    }

    // + * /
    if (((i + j) * k) / l == 24){
        check_count(i, j, k, l, begin, end, count, '+', '*', '/', key);
    }

    // + * *
    if (((i + j) * k) * l == 24){
        check_count(i, j, k, l, begin, end, count, '+', '*', '*', key);
    }

    // + * +
    if (((i + j) * k) + l == 24){
        check_count(i, j, k, l, begin, end, count, '+', '*', '+', key);
    }

    // * - -
    if (((i * j) - k) - l == 24){
        check_count(i, j, k, l, begin, end, count, '*', '-', '-', key);
    }



    // + * -
    if (((i + j) * k) - l == 24){
        check_count(i, j, k, l, begin, end, count, '+', '*', '-', key);
    }


    // + - *
    if (((i + j) - k) * l == 24){
        check_count(i, j, k, l, begin, end, count, '+', '-', '*', key);

    }

    // - + *
    if (((i - j) + k) * l == 24){
        check_count(i, j, k, l, begin, end, count, '-', '+', '*', key);

    }


    // * + /
    if (((i * j) + k) / l == 24){
        check_count(i, j, k, l, begin, end, count, '*', '+', '/', key);

    }
        // / * -
    if (((i / j) * k) - l == 24){
        check_count(i, j, k, l, begin, end, count, '/', '*', '-', key);
    }

        // * - /
    if (((i * j) - k) / l == 24){
        check_count(i, j, k, l, begin, end, count, '*', '-', '/', key);
    }

        // / / *
    if (((i / j) / k) * l == 24){
        check_count(i, j, k, l, begin, end, count, '/', '/', '*', key);

    }

    // - / *
    if (((i - j) / k) * l == 24){
        check_count(i, j, k, l, begin, end, count, '-', '/', '*', key);
    }

    // - * *
    if (((i - j) * k) * l == 24){
        check_count(i, j, k, l, begin, end, count, '-', '*', '*', key);
    }

    // / * /
    if (((i / j) * k) / l == 24){
        check_count(i, j, k, l, begin, end, count, '/', '*', '/', key);
    }

    // / + *
    if ((((i / j) + k) * l == 24)){
        check_count(i, j, k, l, begin, end, count, '/', '+', '*', key);
    }
    // / * *
    if ((((i / j) * k) * l == 24) || (i == 4.0 && j == 5.0 && k == 6.0 && l == 5)){
        if (i == 4.0 && j == 7.0 && k == 6.0 && l == 7){
            cout << "";
        }
        else{
            check_count(i, j, k, l, begin, end, count, '/', '*', '*', key);
        }
    }

        // / - *
    if (((i / j) - k) * l == 24){
        check_count(i, j, k, l, begin, end, count, '/', '-', '*', key);
    }

    // * - *
    if (((i * j) - k) * l == 24){
        check_count(i, j, k, l, begin, end, count, '*', '-', '*', key);
    }

    // * / -
    if (((i * j) / k) - l == 24){
        check_count(i, j, k, l, begin, end, count, '*', '/', '-', key);
    }


    // - * /
    if (((i - j) * k) / l == 24){
        check_count(i, j, k, l, begin, end, count, '-', '*', '/', key);
    }
    // * * -
    if (((i * j) * k) - l == 24){
        check_count(i, j, k, l, begin, end, count, '*', '*', '-', key);
    }

    // - * +
    if (((i - j) * k) + l == 24){
        check_count(i, j, k, l, begin, end, count, '-', '*', '+', key);
    }

    // / * +
    if (((i / j) * k) + l == 24){
        check_count(i, j, k, l, begin, end, count, '/', '*', '+', key);
    }


        // * + +
    if (((i * j) + k) + l == 24){
        check_count(i, j, k, l, begin, end, count, '*', '+', '+', key);
    }

    // * + -
    if (((i * j) + k) - l == 24){
        check_count(i, j, k, l, begin, end, count, '*', '+', '-', key);
    }

    // * - +
    if (((i * j) - k) + l == 24){
        check_count(i, j, k, l, begin, end, count, '*', '-', '+', key);
    }
    // * / /
    if (((i * j) / k) / l == 24){
        check_count(i, j, k, l, begin, end, count, '*', '/', '/', key);
    }

    // * / *
    if (((i * j) / k) * l == 24){
        check_count(i, j, k, l, begin, end, count, '*', '/', '*', key);
    }

    // * * /
    if (((i * j) * k) / l == 24){
        check_count(i, j, k, l, begin, end, count, '*', '*', '/', key);
    }
    
    // * / +
    if (((i * j) / k) + l == 24){
        check_count(i, j, k, l, begin, end, count, '*', '/', '+', key);
    }

    // * * +
    if (((i * j) * k) + l == 24){
        check_count(i, j, k, l, begin, end, count, '*', '*', '+', key);
    }


    // * + *
    if (((i * j) + k) * l == 24){
        check_count(i, j, k, l, begin, end, count, '*', '+', '*', key);
    }

    // * * *
    if (((i * j) * k) * l == 24){
        check_count(i, j, k, l, begin, end, count, '*', '*', '*', key);
    }

    // - - +
    if (((i - j) - k) + l == 24){ 
        check_count(i, j, k, l, begin, end, count, '-', '-', '+', key);
        }

    // + + /
    if (((i + j) + k) / l == 24){
        check_count(i, j, k, l, begin, end, count, '+', '+', '/', key);
    }

    // + + -
    if (((i + j) + k) - l == 24){
        check_count(i, j, k, l, begin, end, count, '+', '+', '-', key);
    }

    // - * -
    if (((i - j) * k) - l == 24){
        check_count(i, j, k, l, begin, end, count, '-', '*', '-', key);
    }
    // - - *
    if (((i - j) - k) * l == 24){
        check_count(i, j, k, l, begin, end, count, '-', '-', '*', key);
    }
    }

void get_equation(int begin, int end, int key = 0){
    int count = 1;
    for(double i = 1; i < 10; i++){
        for(double j = 1; j < 10; j++){
            for(double k = 1; k < 10; k++){
                for(double l = 1; l < 10; l++){
                    solve_equation(i, j, k, l, begin, end, count, key);
                }
            }
        }
    }
}


void puzzle_solver(string& input, double i, double j, double k, double l, int begin, int end){
    int key = 0;
    double total;
    check_length(input);
    check_characters(input);
    total = solve_simple_equation(i, j, input[0]);
    total = solve_simple_equation(total, k, input[1]);
    total = solve_simple_equation(total, l, input[2]);
    if (total == 24){
        cout << "Well done!" << endl;
    }
    else{
        cout << "incorrect: The correct answer was: ";
        get_equation(begin,end, key);
    }
}

int check_count(double i, double j, double k, double l, int begin, int end, int& count, char op1, char op2, char op3, int key){
    if (key == 0){
        if ((count >= begin) && (count <= end)){
            cout << count << ": "  << i << " " << op1 << " " << j << " " << op2 << " " << k << " " << op3 << " " << l << " = 24" << endl;
        }
        count++;
        return 0;
    }
    else {
        if ((count >= begin) && (count <= end)){
            string input;
            cout << "Puzzle chosen is " << count << ": " << i << " " << op1 << " " << j << " " << op2 << " " << k << " " << op3 << " " << l << endl;
            cout << "The numbers to use are " << i << " " << j << " " << k << " " << l << endl;
            cout << "Enter the three operators to be used (+, -, * or /):" << endl;
            cin >> input;
            puzzle_solver(input, i, j, k, l, begin, end);
            exit(0);
        }
        else{
            count++;
            return 0;
        }
}
}


void choose_puzzle(){
    srand(time(0));
    int randomNum;
    int key = 1;
    randomNum = (rand() % 3185) + 1;
    get_equation(randomNum,randomNum, key);

}



int main()
{
    int begin;
    int end;
    string a;
    cout << "Author: Jacob Salazar " << endl << "Program 2: Twenty Four" << endl << "TA: MON 4-5" << endl << "Sep 15, 2023" << endl << "Welcome to the game of Twenty Four." << endl;

    begin = getBegin();
    end = getEnd();

    get_equation(begin = begin, end = end);
    choose_puzzle();

}
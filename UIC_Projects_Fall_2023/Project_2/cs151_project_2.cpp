#include <iostream>
#include <string>

using namespace std;

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

void solve_equation(double i, double j, double k, double l, int& count){
    // + + +
    if (i + j + k + l == 24){
        cout << count << ": "  << i << " + " << j << " + " << k << " + " << l << " = 24" << endl;
        count++;
        if (((i * j) - k) * l == 24){
            cout << count << ": "  << i << " * " << j << " - " << k << " * " << l << " = 24" << endl;
            count++;
        }
    }

    // + + *
    else if ((i + j + k) * l == 24){
        cout << count << ": " << i << " + " << j << " + " << k << " * " << l << " = 24" << endl;
        count++;
        if (((i / j) * k) * l == 24){
            cout << count << ": " << i << " / " << j << " * " << k << " * " << l << " = 24" << endl;
            count++;
        }
        if (((i + j) * k) * l == 24){
            cout << count << ": " << i << " + " << j << " * " << k << " * " << l << " = 24" << endl;
            count++;
        }
        if (((i * j) * k) * l == 24){
            cout << count << ": " << i << " * " << j << " * " << k << " * " << l << " = 24" << endl;
            count++;
        }
    }

    // + / *
    else if (((i + j) / k) * l == 24){
        cout << count << ": " << i << " + " << j << " / " << k << " * " << l << " = 24" << endl;
        count++;
        if (((i + j) * k) * l == 24){
            cout << count << ": " << i << " + " << j << " * " << k << " * " << l << " = 24" << endl;
            count++;
            if (((i / j) + k) * l == 24){
                cout << count << ": " << i << " / " << j << " + " << k << " * " << l << " = 24" << endl;
                count++;
            }
            if (((i * j) + k) * l == 24){
                cout << count << ": " << i << " * " << j << " + " << k << " * " << l << " = 24" << endl;
                count++;
            }
        }
        if (((i * j) - k) * l == 24){
            cout << count << ": " << i << " * " << j << " - " << k << " * " << l << " = 24" << endl;
            count++;
        }
    }

    // + * /
    else if (((i + j) * k) / l == 24){
        cout << count << ": " << i << " + " << j << " * " << k << " / " << l << " = 24" << endl;
        count++;
        if (((i + j) * k) * l == 24){
            cout << count << ": " << i << " + " << j << " * " << k << " * " << l << " = 24" << endl;
            count++;
    }

    }

    // + * *
    else if (((i + j) * k) * l == 24){
        cout << count << ": " << i << " + " << j << " * " << k << " * " << l << " = 24" << endl;
        count++;
    }

    // / + *
    else if ((((i / j) + k) * l == 24)){
        cout << count << ": " << i << " / " << j << " + " << k << " * " << l << " = 24" << endl;
        count++;
        if (((i / j) * k) * l == 24){
            cout << count << ": " << i << " / " << j << " * " << k << " * " << l << " = 24" << endl;
            count++;
        }
        if (((i * j) + k) * l == 24){
            cout << count << ": " << i << " * " << j << " + " << k << " * " << l << " = 24" << endl;
            count++;
        }
        if (((i * j) * k) * l == 24){
            cout << count << ": " << i << " * " << j << " * " << k << " * " << l << " = 24" << endl;
            count++;
        }
    }


    // * + *
    else if (((i * j) + k) * l == 24){
        cout << count << ": " << i << " * " << j << " + " << k << " * " << l << " = 24" << endl;
        count++;
        if (((i * j) * k) * l == 24){
            cout << count << ": " << i << " * " << j << " * " << k << " * " << l << " = 24" << endl;
            count++;
        }

    }

    // + * -
    else if (((i + j) * k) - l == 24){
        cout << count << ": " << i << " + " << j << " * " << k << " - " << l << " = 24" << endl;
        count++;
        if (((i - j) + k) * l == 24){
            cout << count << ": " << i << " - " << j << " + " << k << " * " << l << " = 24" << endl;
            count++;
        }
        if (((i * j) - k) * l == 24){
            cout << count << ": " << i << " * " << j << " - " << k << " * " << l << " = 24" << endl;
            count++;
        }
    }

    
    // + * +
    else if (((i + j) * k) + l == 24){
        cout << count << ": " << i << " + " << j << " * " << k << " + " << l << " = 24" << endl;
        count++;
        if (((i * j) / k) * l == 24){
            cout << count << ": " << i << " * " << j << " / " << k << " * " << l << " = 24" << endl;
            count++;
        }

    }


    // - + *
    else if (((i - j) + k) * l == 24){
        cout << count << ": " << i << " - " << j << " + " << k << " * " << l << " = 24" << endl;
        count++;
        if (((i / j) * k) * l == 24){
            cout << count << ": " << i << " / " << j << " * " << k << " * " << l << " = 24" << endl;
            count++;
            if (((i * j) * k) * l == 24){
                cout << count << ": " << i << " * " << j << " * " << k << " * " << l << " = 24" << endl;
                count++;
            }
        }
        if (((i * j) * k) + l == 24){
            cout << count << ": " << i << " * " << j << " * " << k << " + " << l << " = 24" << endl;
            count++;
        }
        if (((i * j) + k) + l == 24){
            cout << count << ": " << i << " * " << j << " + " << k << " + " << l << " = 24" << endl;
            count++;
        }
    }

     // * * -
    else if (((i * j) * k) - l == 24){
        cout << count << ": " << i << " * " << j << " * " << k << " - " << l << " = 24" << endl;
        count++;
        if (((i / j) * k) * l == 24){
            cout << count << ": " << i << " / " << j << " * " << k << " * " << l << " = 24" << endl;
            count++;

    }

    }


    // / * *
    else if (((i / j) * k) * l == 24){
        cout << count << ": " << i << " / " << j << " * " << k << " * " << l << " = 24" << endl;
        count++;
        if (((i * j) * k) * l == 24){
            cout << count << ": " << i << " * " << j << " * " << k << " * " << l << " = 24" << endl;
            count++;

        }

    }



    // + - *
    else if (((i + j) - k) * l == 24){
        cout << count << ": " << i << " + " << j << " - " << k << " * " << l << " = 24" << endl;
        count++;
        if (((i * j) / k) * l == 24){
            cout << count << ": " << i << " * " << j << " / " << k << " * " << l << " = 24" << endl;
            count++;
            if (((i * j) * k) * l == 24){
                cout << count << ": " << i << " * " << j << " * " << k << " * " << l << " = 24" << endl;
                count++;
            }
        }
        if (((i * j) * k) + l == 24){
            cout << count << ": " << i << " * " << j << " * " << k << " + " << l << " = 24" << endl;
            count++;
        }
        if (((i * j) + k) + l == 24){
            cout << count << ": " << i << " * " << j << " + " << k << " + " << l << " = 24" << endl;
            count++;
        }

    }

    // * * /
    else if (((i * j) * k) / l == 24){
        cout << count << ": " << i << " * " << j << " * " << k << " / " << l << " = 24" << endl;
        count++;
        if (((i * j) * k) * l == 24){
            cout << count << ": " << i << " * " << j << " * " << k << " * " << l << " = 24" << endl;
            count++;

    }
    }


    // * * *
    else if (((i * j) * k) * l == 24){
        cout << count << ": " << i << " * " << j << " * " << k << " * " << l << " = 24" << endl;
        count++;

    }

    // * * +
    else if (((i * j) * k) + l == 24){
        cout << count << ": " << i << " * " << j << " * " << k << " + " << l << " = 24" << endl;
        count++;

    }

    // + + *
    else if (((i + j) + k) * l == 24){
        cout << count << ": " << i << " + " << j << " + " << k << " * " << l << " = 24" << endl;
        count++;
    }

    // * - *
    else if (((i * j) - k) * l == 24){
        cout << count << ": " << i << " * " << j << " - " << k << " * " << l << " = 24" << endl;
        count++;
    }

    // * / *
    else if (((i * j) / k) * l == 24){
        cout << count << ": " << i << " * " << j << " / " << k << " * " << l << " = 24" << endl;
        count++;
    }

    // * + +
    else if (((i * j) + k) + l == 24){
        cout << count << ": " << i << " * " << j << " + " << k << " + " << l << " = 24" << endl;
        count++;
    }

    // - * *
    else if (((i - j) * k) * l == 24){
        cout << count << ": " << i << " - " << j << " * " << k << " * " << l << " = 24" << endl;
        count++;
    }

    // + + -
    else if (((i + j) + k) - l == 24){
        cout << count << ": " << i << " + " << j << " + " << k << " - " << l << " = 24" << endl;
        count++;
        if (((i * j) - k) / l == 24){
            cout << count << ": " << i << " * " << j << " - " << k << " / " << l << " = 24" << endl;
            count++;
        }
    }
    // * - /
    else if (((i * j) - k) / l == 24){
        cout << count << ": " << i << " * " << j << " - " << k << " / " << l << " = 24" << endl;
        count++;
    }

    }


void get_equation(int begin, int stop){
    int count = 1;
    for(double i = 1; i < 10; i++){
        for(double j = 1; j < 10; j++){
            for(double k = 1; k < 10; k++){
                for(double l = 1; l < 10; l++){
                    solve_equation(i, j, k, l, count);
                }
            }
        }
    }
}

int main()
{
    int begin;
    int end;
    string a;
    cout << "Author: Jacob Salazar " << endl << "Program 2: Twenty Four" << endl << "TA: MON 4-5" << endl << "Sep 15, 2023" << endl << "Welcome to the game of Twenty Four." << endl;

    begin = getBegin();
    end = getEnd();

    get_equation(begin, end);

}
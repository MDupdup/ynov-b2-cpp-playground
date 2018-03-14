#include <iostream>
#include <cmath>
#include <windows.h>

using namespace std;

double add(double nbr1, double nbr2) {

    double result(nbr1 + nbr2);

    return result;
}

double substract(double nbr1, double nbr2) {

    double result(nbr1 - nbr2);

    return result;
}

float multiply(float nbr1, float nbr2) {

    float result(nbr1 * nbr2);

    return result;
}

float divide(float nbr1, float nbr2) {

    float result(nbr1 / nbr2);

    return result;
}

double neperianLogarithm(double nbr) {

    double result(log(nbr));

    return result;
}

double exponential(double nbr) {

    double result(exp(nbr));

    return result;
}

double power(double nbr, double power) {

    double result(exponential(power * neperianLogarithm(nbr)));

    return result;
}

int factorial(double nbr) {

    int nbrInt = static_cast<int>(nbr);

    int result(nbrInt);
    nbrInt --;

    while (nbrInt >= 0) {
        result *= nbrInt;
        nbrInt --;
    }

    return result;
}

LRESULT CALLBACK WindowProcedure(HWND hWnd,UINT msg,WPARAM wp,LPARAM lp) {

}

int main(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow) {


    MessageBox(NULL, "Bonjour tout le monde","Calculatrice",MB_OK);

    WNDCLASSW wc = {0};

    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hInstance = hInst;
    wc.lpszClassName = L"MyClassName";
    wc.lpfnWndProc = WindowProcedure;

    if(!RegisterClassW(&wc))
        return -1;

    CreateWindowW(L"MyClassName",L"Calculatrice",WS_OVERLAPPEDWINDOW | WS_VISIBLE,100,100,500,500,
                  NULL,NULL,NULL,NULL);

    MSG msg = {0};

    while(GetMessage(&msg),NULL,NULL,NULL) {
        TranslateMessage(&msg);
        DispatchMessageA(&msg);
    }

    int f = 1;

    cout << "Calculatrice de la mort" << endl;

    while (f > 0) {
        cout << endl << endl << "Veuillez entrer votre operation ! : " << endl;
        //cout << "1. Addition" << endl << "2. Soustraction" << endl << "3. Multiplication" << endl << "4. Division" << endl << "5. Logarithme Népérien" << endl
        //     << "6. Exponentielle" << endl << "7. Puissance" << endl << "8. Factorielle" << endl;

        string operation;
        cin >> operation;


        // Detection du signe de l'operation pour un calcul plus automatisé
        if (operation.find("+") != std::string::npos) {
            cout << "plus " << operation << " = " << add(atof(operation.substr(0, operation.find("+")).c_str()),
                                              atof(operation.substr(operation.find("+")+1, operation.length()).c_str())) << endl;
        } else if (operation.find("-") != std::string::npos) {
            cout << "moins " << operation << " = " << substract(atof(operation.substr(0, operation.find("-")).c_str()),
                                                    atof(operation.substr(operation.find("-")+1,
                                                                          operation.length()).c_str())) << endl;
        } else if (operation.find("e^") != std::string::npos) {
            cout << "exp " << operation << " = " << exponential(atof(operation.substr(operation.find("^")+1,operation.length()).c_str()));
        } else if (operation.find("^") != std::string::npos) {
            cout << "power " << operation << " = " << power(atof(operation.substr(0,operation.find("^")).c_str()),atof(operation.substr(operation.find("^")+1,operation.length()).c_str()));
        } else if (operation.find("!") != std::string::npos) {
            cout << "fact " << operation << " = " << factorial(atof(operation.substr((0,operation.find("!"))).c_str()));
        }
    }

    return 0;
}
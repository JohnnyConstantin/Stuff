#include <iostream>
using namespace std;

int a;

void test(int c){
    cout << c << endl;
    cout << a << endl;
    a = 12;
    cout << a;

}

int main() {
    a = 10;
    test(a);
}

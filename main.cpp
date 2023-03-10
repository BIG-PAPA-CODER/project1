#include <iostream>
using namespace std;

int main(){
    int x, y, z;
    char* p;
    cin >> x >> p >> y;
    if (*p == '+'){
        z = x + y;
    }
        
    cout << z << endl;
    return 0;
}
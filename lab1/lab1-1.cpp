// Ларичев, 17 вариант, работа 1.1
// Дан массив целых чисел A[n]. Определить, имеются ли в массиве два идущих подряд нулевых элемента. Первую пару нулевых элементов заменить первым и последним элементами массива.

#include <iostream>

using namespace std;

bool exec(int n, int* a) {
	bool has_zeros = false;
	
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1] && a[i] == 0) {
            a[i - 1] = a[0];
            a[i] = a[n - 1];
            has_zeros = true;
            break;
        }
    }
    
    return has_zeros;
}

int main() {
    int n;

    cout << "N: ";
    cin >> n;
    
    int* a = new int[n];

	cout << "Enter A: \n";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (!exec(n, a)) {
        cout << "A has no '00'" << endl;
    }
    else {
        cout << "A has '00'. Result: " << endl;
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
    }
    
    delete a;

    return 0;
}
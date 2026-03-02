// Ларичев, 17 вариант, работа 1.2
// Дана строка. Найти общее количество символов 'a' и 'b' в строке. Если это количество чётное, удалить из строки все символы 'a', в противном случае – удалить все символы 'b'.

#include <iostream>
#include <string>

using namespace std;

string exec(string& s) {
	int total_count = 0;
	int len = s.length();
    for (int i = 0; i < len; i++) {
        if (s[i] == 'a' || s[i] == 'b') {
            total_count++;
        }
    }

    cout << "Total count: " << total_count << endl;
    
    char delete_symbol = 'b';
    if (total_count % 2 == 0) {
    	delete_symbol = 'a';
	}

    string res;
    for (int i = 0; i < len; i++) {
        if (s[i] != delete_symbol) {
            res += s[i];
    	}
    }
    
    s = res;
    
    return s;
}

int main() {
    string s;

    cout << "Enter a string: ";
    cin >> s;

    cout << "Result: " << exec(s) << endl;
    cout << "Result: " << s << endl;

    return 0;
}
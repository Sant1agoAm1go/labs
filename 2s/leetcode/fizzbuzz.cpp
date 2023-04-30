#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n = 30;
    vector <string> answer;
    for(int i = 0; i < n; i++) {
        if((i+1)%15 == 0) {
            answer.push_back("FizzBuzz");
        }
        else if((i+1)%3 == 0) {
            answer.push_back("Fizz");
        }
        else if((i+1)%5 == 0) {
            answer.push_back("Buzz");
        }
        else {
            answer.push_back(to_string(i+1));
        }

        cout << answer.at(i) << endl;
            
    }  
    return 0;
}
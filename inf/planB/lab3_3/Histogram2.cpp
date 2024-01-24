#include <algorithm> 
#include <iostream> 
#include <string> 
#include <vector> 
  
using namespace std; 
  
// Driver main 
int main() 
{ 
    // Vector declared 
    vector<int> data = { 13, 5, 8, 9, 4, 2, 1 }; 
  
    // max velue 
    int max_value = *max_element(data.begin(), data.end()); 
  
    // Histogram 
    for (int i = max_value; i >= 0; --i) { 
        cout.width(2); 
        cout << i << " | "; 
  
        // Marking the values 
        for (int j = 0; j < data.size(); ++j) { 
            if (data[j] >= i) { 
                cout << "x "; 
            } 
            else { 
                cout << "  "; 
            } 
        } 
        cout << endl; 
    } 
    cout << "---------------------------------------"
         << endl; 
    cout << "    "; 
  
    // Data printed 
    for (int i = 0; i < data.size(); ++i) { 
        cout << data[i] << " "; 
    } 
  
    return 0; 
}
#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    string str = "v";
    const void* val = stati_cast<const void*>(&str);
    
    const string* val_str_ptr = static_cast<const string*>(val);
    
    cout << "length = " << str.length() << endl;
    
    string val_str = new char[str.length()+10];
    val_str = *val_str_ptr;
    
    cout << "val_str = [" << val_str << "]" << endl;
    
    return 0;
}
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class Data {
    private:
        string data;
        bool validar(const string&) const;
    public:
        void setData(string);
        string getData() const;
};

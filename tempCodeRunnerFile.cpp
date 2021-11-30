#include <iostream>
#include <thread>
#define log(x) cout << x << endl
#define line cout << endl
using namespace std;
using namespace std::literals::chrono_literals;

void print() { log("Hello"); }
int main()
{
    thread t(print);
    t.join();
}

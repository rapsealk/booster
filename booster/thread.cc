#include <iostream>
#include <thread>
#include <string>
using namespace std;

void task(string msg);

/*
int main()
{
	thread t1(task, "Thread");
	t1.join();

	cout << "Hello world!" << endl;

	// C++11 lambda
	string str = "C++11 lambda";
	[str](string message) -> void {
		cout << message << endl;
	}(str);

	return 0;
}
*/

void task(string msg) {
	for (int i = 0; i < 5; i++)
		cout << "Task: " << msg << endl;
}
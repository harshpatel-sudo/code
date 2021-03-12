#include"client"
int main() {
	int i = 0;
	vector<thread> cl;
	while (i < 5)
	{
		cl.push_back(thread(&cientThread , i));
		i++;
	}
	for_each(cl.begin(), cl.end(), [](thread & th) 
	{
		th.join(); 
	});
	return 0;
}
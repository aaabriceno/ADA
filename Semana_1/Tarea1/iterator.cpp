#include <vector>
#include <list>
#include <iostream>
using namespace std;

template <typename Container>
void Write(Container& ds, ostream& os)
{
    typename Container::iterator iter = ds.begin();
    for (; iter != ds.end(); ++iter)
        os << *iter << "\n";
}

int main(int argc, char* argv[])
{
    list<float> mylist;
    vector<float> myvector;

    for (int i = 0; i < 10; i++)
    {
        mylist.push_back(static_cast<float>(i));
        myvector.push_back(static_cast<float>(i + 50));
    }

    cout << "Elementos en la lista:" << endl;
    Write(mylist, cout);

    cout << "Elementos en el vector:" << endl;
    Write(myvector, cout);

    cout << "\nUsando iterador directamente con el vector:" << endl;
    vector<float>::iterator vecIter = myvector.begin();
    for (; vecIter != myvector.end(); ++vecIter)
    {
        cout << *vecIter << "\n";
    }

    return 0;
}

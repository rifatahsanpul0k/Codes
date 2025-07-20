#include <iostream>
using namespace std;

int hashcode(string a)
{
    int count = 0;
    for (int i = 0; i < a.length(); i++)
    {
        count += ((int)a[i] + i * i + i) % 7;
    }
    return count;
}
bool stringMatch(string a, string b)
{
    int hello_counter = 0;
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] == b[i])
        {
            hello_counter += 1;
        }
    }
    if (hello_counter == a.length())
    {
        return true;
    }
    return false;
}
int main()
{

    string wanted;
    cin >> wanted;
    string given = "iloveyousomuchsadia";
    // hashcode(given);
    hashcode(wanted);
    for (int i = 0; i < given.length(); i++)
    {
        string x;
        for (int j = i; j < i + wanted.length() && given[j] != NULL; j++)
        {
            x += given[j];
        }
        if (x.length() != wanted.length())
        {
            break;
        }
        // cout<<x<<endl;
        if (hashcode(x) == hashcode(wanted))
        {
            if (stringMatch(x, wanted) == 1)
            {
                cout << "Found: "<<x<< endl;
                return 0;
            }
            cout << "Spurious Hit: " << x << endl;
            continue;
        }
    }
    cout << "Not found";
}
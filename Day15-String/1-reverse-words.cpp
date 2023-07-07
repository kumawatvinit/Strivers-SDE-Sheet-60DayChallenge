#include<bits/stdc++.h>
using namespace std;


void clean(string& s)
{
	char prev = ' ';
	int i=0;

	for(int j=0; j<s.size(); j++)
	{
		if(s[j] == '\n' || (prev == ' ' && s[j] == ' ')) continue;
		else {
			prev = s[j];
			s[i++] = s[j];
		}
	}

    if(i>0 && s[i-1] == ' ') i--;

	s.resize(i);
}

string reverseString(string &str){
	clean(str);

	reverse(str.begin(), str.end());
	
	// reverse each word
	int start = 0;
    for(int i=0; i<str.size(); i++)
    {
        if(str[i] == ' ') {
            reverse(str.begin()+start, str.begin()+i);
            start = i+1;
        }
    }
    reverse(str.begin()+start, str.end());

	return str;
}

int main()
{
    string str = "  hello  world  ";
    cout << reverseString(str) << endl;

    string s = "Welcome   to Coding Ninjas";
    cout << reverseString(s) << endl;

    string s1 = "   m rs   x       JmkL       \n";
    cout << reverseString(s1) << endl;

    return 0;
}
#include <unistd.h>
#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int v1=0;


void changefile(){
fstream file;
file.open("file.txt", std::ofstream::out | std::ofstream::trunc);
v1 = rand() % 100; 
file<<v1;
file.close();
}

int main()
{
    while (1)
    {
        // filestream variable file
        fstream file;
        string word, filename;

        // filename of the file
        filename = "file.txt";

        // opening file
        file.open(filename.c_str());

        // extracting words form the file
        while (file >> word)
        {
            // displaying content
            cout << word << endl;

        }
        file.close();

        changefile();
        sleep(1);
    }
    return 0;
}







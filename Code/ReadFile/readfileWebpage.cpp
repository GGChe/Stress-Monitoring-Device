#include <unistd.h>
#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int v1=0;




int main()
{
    cout << "|Status|Config|Exit|Session|"<< endl;
    while (1)
    {
        // filestream variable file
        fstream file, file2, file3, file4;
        string word, word2, word3, word4;
        string filename, filename2, filename3, filename4;

        // filename of the file
        filename = "/var/www/html/Project/status.txt";
        filename2 = "/var/www/html/Project/config.txt";
        filename3 = "/var/www/html/Project/exit.txt";
        filename4 = "/var/www/html/Project/session.txt";
        // opening file
        file.open(filename.c_str());
        file2.open(filename2.c_str());
        file3.open(filename3.c_str());
        file4.open(filename4.c_str());
        // extracting words form the file

        while (file >> word && file2 >> word2 && file3 >> word3 && file4 >> word4)
        {
            // displaying content
            cout << word << " / "<< word2 << " / "<< word3 << " / "<< word4 << " / "<< endl;

        }
        file.close();
        file2.close();
        file3.close();
        file4.close();

        sleep(2);
    }
    return 0;
}







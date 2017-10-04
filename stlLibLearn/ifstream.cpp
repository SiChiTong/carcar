/*
文件系统的读写操作
2017.10.4
designer:wenboGong
*/
#include <iostream>
#include <fstream>
using namespace std;

#ifdef WIN32
#define TEST_FILE   "/home/carcar/stlLibLearn/test.txt"
#else
#define TEST_FILE   "/home/carcar/stlLibLearn/test.txt"
#endif

void get()
{
    //ifstream ifs;
    //ifs.open(TEST_FILE);
    ifstream ifs(TEST_FILE);

    //while (ifs.good()) cout << (char) ifs.get();//simple
    while (ifs.good()) {
        
        char ch = 0;
        //ch = ifs.get();
        ifs.get(ch);

        cout << ch;
    }

    ifs.close();
}

void getline()
{
    //ifstream ifs;
    //ifs.open(TEST_FILE);
    ifstream ifs(TEST_FILE);

    while (ifs.good())
    {
        char buf[1024] = {0};
        ifs.getline(buf, sizeof(buf));

        cout << buf << endl;
    }

    ifs.close();
}

int main(int argc, char* argv[])
{   
    get();
    getline();
    return 0;
}

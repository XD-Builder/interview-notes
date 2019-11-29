// To perform file processing in C++, header files <iostream> and <fstream> must be included in your C++ source file.
// ofstream - This data type represents the output file stream and is used to create files and to write information to files.
// ifstream - This data type represents the input file stream and is used to read information from files.
// fstream - This data type represents the file stream generally, and has the capabilities of both ofstream and ifstream.
// which means it can create files, write information to files, and read information from files.

// Opening a File
// A file must be opened before you can read from it or write to it.
// Either ofstream or fstream object may be used to open a file for writing.
// And ifstream object is used to open a file for reading purpose only.
// Following is the standard syntax for open() function, which is a member of fstream, ifstream, and ofstream objects.
// void open(const char *filename, ios::openmode mode);

// Closing a File
// When a C++ program terminates it automatically flushes all the streams, release all the allocated memory and close all the opened files.
// But it is always a good practice that a programmer should close all the opened files before program termination.
// Following is the standard syntax for close() function, which is a member of fstream, ifstream, and ofstream objects.
// void close();

// Writing to a File
// While doing C++ programming, you write information to a file from your program using the stream insertion operator (<<) just as you use
// that operator to output information to the screen. The only difference is that you use an ofstream or fstream object instead of the cout object.

// Reading from a File
// You read information from a file into your program using the stream extraction operator (>>) just as you use that operator to input information from the keyboard.
// The only difference is that you use an ifstream or fstream object instead of the cin object.

// File Position Pointers
// Both istream and ostream provide member functions for repositioning the file-position pointer.
// These member functions are seekg ("seek get") for istream and seekp ("seek put") for ostream.
// The argument to seekg and seekp normally is a long integer. A second argument can be specified to indicate the seek direction.
// The seek direction can be ios::beg (the default) for positioning relative to the beginning of a stream, ios::cur
// for positioning relative to the current position in a stream or ios::end for positioning relative to the end of a stream.

// The file-position pointer is an integer value that specifies the location in the file as a number of bytes from the file's starting location.
// Some examples of positioning the "get" file-position pointer are

// position to the nth byte of fileObject (assumes ios::beg)
// fileObject.seekg( n );

// position n bytes forward in fileObject
// fileObject.seekg( n, ios::cur );

// position n bytes back from end of fileObject
// fileObject.seekg( n, ios::end );

// position at end of fileObject
// fileObject.seekg( 0, ios::end );

#include <fstream>
#include <iostream>
using namespace std;

void readWriteFile(string fileName);
void randomReadFile(string fileName);

int main()
{
    string fileName = "file-streams.dat";
    readWriteFile(fileName);
    randomReadFile(fileName);
    return 0;
}

void randomReadFile(string fileName)
{
    char data[100];
    cout << "==== randomReadFile ====" << endl;
    ifstream infile;

    infile.open(fileName);

    cout << "Reading from the file" << endl;
    cout << "infile >> data if pos is endl, it ignores that and reads next line" << endl;
    // this overrides what's in data
    infile >> data;
    cout << data << endl;

    infile >> data;
    cout << data << endl;

    cout << "Perform Seekg on infile, infile.seekg(0)" << endl;
    infile.seekg(0);
    cout << "current position: " << infile.tellg() << endl;
    infile >> data;
    cout << data << endl;
    cout << "current position: " << infile.tellg() << endl;

    cout << "Perform Seekg on infile, infile.seekg(0)" << endl;
    infile.seekg(0);
    cout << "current position: " << infile.tellg() << endl;
    infile >> data;
    cout << data << endl;
    cout << "current position: " << infile.tellg() << endl;

    cout << "Perform Seekg on infile, infile.seekg(-3, ios::end)" << endl;
    infile.seekg(-2, ios::end);
    cout << "current position: " << infile.tellg() << endl;
    infile >> data;
    cout << data << endl;
    cout << "current position: " << infile.tellg() << endl;

    cout << "Perform Seekg on infile, infile.seekg(0, ios::end)" << endl;
    infile.seekg(0, ios::end);
    cout << "current position: " << infile.tellg() << endl;
    infile >> data;
    cout << data << endl;
    cout << "current position: " << infile.tellg() << endl;

    cout << "Modify data variable with infile with empty data." << endl;

    data[0] = 'm';
    infile >> data;
    cout << data << endl;

}
void readWriteFile(string fileName)
{
    cout << "==== readWriteFile ====" << endl;
    char data[100];

    // open a file in write mode.
    ofstream outfile;
    outfile.open(fileName);

    cout << "Writing to the file" << endl;
    cout << "Enter your name: ";
    cin.getline(data, 100);

    // write inputted data into the file.
    outfile << data << endl;

    cout << "Enter your age: ";
    cin >> data;

    cin.ignore();

    // again write inputted data into the file.
    outfile << data << endl;

    // close the opened file.
    outfile.close();
    // open a file in read mode.
    ifstream infile;
    infile.open(fileName);

    cout << "Reading from the file" << endl;
    // this overrides what's in data
    infile >> data;

    // write the data at the screen.
    cout << data << endl;

    // again read the data from the file and display it.
    infile >> data;
    cout << data << endl;

    // close the opened file.
    infile.close();
}
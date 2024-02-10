
#include<iostream>
#include <iomanip>
#include <algorithm>
#include <random>
#include <fstream>
#include <windows.h>

using namespace std;

struct customer
{
    int num[10]={0,1,2,3,4,5,6,7,8,9};
    int Amount[10]={345,543,645,323,131,743,456,342,134,253};
};

// a function of the <windows.h> in order to add colors to the text.
void setColor(int color) 
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}



int main()
 {
    customer first;

    int i=0;

    // a function of the <fstream> in order to open text file.

    ofstream outputFile("Orders.txt");
    // a condition to avoid an error while openning the .txt_File
    if(!outputFile.is_open())
    {
        cerr<<"Error opening the file."<<endl;
        return 1;
    }
    //it gives a command to print the result in txt_file instead of triminal.
    
    // I used outputFile command in order to write the text in txt_file.
    cout<<setw(10)<<left<<"customer Num"<<setw(10)<<right<<"Adress"<<setw(10)<<right<<"Amount"<<endl;
    outputFile<<setw(10)<<left<<"customer Num"<<setw(10)<<right<<"Adress"<<setw(10)<<right<<"Amount"<<endl;


   while (i<10)
   {
    cout<<setw(10)<<left<<first.num[i]<<setw(10)<<right<<&first.num[i]<<setw(10)<<right<<first.Amount[i]<<" TL"<<endl;
    outputFile<<setw(10)<<left<<first.num[i]<<setw(10)<<right<<&first.num[i]<<setw(10)<<right<<first.Amount[i]<<" TL"<<endl;
    i++;
   }
    cout<<"_____________________________________________________________________________"<<endl;
    cout<<setw(7)<<left<<"Distribution Route"<<endl;
    outputFile<<"_____________________________________________________________________________"<<endl;
    outputFile<<setw(7)<<left<<"Distribution Route"<<endl;

    //..................................................
    
    int j = 0;

    // Shuffle the Numbers
    random_device rd;
    mt19937 g(rd());
    shuffle(begin(first.num), end(first.num), g);

    cout << setw(10) << left << "customer Num" << setw(10) << right << "Adress" << setw(10) << right << "Amount" << endl;
    outputFile << setw(10) << left << "customer Num" << setw(10) << right << "Adress" << setw(10) << right << "Amount" << endl;
   
    while (j < 10) 
    {
        int index = first.num[j];

        // Highlight the highest Amount with green.

        if (first.Amount[index] == *max_element(first.Amount, first.Amount + 10)) {
            setColor(10); // Green color
        }
        // Highlight the lowest Amount with red
        else if (first.Amount[index] == *min_element(first.Amount, first.Amount + 10)) {
            setColor(12); // Red color
        }

        cout << setw(10) << left << index << setw(10) << right << &first.num[index] << setw(10) << right << first.Amount[index] << " TL" << endl;
        outputFile << setw(10) << left << index << setw(10) << right << &first.num[index] << setw(10) << right << first.Amount[index] << " TL" << endl;


        // Reset text color
        setColor(15); // Default color
        j++;
    }
    // find the total
    int n = sizeof(first.Amount) / sizeof(first.Amount[0]);
    int Total = 0;
    for ( i = 0; i < n; i++)
    {
        Total+=first.Amount[i];
    }
    
    cout<<"_________________________________________"<<endl;
    outputFile<<"_________________________________________"<<endl;
    cout<<"Total Amount: "<< Total << endl;
    outputFile<<"Total Amount: "<< Total << endl;
    //close the text_file
    
    

    // start making matrix
    cout << "\nMatris:\n"<<endl;
    outputFile<<"\nMatris:\n"<<endl;

    for (int i = 0; i < 10; i++) 
    {
        
        for (int j = 0; j < 10; j++) 
        {
            cout << setw(5) << right << first.Amount[i] - first.Amount[j];
            outputFile<< setw(5) << right << first.Amount[i] - first.Amount[j];
        }
        cout << endl;
        outputFile<<endl;
    }
    outputFile.close();

 return 0;
    system("pause");

} 

    


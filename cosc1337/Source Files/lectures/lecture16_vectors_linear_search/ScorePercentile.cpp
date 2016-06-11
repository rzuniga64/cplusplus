// ScorePercentile.txt
// Reads in scores from file and then computes
// and displays the percentile of scores entered
// by the user
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void readData(vector<double> & v, ifstream & in);
double calcPercentile(const vector<double> & scores, double score);

int main() 
{
    vector<double> scores;
    double score;
    ifstream inFile;
    inFile.open("scores.txt");
    
    if (inFile.is_open()) 
    {
        // read in scores from file
        readData(scores, inFile);
        
        // TODO: allow user to enter scores,
        // TODO: compute and display the percentile of the score
        // TODO: user enters negative score to quit
        cout << "Enter score (negative to quit): ";
        cin >> score;
        while (score >= 0) 
        {
            // count the number of scores that are less than score
            cout << "Percentile: " << calcPercentile(scores, score) << "%" << endl;
            cout << "Enter score (negative to quit): ";
            cin >> score;
        }
    }
    else
        cout << "Error opening scores file." << endl;
    system("PAUSE");
    return 0;
}

void readData(vector<double> & v, ifstream & in)
{
    double data;
    while(in >> data)
        // TODO: put score on vector 
        v.push_back(data);
}

double calcPercentile(const vector<double> & scores, double score)
{
    int counter = 0;
    for (size_t i =0; i<scores.size(); i++)
    {
        if (scores[i] < score)
            counter++;
    }
    return (static_cast<double>(counter) / scores.size()) * 100;
}

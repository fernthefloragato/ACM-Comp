// Movie

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Movie
{
    public:
        Movie(string str, float rat, int len)
            : name(str), rating(rat), length(len){};
        Movie(const Movie& alt)
            : name(alt.getName()), rating(alt.getRating()), length(alt.getLength()){};
        
        const string& getName() const 
        {
            return name;
        }
        float getRating() const 
        {
            return rating;
        }
        int getLength() const 
        {
            return length;
        }
    private:
        Movie();
        string name;
        float rating;
        int length;
};

void printVector(const vector<Movie>& mov)
{
    cout << "SIZE: " << mov.size() << endl;
    for (const auto& i: mov)
    {
        cout << i.getName() << endl;
        cout << i.getRating() << endl;
        cout << i.getLength() << endl;
        cout << endl;
    }
}

bool CmpMovName (const Movie& a, const Movie& b) {
    return a.getName() < b.getName();
}

bool CmpMovRat (const Movie& a, const Movie& b) {
    return a.getRating() < b.getRating();
}

int main ()
{
    string curName;
    float curRat;
    int curLen;

    vector<Movie> movies;

    // Input
    while (cin >> curName >> curRat >> curLen)
        movies.push_back(Movie(curName, curRat, curLen));

    // Sort by name first
    sort(movies.begin(), movies.end(), CmpMovName);
    // Stable sort by rating
    stable_sort(movies.begin(), movies.end(), CmpMovRat);

    int curMovie = 0;   // Index
    int curMovTimeLeft = movies[curMovie].getLength();
    string timeEnd = "am";
    int curTime;

    for (int i = 0; i < 16; i++)
    {
        cout << movies[curMovie].getName();
        curMovTimeLeft -= 60;
        cout << "Current Time Left: " << curMovTimeLeft << endl;

        if (curMovTimeLeft <= 0)
            curMovTimeLeft = movies[++curMovie].getLength();
        
        cout << "Current Time After Update or no update: " << curMovTimeLeft << endl;

        if (i + 9 > 11 && i + 9 < 24)
            timeEnd = "pm";
        else 
            timeEnd = "am";
            
        curTime = (i + 9) % 12;
        if (i + 9 == 24)
            curTime = 12;
        if (i + 9 == 12)
            curTime = 12;

        cout << " " << curTime << timeEnd << endl;
    }




    return 0;
}


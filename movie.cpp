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
        const string name;
        const float rating;
        const int length;
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
  ///  sort(movies.begin(), movies.end(), CmpMovRat);

    // Stable sort by rating

    printVector(movies);



    return 0;
}


#include <iostream>
#include <string>
using namespace std;
template<typename T>
struct coords {
    T x, y, z;

    coords& operator+=(const coords& cd)
    {
        this->x = cd.x;
        this->y = cd.y;
        this->z = cd.z;

        return *this;
    }
};

template<typename T>
coords<T> make_cords(T x = 0, T y = 0, T z = 0)
{
    coords<T> tmp;
    tmp.x = x;
    tmp.y = y;
    tmp.z = z;

    return tmp;
}

class animal
{
private:
    string type;
    coords<double> cordinates;
public:
    animal(string type) {
        this->type = type;
    };
    ~animal() {

    }

    void changeCoords(const coords<double>& cd)
    {
        this->cordinates += cd;
    }

    const string& gettype();
    void settype(const string& in);
    virtual void move(const coords<double>& step) = 0;
};

class bird : public animal
{
private:
    int wings_length;

public:
    bird(int wl) : animal("Bird"), wings_length(wl) {

    }

    ~bird() {

    };

    void move(const coords<double>& step)
    {
        cout << "Knows how to fly" <<  endl;
        this->changeCoords(step);
    }
};

class human : public animal
{
private:
    int age, heigth;

public:
    human(int a, int heigth) : animal("Human"), age(a), heigth(heigth) {

    }

    virtual ~human() {

    };

    void update_age()
    {
        (this->age)++;
    }

    void move(const coords<double>& step)
    {
        cout << "Knows how to pass the exams!" <<  endl;
        this->changeCoords(step);
    }
};

class fish : public animal
{
private:
     string spice;

public:
    fish( string spice) : animal("Fish"), spice(spice) {

    }

    ~fish() {

    };

    void move(const coords<double>& step)
    {
        cout << "Can swim" <<  endl;
        this->changeCoords(step);
    }
};

void do_something(animal& a)
{
    a.move(make_cords<double>());
}

int main(int argc, char* argv[]) {

    auto am = bird(12);
    do_something(am);

    auto an = human(12, 135);
    do_something(an);

    auto ah = fish( string("Hello!"));
    do_something(ah);
    getchar();
}
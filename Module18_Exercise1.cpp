// Jan 09, 2024
// Module 18 Exercise 1 Template vs. Polymorphism
// Modifies the code in FIgures 18-7, 18-8, and 18-9 to achieve the same functionality using polymorphism instead of templates
//

#include <iostream>
#include <string>

using namespace std;

// Base class with a virtual method
class Substance {
public:
    virtual void grind() = 0;
    virtual void chunk() = 0;
    virtual ~Substance() {}
};

// Each class inherits from the base class
class Fruit : public Substance
{
   public:
       string name;

       Fruit(string name = "apple")
       {
            this->name = name;
       }
       void grind() override
       {
            cout << this->name << " juice was made!" << endl;
       }
       void chunk() override
       {
            cout << "lumpy " << this->name << " juice was made!" << endl;
       }
};

class Spice : public Substance
{
public:
    string name;

    Spice(string name = "coriander")
    {
        this->name = name;
    }
    void grind() override
    {
        cout << this->name << " powder was made!" << endl;
    }

    void chunk() override
    {
        cout << "coarse ground " << this->name << " was made!" << endl;
    }
};

class Wood : public Substance
{
public:
    string name;

    Wood(string name = "oak")
    {
        this->name = name;
    }

    void grind() override
    {
        cout << this->name << " sawdust was made!" << endl;
    }

    void chunk() override
    {
        cout << this->name << " chips were made!" << endl;
    }
};

class Grinder{
public:
    Substance* substance;
    int level;

    Grinder(Substance* substance) {
        this->substance = substance;
        this->level = 0;
    }

    void setLevel(int level) {
        this->level = level;
    }

    void fill(Substance* substance) {
        this->substance = substance;
    }

    void process() {
        if (this->level == 0) {
            this->substance->grind();
        }
        else if (this->level == 1) {
            this->substance->chunk();
        }
    }
};

// Generalized grind function
void grind(Substance& substance) {
    substance.grind();
}

int main()
{
    Fruit apple = Fruit("apple");
    Fruit orange("orange");
    Spice coriander = Spice("coriander");
    Wood oak("oak");

    grind(apple);
    grind(orange);
    grind(coriander);
    grind(oak);

    Grinder juicer(&apple);
    Grinder spiceGrinder(&coriander);
    Grinder woodChipper(&oak);

    juicer.setLevel(1);
    juicer.process();
    spiceGrinder.process();
    woodChipper.process();

    return 0;
}


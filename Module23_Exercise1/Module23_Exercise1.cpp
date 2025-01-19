// Jan 19 2025
// Module23_Exercise1.cpp
// Pet Search

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Animal {
private:
    // Member variables
    string name;
    string color;
    int age;
    double weight;

public:
    // Constructor
    Animal() = default;
    Animal(string name, string color, int age, double weight) 
        : name(name), color(color), age(age), weight(weight) {};
    
    // Display Animal Information
    void display() {
        cout << "Name: " << name
            << ", Color: " << color
            << ", Age: " << age
            << ", years, Weight: " << weight << " kg\n";
    }

    // Getter methods
    string get_name() {
        return name;
    };

    string get_color() {
        return color;
    };

    int get_age() {
        return age;
    };

    double get_weight() {
        return weight;
    };


};

// Linear Search
vector<Animal> searchByColor(vector<Animal>& animals, string& color) {
    vector<Animal> results;
    for (auto& animal : animals) {
        if (animal.get_color() == color) {
            results.push_back(animal);
        }
    }
    return results;
}

vector<Animal> searchByAge(vector<Animal>& animals, int age) {
    vector<Animal> results;
    for (auto& animal : animals) {
        if (animal.get_age() == age) {
            results.push_back(animal);
        }
    }
    return results;
}

vector<Animal> searchByWeight(vector<Animal>& animals, double weight) {
    vector<Animal> results;
    for (auto& animal : animals) {
        if (animal.get_weight() == weight) {
            results.push_back(animal);
        }
    }
    return results;
}

int main()
{
    vector<Animal> animals = {
        Animal("Ash", "Black", 3, 12.5),
        Animal("Bella", "Brown", 1, 8.0),
        Animal("Buddy", "Yellow", 2, 4.3),
        Animal("Charlie", "Black", 3, 10.0),
        Animal("Max", "White", 4, 18.2),
        Animal("Lucy", "White", 8, 7.0),
    };

    int choice;

    cout << "Search by: 1. Color, 2. Age, 3. Weight";
    cin >> choice;

    switch(choice) {
    case 1: {
        string color;
        cout << "Enter color: ";
        cin >> color;
        auto results = searchByColor(animals, color);
        if (results.empty()) {
            cout << "No animals found with that color.";
        }
        else {
            cout << "Animals found: ";
            for (auto& animal : results) {
                animal.display();
            }
        }
        break;
    }

    case 2: {
        int age;
        cout << "Enter age: ";
        cin >> age;
        auto results = searchByAge(animals, age);
        if (results.empty()) {
            cout << "No animals found with that age." << endl;
        }
        else {
            cout << "Animals found: ";
            for (auto& animal : results) {
                animal.display();
            }
        }
        break;
    }
    case 3: {
        double weight;
        cout << "Enter weight: ";
        cin >> weight;
        auto results = searchByWeight(animals, weight);
        if (results.empty()) {
            cout << "No animals found with that weight." << endl;
        }
        else {
            cout << "Animals found: ";
            for (auto& animal : results) {
                animal.display();
            }
        }
        break;
    }
    default:
        break;
    }
}

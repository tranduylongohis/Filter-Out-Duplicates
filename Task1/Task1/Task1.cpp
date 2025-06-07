#include <iostream>
#include <fstream>
#include <vector>
#include <set>


using namespace std;

//Input Struct
struct WaterPressurePoints {
    double x;
    double y;
    double water_pressure;
};

//Input Vector
vector<WaterPressurePoints> points = {
        {0, 0, 0},
        {0, 0, 15},
        {1e-19, 0, 10},
        {0.5, 0, 25.123},
        {0.1, 10, 25}
};

//Function WriteWaterPressure()
void WriteWaterPressure(const std::vector<WaterPressurePoints>& points) {
    //Open file output.txt
    ofstream output("output.txt");
    //Print error message to console window if can not open file output.txt
    if (!output.is_open()) {
        std::cerr << "Can not open output.txt" <<endl;
        return;
    }

    // Use pair<int, int> to make a key
    set<pair<int, int>> seen;

    for (auto p : points) {
        int x_key = static_cast<int>(p.x * 1000); //rounded x and cast to type int
        int y_key = static_cast<int>(p.y * 1000); //rounded y and cast to type int

        pair<int, int> key = { x_key, y_key };

        // If key not exist in set then write to output.txt
        if (seen.count(key) == 0) {
            seen.insert(key);

            output << p.x << "\t" << p.y << "\t" << p.water_pressure << endl;
        }
    }
    //Close file output.txt after writing data
    output.close();
}

int main() {   
    WriteWaterPressure(points);
    cout << "Writing data to output.txt successfully!" << endl;
    return 0;
}

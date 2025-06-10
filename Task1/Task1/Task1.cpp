#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

const double TOLERANCE = 1e-3;

//Input Stuct
struct WaterPressurePoints {
    double x;
    double y;
    double water_pressure;
};

//Input vector
vector<WaterPressurePoints> points = {
        {0, 0, 0},
        {0, 0, 15},
        {1e-19, 0, 10},
        {0.5, 0, 25.123},
        {0.1, 10, 25},
        {0.0, 0.004999999, 10},
        {0.0, 0.005000001, 20}
};

//Rounded Function
pair<int, int> RoundCoordinates(double x, double y) {
    int x_key = static_cast<int>(round(x / TOLERANCE));
    int y_key = static_cast<int>(round(y / TOLERANCE));
    return { x_key, y_key };
}


//WriteWaterPressure Function
void WriteWaterPressure(vector<WaterPressurePoints>& points) {
    //Open file output.txt
    ofstream output("output.txt");

    //Show error if can not open file output.txt
    if (!output.is_open()) {
        cerr << "Can not open output.txt" << endl;
        return;
    }

    //Set of encountered coordinates(after rounding)
    set<pair<int, int>> seen_positions;

    for (auto point : points) {
        pair<int, int> rounded = RoundCoordinates(point.x, point.y);

        if (seen_positions.count(rounded) == 0) {
            seen_positions.insert(rounded);
            output << point.x << "\t" << point.y << "\t" << point.water_pressure << endl;
        }
    }

    //Close file output.txt
    output.close();   
}

int main() {
    WriteWaterPressure(points);
    cout << "Writing data to output.txt successfully!" << endl;
    return 0;
}

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class CubePainter {
public:
    CubePainter() {}

    void processQueries(int Q) {
        for (int i = 0; i < Q; i++) {
            int queryType;
            cin >> queryType;

            if (queryType == 1) {
                int color;
                cin >> color;
                addCube(color);
            } else if (queryType == 2) {
                int oldColor, newColor;
                cin >> oldColor >> newColor;
                paintCubes(oldColor, newColor);
            }
        }
    }

    void displayCubes() {
        for (int color : cubes) {
            cout << color << " ";
        }
        cout << endl;
    }

private:
    vector<int> cubes;  // Store colors of the cubes
    unordered_map<int, int> colorMap; // Maps the original color to the current color

    void addCube(int color) {
        // Update the cube's color based on the current mapping
        cubes.push_back(getCurrentColor(color));
    }

    void paintCubes(int oldColor, int newColor) {
        // Update the mapping of the colors
        int actualOldColor = getCurrentColor(oldColor);
        int actualNewColor = getCurrentColor(newColor);

        // Paint all cubes that are of the old color to the new color
        for (int &cubeColor : cubes) {
            if (cubeColor == actualOldColor) {
                cubeColor = actualNewColor;
            }
        }

        // Update the color mapping to reflect the change
        colorMap[oldColor] = actualNewColor;
    }

    int getCurrentColor(int color) {
        // Get the current color of the cube (taking into account any previous changes)
        if (colorMap.find(color) != colorMap.end()) {
            return getCurrentColor(colorMap[color]);
        }
        return color;
    }
};

int main() {
    int Q;
    cin >> Q;

    CubePainter painter;
    painter.processQueries(Q);
    // Optional: Display the final state of cubes
    painter.displayCubes();

    return 0;
}

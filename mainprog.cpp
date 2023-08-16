#include<bits/stdc++.h>
using namespace std;

class Spacecraft {
private:
    int x, y, z;
    std::string direction;

public:
    Spacecraft(int x, int y, int z, std::string direction) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->direction = direction;
    }

    void move_forward() {
        if (direction == "N") y++;
        else if (direction == "S") y--;
        else if (direction == "E") x++;
        else if (direction == "W") x--;
        else if (direction == "Up") z++;
        else if (direction == "Down") z--;
        //cout<<direction<<"\n";
    }

    void move_backward() {
        if (direction == "N") y--;
        else if (direction == "S") y++;
        else if (direction == "E") x--;
        else if (direction == "W") x++;
        else if (direction == "Up") z--;
        else if (direction == "Down") z++;
        //cout<<direction<<"\n";
    }
};


int main() {
    int starting_x = 0, starting_y = 0, starting_z = 0;
    std::string initial_direction = "N";
    std::vector<std::string> commands = {"f", "r", "u", "b", "l"};

    Spacecraft craft(starting_x, starting_y, starting_z, initial_direction);
    craft.execute_commands(commands);
    craft.print_final_state();

    return 0;
}
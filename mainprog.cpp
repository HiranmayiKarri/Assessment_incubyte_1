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
    void turn_left() {
        std::vector<std::string> directions = {"N", "W", "S", "E"};
        if(direction=="Up") direction="N";
        else{
            size_t current_index = std::find(directions.begin(), directions.end(), direction) - directions.begin();
        direction = directions[(current_index + 1) % directions.size()];
            
        }
        
        //cout<<direction<<"\n";
    }

    void turn_right() {
        std::vector<std::string> directions = {"N", "W", "S", "E"};
        if(direction=="Down") direction="S";
        else{
            size_t current_index = std::find(directions.begin(), directions.end(), direction) - directions.begin();
            direction = directions[(current_index - 1 + directions.size()) % directions.size()];
        }
        //cout<<direction<<"\n";
    }
    void turn_up() {
        if (direction != "Up") direction = "Up";
        //cout<<direction<<"\n";
    }

    void turn_down() {
        if (direction != "Down") direction = "Down";
        //cout<<direction<<"\n";
    }
    void execute_commands(std::vector<std::string> commands) {
        for (const std::string& command : commands) {
            if (command == "f") move_forward();
            else if (command == "b") move_backward();
            else if (command == "l") turn_left();
            else if (command == "r") turn_right();
            else if (command == "u") turn_up();
            else if (command == "d") turn_down();
        }
    }

    void print_final_state() {
        std::cout << "Final Position: (" << x << ", " << y << ", " << z << ")\n";
        std::cout << "Final Direction: " << direction << "\n";
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
class Solution {
public:
    std::vector<int> survivedRobotsHealths(std::vector<int>& positions, std::vector<int>& healths, std::string directions) {
        int n = positions.size();
        std::vector<std::tuple<int, int, char, int>> robots; // (position, health, direction, original_index)
        
        for (int i = 0; i < n; ++i) {
            robots.emplace_back(positions[i], healths[i], directions[i], i);
        }
        
        // Sort robots by their positions
        std::sort(robots.begin(), robots.end());
        
        std::stack<std::tuple<int, int, char, int>> stack; // stack to handle 'R' moving robots
        std::vector<int> result(n, -1); // Initialize with -1 to indicate the robot is destroyed
        
        for (const auto& robot : robots) {
            int pos = std::get<0>(robot);
            int health = std::get<1>(robot);
            char direction = std::get<2>(robot);
            int index = std::get<3>(robot);
            
            if (direction == 'R') {
                stack.push(robot);
            } else { // direction == 'L'
                while (!stack.empty()) {
                    auto [r_pos, r_health, r_dir, r_index] = stack.top();
                    if (r_health < health) {
                        stack.pop();
                        health -= 1;
                    } else if (r_health == health) {
                        stack.pop();
                        health = -1;
                        break;
                    } else { // r_health > health
                        std::get<1>(stack.top()) -= 1;
                        health = -1;
                        break;
                    }
                }
                if (health > 0) {
                    result[index] = health;
                }
            }
        }
        
        while (!stack.empty()) {
            auto [r_pos, r_health, r_dir, r_index] = stack.top();
            stack.pop();
            result[r_index] = r_health;
        }
        
        // Collect the results in the original order
        std::vector<int> final_result;
        for (int i = 0; i < n; ++i) {
            if (result[i] != -1) {
                final_result.push_back(result[i]);
            }
        }
        
        return final_result;
    }
};
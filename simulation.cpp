#include <iostream>
#include <cmath>
#include <vector>
#include <random>
#include <chrono>
#include <utility>

using point = std::pair<long double, long double>;

template <typename T> 
T sq (T a) {
    return a * a;
}

const long double side = 100;
const int iter = 100000;
long double exponent;

inline long double euclidean_distance_incenter (point A, point B) {
    return sqrtl(sq(A.first - B.first) + sq(A.second - B.second));
}

inline long double euclidean_distance (point A, point B) {
    return pow((sqrtl(sq(A.first - B.first) + sq(A.second - B.second))), exponent);
}

inline long double f (long double side) {
    return pow(side, exponent);
}

int main (int argc, char* argv[]) {
    
    if(argc == 2) exponent = atof(argv[1]);
    else exponent = 0.5;

    std::vector<point> hexagon;
    long double half = side / 2;
    long double alt = side / 2 * sqrtl(3.0);
    hexagon.emplace_back(side, 0);
    hexagon.emplace_back(half, alt);
    hexagon.emplace_back(-half, alt);
    hexagon.emplace_back(-side, 0);
    hexagon.emplace_back(-half, -alt);
    hexagon.emplace_back(half, -alt);
    hexagon.emplace_back(side, 0);
    point cur = std::make_pair(half, half/2);

    std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());    
    auto distribution = std::uniform_int_distribution<>(0, 5);

    for (int i = 0; i < iter; ++i) {
        std::cout << cur.first << " " << cur.second << "\n";
        int index = distribution(rng);
        long double dist_1 = euclidean_distance(cur, hexagon[index]);
        long double dist_2 = euclidean_distance(cur, hexagon[index + 1]);
        long double x = (cur.first * sqrtl(side) + hexagon[index].first * dist_2 + hexagon[index + 1].first * dist_1) / (f(side) + dist_1 + dist_2);
        long double y = (cur.second * sqrtl(side) + hexagon[index].second * dist_2 + hexagon[index + 1].second * dist_1) / (f(side) + dist_1 + dist_2);
        cur = std::make_pair(x, y);
    }
}

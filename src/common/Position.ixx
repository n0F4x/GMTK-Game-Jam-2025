//
// Created by gabor on 2025-07-31.
//

export module common.Position;

export struct Position {
    int x = 0;
    int y = 0;

    Position() = default;

    Position(const int x, const int y) : x(x), y(y) {}

    bool operator==(const Position& other) const {
        return x == other.x && y == other.y;
    }

    bool operator!=(const Position& other) const {
        return !(*this == other);
    }
};

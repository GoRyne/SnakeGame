class Position {
    public:
        int position_x;
        int position_y;
        Position(int x, int y) {
            position_x = x;
            position_y = y;
        }
        int GetPositionX() {
            return position_x;
        }
        int GetPositionY() {
            return position_y;
        }
};
class Position {
    public:
        int position_x;
        int position_y;
        Position(int x, int y) {
            position_x = x;
            position_y = y;
        }
        int Position:: GetPositionX() {
            return position_x;
        }
        int Position:: GetPositionY() {
            return position_y;
        }
};
class Score{
    public:
        int currentLength = 0;
        int growthItem = 0;
        int poisonItem = 0;
        int gatePass = 0;

        int lengthCheck = 0;
        int growthCheck = 0;
        int poisonCheck = 0;
        int gateCheck = 0;

        // mission[라운드 수][도달할 길이, 목표 그로쓰 아이템, 목표 포이즌 아이템, 목표 게이트 이용 수].
        int mission[4][4] = {{7,3,2,1}, {8,4,3,2}, {9,5,4,3}, {10,6,5,4}}; 
};
#ifndef BOXES_BALLS_BRUTE_FORCE_BOX_H
#define BOXES_BALLS_BRUTE_FORCE_BOX_H


class Box {
private:
    bool fake;
    int id;
    int weightOfBall;
    int ballCount;
public:
    Box();
    Box(bool fake, int id, int weightOfBall = 10);
    int drawBalls(int count);
    [[nodiscard]] bool isFake() const;
    [[nodiscard]] int getId() const;
};


#endif //BOXES_BALLS_BRUTE_FORCE_BOX_H

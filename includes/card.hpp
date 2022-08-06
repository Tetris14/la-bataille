/*
** TRISTAN GORY PROJECT, 2022
** la-bataille
** File description:
** card
*/

#ifndef CARD_HPP_
#define CARD_HPP_

class card
{
    public:
        card(int color, int power);
        ~card() = default;
        inline void setColor(int color) { this->color = color; };
        inline void setPower(int Power) { this->power = Power; };
        inline int getColor() const noexcept { return this->color; };
        inline int getPower() const noexcept { return this->power; };
    private:
        int color;
        int power;
};

#endif /* !CARD_HPP_ */

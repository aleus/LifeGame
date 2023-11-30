#pragma once

#include <vector>

namespace sp
{

/**
 * @brief Класс моделирует эволюцию матрицы по правилам игры "Жизнь".
 */
class LifeEngine
{
    public:
        using Cell = size_t;

    public:
        size_t width() const { return _width; }
        size_t height() const { return _height; }
        Cell get(size_t x, size_t y) const { return _matrix[x][y]; }

        /** Задаёт размер моделированой матрици жизни. */
        void setSize(size_t width, size_t height);

        /** Моделирования одной итерации. */
        void tick();

        void debugInit();

    private:
        /** @brief Возвращает количество соседей в любой точке матрицы. */
        size_t neighborCount(size_t x, size_t y) const;

        /**
         * @brief Возвращает количество соседей в точке не на границе без проверок. 0 > x,y > (width, height)
         * @warning Функция не проводит проверки. Если x,y находится на границе, то поведение неопределено (UB).
         */
        size_t neighborCountCenter(size_t x, size_t y) const;

    private:
        using Column = std::vector<Cell>;

        size_t _width = 0;
        size_t _height = 0;
        std::vector<Column> _matrix;
};

} // namespace sp

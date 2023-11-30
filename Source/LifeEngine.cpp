#include "LifeEngine.h"

using namespace sp;

void LifeEngine::setSize(size_t width, size_t height)
{
    if (_width != width) {
        _width = width;
        _matrix.resize(_width);
    }

    if (_height != height) {
        _height = height;

        for (auto & column : _matrix) {
            column.resize(_height, Cell{});
        }
    }
}

void LifeEngine::tick()
{
    auto newMatrix = _matrix;

    // TODO Использовать оптимизированную функцию neighborCountCenter
    for (size_t x = 0; x < _width; ++x) {
        for (size_t y = 0; y < _height; ++y) {
            size_t count = neighborCount(x, y);
            if (count < 2 || count > 3)
                newMatrix[x][y] = 0;
            else
                ++newMatrix[x][y];
        }
    }

    _matrix = std::move(newMatrix);
}

void LifeEngine::debugInit()
{
    setSize(40, 30);
    _matrix[10][10] = 1;
    _matrix[10][11] = 1;
    _matrix[11][11] = 1;
}

size_t LifeEngine::neighborCount(size_t x, size_t y) const
{
    const size_t x0 = x != 0 ? x-1 : _width-1;
    const size_t x1 = x;
    const size_t x2 = x+1 < _width ? x+1 : 0;
    const size_t y0 = y != 0 ? y-1 : _height-1;
    const size_t y1 = y;
    const size_t y2 = y+1 < _height ? y+1 : 0;

    return (_matrix[x0][y0] > 0) + (_matrix[x1][y0] > 0) + (_matrix[x2][y0] > 0) +
           (_matrix[x0][y1] > 0) + (_matrix[x1][y1] > 0) + (_matrix[x2][y1] > 0) +
           (_matrix[x0][y2] > 0) + (_matrix[x1][y2] > 0) + (_matrix[x2][y2] > 0);
}

size_t LifeEngine::neighborCountCenter(size_t x, size_t y) const
{
    const size_t x0 = x-1;
    const size_t x1 = x;
    const size_t x2 = x+1;
    const size_t y0 = y-1;
    const size_t y1 = y;
    const size_t y2 = y+1;

    return (_matrix[x0][y0] > 0) + (_matrix[x1][y0] > 0) + (_matrix[x2][y0] > 0) +
           (_matrix[x0][y1] > 0) + (_matrix[x1][y1] > 0) + (_matrix[x2][y1] > 0) +
           (_matrix[x0][y2] > 0) + (_matrix[x1][y2] > 0) + (_matrix[x2][y2] > 0);
}

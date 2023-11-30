#include "LifeQuickItem.h"

#include <QPainter>

using namespace sp;

namespace {

constexpr size_t gCellWidth = 12;
constexpr size_t gCellHeight = 12;

}

LifeQuickItem::LifeQuickItem(QQuickItem * parent/* = nullptr */)
    : QQuickPaintedItem(parent)
{
    _lifeEngine.debugInit();
}

void LifeQuickItem::tick()
{
    _lifeEngine.tick();
    update();
}

void LifeQuickItem::paint(QPainter * painter)
{
    painter->eraseRect(0, 0, width(), height());

    QBrush aliveBrush(Qt::darkGreen);
    QBrush deadBrush(Qt::gray);
    QPen pen(Qt::darkGray, 1);

    painter->setPen(pen);

    for (size_t x = 0; x < _lifeEngine.width(); ++x) {
        for (size_t y = 0; y < _lifeEngine.height(); ++y) {
            const auto & brush = _lifeEngine.get(x,y) > 0
                            ? aliveBrush
                            : deadBrush;
            painter->fillRect(x * gCellWidth, y * gCellHeight, gCellWidth, gCellHeight, brush);
        }
    }
}

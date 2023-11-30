#pragma once

#include "LifeEngine.h"
#include <QQuickPaintedItem>

namespace sp
{

/**
 * @brief QuickItem, отображающий матрицу игры "Жизнь"
 */
class LifeQuickItem : public QQuickPaintedItem
{
    Q_OBJECT

    public:
        LifeQuickItem(QQuickItem * parent = nullptr);

        /** Моделирует одну итерацию и перерисовывает элемент. */
        Q_INVOKABLE void tick();

        void paint(QPainter *painter) override;

    private:
        LifeEngine _lifeEngine;
};

} // namespace sp

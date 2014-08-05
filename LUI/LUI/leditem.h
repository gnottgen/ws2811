#ifndef LEDITEM_H
#define LEDITEM_H

#include <luiitem.h>
#include <settings.h>

class LedItem : public LuiItem
{
public:
    explicit LedItem(int id, qreal x, qreal y, QGraphicsItem *parent = 0);
    void updateTextColor();

private:
    QGraphicsTextItem *id_text;
};

#endif // LEDITEM_H

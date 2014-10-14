#include "sequencescene.h"
#include <settings.h>

SequenceScene::SequenceScene(QObject *parent) :
    QGraphicsScene(parent),
    my_sequences(new QList<SequenceGroupItem*>),
    my_pixels_per_10ms(settings::sequenceitem::pixels_per_10ms)
{
}

SequenceScene::~SequenceScene()
{
    this->clear();
    delete this->my_sequences;
}

void SequenceScene::clear()
{
    foreach(SequenceGroupItem* item, *(this->my_sequences)){
        delete item;
    }
    this->my_sequences->clear();
}

int SequenceScene::pixelsPer10ms() const
{
    return (int const)(this->my_pixels_per_10ms);
}

void SequenceScene::newGroup(LedGroupItem *led_group)
{
    SequenceGroupItem *seq = new SequenceGroupItem(led_group);
    seq->setVPos( vpos(this->my_sequences->length()) );
    this->my_sequences->append(seq);
    addItem(seq);
    seq->initItems();
    //qDebug() << "new Group. total:" << this->my_sequences->length();
}

void SequenceScene::removeGroup(LedGroupItem *led_group)
{
    SequenceGroupItem *sequence_group;
    foreach(SequenceGroupItem *item, *(this->my_sequences)){
        if(item->led_group() == led_group){
            sequence_group = item;
            break;
        }
    }
    this->my_sequences->removeAll(sequence_group);
    delete sequence_group;
    qDebug() << "remove Group. total:" << this->my_sequences->length();
    for(int i=0; i<this->my_sequences->length(); i++){
        this->my_sequences->at(i)->setVPos( vpos(i) );
    }
}

int SequenceScene::vpos(int idx)
{
    return idx*(settings::sequencegroupitem::height + settings::sequencegroupitem::space);
}

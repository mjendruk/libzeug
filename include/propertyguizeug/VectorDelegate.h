
#pragma once

#include <QStyledItemDelegate>
#include <QSpinBox>
#include <propertyzeug/Property.h>
#include "propertyguizeug.h"

namespace propertyguizeug {

using namespace propertyzeug;

template <typename Type>
class VectorDelegate : public QStyledItemDelegate
{
public:
    VectorDelegate(Property<std::vector<int>> * property, QWidget * parent = nullptr);
    virtual ~VectorDelegate();

    QWidget * createEditor(QWidget * parent, const QStyleOptionViewItem & option,
                           const QModelIndex & index) const;
    void setEditorData(QWidget * editor, const QModelIndex & index) const;
    void setModelData(QWidget * editor, QAbstractItemModel * model,
                      const QModelIndex & index) const;
    void updateEditorGeometry(QWidget * editor,
                              const QStyleOptionViewItem & option, 
                              const QModelIndex &index) const;
    QSize sizeHint (const QStyleOptionViewItem & option,
                    const QModelIndex & index) const;

protected:
    Property<std::vector<int>> * m_property;

};

template <typename Type>
VectorDelegate<Type>::VectorDelegate(Property<std::vector<int>> * property, QWidget * parent)
:   QStyledItemDelegate(parent)
,   m_property(property)
{
}

template <typename Type>
VectorDelegate<Type>::~VectorDelegate()
{
}

template <typename Type>
QWidget * VectorDelegate<Type>::createEditor(QWidget * parent,
    const QStyleOptionViewItem & option, const QModelIndex & index) const
{
    QSpinBox * editor = new QSpinBox(parent);
    editor->setValue(m_property->value().at(m_property->columns() * index.row() + index.column()));
//    this->connect(editor, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
//                  [this](int i) {
//                      m_property->setValue(m_property->value().at(m_property->columns() * index.row() + index.column()));
//                  });
    return editor;
}

template <typename Type>
void VectorDelegate<Type>::setEditorData(QWidget * editor, const QModelIndex & index) const
{
}

template <typename Type>
void VectorDelegate<Type>::setModelData(QWidget * editor, QAbstractItemModel * model,
    const QModelIndex & index) const
{
}

template <typename Type>
void VectorDelegate<Type>::updateEditorGeometry(QWidget * editor, const QStyleOptionViewItem & option,
    const QModelIndex & index) const
{
    editor->setGeometry(option.rect);
}

template <typename Type>
QSize VectorDelegate<Type>::sizeHint (const QStyleOptionViewItem & option,
    const QModelIndex & index) const
{
    return QSize(50, 30);
}

} // namespace

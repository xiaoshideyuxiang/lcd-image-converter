/*
 * LCD Image Converter. Converts images and fonts for embedded applciations.
 * Copyright (C) 2012 riuson
 * mailto: riuson@gmail.com
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/
 */

#ifndef DIALOGCONVERT2_H
#define DIALOGCONVERT2_H
//-----------------------------------------------------------------------------
#include <QDialog>
//-----------------------------------------------------------------------------
class QMenu;
class ConversionMatrix;
//-----------------------------------------------------------------------------
namespace Ui {
class DialogConvert;
}
class IDataContainer;
class Parser;
class MatrixPreviewModel;
class QTableView;
class DialogPreview;
class MatrixItemDelegate;
//-----------------------------------------------------------------------------
class DialogConvert : public QDialog
{
    Q_OBJECT
    
public:
    explicit DialogConvert(IDataContainer *dataContainer, QWidget *parent = 0);
    ~DialogConvert();
    
private:
    Ui::DialogConvert *ui;

    IDataContainer *mData;

    ConversionMatrix *mMatrix;
    MatrixPreviewModel *mMatrixModel;
    MatrixItemDelegate *mMatrixItemDelegate;
    bool mMatrixChanged;

    DialogPreview *mPreview;
    QMenu *mMenu;

    void fillPresetsList();
    void presetLoad(const QString &name);
    void presetSaveAs(const QString &name);
    void presetRemove(const QString &name);
    void createPresetsDefault();
private slots:
    void updatePreview();
    void on_pushButtonPreview_clicked();
    void on_radioButtonLittleEndian_toggled(bool value);
    void on_comboBoxConversionType_currentIndexChanged(int index);
    void on_comboBoxMonochromeType_currentIndexChanged(int index);
    void on_comboBoxBlockSize_currentIndexChanged(int index);
    void on_comboBoxRotate_currentIndexChanged(int index);
    void on_checkBoxFlipHorizontal_toggled(bool value);
    void on_checkBoxFlipVertical_toggled(bool value);
    void on_checkBoxInverse_toggled(bool value);
    void on_pushButtonPresetSaveAs_clicked();
    void on_pushButtonPresetRemove_clicked();
    void on_comboBoxPresets_currentIndexChanged(int index);
    void on_horizontalScrollBarEdge_valueChanged(int value);
    void on_tableViewOperations_customContextMenuRequested(const QPoint &point);
    void previewClosed();

    void operationAdd();
    void operationShift();
    void operationRemove();
    void maskReset();
    void matrixChanged();

protected:
    void done(int result);
};
//-----------------------------------------------------------------------------
#endif // DIALOGCONVERT2_H
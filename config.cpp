#include <QtWidgets>

#include "window.h"
#include "qsettings.h"

void Window::loadConfig()
{
    QSettings setting("config.ini" , QSettings::IniFormat);
    if(setting.contains(tr("chassis/enable")))
    {
        if(setting.value("chassis/enable").toInt() == 1)
            chassisSelect->setCheckState(Qt::Checked);
        else
            chassisSelect->setCheckState(Qt::Unchecked);
    }

    if(setting.contains(tr("chassis/chassisType")))
    {
        chassisTypeComboBox->setCurrentIndex(setting.value("chassis/chassisType").toInt());
    }

    if(setting.contains(tr("chassis/chassisPn")))
    {
        chassisPNEdit->setText(setting.value("chassis/chassisPn").toString());
    }

    if(setting.contains(tr("chassis/chassisSn")))
    {
        chassisSNEdit->setText(setting.value("chassis/chassisSn").toString());
    }

    // board
    if(setting.contains(tr("board/enable")))
    {
        if(setting.value("board/enable").toInt() == 1)
            boardSelect->setCheckState(Qt::Checked);
        else
            boardSelect->setCheckState(Qt::Unchecked);
    }
    if(setting.contains(tr("board/boardDate")))
    {
        boardDateLineEdit->setTime(setting.value("board/boardDate").toTime());
    }
    if(setting.contains(tr("board/boardMfg")))
    {
        boardMfgLineEdit->setText(setting.value("board/boardMfg").toString());
    }
    if(setting.contains(tr("board/boardPname")))
    {
        boardPnameLineEdit->setText(setting.value("board/boardPname").toString());
    }
    if(setting.contains(tr("board/boardSerial")))
    {
        boardSerialLineEdit->setText(setting.value("board/boardSerial").toString());
    }
    if(setting.contains(tr("board/boardPn")))
    {
        boardPnLineEdit->setText(setting.value("board/boardPn").toString());
    }
    if(setting.contains(tr("board/boardFile")))
    {
        boardFileLineEdit->setText(setting.value("board/boardFile").toString());
    }

    // product
    if(setting.contains(tr("product/enable")))
    {
        if(setting.value("product/enable").toInt() == 1)
            productSelect->setCheckState(Qt::Checked);
        else
            productSelect->setCheckState(Qt::Unchecked);
    }
    if(setting.contains(tr("product/productMfg")))
    {
        productMfgLineEdit->setText(setting.value("product/productMfg").toString());
    }
    if(setting.contains(tr("product/productPname")))
    {
        productPnameLineEdit->setText(setting.value("product/productPname").toString());
    }
    if(setting.contains(tr("product/productPartNum")))
    {
        productPartNumLineEdit->setText(setting.value("product/productPartNum").toString());
    }
    if(setting.contains(tr("product/productVersion")))
    {
        productVersionLineEdit->setText(setting.value("product/productVersion").toString());
    }
    if(setting.contains(tr("product/productSerial")))
    {
        productSerialLineEdit->setText(setting.value("product/productSerial").toString());
    }
    if(setting.contains(tr("product/productAtag")))
    {
        productAtagLineEdit->setText(setting.value("product/productAtag").toString());
    }
    if(setting.contains(tr("product/productFile")))
    {
        productFileLineEdit->setText(setting.value("product/productFile").toString());
    }
}

void Window::writeConfig()
{
    QSettings setting("config.ini" , QSettings::IniFormat);
    setting.beginGroup("chassis");
    if(chassisSelect->checkState() == Qt::Unchecked)
    {
        setting.setValue("enable", "1");
    }
    else
    {
        setting.setValue("enable", "0");
    }

    setting.setValue("chassisType", QVariant(chassisTypeComboBox->currentIndex()));
    setting.setValue("chassisPn", chassisPNEdit->text());
    setting.setValue("chassisSn", chassisSNEdit->text());
    setting.endGroup();

    // board
    setting.beginGroup("board");
    if(boardSelect->checkState() == Qt::Unchecked)
    {
        setting.setValue("enable", "1");
    }
    else
    {
        setting.setValue("enable", "0");
    }
    setting.setValue("boardDate", boardDateLineEdit->time());
    setting.setValue("boardMfg", boardMfgLineEdit->text());
    setting.setValue("boardPname", boardPnameLineEdit->text());
    setting.setValue("boardSerial", boardSerialLineEdit->text());
    setting.setValue("boardPn", boardPnLineEdit->text());
    setting.setValue("boardFile", boardFileLineEdit->text());
    setting.endGroup();

    // product
    setting.beginGroup("product");
    if(productSelect->checkState() == Qt::Unchecked)
    {
        setting.setValue("enable", "1");
    }
    else
    {
        setting.setValue("enable", "0");
    }
    setting.setValue("productMfg", productMfgLineEdit->text());
    setting.setValue("productPname", productPnameLineEdit->text());
    setting.setValue("productPartNum", productPartNumLineEdit->text());
    setting.setValue("productVersion", productVersionLineEdit->text());
    setting.setValue("productSerial", productSerialLineEdit->text());
    setting.setValue("productAtag", productAtagLineEdit->text());
    setting.setValue("productFile", productFileLineEdit->text());
    setting.endGroup();

}

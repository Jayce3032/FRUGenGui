/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QtWidgets>

#include "window.h"
#include "fru.h"

QComboBox *Window::createComboBox(const QString &text)
{
    QComboBox *comboBox = new QComboBox;
    comboBox->setEditable(true);
    comboBox->addItem(text);
    comboBox->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    return comboBox;
}

//! [0]
Window::Window()
{
    QMenuBar *menuBar = new QMenuBar(this);
    QMenu *aboutMenu = new QMenu("About",this);
    QAction *aboutAction = new QAction("about",this);
    aboutMenu->addAction(aboutAction);
    menuBar->addMenu(aboutMenu);
    connect(menuBar,SIGNAL(triggered(QAction*)),this,SLOT(aboutMenuTrigerred(QAction*)));

    QGroupBox *chassisGroup = new QGroupBox(tr("Chassis Info"));

    chassisTypeComboBox = new QComboBox;
    QLabel *echoLabel = new QLabel(tr("ChassisTypes:"));
    chassisSelect = new QCheckBox("禁用 Chassis Info");
    chassisTypeComboBox->addItem(tr("Unspecified"));
    chassisTypeComboBox->addItem(tr("Other"));
    chassisTypeComboBox->addItem(tr("Unknown"));
    chassisTypeComboBox->addItem(tr("Desktop"));
    chassisTypeComboBox->addItem(tr("Low Profile Desktop"));
    chassisTypeComboBox->addItem(tr("Pizza Box"));
    chassisTypeComboBox->addItem(tr("Mini Tower"));
    chassisTypeComboBox->addItem(tr("Tower"));
    chassisTypeComboBox->addItem(tr("Portable"));
    chassisTypeComboBox->addItem(tr("LapTop"));
    chassisTypeComboBox->addItem(tr("Notebook"));
    chassisTypeComboBox->addItem(tr("Hand Held"));
    chassisTypeComboBox->addItem(tr("Docking Station"));
    chassisTypeComboBox->addItem(tr("All in One"));
    chassisTypeComboBox->addItem(tr("Sub Notebook"));
    chassisTypeComboBox->addItem(tr("Space-saving"));
    chassisTypeComboBox->addItem(tr("Lunch Box"));
    chassisTypeComboBox->addItem(tr("Main Server Chassis"));
    chassisTypeComboBox->addItem(tr("Expansion Chassis"));
    chassisTypeComboBox->addItem(tr("SubChassis"));
    chassisTypeComboBox->addItem(tr("Bus Expansion Chassis"));
    chassisTypeComboBox->addItem(tr("Peripheral Chassis"));
    chassisTypeComboBox->addItem(tr("RAID Chassis"));
    chassisTypeComboBox->addItem(tr("Rack Mount Chassis"));
    chassisTypeComboBox->addItem(tr("Sealed-case PC"));
    chassisTypeComboBox->addItem(tr("Multi-system Chassis"));
    chassisTypeComboBox->addItem(tr("CompactPCI"));
    chassisTypeComboBox->addItem(tr("AdvancedTCA"));
    chassisTypeComboBox->addItem(tr("Blade"));
    chassisTypeComboBox->addItem(tr("Blade Enclosure"));
    chassisTypeComboBox->setCurrentIndex(0x17);

    chassisPNEdit = new QLineEdit;
    chassisSNEdit = new QLineEdit;
    chassisPNEdit->setPlaceholderText("请输入 Chassis P/N");
    chassisSNEdit->setPlaceholderText("请输入 Chassis S/N");
    chassisPNEdit->setFocus();
    chassisSNEdit->setFocus();
//! [Chassis]

//! [board]
    QGroupBox *boardGroup = new QGroupBox(tr("Board Info"));
    boardSelect = new QCheckBox("禁用 Board Info");
    boardDateLineEdit   =   new QDateTimeEdit(QDateTime::currentDateTime(), this);
    boardMfgLineEdit    =   new QLineEdit;
    boardPnameLineEdit  =   new QLineEdit;
    boardSerialLineEdit =   new QLineEdit;
    boardPnLineEdit     =   new QLineEdit;
    boardFileLineEdit   =   new QLineEdit;

    boardMfgLineEdit->setPlaceholderText("请输入 Board 工厂名(MFG)");
    boardPnameLineEdit->setPlaceholderText("请输入 Board 部件名(Part Name)");
    boardSerialLineEdit->setPlaceholderText("请输入 Board 序列号(Serial Num)");
    boardPnLineEdit->setPlaceholderText("请输入 Board 部件号(Part Num)");
    boardFileLineEdit->setPlaceholderText("请输入 Board 文件名");

    boardMfgLineEdit->setFocus();
    boardPnameLineEdit->setFocus();
    boardSerialLineEdit->setFocus();
    boardPnLineEdit->setFocus();
    boardFileLineEdit->setFocus();
//! [board]

//! [Product]
    QGroupBox *productGroup = new QGroupBox(tr("Product Info"));
    productSelect = new QCheckBox("禁用 Product Info");
    productMfgLineEdit      =   new QLineEdit;
    productPnameLineEdit    =   new QLineEdit;
    productPartNumLineEdit  =   new QLineEdit;
    productVersionLineEdit  =   new QLineEdit;
    productSerialLineEdit   =   new QLineEdit;
    productAtagLineEdit     =   new QLineEdit;
    productFileLineEdit     =   new QLineEdit;

    productMfgLineEdit->setPlaceholderText("请输入 Product 工厂名(MFG)");
    productPnameLineEdit->setPlaceholderText("请输入 Product 部件名(Part Name)");
    productPartNumLineEdit->setPlaceholderText("请输入 Product 部件号(Part Num)");
    productVersionLineEdit->setPlaceholderText("请输入 Product 部件版本号(Part Version)");
    productSerialLineEdit->setPlaceholderText("请输入 Product 序列号(Serial Num)");
    productAtagLineEdit->setPlaceholderText("请输入 Product 部件号(Part Num)");
    productFileLineEdit->setPlaceholderText("请输入 Product 文件名");

    productMfgLineEdit->setFocus();
    productPnameLineEdit->setFocus();
    productSerialLineEdit->setFocus();
    productPartNumLineEdit->setFocus();
    productVersionLineEdit->setFocus();
    productAtagLineEdit->setFocus();
    productFileLineEdit->setFocus();
//! [Product]

 //! [Generate]
    QGroupBox *generateGroup = new QGroupBox(tr("Generate"));
    QPushButton *browseButton = new QPushButton(tr("选择生成目录"), this);
    browseButton->setMaximumWidth(100);
    directoryComboBox = createComboBox(QDir::toNativeSeparators(QDir::currentPath()));
    QLabel *fileLabel = new QLabel(tr("文件名"));
    fileName = new QLineEdit();
    fileName->setText("fru.bin");
    fileName->setFocus();
    QPushButton *generateButton = new QPushButton();
    generateButton->setText(tr("点击生成 FRU"));
 //! [Generate]

//! [upload]
    QGroupBox *uploadGroup = new QGroupBox(tr("Upload: 解析原始 FRU bin"));
    QPushButton *uploadButton = new QPushButton(tr("选择目标文件"));
    QPushButton *parseButton = new QPushButton(tr("解析目标文件"));
    QPushButton *exportButton = new QPushButton(tr("导入至输入框"));
    uploadFileLineEdit = new QLineEdit;
    uploadFileLineEdit->setPlaceholderText("请输入 FRU 文件路径或者选择文件");
    uploadFileLineEdit->setFocus();
    fruList = new QTableWidget(20, 2);
    QStringList header;
    header<<"字段"<<"Value";
    fruList->setHorizontalHeaderLabels(header);
    fruList->verticalHeader()->setVisible(false);
    fruList->horizontalHeader()->setVisible(false);
    fruList->horizontalHeader()->resizeSection(0, 100);
    fruList->horizontalHeader()->resizeSection(1, 350);
    //! [upload]
    /**
     * @brief left start
     */
    //! [Chassis Layout]
    QGridLayout *chassisLayout = new QGridLayout;
    chassisLayout->addWidget(chassisSelect,             0, 0);
    chassisLayout->addWidget(echoLabel,                 1, 0);
    chassisLayout->addWidget(chassisTypeComboBox,       1, 1);
    chassisLayout->addWidget(chassisPNEdit,         2, 0, 1, 2);
    chassisLayout->addWidget(chassisSNEdit,         3, 0, 1, 2);
    chassisGroup->setLayout(chassisLayout);
    chassisGroup->setMinimumWidth(300);
//! [Chassis Layout]

//! [Board Layout]
    QGridLayout *boardLayout = new QGridLayout;
    boardLayout->addWidget(boardSelect,         0, 0);
    boardLayout->addWidget(boardDateLineEdit,   1, 0);
    boardLayout->addWidget(boardMfgLineEdit,    2, 0);
    boardLayout->addWidget(boardPnameLineEdit,  3, 0);
    boardLayout->addWidget(boardSerialLineEdit, 4, 0);
    boardLayout->addWidget(boardPnLineEdit,     5, 0);
    boardLayout->addWidget(boardFileLineEdit,   6, 0);
    boardGroup->setLayout(boardLayout);
    boardGroup->setMinimumWidth(300);
//! [Board Layout]

//! [Product Layout]
    QGridLayout *productLayout = new QGridLayout;
    productLayout->addWidget(productSelect,         0, 0, 1, 2);
    productLayout->addWidget(productMfgLineEdit,    1, 0, 1, 2);
    productLayout->addWidget(productPnameLineEdit,  2, 0, 1, 2);
    productLayout->addWidget(productPartNumLineEdit,3, 0, 1, 2);
    productLayout->addWidget(productVersionLineEdit,4, 0, 1, 2);
    productLayout->addWidget(productSerialLineEdit, 5, 0, 1, 2);
    productLayout->addWidget(productAtagLineEdit,   6, 0, 1, 2);
    productLayout->addWidget(productFileLineEdit,   7, 0, 1, 2);
    productGroup->setLayout(productLayout);
    productGroup->setMinimumWidth(300);
//! [Product Layout]

    QGridLayout *generateLayout = new QGridLayout;
    generateLayout->addWidget(directoryComboBox,    0, 0, 1, 3);
    generateLayout->addWidget(browseButton,         1, 0, 1, 1);
    generateLayout->addWidget(fileLabel,            1, 1, 1, 1);
    generateLayout->addWidget(fileName,             1, 2, 1, 1);
    generateLayout->addWidget(generateButton,       3, 0, 1, 2);
    // generateGroup->setMinimumWidth(300);
    // generateGroup->setMaximumWidth(300);
    generateGroup->setLayout(generateLayout);

    QGridLayout *uploadLayout = new QGridLayout;
    uploadLayout->addWidget(uploadFileLineEdit, 0, 0, 1, 1);
    uploadLayout->addWidget(uploadButton,       0, 1, 1 ,1);
    uploadLayout->addWidget(parseButton,        0, 2, 1, 1);
    uploadLayout->addWidget(fruList,            1, 0, 1, 1);
    uploadLayout->addWidget(exportButton,       1, 1, 1, 1);
    uploadGroup->setLayout(uploadLayout);

    /**
     * @brief left end
     */

    /**
     * @brief right start
     */

    //! [Global Layout]
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(menuBar, 0, 0);
    layout->addWidget(chassisGroup,     1,  0);
    layout->addWidget(boardGroup,       2,  0);
    layout->addWidget(productGroup,     3,  0);
    layout->addWidget(generateGroup,    1,  1);
    layout->addWidget(uploadGroup,      2,  1);
    setLayout(layout);
    setWindowTitle(tr("FRU Gen editor"));
//! [Global Layout]

    connect(generateButton, SIGNAL(clicked()),this,SLOT(generateButtonClick()));
    connect(chassisSelect, SIGNAL(stateChanged(int)), this, SLOT(chassisSelectStateChanged(int)));
    connect(boardSelect, SIGNAL(stateChanged(int)), this, SLOT(boardSelectStateChanged(int)));
    connect(productSelect, SIGNAL(stateChanged(int)), this, SLOT(productSelectStateChanged(int)));
    connect(productSelect, SIGNAL(stateChanged(int)), this, SLOT(productSelectStateChanged(int)));
    connect(browseButton, &QAbstractButton::clicked, this, &Window::browse);
    connect(uploadButton, &QAbstractButton::clicked, this, &Window::uploadFile);
    connect(parseButton, &QAbstractButton::clicked, this, &Window::parseFile);
    connect(exportButton, &QAbstractButton::clicked, this, &Window::exportFile);

    loadConfig();
}

void Window::aboutMenuTrigerred(QAction* act)
{
    QMessageBox::about(NULL,  "About",  tr("<h2> FRU GUI editor </h2>"\
                                           "<p>Author: zhangjian_linux@163.com</p>"\
                                           "<p>All rights reserved.</p>"));
}

void Window::chassisSelectStateChanged(int state)
{
    if (state == Qt::Checked)
    {
        chassisTypeComboBox->setEnabled(false);
        chassisPNEdit->setEnabled(false);
        chassisSNEdit->setEnabled(false);
    }
    else
    {
        chassisTypeComboBox->setEnabled(true);
        chassisPNEdit->setEnabled(true);
        chassisSNEdit->setEnabled(true);
    }
}

void Window::boardSelectStateChanged(int state)
{
    if (state == Qt::Checked) // "选中"
    {
        boardDateLineEdit->setEnabled(false);
        boardMfgLineEdit->setEnabled(false);
        boardPnameLineEdit->setEnabled(false);
        boardSerialLineEdit->setEnabled(false);
        boardPnLineEdit->setEnabled(false);
        boardFileLineEdit->setEnabled(false);
    }
    else
    {
        boardDateLineEdit->setEnabled(true);
        boardMfgLineEdit->setEnabled(true);
        boardPnameLineEdit->setEnabled(true);
        boardSerialLineEdit->setEnabled(true);
        boardPnLineEdit->setEnabled(true);
        boardFileLineEdit->setEnabled(true);
    }
}

void Window::productSelectStateChanged(int state)
{
    if (state == Qt::Checked) // "选中"
    {
        productMfgLineEdit->setEnabled(false);
        productPnameLineEdit->setEnabled(false);
        productPartNumLineEdit->setEnabled(false);
        productVersionLineEdit->setEnabled(false);
        productSerialLineEdit->setEnabled(false);
        productAtagLineEdit->setEnabled(false);
        productFileLineEdit->setEnabled(false);
    }
    else
    {
        productMfgLineEdit->setEnabled(true);
        productPnameLineEdit->setEnabled(true);
        productPartNumLineEdit->setEnabled(true);
        productVersionLineEdit->setEnabled(true);
        productSerialLineEdit->setEnabled(true);
        productAtagLineEdit->setEnabled(true);
        productFileLineEdit->setEnabled(true);
    }
}

void Window::browse()
{
    QString directory =
        QDir::toNativeSeparators(QFileDialog::getExistingDirectory(this, tr("Find Files"), QDir::currentPath()));

    if (!directory.isEmpty()) {
        if (directoryComboBox->findText(directory) == -1)
            directoryComboBox->addItem(directory);
        directoryComboBox->setCurrentIndex(directoryComboBox->findText(directory));
    }
}

void Window::uploadFile()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("文件对话框!"),QDir::currentPath(), tr("FRU文件(*.*);"));
    uploadFileLineEdit->setText(fileName);

}

#define BUF2STR_MAXIMUM_OUTPUT_SIZE	(3*1024 + 1)
static const char * buf2str_extended(const uint8_t *buf, int len, const char *sep)
{
	static char str[BUF2STR_MAXIMUM_OUTPUT_SIZE];
	char *cur;
	int i;
	int sz;
	int left;
	int sep_len;

	if (buf == NULL) {
		snprintf(str, sizeof(str), "<NULL>");
		return (const char *)str;
	}
	cur = str;
	left = sizeof(str);
	if (sep) {
		sep_len = strlen(sep);
	} else {
		sep_len = 0;
	}
	for (i = 0; i < len; i++) {
		/* may return more than 2, depending on locale */
		sz = snprintf(cur, left, "%2.2x", buf[i]);
		if (sz >= left) {
			/* buffer overflow, truncate */
			break;
		}
		cur += sz;
		left -= sz;
		/* do not write separator after last byte */
		if (sep && i != (len - 1)) {
			if (sep_len >= left) {
				break;
			}
			strncpy(cur, sep, left - sz);
			cur += sep_len;
			left -= sep_len;
		}
	}
	*cur = '\0';

	return (const char *)str;
}

static const char *
buf2str(const uint8_t *buf, int len)
{
	return buf2str_extended(buf, len, NULL);
}

static const char * chassis_type_desc[] __attribute__((unused)) = {
	"Unspecified", "Other", "Unknown",
	"Desktop", "Low Profile Desktop", "Pizza Box",
	"Mini Tower", "Tower",
	"Portable", "LapTop", "Notebook", "Hand Held",
	"Docking Station", "All in One", "Sub Notebook",
	"Space-saving", "Lunch Box", "Main Server Chassis",
	"Expansion Chassis", "SubChassis", "Bus Expansion Chassis",
	"Peripheral Chassis", "RAID Chassis", "Rack Mount Chassis",
	"Sealed-case PC", "Multi-system Chassis", "CompactPCI",
	"AdvancedTCA", "Blade", "Blade Enclosure"
};
static const uint64_t secs_from_1970_1996 = 820454400;
static char * get_fru_area_str(uint8_t * data, uint32_t * offset)
{
	static const char bcd_plus[] = "0123456789 -.:,_";
	char * str;
	int len, off, size, i, j, k, typecode;
	union {
		uint32_t bits;
		char chars[4];
	} u;

	size = 0;
	off = *offset;

	/* bits 6:7 contain format */
	typecode = ((data[off] & 0xC0) >> 6);

	// printf("Typecode:%i\n", typecode);
	/* bits 0:5 contain length */
	len = data[off++];
	len &= 0x3f;

	switch (typecode) {
	case 0:           /* 00b: binary/unspecified */
		/* hex dump -> 2x length */
		size = (len*2);
		break;
	case 2:           /* 10b: 6-bit ASCII */
		/* 4 chars per group of 1-3 bytes */
		size = ((((len+2)*4)/3) & ~3);
		break;
	case 3:           /* 11b: 8-bit ASCII */
	case 1:           /* 01b: BCD plus */
		/* no length adjustment */
		size = len;
		break;
	default:
		break;
	}

	if (size < 1) {
		*offset = off;
		return NULL;
	}
    str = (char *)malloc(size+1);
	if (str == NULL)
		return NULL;
	memset(str, 0, size+1);

	if (len == 0) {
		str[0] = '\0';
		*offset = off;
		return str;
	}

	switch (typecode) {
	case 0:        /* Binary */
		strncpy(str, buf2str(&data[off], len), len*2);
		break;

	case 1:        /* BCD plus */
		for (k=0; k<len; k++)
			str[k] = bcd_plus[(data[off+k] & 0x0f)];
		str[k] = '\0';
		break;

	case 2:        /* 6-bit ASCII */
		for (i=j=0; i<len; i+=3) {
			u.bits = 0;
			k = ((len-i) < 3 ? (len-i) : 3);
#if WORDS_BIGENDIAN
			u.chars[3] = data[off+i];
			u.chars[2] = (k > 1 ? data[off+i+1] : 0);
			u.chars[1] = (k > 2 ? data[off+i+2] : 0);
#define CHAR_IDX 3
#else
			memcpy((void *)&u.bits, &data[off+i], k);
#define CHAR_IDX 0
#endif
			for (k=0; k<4; k++) {
				str[j++] = ((u.chars[CHAR_IDX] & 0x3f) + 0x20);
				u.bits >>= 6;
			}
		}
		str[j] = '\0';
		break;

	case 3:
		memcpy(str, &data[off], len);
		str[len] = '\0';
		break;
	default:
		break;
	}

	off += len;
	*offset = off;

	return str;
}

void Window::parseFile()
{
    QString fileName = uploadFileLineEdit->text();
    QFile file(fileName);
    file.open(QIODevice::ReadOnly);
    QDataStream in(&file);
    qint8 *buf = (qint8 *)calloc(1, 8192);
    int size = 0;
    uint32_t i;
    int row = 0;

    while (!in.atEnd())
    {
        in >> buf[size++];
    }

    fru_t *fru = (fru_t *)buf;
    uint8_t *fru_data = NULL;
    char * fru_area;

    if (fru->chassis)
    {
        chassisSelect->setCheckState(Qt::Unchecked);
        fru_data = (uint8_t *)&buf[fru->chassis * 8];
        /*
         * skip first two bytes which specify
         * fru area version and fru area length
         */
        i = 2;
        qDebug(" Chassis Type          : %s\n",
                chassis_type_desc[fru_data[i] > (sizeof(chassis_type_desc) / sizeof(chassis_type_desc[0])) - 1 ? 2 : fru_data[i]]);
        fruList->setItem(row, 0, new QTableWidgetItem("Chassis Type"));
        fruList->setItem(row, 1, new QTableWidgetItem(chassis_type_desc[fru_data[i]]));
        if(exportFileToedit) chassisTypeComboBox->setCurrentIndex(fru_data[i]);
        row++;
        i++;

        fru_area = get_fru_area_str(fru_data, &i);
        if (fru_area != NULL)
        {
            if (strlen(fru_area) > 0)
            {
                qDebug(" Chassis Part Number   : %s\n", fru_area);
                fruList->setItem(row, 0, new QTableWidgetItem(tr("Chassis Part Number")));
                fruList->setItem(row, 1, new QTableWidgetItem(tr(fru_area)));
                if(exportFileToedit) chassisPNEdit->setText(tr(fru_area));
                row++;
            }

            free(fru_area);
            fru_area = NULL;
        }

        fru_area = get_fru_area_str(fru_data, &i);
        if (fru_area != NULL)
        {
            if (strlen(fru_area) > 0)
            {
                qDebug(" Chassis Serial        : %s\n", fru_area);
                fruList->setItem(row, 0, new QTableWidgetItem(tr("Chassis Serial")));
                fruList->setItem(row, 1, new QTableWidgetItem(tr(fru_area)));
                if(exportFileToedit) chassisSNEdit->setText(tr(fru_area));
                row++;
            }
            free(fru_area);
            fru_area = NULL;
        }
    }
    else
    {
        chassisSelect->setCheckState(Qt::Checked);
    }

    if (fru->board)
    {
        boardSelect->setCheckState(Qt::Unchecked);
        fru_data = (uint8_t *)&buf[fru->board * 8];
        /*
         * skip first three bytes which specify
         * fru area version, fru area length
         * and fru board language
         */
        i = 3;
        time_t tval = ((fru_data[i + 2] << 16) + (fru_data[i + 1] << 8) + (fru_data[i]));
        tval = tval * 60;
        tval = tval + secs_from_1970_1996;
        qDebug(" Board Mfg Date        : %s", asctime(localtime(&tval)));
        i += 3; /* skip mfg. date time */
        fruList->setItem(row, 0, new QTableWidgetItem(tr("Board Mfg Date")));
        fruList->setItem(row, 1, new QTableWidgetItem(tr(asctime(localtime(&tval)))));
        row++;
        fru_area = get_fru_area_str(fru_data, &i);
        if (fru_area != NULL)
        {
            if (strlen(fru_area) > 0)
            {
                qDebug(" Board Mfg             : %s\n", fru_area);
                fruList->setItem(row, 0, new QTableWidgetItem(tr("Board Mfg")));
                fruList->setItem(row, 1, new QTableWidgetItem(tr(fru_area)));
                if(exportFileToedit) boardMfgLineEdit->setText(tr(fru_area));
                row++;
            }
            free(fru_area);
            fru_area = NULL;
        }

        fru_area = get_fru_area_str(fru_data, &i);
        if (fru_area != NULL)
        {
            if (strlen(fru_area) > 0)
            {
                qDebug(" Board Product         : %s\n", fru_area);
                fruList->setItem(row, 0, new QTableWidgetItem(tr("Board Product")));
                fruList->setItem(row, 1, new QTableWidgetItem(tr(fru_area)));
                if(exportFileToedit) boardPnameLineEdit->setText(tr(fru_area));
                row++;
            }
            free(fru_area);
            fru_area = NULL;
        }

        fru_area = get_fru_area_str(fru_data, &i);
        if (fru_area != NULL)
        {
            if (strlen(fru_area) > 0)
            {
                qDebug(" Board Serial          : %s\n", fru_area);
                fruList->setItem(row, 0, new QTableWidgetItem(tr("Board Serial")));
                fruList->setItem(row, 1, new QTableWidgetItem(tr(fru_area)));
                if(exportFileToedit) boardSerialLineEdit->setText(tr(fru_area));
                row++;
            }
            free(fru_area);
            fru_area = NULL;
        }

        fru_area = get_fru_area_str(fru_data, &i);
        if (fru_area != NULL)
        {
            if (strlen(fru_area) > 0)
            {
                qDebug(" Board Part Number     : %s\n", fru_area);
                fruList->setItem(row, 0, new QTableWidgetItem(tr("Board Part Number")));
                fruList->setItem(row, 1, new QTableWidgetItem(tr(fru_area)));
                if(exportFileToedit) boardPnLineEdit->setText(tr(fru_area));
                row++;
            }
            free(fru_area);
            fru_area = NULL;
        }

        fru_area = get_fru_area_str(fru_data, &i);
        if (fru_area != NULL)
        {
            if (strlen(fru_area) > 0)
            {
                qDebug(" Board FRU ID          : %s\n", fru_area);
                fruList->setItem(row, 0, new QTableWidgetItem(tr("Board FRU ID")));
                fruList->setItem(row, 1, new QTableWidgetItem(tr(fru_area)));
                if(exportFileToedit) boardFileLineEdit->setText(tr(fru_area));
                row++;
            }
            free(fru_area);
            fru_area = NULL;
        }
    }
    else
    {
        boardSelect->setCheckState(Qt::Checked);
    }

    if (fru->product)
    {
        productSelect->setCheckState(Qt::Unchecked);
        fru_data = (uint8_t *)&buf[fru->product * 8];
        /*
         * skip first three bytes which specify
         * fru area version, fru area length
         * and fru board language
         */
        i = 3;
        fru_area = get_fru_area_str(fru_data, &i);
        if (fru_area != NULL)
        {
            if (strlen(fru_area) > 0)
            {
                qDebug(" Product Manufacturer  : %s\n", fru_area);
                fruList->setItem(row, 0, new QTableWidgetItem(tr("Product Manufacturer")));
                fruList->setItem(row, 1, new QTableWidgetItem(tr(fru_area)));
                if(exportFileToedit) productMfgLineEdit->setText(tr(fru_area));
                row++;
            }
            free(fru_area);
            fru_area = NULL;
        }

        fru_area = get_fru_area_str(fru_data, &i);
        if (fru_area != NULL)
        {
            if (strlen(fru_area) > 0)
            {
                qDebug(" Product Name          : %s\n", fru_area);
                fruList->setItem(row, 0, new QTableWidgetItem(tr("Product Name")));
                fruList->setItem(row, 1, new QTableWidgetItem(tr(fru_area)));
                if(exportFileToedit) productPnameLineEdit->setText(tr(fru_area));
                row++;
            }
            free(fru_area);
            fru_area = NULL;
        }

        fru_area = get_fru_area_str(fru_data, &i);
        if (fru_area != NULL)
        {
            if (strlen(fru_area) > 0)
            {
                qDebug(" Product Part Number   : %s\n", fru_area);
                fruList->setItem(row, 0, new QTableWidgetItem(tr("Product Part Number")));
                fruList->setItem(row, 1, new QTableWidgetItem(tr(fru_area)));
                if(exportFileToedit) productPartNumLineEdit->setText(tr(fru_area));
                row++;
            }
            free(fru_area);
            fru_area = NULL;
        }

        fru_area = get_fru_area_str(fru_data, &i);
        if (fru_area != NULL)
        {
            if (strlen(fru_area) > 0)
            {
                qDebug(" Product Version       : %s\n", fru_area);
                fruList->setItem(row, 0, new QTableWidgetItem(tr("Product Version       :")));
                fruList->setItem(row, 1, new QTableWidgetItem(tr(fru_area)));
                if(exportFileToedit) productVersionLineEdit->setText(tr(fru_area));
                row++;
            }
            free(fru_area);
            fru_area = NULL;
        }

        fru_area = get_fru_area_str(fru_data, &i);
        if (fru_area != NULL)
        {
            if (strlen(fru_area) > 0)
            {
                qDebug(" Product Serial        : %s\n", fru_area);
                fruList->setItem(row, 0, new QTableWidgetItem(tr("Product Serial        :")));
                fruList->setItem(row, 1, new QTableWidgetItem(tr(fru_area)));
                if(exportFileToedit) productSerialLineEdit->setText(tr(fru_area));
                row++;
            }
            free(fru_area);
            fru_area = NULL;
        }

        fru_area = get_fru_area_str(fru_data, &i);
        if (fru_area != NULL)
        {
            if (strlen(fru_area) > 0)
            {
                qDebug(" Product Asset Tag     : %s\n", fru_area);
                fruList->setItem(row, 0, new QTableWidgetItem(tr("Product Asset Tag")));
                fruList->setItem(row, 1, new QTableWidgetItem(tr(fru_area)));
                if(exportFileToedit) productAtagLineEdit->setText(tr(fru_area));
                row++;
            }
            free(fru_area);
            fru_area = NULL;
        }

        fru_area = get_fru_area_str(fru_data, &i);
        if (fru_area != NULL)
        {
            if (strlen(fru_area) > 0)
            {
                qDebug(" Product FRU ID        : %s\n", fru_area);
                fruList->setItem(row, 0, new QTableWidgetItem(tr("Product FRU ID")));
                fruList->setItem(row, 1, new QTableWidgetItem(tr(fru_area)));
                if(exportFileToedit) productFileLineEdit->setText(tr(fru_area));
                row++;
            }
            free(fru_area);
            fru_area = NULL;
        }
    }
    else
    {
        productSelect->setCheckState(Qt::Checked);
    }


    file.close();
    free(buf);
}

void Window::exportFile()
{
    exportFileToedit = 1;
    parseFile();
    exportFileToedit = 0;
}

void Window::generateButtonClick()
{
//    QMessageBox *msg = new QMessageBox(this);
//    msg->setText("user name is jian");
//    msg->exec();

    bool    has_chassis  = true,
            has_board    = true,
            has_product  = true;
    fru_product_area_t *pi = NULL;
    fru_board_area_t *bi = NULL;
    fru_chassis_area_t *ci = NULL;
    fru_area_t areas[FRU_MAX_AREAS] = {
        {.atype = FRU_INTERNAL_USE},
        {.atype = FRU_CHASSIS_INFO},
        {.atype = FRU_BOARD_INFO},
        {.atype = FRU_PRODUCT_INFO},
        {.atype = FRU_MULTIRECORD}
    };

    if(chassisSelect->isChecked() == true)
    {
        has_chassis = false;
    }

    if(boardSelect->isChecked() == true)
    {
        has_board = false;
    }

    if(productSelect->isChecked() == true)
    {
        has_product = true;
    }


    if (has_chassis)
    {
        fru_exploded_chassis_t chassis;
        memset(&chassis, 0, sizeof(chassis));
        chassis.type = chassisTypeComboBox->currentIndex();
        memcpy(chassis.pn, chassisPNEdit->text().toStdString().data(), chassisPNEdit->text().toStdString().length());
        memcpy(chassis.serial, chassisSNEdit->text().toStdString().data(), chassisSNEdit->text().toStdString().length());

        qDebug() << "type = " << chassis.type << endl;
        qDebug() << "pn = " << (char *)chassis.pn << endl;
        qDebug() << "serial = " << (char *)chassis.serial << endl;

        ci = fru_chassis_info(&chassis);
        free_reclist(chassis.cust);
		if (ci) areas[FRU_CHASSIS_INFO].data = ci;
	}

    if (has_board) 
    {
        fru_exploded_board_t board;
        memset(&board, 0, sizeof(board));
        board.tv.tv_sec = boardDateLineEdit->dateTime().currentDateTimeUtc().toTime_t();
        qDebug() << "time: " << boardDateLineEdit->dateTime().currentDateTimeUtc().toTime_t() << endl;
        memcpy(board.mfg, boardMfgLineEdit->text().toStdString().data(), boardMfgLineEdit->text().toStdString().length());
        qDebug() << "board Mfg" << boardMfgLineEdit->text().toStdString().data() << endl;
        memcpy(board.pname, boardPnameLineEdit->text().toStdString().data(), boardPnameLineEdit->text().toStdString().length());
        qDebug() << "board Pname" << boardPnameLineEdit->text().toStdString().data() << endl;
        memcpy(board.serial, boardSerialLineEdit->text().toStdString().data(), boardSerialLineEdit->text().toStdString().length());
        qDebug() << "board Serial" << boardSerialLineEdit->text().toStdString().data() << endl;
        memcpy(board.pn, boardPnLineEdit->text().toStdString().data(), boardPnLineEdit->text().toStdString().length());
        qDebug() << "board Pn" << boardPnLineEdit->text().toStdString().data() << endl;
        memcpy(board.file, boardFileLineEdit->text().toStdString().data(), boardFileLineEdit->text().toStdString().length());
        qDebug() << "board File" << boardFileLineEdit->text().toStdString().data() << endl;
        board.lang = LANG_ENGLISH;

        bi = fru_board_info(&board);
        free_reclist(board.cust);
        if (bi) areas[FRU_BOARD_INFO].data = bi;
    }

    if (has_product) 
    {
        fru_exploded_product_t product;
        memset(&product, 0, sizeof(product));
        product.lang = LANG_ENGLISH;
        memcpy(product.mfg, productMfgLineEdit->text().toStdString().data(), productMfgLineEdit->text().toStdString().length());
        memcpy(product.pname, productPnameLineEdit->text().toStdString().data(), productPnameLineEdit->text().toStdString().length());
        memcpy(product.pn, productPartNumLineEdit->text().toStdString().data(), productPartNumLineEdit->text().toStdString().length());
        memcpy(product.ver, productVersionLineEdit->text().toStdString().data(), productVersionLineEdit->text().toStdString().length());
        memcpy(product.serial, productSerialLineEdit->text().toStdString().data(), productSerialLineEdit->text().toStdString().length());
        memcpy(product.atag, productAtagLineEdit->text().toStdString().data(), productAtagLineEdit->text().toStdString().length());
        memcpy(product.file, productFileLineEdit->text().toStdString().data(), productFileLineEdit->text().toStdString().length());

        pi = fru_product_info(&product);

        areas[FRU_PRODUCT_INFO].data = pi;
    }

    fru_t *fru;
    size_t size;
    fru = fru_create(areas, &size);

    QFile file(directoryComboBox->currentData().toString() + fileName->text());
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);
    out.setVersion(QDataStream::Qt_5_9);

    for(size_t i = 0; i < FRU_BYTES(size); i ++)
    {
        out << (qint8)((uint8_t *)fru)[i];
    }
    file.close();

    if(ci) free(ci);
    if(bi) free(bi);
    if(pi) free(pi);
    if(fru) free(fru);
    writeConfig();

    QMessageBox::about(NULL, "awesome", tr("<h3>gen okay ...</h3>"));
}

/* Copyright (c) 2012-2024 ImFusion GmbH, Munich, Germany. All rights reserved. */
#include <ImFusion/Dicom/GUI/DicomBrowserModel.h>

#include <QtWidgets/QDialog>
#include <QtWidgets/QBoxLayout>
#include <QtWidgets/QDialog>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QTreeView>

class DicomBrowser : public QDialog
{
	Q_OBJECT
public:
	DicomBrowser(const QString& directory, QWidget* parent = nullptr);
};
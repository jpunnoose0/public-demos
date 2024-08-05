/* Copyright (c) 2012-2024 ImFusion GmbH, Munich, Germany. All rights reserved. */
#pragma once

#include <ImFusion/GUI/AlgorithmController.h>

#include <QtWidgets/QWidget>

class Ui_DemoController;
namespace ImFusion
{
	class DemoAlgorithm;

	/// Demonstration of implementing a custom controller using Qt widgets.
	class DemoController
		: public QWidget
		, public AlgorithmController
	{
		Q_OBJECT

	public:
		/// Constructor with the algorithm instance
		explicit DemoController(DemoAlgorithm* algorithm);

		/// Destructor
		~DemoController() override;

		/// Initializes the widget
		void init() override;

	public slots:
		/// Apply the chosen processing
		void onApply();

	protected:
		Ui_DemoController* m_ui;    ///< The actual GUI
		DemoAlgorithm* m_alg;       ///< The algorithm instance
	};
}

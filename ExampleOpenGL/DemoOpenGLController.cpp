#include "DemoOpenGLController.h"

#include "DemoOpenGLAlgorithm.h"
#include "MyCustomGlObject.h"

#include <ImFusion/Base/DataModel.h>
#include <ImFusion/Base/SharedImageSet.h>
#include <ImFusion/GUI/DisplayWidgetMulti.h>
#include <ImFusion/GUI/ImageView2D.h>
#include <ImFusion/GUI/MainWindowBase.h>

#include <QPushButton>
#include <QVBoxLayout>

namespace ImFusion
{
	DemoOpenGLController::DemoOpenGLController(DemoOpenGLAlgorithm* algorithm)
		: DefaultAlgorithmController(algorithm)
	{
	}

	DemoOpenGLController::~DemoOpenGLController()
	{
		if (m_myInteractiveObject)
			m_disp->view2D()->removeObject(m_myInteractiveObject.get());
	}

	void DemoOpenGLController::init()
	{
		DefaultAlgorithmController::init();

		auto createGlObjectBtn = new QPushButton();
		createGlObjectBtn->setText("Create Object");
		m_layout->addWidget(createGlObjectBtn);
		connect(createGlObjectBtn, &QPushButton::clicked, [this, createGlObjectBtn]() {
			// lifetime is managed by this controller
			m_myInteractiveObject = std::make_unique<InteractiveObject>(new MyCustomGlObject);
			m_disp->view2D()->addObject(m_myInteractiveObject.get());
			createGlObjectBtn->setEnabled(false);
			m_disp->requestUpdate();
		});
	}
}

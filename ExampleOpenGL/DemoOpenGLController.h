/* Copyright (c) 2012-2024 ImFusion GmbH, Munich, Germany. All rights reserved. */
#pragma once

#include <ImFusion/GUI/DefaultAlgorithmController.h>

namespace ImFusion
{
	class DemoOpenGLAlgorithm;
	class InteractiveObject;

	/// Demonstration of implementing a custom controller using Qt widgets.
	class DemoOpenGLController : public DefaultAlgorithmController
	{
	public:
		/// Constructor with the algorithm instance
		explicit DemoOpenGLController(DemoOpenGLAlgorithm* algorithm);

		/// Destructor
		~DemoOpenGLController() override;

		/// Initializes the widget
		void init() override;

	protected:
		std::unique_ptr<InteractiveObject> m_myInteractiveObject;  ///< The custom interactive object
	};
}

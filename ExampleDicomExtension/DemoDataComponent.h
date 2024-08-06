/* Copyright (c) 2012-2024 ImFusion GmbH, Munich, Germany. All rights reserved. */
#pragma once

#include <ImFusion/Base/DataComponent.h>
#include <ImFusion/Core/Parameter.h>


class DemoDataComponent : public ImFusion::DataComponent<DemoDataComponent>
{
public:
	DemoDataComponent() = default;
	DemoDataComponent(const DemoDataComponent& other) = default;
	DemoDataComponent& operator=(const DemoDataComponent& other) = default;
	bool operator==(const DemoDataComponent& other) const
	{
		return (other.p_privateStringTag.value() == p_privateStringTag.value()) && (other.p_privateIntTag == p_privateIntTag);
	}

	std::string id() const override { return "DemoDataComponent"; }

	ImFusion::Parameter<std::string> p_privateStringTag = {"privateStringTag", "someString", this};
	ImFusion::Parameter<int> p_privateIntTag = {"privateIntTag", 15, this};
};
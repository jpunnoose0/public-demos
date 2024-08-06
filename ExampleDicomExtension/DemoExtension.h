/* Copyright (c) 2012-2024 ImFusion GmbH, Munich, Germany. All rights reserved. */
#pragma once

#include <ImFusion/Base/Data.h>
#include <ImFusion/Dicom/DicomElement.h>
#include <ImFusion/Dicom/DicomIOD.h>
#include <ImFusion/Dicom/DicomIOD_Registry.h>
#include <ImFusion/Dicom/Extension.h>

#include <dcmtk/dcmdata/dctk.h>

namespace ImFusion
{
	class DemoExtension : public ImFusion::Dicom::Extension
	{
	public:
		DemoExtension()
		{
			// In order to get dcmtk to correctly convert private tags, the tags and their VRs need to be registered with the DcmDataDictionary.
			// Here we register the tags with the GlobalDcmDataDictionary "dcmDataDict". This is a global variable defined in dcmtk.
			DcmDataDictionary& dict = dcmDataDict.wrlock();
			dict.addEntry(new DcmDictEntry(
				someStringTag.getGTag(), someStringTag.getETag(), EVR_LO, "PrivateText", 1, 1, "private", OFTrue, creatorName.c_str()));
			dict.addEntry(
				new DcmDictEntry(someIntTag.getGTag(), someIntTag.getETag(), EVR_US, "PrivateInteger", 1, 1, "private", OFTrue, creatorName.c_str()));
#if OFFIS_DCMTK_VERSION_NUMBER < 364
			dcmDataDict.unlock();
#else
			dcmDataDict.wrunlock();
#endif
		}


		std::unique_ptr<Extension> clone() const override { return std::make_unique<DemoExtension>(); }

		std::string name() const override { return "DemoExtension"; }

		std::vector<std::unique_ptr<Data>> load(const Dicom::FrameDescriptor& frame, SharedImageSet& sis) const override
		{
			if (frame.sharedImageIndex != 0 || frame.sliceIndex != 0)
				return {};

			// We only create the DataComponent if the tags actually exist and the creator matches
			Dicom::Element<std::string> creator(*frame.iod, creatorTag);

			// In general any creator can use any odd group number for private tags.
			// That means that we need to check first if the creatorName matches
			if (creator.isValid() && creator.value() == creatorName)
			{
				Dicom::Element<std::string> someString(*frame.iod, someStringTag);
				Dicom::Element<int> someInt(*frame.iod, someIntTag);

				auto& dc = sis.components().getOrCreate<DemoDataComponent>();
				if (someString.isValid())
					dc.p_privateStringTag = someString.value();
				if (someInt.isValid())
					dc.p_privateIntTag = someInt.value();
			}

			return {};
		}

		void save(const Dicom::FrameDescriptor& frame, const SharedImageSet& sis) const override
		{
			// In this example we only write the private tags if the corresponding DataComponent
			// has been added to the SharedImageSet at some point
			if (auto dc = sis.components().get<DemoDataComponent>())
			{
				Dicom::Element<std::string> creator(*frame.iod, creatorTag);
				creator.setValue(creatorName);
				Dicom::Element<std::string> someString(*frame.iod, someStringTag);
				someString.setValue(dc->p_privateStringTag);
				Dicom::Element<int> someInt(*frame.iod, someIntTag);
				someInt.setValue(dc->p_privateIntTag);
			}
		}

	private:
		const std::string creatorName = "ImFusion";
		const DcmTag creatorTag = DcmTag(DcmTagKey(0x0029, 0x0010), EVR_LO);
		const DcmTag someStringTag = DcmTag(DcmTagKey(0x0029, 0x1000), EVR_LO);
		const DcmTag someIntTag = DcmTag(DcmTagKey(0x0029, 0x1010), EVR_US);
	};
}
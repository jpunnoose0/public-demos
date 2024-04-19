#include "AnatomyKeys.h"

#include <ImFusion/AnatomyPlugin/Keys.h>

namespace TotalSegmentator::Keys
{
	std::string TotalSegmentator::Keys::AnatomyKeys::translateKey(const std::string& keyTotalSegmentator) noexcept
	{
		if (auto it = m_demoToImFusionNameMap.find(keyTotalSegmentator); it != m_demoToImFusionNameMap.end())
		{
			return it->second;
		}
		return "Unknown-" + keyTotalSegmentator;
	}

	// Where TotalSegmentator key exists, translate between anatomical structure name
	// in demo and TotalSegmentator name (anatomy key) defined in Keys.h
	const std::unordered_map<std::string, std::string> AnatomyKeys::m_demoToImFusionNameMap = {
		{"spleen", Keys::Spleen::key},
		{"kidney_right", Keys::RightKidney::key},
		{"kidney_left", Keys::LeftKidney::key},
		{"gallbladder", Keys::Gallbladder::key},
		{"liver", Keys::Liver::key},
		{"stomach", Keys::Stomach::key},
		{"pancreas", Keys::Pancreas::key},
		{"adrenal_gland_right", Keys::AdrenalGlandRight::key},
		{"adrenal_gland_left", Keys::AdrenalGlandLeft::key},
		{"lung_upper_lobe_left", Keys::Lung::UpperLobeLeft::key},
		{"lung_lower_lobe_left", Keys::Lung::LowerLobeLeft::key},
		{"lung_upper_lobe_right", Keys::Lung::UpperLobeRight::key},
		{"lung_middle_lobe_right", Keys::Lung::MiddleLobeRight::key},
		{"lung_lower_lobe_right", Keys::Lung::LowerLobeRight::key},
		{"esophagus", Keys::Esophagus::key},
		{"small_bowel", Keys::SmallBowel::key},
		{"duodenum", Keys::Duodenum::key},
		{"colon", Keys::Colon::key},
		{"urinary_bladder", Keys::UrinaryBladder::key},
		{"prostate", Keys::Prostate::key},
		{"sacrum", Keys::Spine::Sacrum::key},
		{"vertebrae_S1", Spine::Vertebra::S1::key},
		{"vertebrae_L5", Spine::Vertebra::L5::key},
		{"vertebrae_L4", Spine::Vertebra::L4::key},
		{"vertebrae_L3", Spine::Vertebra::L3::key},
		{"vertebrae_L2", Spine::Vertebra::L2::key},
		{"vertebrae_L1", Spine::Vertebra::L1::key},
		{"vertebrae_T12", Spine::Vertebra::T12::key},
		{"vertebrae_T11", Spine::Vertebra::T11::key},
		{"vertebrae_T10", Spine::Vertebra::T10::key},
		{"vertebrae_T9", Spine::Vertebra::T9::key},
		{"vertebrae_T8", Spine::Vertebra::T8::key},
		{"vertebrae_T7", Spine::Vertebra::T7::key},
		{"heart", Keys::Heart::key},
		{"aorta", Keys::Aorta::key},
		{"pulmonary_vein", Keys::PulmonaryVein::key},
		{"atrial_appendage_left", Keys::AtrialAppendageLeft::key},
		{"superior_vena_cava", Keys::SuperiorVenaCava::key},
		{"inferior_vena_cava", Keys::InferiorVenaCava::key},
		{"portal_vein_and_splenic_vein", Keys::PortalVeinAndSplenicVein::key},
		{"iliac_artery_left", Keys::IliacArteryLeft::key},
		{"iliac_artery_right", Keys::IliacArteryLeft::key},
		{"iliac_vena_left", Keys::IliacVenaLeft::key},
		{"iliac_vena_right", Keys::IliacVenaRight::key},
		{"scapula_left", Keys::ScapulaLeft::key},
		{"scapula_right", Keys::ScapulaRight::key},
		{"femur_left", Keys::FemurLeft::key},
		{"femur_right", Keys::FemurRight::key},
		{"hip_left", Keys::HipLeft::key},
		{"hip_right", Keys::HipRight::key},
		{"hip_right", Keys::Spine::SpinalCord::key},
		{"spinal_cord", Keys::Spine::SpinalCord::key},
		{"gluteus_maximus_left", Keys::GluteusMaximusLeft::key},
		{"gluteus_maximus_right", Keys::GluteusMaximusRight::key},
		{"gluteus_medius_left", Keys::GluteusMediusLeft::key},
		{"gluteus_medius_right", Keys::GluteusMediusRight::key},
		{"gluteus_minimus_left", Keys::GluteusMinimusLeft::key},
		{"gluteus_minimus_right", Keys::GluteusMinimusRight::key},
		{"autochthon_left", Keys::AutochthonLeft::key},
		{"autochthon_right", Keys::AutochthonRight::key},
		{"iliopsoas_left", Keys::IliopsoasLeft::key},
		{"iliopsoas_right", Keys::IliopsoasLeft::key},
		{"rib_left_4", Keys::RibLeft::R4::key},
		{"rib_left_5", Keys::RibLeft::R5::key},
		{"rib_left_6", Keys::RibLeft::R6::key},
		{"rib_left_7", Keys::RibLeft::R7::key},
		{"rib_left_8", Keys::RibLeft::R8::key},
		{"rib_left_9", Keys::RibLeft::R9::key},
		{"rib_left_10", Keys::RibLeft::R10::key},
		{"rib_left_11", Keys::RibLeft::R11::key},
		{"rib_left_12", Keys::RibLeft::R12::key},
		{"rib_right_3", Keys::RibRight::R3::key},
		{"rib_right_4", Keys::RibRight::R4::key},
		{"rib_right_5", Keys::RibRight::R5::key},
		{"rib_right_6", Keys::RibRight::R6::key},
		{"rib_right_7", Keys::RibRight::R7::key},
		{"rib_right_8", Keys::RibRight::R8::key},
		{"rib_right_9", Keys::RibRight::R9::key},
		{"rib_right_10", Keys::RibRight::R10::key},
		{"rib_right_11", Keys::RibRight::R11::key},
		{"rib_right_12", Keys::RibRight::R12::key},
		{"sternum", Keys::Sternum::key},
		{"costal_cartilages", Keys::CostalCartilages::key}};
}

#pragma once
/**
\file       syn.hpp
\author     Anton Erashov /eai/ skype: ytkoduff; emails: erashov@uuusoft.com, erashov2004@yandex.ru
\date       26.07.2016
\copyright  www.uuusoft.com
\project    uuu_vgen_diff
\brief      empty brief
*/

namespace dlls { namespace gens { namespace vgen_diff {
//  syn
using ::libs::ievents::props::videos::gens::diff::VideoDiffProp;
using ::utils::dbuffs::video::consts::offs::off_buff_type;
using ::libs::icore::impl::var1::obj::PointFilter;
using TInfoBuff       = ::libs::ievents::props::videos::gens::diff::InfoBuffVideoDiffProp;
using ParamsOperation = ::libs::ievents::props::videos::gens::diff::ParamsVideoDiffProp;
using TBuff2Info      = std::pair<off_buff_type, TInfoBuff>;
using ::libs::icore::impl::var1::obj::FilterInfo;
using ::libs::icore::impl::var1::obj::dll::TransformInfo;
using ::libs::icore::impl::var1::obj::dll::CallInterfInfo;
using ::libs::icore::impl::var1::obj::ConnectInfo;
using ::utils::dbuffs::video::IVideoBuff;

}}}      // namespace dlls::gens::vgen_diff
//This is an independent project of an individual developer. Dear PVS-Studio, please check it.
//PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
/**
\file       filter-dll-convert_from_y16_funct.cpp
\date       01.05.2017
\author     Anton Erashov /eai/ skype: ytkoduff; emails: erashov@uuusoft.com, erashov2004@yandex.ru
\copyright  www.uuusoft.com
\project    uuu_all2hsl
\brief      empty brief
*/
#include "mmedia/defines/defines.hpp"
#include "mmedia/defines/includes.hpp"
#include "includes_int.hpp"
#include "info-filter-dll.hpp"
#include "filter-dll.hpp"

namespace dlls { namespace convertors { namespace all2hsl {

void
Filter::convert_buffs_from_y16 ()
{
  IVideoBuff::raw_ptr _l      = (*pbuff_)[svideo::consts::offs::lit];
  IVideoBuff::raw_ptr _rcbuff = (*pbuff_)[svideo::consts::offs::raw];

  _l->swap (*_rcbuff);
  _l->set_mem_var (::utils::dbuffs::TypeMemVar::size_data, _l->get_dim_var (svideo::TypeDimVar::height) * _l->get_dim_var (svideo::TypeDimVar::stride));
  //_l->fill( rand() % 255 );//debug
  //_l->fill( 111 );//debug
  return;
}

}}}      // namespace dlls::convertors::all2hsl

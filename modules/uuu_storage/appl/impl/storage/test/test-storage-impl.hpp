#pragma once
/**
\file       test-storage-impl.hpp
\author     Anton Erashov /eai/ skype: ytkoduff; emails: erashov@uuusoft.com, erashov2004@yandex.ru
\date       10.08.2018
\copyright  www.uuusoft.com
\project    uuu_module_storage
\brief      empty brief
*/

namespace modules { namespace uuu_storage { namespace appl { namespace impl { namespace storage { namespace test {
/*
  \brief  ������� ���������� ���������� ��������� ������� ����������.
          ������� �������� ������:
          - ������ ������ ������ ����������� � ���������� ������� id_seance
          - ������ ���������� ������ � ������ ������ ������� � ����� ������ ������
          - ������ ���� ������ ������ ��������� ��� �� ���������� ���������� � ��� (max_count_fragments_session_data_file), ��� � �� ������������� ������ ������� (max_size_session_data_file),
            ��� ���������� ������ �� ��� ��������� ����� ���� ������. ��� ������� � �������������� �������� ������ � ��������� �� ������ ����� ������.
          - ������ ������ ������ ������� ��� ������� ����� ������ � ��������� � ��� ����� ��������
          - �������������� ��������� ������� �� ����� �������� ������ (guid ������������� �����), ������ ����� ������ (int) � ������� � ��� (int).
  */
class TestStorageImpl : public IStorageImpl
{
  public:
  //  ext types
  using IStorageImpl::id_chunk_type;
  using IStorageImpl::seance_type;
  using IStorageImpl::ids_chunk_type;
  using IStorageImpl::id_locker_type;
  using info_seance_type = RuntimeInfoSeance;

  explicit TestStorageImpl (const std::string& _path);

  virtual ~TestStorageImpl ();


  private:
  // int types
  using id_chunk2info    = std::unordered_map<seance_type, info_seance_type>;
  using id_lockers_type  = std::unordered_set<id_locker_type>;
  //  IStorageImpl overrides
  virtual void          set_info_int (const PathInfo::craw_ptr _info) override;
  virtual bool          change_state_int (const StateImplsType& _state) override;
  virtual void          load_int (const seance_type& _info, const id_chunk_type& _id, IBlockMem::raw_ptr _mem) override;
  virtual id_chunk_type save_int (const seance_type& _info, IBlockMem::craw_ptr _mem) override;
  virtual id_chunk_type save_int (const seance_type& _info, const unsigned char* _mem, const std::size_t _size_mem) override;
  //virtual void           get_all_ids_int (ids_chunk_type& _ids) override;
  //virtual void           remove_ids_int (const id_locker_type& _lid) override;
  //virtual void           get_info_ids_int (const id_locker_type& _lid) override;
  //virtual id_locker_type lock_ids_int (const ids_chunk_type& _ids) override;
  //virtual void           unlock_ids_int (const id_locker_type& _lid) override;

  info_seance_type& get_seance_info (const seance_type& _info);

  //id_chunk_type get_next_write_id_by_seance (const seance_type& _info, info_seance_type& _sinfo);
  void get_next_write_id_by_seance (const seance_type& _info, info_seance_type& _sinfo);

  void prepare_write_seance (const seance_type& _info);

  id_chunk_type save_impl (const seance_type& _info, const unsigned char* _mem, const std::size_t _size_mem);

  //bool save_data (const id_chunk_type& _id, const unsigned char* _mem, const std::size_t _size_mem);
  bool save_data (const seance_type& _info, info_seance_type& _sinfo, const unsigned char* _mem, const std::size_t _size_mem);

  void flush_seances();

  void update_path ();

  id_chunk2info   seances2infos_;      //< ������ ���������� �� ������ �������.
  PathInfo        info_;               //< ������� ���������� � �����������.
  std::string     root_path_;          //< �������������� ���� � ������ ���������.
  id_lockers_type lockers_;            //< ������� ����� ���������� ��� �������.
};

}}}}}}      // namespace modules::uuu_storage::appl::impl::storage::test

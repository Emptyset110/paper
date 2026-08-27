// Lean compiler output
// Module: Bounded.Equiv
// Imports: public import Init public meta import Init public import Bounded.Explore
#include <lean/lean.h>
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunused-parameter"
#pragma clang diagnostic ignored "-Wunused-label"
#elif defined(__GNUC__) && !defined(__CLANG__)
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-label"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif
#ifdef __cplusplus
extern "C" {
#endif
lean_object* lean_mk_empty_array_with_capacity(lean_object*);
lean_object* l_List_mapTR_loop___redArg(lean_object*, lean_object*, lean_object*);
lean_object* l___private_Init_Data_List_Impl_0__List_flatMapTR_go___redArg(lean_object*, lean_object*, lean_object*);
lean_object* lean_nat_mod(lean_object*, lean_object*);
lean_object* lean_array_to_list(lean_object*);
lean_object* l_List_reverse___redArg(lean_object*);
lean_object* l_List_foldl___at___00Array_appendList_spec__0___redArg(lean_object*, lean_object*);
lean_object* lp_bounded_Bounded_Ren_slotInv(lean_object*, lean_object*);
lean_object* lp_bounded_Bounded_SMap_get___redArg(lean_object*, lean_object*);
lean_object* lp_bounded_Bounded_Ren_key(lean_object*, lean_object*);
lean_object* lp_bounded_Bounded_Ren_val(lean_object*, lean_object*);
lean_object* lp_bounded_Bounded_BList_map___redArg(lean_object*, lean_object*);
lean_object* lp_bounded_Bounded_Ren_slot(lean_object*, lean_object*);
lean_object* lp_bounded_Bounded_KMap_get___redArg(lean_object*, lean_object*);
extern lean_object* lp_bounded_Bounded_childComp;
uint8_t lp_bounded_Bounded_instDecidableEqComponent_decEq(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumRen___lam__0(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumRen___lam__0___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumRen___lam__1(uint8_t, uint8_t);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumRen___lam__1___boxed(lean_object*, lean_object*);
static const lean_ctor_object lp_bounded_Bounded_instFinEnumRen___lam__2___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(1) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_bounded_Bounded_instFinEnumRen___lam__2___closed__0 = (const lean_object*)&lp_bounded_Bounded_instFinEnumRen___lam__2___closed__0_value;
static const lean_ctor_object lp_bounded_Bounded_instFinEnumRen___lam__2___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_bounded_Bounded_instFinEnumRen___lam__2___closed__0_value)}};
static const lean_object* lp_bounded_Bounded_instFinEnumRen___lam__2___closed__1 = (const lean_object*)&lp_bounded_Bounded_instFinEnumRen___lam__2___closed__1_value;
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumRen___lam__2(uint8_t);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumRen___lam__2___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumRen___lam__3(uint8_t, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumRen___lam__3___boxed(lean_object*, lean_object*);
static const lean_array_object lp_bounded_Bounded_instFinEnumRen___lam__4___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_array_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 246}, .m_size = 0, .m_capacity = 0, .m_data = {}};
static const lean_object* lp_bounded_Bounded_instFinEnumRen___lam__4___closed__0 = (const lean_object*)&lp_bounded_Bounded_instFinEnumRen___lam__4___closed__0_value;
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumRen___lam__4(lean_object*, uint8_t);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumRen___lam__4___boxed(lean_object*, lean_object*);
static const lean_closure_object lp_bounded_Bounded_instFinEnumRen___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_bounded_Bounded_instFinEnumRen___lam__0___boxed, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_bounded_Bounded_instFinEnumRen___closed__0 = (const lean_object*)&lp_bounded_Bounded_instFinEnumRen___closed__0_value;
static const lean_closure_object lp_bounded_Bounded_instFinEnumRen___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_bounded_Bounded_instFinEnumRen___lam__2___boxed, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_bounded_Bounded_instFinEnumRen___closed__1 = (const lean_object*)&lp_bounded_Bounded_instFinEnumRen___closed__1_value;
static const lean_closure_object lp_bounded_Bounded_instFinEnumRen___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*1, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_bounded_Bounded_instFinEnumRen___lam__4___boxed, .m_arity = 2, .m_num_fixed = 1, .m_objs = {((lean_object*)&lp_bounded_Bounded_instFinEnumRen___closed__1_value)} };
static const lean_object* lp_bounded_Bounded_instFinEnumRen___closed__2 = (const lean_object*)&lp_bounded_Bounded_instFinEnumRen___closed__2_value;
static const lean_ctor_object lp_bounded_Bounded_instFinEnumRen___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(5) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_bounded_Bounded_instFinEnumRen___closed__3 = (const lean_object*)&lp_bounded_Bounded_instFinEnumRen___closed__3_value;
static const lean_ctor_object lp_bounded_Bounded_instFinEnumRen___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(4) << 1) | 1)),((lean_object*)&lp_bounded_Bounded_instFinEnumRen___closed__3_value)}};
static const lean_object* lp_bounded_Bounded_instFinEnumRen___closed__4 = (const lean_object*)&lp_bounded_Bounded_instFinEnumRen___closed__4_value;
static const lean_ctor_object lp_bounded_Bounded_instFinEnumRen___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(3) << 1) | 1)),((lean_object*)&lp_bounded_Bounded_instFinEnumRen___closed__4_value)}};
static const lean_object* lp_bounded_Bounded_instFinEnumRen___closed__5 = (const lean_object*)&lp_bounded_Bounded_instFinEnumRen___closed__5_value;
static const lean_ctor_object lp_bounded_Bounded_instFinEnumRen___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(2) << 1) | 1)),((lean_object*)&lp_bounded_Bounded_instFinEnumRen___closed__5_value)}};
static const lean_object* lp_bounded_Bounded_instFinEnumRen___closed__6 = (const lean_object*)&lp_bounded_Bounded_instFinEnumRen___closed__6_value;
static const lean_ctor_object lp_bounded_Bounded_instFinEnumRen___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(1) << 1) | 1)),((lean_object*)&lp_bounded_Bounded_instFinEnumRen___closed__6_value)}};
static const lean_object* lp_bounded_Bounded_instFinEnumRen___closed__7 = (const lean_object*)&lp_bounded_Bounded_instFinEnumRen___closed__7_value;
static const lean_ctor_object lp_bounded_Bounded_instFinEnumRen___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_bounded_Bounded_instFinEnumRen___closed__7_value)}};
static const lean_object* lp_bounded_Bounded_instFinEnumRen___closed__8 = (const lean_object*)&lp_bounded_Bounded_instFinEnumRen___closed__8_value;
static const lean_array_object lp_bounded_Bounded_instFinEnumRen___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_array_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 246}, .m_size = 0, .m_capacity = 0, .m_data = {}};
static const lean_object* lp_bounded_Bounded_instFinEnumRen___closed__9 = (const lean_object*)&lp_bounded_Bounded_instFinEnumRen___closed__9_value;
static lean_once_cell_t lp_bounded_Bounded_instFinEnumRen___closed__10_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_instFinEnumRen___closed__10;
static lean_once_cell_t lp_bounded_Bounded_instFinEnumRen___closed__11_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_instFinEnumRen___closed__11;
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumRen;
LEAN_EXPORT lean_object* lp_bounded_List_mapTR_loop___at___00Bounded_allRens_spec__4(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_List_mapTR_loop___at___00Bounded_allRens_spec__0(uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_List_mapTR_loop___at___00Bounded_allRens_spec__0___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00Bounded_allRens_spec__1(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00Bounded_allRens_spec__1___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_List_mapTR_loop___at___00Bounded_allRens_spec__2(uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_List_mapTR_loop___at___00Bounded_allRens_spec__2___boxed(lean_object*, lean_object*, lean_object*);
static lean_once_cell_t lp_bounded___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00Bounded_allRens_spec__3___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00Bounded_allRens_spec__3___closed__0;
LEAN_EXPORT lean_object* lp_bounded___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00Bounded_allRens_spec__3(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00Bounded_allRens_spec__3___boxed(lean_object*, lean_object*);
static lean_once_cell_t lp_bounded_Bounded_allRens___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_allRens___closed__0;
static lean_once_cell_t lp_bounded_Bounded_allRens___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_allRens___closed__1;
LEAN_EXPORT lean_object* lp_bounded_Bounded_allRens;
static lean_once_cell_t lp_bounded_Bounded_KMap_ren___redArg___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_KMap_ren___redArg___closed__0;
static lean_once_cell_t lp_bounded_Bounded_KMap_ren___redArg___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_KMap_ren___redArg___closed__1;
LEAN_EXPORT lean_object* lp_bounded_Bounded_KMap_ren___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_KMap_ren___redArg___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_KMap_ren(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_KMap_ren___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
static lean_once_cell_t lp_bounded_Bounded_SMap_ren___redArg___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_SMap_ren___redArg___closed__0;
static lean_once_cell_t lp_bounded_Bounded_SMap_ren___redArg___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_SMap_ren___redArg___closed__1;
static lean_once_cell_t lp_bounded_Bounded_SMap_ren___redArg___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_SMap_ren___redArg___closed__2;
LEAN_EXPORT lean_object* lp_bounded_Bounded_SMap_ren___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_SMap_ren___redArg___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_SMap_ren(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_SMap_ren___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_renStep(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_renStep___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_renScript(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_renKSet___lam__0(uint8_t);
LEAN_EXPORT lean_object* lp_bounded_Bounded_renKSet___lam__0___boxed(lean_object*);
static const lean_closure_object lp_bounded_Bounded_renKSet___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_bounded_Bounded_renKSet___lam__0___boxed, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_bounded_Bounded_renKSet___closed__0 = (const lean_object*)&lp_bounded_Bounded_renKSet___closed__0_value;
LEAN_EXPORT lean_object* lp_bounded_Bounded_renKSet(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_renKSet___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_renTable___lam__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_renTable___lam__0___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_renTable(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_renTable___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_renView___lam__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_renView___lam__0___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_renView(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_renView___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_renComponent(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_renInv(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_renInv___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_renAcc(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_renLState(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_renFiber(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_renConfig___lam__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_renConfig(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_renConfig___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_renAct(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_renEvent(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_renEvent___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_List_mapTR_loop___at___00Bounded_renEv_spec__0(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_List_mapTR_loop___at___00Bounded_renEv_spec__0___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_renEv(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_renEv___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_renRow(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_renFixesChild(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_renFixesChild___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_List_filterTR_loop___at___00Bounded_kRens_spec__0(lean_object*, lean_object*);
static lean_once_cell_t lp_bounded_Bounded_kRens___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_kRens___closed__0;
LEAN_EXPORT lean_object* lp_bounded_Bounded_kRens;
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumRen___lam__0(lean_object* v_t_1_){
_start:
{
lean_object* v_snd_2_; lean_object* v_fst_3_; lean_object* v_fst_4_; lean_object* v_snd_5_; lean_object* v___x_6_; uint8_t v___x_7_; uint8_t v___x_8_; uint8_t v___x_9_; 
v_snd_2_ = lean_ctor_get(v_t_1_, 1);
v_fst_3_ = lean_ctor_get(v_t_1_, 0);
v_fst_4_ = lean_ctor_get(v_snd_2_, 0);
v_snd_5_ = lean_ctor_get(v_snd_2_, 1);
v___x_6_ = lean_alloc_ctor(0, 0, 3);
v___x_7_ = lean_unbox(v_fst_3_);
lean_ctor_set_uint8(v___x_6_, 0, v___x_7_);
v___x_8_ = lean_unbox(v_fst_4_);
lean_ctor_set_uint8(v___x_6_, 1, v___x_8_);
v___x_9_ = lean_unbox(v_snd_5_);
lean_ctor_set_uint8(v___x_6_, 2, v___x_9_);
return v___x_6_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumRen___lam__0___boxed(lean_object* v_t_10_){
_start:
{
lean_object* v_res_11_; 
v_res_11_ = lp_bounded_Bounded_instFinEnumRen___lam__0(v_t_10_);
lean_dec_ref(v_t_10_);
return v_res_11_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumRen___lam__1(uint8_t v_a_12_, uint8_t v_b_13_){
_start:
{
lean_object* v___x_14_; lean_object* v___x_15_; lean_object* v___x_16_; 
v___x_14_ = lean_box(v_a_12_);
v___x_15_ = lean_box(v_b_13_);
v___x_16_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_16_, 0, v___x_14_);
lean_ctor_set(v___x_16_, 1, v___x_15_);
return v___x_16_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumRen___lam__1___boxed(lean_object* v_a_17_, lean_object* v_b_18_){
_start:
{
uint8_t v_a_boxed_19_; uint8_t v_b_boxed_20_; lean_object* v_res_21_; 
v_a_boxed_19_ = lean_unbox(v_a_17_);
v_b_boxed_20_ = lean_unbox(v_b_18_);
v_res_21_ = lp_bounded_Bounded_instFinEnumRen___lam__1(v_a_boxed_19_, v_b_boxed_20_);
return v_res_21_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumRen___lam__2(uint8_t v_a_30_){
_start:
{
lean_object* v___x_31_; lean_object* v___f_32_; lean_object* v___x_33_; lean_object* v___x_34_; lean_object* v___x_35_; 
v___x_31_ = lean_box(v_a_30_);
v___f_32_ = lean_alloc_closure((void*)(lp_bounded_Bounded_instFinEnumRen___lam__1___boxed), 2, 1);
lean_closure_set(v___f_32_, 0, v___x_31_);
v___x_33_ = lean_box(0);
v___x_34_ = ((lean_object*)(lp_bounded_Bounded_instFinEnumRen___lam__2___closed__1));
v___x_35_ = l_List_mapTR_loop___redArg(v___f_32_, v___x_34_, v___x_33_);
return v___x_35_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumRen___lam__2___boxed(lean_object* v_a_36_){
_start:
{
uint8_t v_a_boxed_37_; lean_object* v_res_38_; 
v_a_boxed_37_ = lean_unbox(v_a_36_);
v_res_38_ = lp_bounded_Bounded_instFinEnumRen___lam__2(v_a_boxed_37_);
return v_res_38_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumRen___lam__3(uint8_t v_a_39_, lean_object* v_b_40_){
_start:
{
lean_object* v___x_41_; lean_object* v___x_42_; 
v___x_41_ = lean_box(v_a_39_);
v___x_42_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_42_, 0, v___x_41_);
lean_ctor_set(v___x_42_, 1, v_b_40_);
return v___x_42_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumRen___lam__3___boxed(lean_object* v_a_43_, lean_object* v_b_44_){
_start:
{
uint8_t v_a_boxed_45_; lean_object* v_res_46_; 
v_a_boxed_45_ = lean_unbox(v_a_43_);
v_res_46_ = lp_bounded_Bounded_instFinEnumRen___lam__3(v_a_boxed_45_, v_b_44_);
return v_res_46_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumRen___lam__4(lean_object* v___f_49_, uint8_t v_a_50_){
_start:
{
lean_object* v___x_51_; lean_object* v___f_52_; lean_object* v___x_53_; lean_object* v___x_54_; lean_object* v___x_55_; lean_object* v___x_56_; lean_object* v___x_57_; 
v___x_51_ = lean_box(v_a_50_);
v___f_52_ = lean_alloc_closure((void*)(lp_bounded_Bounded_instFinEnumRen___lam__3___boxed), 2, 1);
lean_closure_set(v___f_52_, 0, v___x_51_);
v___x_53_ = lean_box(0);
v___x_54_ = ((lean_object*)(lp_bounded_Bounded_instFinEnumRen___lam__2___closed__1));
v___x_55_ = ((lean_object*)(lp_bounded_Bounded_instFinEnumRen___lam__4___closed__0));
v___x_56_ = l___private_Init_Data_List_Impl_0__List_flatMapTR_go___redArg(v___f_49_, v___x_54_, v___x_55_);
v___x_57_ = l_List_mapTR_loop___redArg(v___f_52_, v___x_56_, v___x_53_);
return v___x_57_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumRen___lam__4___boxed(lean_object* v___f_58_, lean_object* v_a_59_){
_start:
{
uint8_t v_a_boxed_60_; lean_object* v_res_61_; 
v_a_boxed_60_ = lean_unbox(v_a_59_);
v_res_61_ = lp_bounded_Bounded_instFinEnumRen___lam__4(v___f_58_, v_a_boxed_60_);
return v_res_61_;
}
}
static lean_object* _init_lp_bounded_Bounded_instFinEnumRen___closed__10(void){
_start:
{
lean_object* v___x_92_; lean_object* v___x_93_; lean_object* v___f_94_; lean_object* v___x_95_; 
v___x_92_ = ((lean_object*)(lp_bounded_Bounded_instFinEnumRen___closed__9));
v___x_93_ = ((lean_object*)(lp_bounded_Bounded_instFinEnumRen___closed__8));
v___f_94_ = ((lean_object*)(lp_bounded_Bounded_instFinEnumRen___closed__2));
v___x_95_ = l___private_Init_Data_List_Impl_0__List_flatMapTR_go___redArg(v___f_94_, v___x_93_, v___x_92_);
return v___x_95_;
}
}
static lean_object* _init_lp_bounded_Bounded_instFinEnumRen___closed__11(void){
_start:
{
lean_object* v___x_96_; lean_object* v___x_97_; lean_object* v___f_98_; lean_object* v___x_99_; 
v___x_96_ = lean_box(0);
v___x_97_ = lean_obj_once(&lp_bounded_Bounded_instFinEnumRen___closed__10, &lp_bounded_Bounded_instFinEnumRen___closed__10_once, _init_lp_bounded_Bounded_instFinEnumRen___closed__10);
v___f_98_ = ((lean_object*)(lp_bounded_Bounded_instFinEnumRen___closed__0));
v___x_99_ = l_List_mapTR_loop___redArg(v___f_98_, v___x_97_, v___x_96_);
return v___x_99_;
}
}
static lean_object* _init_lp_bounded_Bounded_instFinEnumRen(void){
_start:
{
lean_object* v___x_100_; 
v___x_100_ = lean_obj_once(&lp_bounded_Bounded_instFinEnumRen___closed__11, &lp_bounded_Bounded_instFinEnumRen___closed__11_once, _init_lp_bounded_Bounded_instFinEnumRen___closed__11);
return v___x_100_;
}
}
LEAN_EXPORT lean_object* lp_bounded_List_mapTR_loop___at___00Bounded_allRens_spec__4(lean_object* v_a_101_, lean_object* v_a_102_){
_start:
{
if (lean_obj_tag(v_a_101_) == 0)
{
lean_object* v___x_103_; 
v___x_103_ = l_List_reverse___redArg(v_a_102_);
return v___x_103_;
}
else
{
lean_object* v_head_104_; lean_object* v_snd_105_; lean_object* v_tail_106_; lean_object* v___x_108_; uint8_t v_isShared_109_; uint8_t v_isSharedCheck_121_; 
v_head_104_ = lean_ctor_get(v_a_101_, 0);
lean_inc(v_head_104_);
v_snd_105_ = lean_ctor_get(v_head_104_, 1);
lean_inc(v_snd_105_);
v_tail_106_ = lean_ctor_get(v_a_101_, 1);
v_isSharedCheck_121_ = !lean_is_exclusive(v_a_101_);
if (v_isSharedCheck_121_ == 0)
{
lean_object* v_unused_122_; 
v_unused_122_ = lean_ctor_get(v_a_101_, 0);
lean_dec(v_unused_122_);
v___x_108_ = v_a_101_;
v_isShared_109_ = v_isSharedCheck_121_;
goto v_resetjp_107_;
}
else
{
lean_inc(v_tail_106_);
lean_dec(v_a_101_);
v___x_108_ = lean_box(0);
v_isShared_109_ = v_isSharedCheck_121_;
goto v_resetjp_107_;
}
v_resetjp_107_:
{
lean_object* v_fst_110_; lean_object* v_fst_111_; lean_object* v_snd_112_; lean_object* v___x_113_; uint8_t v___x_114_; uint8_t v___x_115_; uint8_t v___x_116_; lean_object* v___x_118_; 
v_fst_110_ = lean_ctor_get(v_head_104_, 0);
lean_inc(v_fst_110_);
lean_dec(v_head_104_);
v_fst_111_ = lean_ctor_get(v_snd_105_, 0);
lean_inc(v_fst_111_);
v_snd_112_ = lean_ctor_get(v_snd_105_, 1);
lean_inc(v_snd_112_);
lean_dec(v_snd_105_);
v___x_113_ = lean_alloc_ctor(0, 0, 3);
v___x_114_ = lean_unbox(v_fst_110_);
lean_dec(v_fst_110_);
lean_ctor_set_uint8(v___x_113_, 0, v___x_114_);
v___x_115_ = lean_unbox(v_fst_111_);
lean_dec(v_fst_111_);
lean_ctor_set_uint8(v___x_113_, 1, v___x_115_);
v___x_116_ = lean_unbox(v_snd_112_);
lean_dec(v_snd_112_);
lean_ctor_set_uint8(v___x_113_, 2, v___x_116_);
if (v_isShared_109_ == 0)
{
lean_ctor_set(v___x_108_, 1, v_a_102_);
lean_ctor_set(v___x_108_, 0, v___x_113_);
v___x_118_ = v___x_108_;
goto v_reusejp_117_;
}
else
{
lean_object* v_reuseFailAlloc_120_; 
v_reuseFailAlloc_120_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_120_, 0, v___x_113_);
lean_ctor_set(v_reuseFailAlloc_120_, 1, v_a_102_);
v___x_118_ = v_reuseFailAlloc_120_;
goto v_reusejp_117_;
}
v_reusejp_117_:
{
v_a_101_ = v_tail_106_;
v_a_102_ = v___x_118_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_List_mapTR_loop___at___00Bounded_allRens_spec__0(uint8_t v_a_123_, lean_object* v_a_124_, lean_object* v_a_125_){
_start:
{
if (lean_obj_tag(v_a_124_) == 0)
{
lean_object* v___x_126_; 
v___x_126_ = l_List_reverse___redArg(v_a_125_);
return v___x_126_;
}
else
{
lean_object* v_head_127_; lean_object* v_tail_128_; lean_object* v___x_130_; uint8_t v_isShared_131_; uint8_t v_isSharedCheck_138_; 
v_head_127_ = lean_ctor_get(v_a_124_, 0);
v_tail_128_ = lean_ctor_get(v_a_124_, 1);
v_isSharedCheck_138_ = !lean_is_exclusive(v_a_124_);
if (v_isSharedCheck_138_ == 0)
{
v___x_130_ = v_a_124_;
v_isShared_131_ = v_isSharedCheck_138_;
goto v_resetjp_129_;
}
else
{
lean_inc(v_tail_128_);
lean_inc(v_head_127_);
lean_dec(v_a_124_);
v___x_130_ = lean_box(0);
v_isShared_131_ = v_isSharedCheck_138_;
goto v_resetjp_129_;
}
v_resetjp_129_:
{
lean_object* v___x_132_; lean_object* v___x_133_; lean_object* v___x_135_; 
v___x_132_ = lean_box(v_a_123_);
v___x_133_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_133_, 0, v___x_132_);
lean_ctor_set(v___x_133_, 1, v_head_127_);
if (v_isShared_131_ == 0)
{
lean_ctor_set(v___x_130_, 1, v_a_125_);
lean_ctor_set(v___x_130_, 0, v___x_133_);
v___x_135_ = v___x_130_;
goto v_reusejp_134_;
}
else
{
lean_object* v_reuseFailAlloc_137_; 
v_reuseFailAlloc_137_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_137_, 0, v___x_133_);
lean_ctor_set(v_reuseFailAlloc_137_, 1, v_a_125_);
v___x_135_ = v_reuseFailAlloc_137_;
goto v_reusejp_134_;
}
v_reusejp_134_:
{
v_a_124_ = v_tail_128_;
v_a_125_ = v___x_135_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_List_mapTR_loop___at___00Bounded_allRens_spec__0___boxed(lean_object* v_a_139_, lean_object* v_a_140_, lean_object* v_a_141_){
_start:
{
uint8_t v_a_boxed_142_; lean_object* v_res_143_; 
v_a_boxed_142_ = lean_unbox(v_a_139_);
v_res_143_ = lp_bounded_List_mapTR_loop___at___00Bounded_allRens_spec__0(v_a_boxed_142_, v_a_140_, v_a_141_);
return v_res_143_;
}
}
LEAN_EXPORT lean_object* lp_bounded___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00Bounded_allRens_spec__1(lean_object* v_a_144_, lean_object* v_a_145_){
_start:
{
if (lean_obj_tag(v_a_144_) == 0)
{
lean_object* v___x_146_; 
v___x_146_ = lean_array_to_list(v_a_145_);
return v___x_146_;
}
else
{
lean_object* v_head_147_; lean_object* v_tail_148_; lean_object* v___x_149_; lean_object* v___x_150_; uint8_t v___x_151_; lean_object* v___x_152_; lean_object* v___x_153_; 
v_head_147_ = lean_ctor_get(v_a_144_, 0);
v_tail_148_ = lean_ctor_get(v_a_144_, 1);
v___x_149_ = lean_box(0);
v___x_150_ = ((lean_object*)(lp_bounded_Bounded_instFinEnumRen___lam__2___closed__1));
v___x_151_ = lean_unbox(v_head_147_);
v___x_152_ = lp_bounded_List_mapTR_loop___at___00Bounded_allRens_spec__0(v___x_151_, v___x_150_, v___x_149_);
v___x_153_ = l_List_foldl___at___00Array_appendList_spec__0___redArg(v_a_145_, v___x_152_);
v_a_144_ = v_tail_148_;
v_a_145_ = v___x_153_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* lp_bounded___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00Bounded_allRens_spec__1___boxed(lean_object* v_a_155_, lean_object* v_a_156_){
_start:
{
lean_object* v_res_157_; 
v_res_157_ = lp_bounded___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00Bounded_allRens_spec__1(v_a_155_, v_a_156_);
lean_dec(v_a_155_);
return v_res_157_;
}
}
LEAN_EXPORT lean_object* lp_bounded_List_mapTR_loop___at___00Bounded_allRens_spec__2(uint8_t v_a_158_, lean_object* v_a_159_, lean_object* v_a_160_){
_start:
{
if (lean_obj_tag(v_a_159_) == 0)
{
lean_object* v___x_161_; 
v___x_161_ = l_List_reverse___redArg(v_a_160_);
return v___x_161_;
}
else
{
lean_object* v_head_162_; lean_object* v_tail_163_; lean_object* v___x_165_; uint8_t v_isShared_166_; uint8_t v_isSharedCheck_173_; 
v_head_162_ = lean_ctor_get(v_a_159_, 0);
v_tail_163_ = lean_ctor_get(v_a_159_, 1);
v_isSharedCheck_173_ = !lean_is_exclusive(v_a_159_);
if (v_isSharedCheck_173_ == 0)
{
v___x_165_ = v_a_159_;
v_isShared_166_ = v_isSharedCheck_173_;
goto v_resetjp_164_;
}
else
{
lean_inc(v_tail_163_);
lean_inc(v_head_162_);
lean_dec(v_a_159_);
v___x_165_ = lean_box(0);
v_isShared_166_ = v_isSharedCheck_173_;
goto v_resetjp_164_;
}
v_resetjp_164_:
{
lean_object* v___x_167_; lean_object* v___x_168_; lean_object* v___x_170_; 
v___x_167_ = lean_box(v_a_158_);
v___x_168_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_168_, 0, v___x_167_);
lean_ctor_set(v___x_168_, 1, v_head_162_);
if (v_isShared_166_ == 0)
{
lean_ctor_set(v___x_165_, 1, v_a_160_);
lean_ctor_set(v___x_165_, 0, v___x_168_);
v___x_170_ = v___x_165_;
goto v_reusejp_169_;
}
else
{
lean_object* v_reuseFailAlloc_172_; 
v_reuseFailAlloc_172_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_172_, 0, v___x_168_);
lean_ctor_set(v_reuseFailAlloc_172_, 1, v_a_160_);
v___x_170_ = v_reuseFailAlloc_172_;
goto v_reusejp_169_;
}
v_reusejp_169_:
{
v_a_159_ = v_tail_163_;
v_a_160_ = v___x_170_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_List_mapTR_loop___at___00Bounded_allRens_spec__2___boxed(lean_object* v_a_174_, lean_object* v_a_175_, lean_object* v_a_176_){
_start:
{
uint8_t v_a_boxed_177_; lean_object* v_res_178_; 
v_a_boxed_177_ = lean_unbox(v_a_174_);
v_res_178_ = lp_bounded_List_mapTR_loop___at___00Bounded_allRens_spec__2(v_a_boxed_177_, v_a_175_, v_a_176_);
return v_res_178_;
}
}
static lean_object* _init_lp_bounded___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00Bounded_allRens_spec__3___closed__0(void){
_start:
{
lean_object* v___x_179_; lean_object* v___x_180_; lean_object* v___x_181_; 
v___x_179_ = ((lean_object*)(lp_bounded_Bounded_instFinEnumRen___lam__4___closed__0));
v___x_180_ = ((lean_object*)(lp_bounded_Bounded_instFinEnumRen___lam__2___closed__1));
v___x_181_ = lp_bounded___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00Bounded_allRens_spec__1(v___x_180_, v___x_179_);
return v___x_181_;
}
}
LEAN_EXPORT lean_object* lp_bounded___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00Bounded_allRens_spec__3(lean_object* v_a_182_, lean_object* v_a_183_){
_start:
{
if (lean_obj_tag(v_a_182_) == 0)
{
lean_object* v___x_184_; 
v___x_184_ = lean_array_to_list(v_a_183_);
return v___x_184_;
}
else
{
lean_object* v_head_185_; lean_object* v_tail_186_; lean_object* v___x_187_; lean_object* v___x_188_; uint8_t v___x_189_; lean_object* v___x_190_; lean_object* v___x_191_; 
v_head_185_ = lean_ctor_get(v_a_182_, 0);
v_tail_186_ = lean_ctor_get(v_a_182_, 1);
v___x_187_ = lean_box(0);
v___x_188_ = lean_obj_once(&lp_bounded___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00Bounded_allRens_spec__3___closed__0, &lp_bounded___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00Bounded_allRens_spec__3___closed__0_once, _init_lp_bounded___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00Bounded_allRens_spec__3___closed__0);
v___x_189_ = lean_unbox(v_head_185_);
v___x_190_ = lp_bounded_List_mapTR_loop___at___00Bounded_allRens_spec__2(v___x_189_, v___x_188_, v___x_187_);
v___x_191_ = l_List_foldl___at___00Array_appendList_spec__0___redArg(v_a_183_, v___x_190_);
v_a_182_ = v_tail_186_;
v_a_183_ = v___x_191_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* lp_bounded___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00Bounded_allRens_spec__3___boxed(lean_object* v_a_193_, lean_object* v_a_194_){
_start:
{
lean_object* v_res_195_; 
v_res_195_ = lp_bounded___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00Bounded_allRens_spec__3(v_a_193_, v_a_194_);
lean_dec(v_a_193_);
return v_res_195_;
}
}
static lean_object* _init_lp_bounded_Bounded_allRens___closed__0(void){
_start:
{
lean_object* v___x_196_; lean_object* v___x_197_; lean_object* v___x_198_; 
v___x_196_ = ((lean_object*)(lp_bounded_Bounded_instFinEnumRen___closed__9));
v___x_197_ = ((lean_object*)(lp_bounded_Bounded_instFinEnumRen___closed__8));
v___x_198_ = lp_bounded___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00Bounded_allRens_spec__3(v___x_197_, v___x_196_);
return v___x_198_;
}
}
static lean_object* _init_lp_bounded_Bounded_allRens___closed__1(void){
_start:
{
lean_object* v___x_199_; lean_object* v___x_200_; lean_object* v___x_201_; 
v___x_199_ = lean_box(0);
v___x_200_ = lean_obj_once(&lp_bounded_Bounded_allRens___closed__0, &lp_bounded_Bounded_allRens___closed__0_once, _init_lp_bounded_Bounded_allRens___closed__0);
v___x_201_ = lp_bounded_List_mapTR_loop___at___00Bounded_allRens_spec__4(v___x_200_, v___x_199_);
return v___x_201_;
}
}
static lean_object* _init_lp_bounded_Bounded_allRens(void){
_start:
{
lean_object* v___x_202_; 
v___x_202_ = lean_obj_once(&lp_bounded_Bounded_allRens___closed__1, &lp_bounded_Bounded_allRens___closed__1_once, _init_lp_bounded_Bounded_allRens___closed__1);
return v___x_202_;
}
}
static lean_object* _init_lp_bounded_Bounded_KMap_ren___redArg___closed__0(void){
_start:
{
lean_object* v___x_203_; lean_object* v___x_204_; lean_object* v___x_205_; 
v___x_203_ = lean_unsigned_to_nat(2u);
v___x_204_ = lean_unsigned_to_nat(0u);
v___x_205_ = lean_nat_mod(v___x_204_, v___x_203_);
return v___x_205_;
}
}
static lean_object* _init_lp_bounded_Bounded_KMap_ren___redArg___closed__1(void){
_start:
{
lean_object* v___x_206_; lean_object* v___x_207_; lean_object* v___x_208_; 
v___x_206_ = lean_unsigned_to_nat(2u);
v___x_207_ = lean_unsigned_to_nat(1u);
v___x_208_ = lean_nat_mod(v___x_207_, v___x_206_);
return v___x_208_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_KMap_ren___redArg(lean_object* v_r_209_, lean_object* v_f_210_, lean_object* v_m_211_){
_start:
{
lean_object* v___x_212_; lean_object* v___x_213_; lean_object* v___x_214_; lean_object* v___x_215_; lean_object* v___x_216_; lean_object* v___x_217_; lean_object* v___x_218_; lean_object* v___x_219_; lean_object* v___x_220_; 
v___x_212_ = lean_obj_once(&lp_bounded_Bounded_KMap_ren___redArg___closed__0, &lp_bounded_Bounded_KMap_ren___redArg___closed__0_once, _init_lp_bounded_Bounded_KMap_ren___redArg___closed__0);
v___x_213_ = lp_bounded_Bounded_Ren_key(v_r_209_, v___x_212_);
v___x_214_ = lp_bounded_Bounded_KMap_get___redArg(v_m_211_, v___x_213_);
lean_dec(v___x_213_);
lean_inc(v_f_210_);
v___x_215_ = lean_apply_1(v_f_210_, v___x_214_);
v___x_216_ = lean_obj_once(&lp_bounded_Bounded_KMap_ren___redArg___closed__1, &lp_bounded_Bounded_KMap_ren___redArg___closed__1_once, _init_lp_bounded_Bounded_KMap_ren___redArg___closed__1);
v___x_217_ = lp_bounded_Bounded_Ren_key(v_r_209_, v___x_216_);
v___x_218_ = lp_bounded_Bounded_KMap_get___redArg(v_m_211_, v___x_217_);
lean_dec(v___x_217_);
v___x_219_ = lean_apply_1(v_f_210_, v___x_218_);
v___x_220_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_220_, 0, v___x_215_);
lean_ctor_set(v___x_220_, 1, v___x_219_);
return v___x_220_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_KMap_ren___redArg___boxed(lean_object* v_r_221_, lean_object* v_f_222_, lean_object* v_m_223_){
_start:
{
lean_object* v_res_224_; 
v_res_224_ = lp_bounded_Bounded_KMap_ren___redArg(v_r_221_, v_f_222_, v_m_223_);
lean_dec_ref(v_m_223_);
lean_dec_ref(v_r_221_);
return v_res_224_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_KMap_ren(lean_object* v_00_u03b1_225_, lean_object* v_r_226_, lean_object* v_f_227_, lean_object* v_m_228_){
_start:
{
lean_object* v___x_229_; 
v___x_229_ = lp_bounded_Bounded_KMap_ren___redArg(v_r_226_, v_f_227_, v_m_228_);
return v___x_229_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_KMap_ren___boxed(lean_object* v_00_u03b1_230_, lean_object* v_r_231_, lean_object* v_f_232_, lean_object* v_m_233_){
_start:
{
lean_object* v_res_234_; 
v_res_234_ = lp_bounded_Bounded_KMap_ren(v_00_u03b1_230_, v_r_231_, v_f_232_, v_m_233_);
lean_dec_ref(v_m_233_);
lean_dec_ref(v_r_231_);
return v_res_234_;
}
}
static lean_object* _init_lp_bounded_Bounded_SMap_ren___redArg___closed__0(void){
_start:
{
lean_object* v___x_235_; lean_object* v___x_236_; lean_object* v___x_237_; 
v___x_235_ = lean_unsigned_to_nat(3u);
v___x_236_ = lean_unsigned_to_nat(0u);
v___x_237_ = lean_nat_mod(v___x_236_, v___x_235_);
return v___x_237_;
}
}
static lean_object* _init_lp_bounded_Bounded_SMap_ren___redArg___closed__1(void){
_start:
{
lean_object* v___x_238_; lean_object* v___x_239_; lean_object* v___x_240_; 
v___x_238_ = lean_unsigned_to_nat(3u);
v___x_239_ = lean_unsigned_to_nat(1u);
v___x_240_ = lean_nat_mod(v___x_239_, v___x_238_);
return v___x_240_;
}
}
static lean_object* _init_lp_bounded_Bounded_SMap_ren___redArg___closed__2(void){
_start:
{
lean_object* v___x_241_; lean_object* v___x_242_; lean_object* v___x_243_; 
v___x_241_ = lean_unsigned_to_nat(3u);
v___x_242_ = lean_unsigned_to_nat(2u);
v___x_243_ = lean_nat_mod(v___x_242_, v___x_241_);
return v___x_243_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_SMap_ren___redArg(lean_object* v_r_244_, lean_object* v_f_245_, lean_object* v_m_246_){
_start:
{
lean_object* v___x_247_; lean_object* v___x_248_; lean_object* v___x_249_; lean_object* v___x_250_; lean_object* v___x_251_; lean_object* v___x_252_; lean_object* v___x_253_; lean_object* v___x_254_; lean_object* v___x_255_; lean_object* v___x_256_; lean_object* v___x_257_; lean_object* v___x_258_; lean_object* v___x_259_; 
v___x_247_ = lean_obj_once(&lp_bounded_Bounded_SMap_ren___redArg___closed__0, &lp_bounded_Bounded_SMap_ren___redArg___closed__0_once, _init_lp_bounded_Bounded_SMap_ren___redArg___closed__0);
v___x_248_ = lp_bounded_Bounded_Ren_slotInv(v_r_244_, v___x_247_);
v___x_249_ = lp_bounded_Bounded_SMap_get___redArg(v_m_246_, v___x_248_);
lean_dec(v___x_248_);
lean_inc_n(v_f_245_, 2);
v___x_250_ = lean_apply_1(v_f_245_, v___x_249_);
v___x_251_ = lean_obj_once(&lp_bounded_Bounded_SMap_ren___redArg___closed__1, &lp_bounded_Bounded_SMap_ren___redArg___closed__1_once, _init_lp_bounded_Bounded_SMap_ren___redArg___closed__1);
v___x_252_ = lp_bounded_Bounded_Ren_slotInv(v_r_244_, v___x_251_);
v___x_253_ = lp_bounded_Bounded_SMap_get___redArg(v_m_246_, v___x_252_);
lean_dec(v___x_252_);
v___x_254_ = lean_apply_1(v_f_245_, v___x_253_);
v___x_255_ = lean_obj_once(&lp_bounded_Bounded_SMap_ren___redArg___closed__2, &lp_bounded_Bounded_SMap_ren___redArg___closed__2_once, _init_lp_bounded_Bounded_SMap_ren___redArg___closed__2);
v___x_256_ = lp_bounded_Bounded_Ren_slotInv(v_r_244_, v___x_255_);
v___x_257_ = lp_bounded_Bounded_SMap_get___redArg(v_m_246_, v___x_256_);
lean_dec(v___x_256_);
v___x_258_ = lean_apply_1(v_f_245_, v___x_257_);
v___x_259_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v___x_259_, 0, v___x_250_);
lean_ctor_set(v___x_259_, 1, v___x_254_);
lean_ctor_set(v___x_259_, 2, v___x_258_);
return v___x_259_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_SMap_ren___redArg___boxed(lean_object* v_r_260_, lean_object* v_f_261_, lean_object* v_m_262_){
_start:
{
lean_object* v_res_263_; 
v_res_263_ = lp_bounded_Bounded_SMap_ren___redArg(v_r_260_, v_f_261_, v_m_262_);
lean_dec_ref(v_m_262_);
lean_dec_ref(v_r_260_);
return v_res_263_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_SMap_ren(lean_object* v_00_u03b1_264_, lean_object* v_r_265_, lean_object* v_f_266_, lean_object* v_m_267_){
_start:
{
lean_object* v___x_268_; 
v___x_268_ = lp_bounded_Bounded_SMap_ren___redArg(v_r_265_, v_f_266_, v_m_267_);
return v___x_268_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_SMap_ren___boxed(lean_object* v_00_u03b1_269_, lean_object* v_r_270_, lean_object* v_f_271_, lean_object* v_m_272_){
_start:
{
lean_object* v_res_273_; 
v_res_273_ = lp_bounded_Bounded_SMap_ren(v_00_u03b1_269_, v_r_270_, v_f_271_, v_m_272_);
lean_dec_ref(v_m_272_);
lean_dec_ref(v_r_270_);
return v_res_273_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_renStep(lean_object* v_r_274_, lean_object* v_x_275_){
_start:
{
switch(lean_obj_tag(v_x_275_))
{
case 0:
{
lean_object* v_k_276_; lean_object* v_v_277_; lean_object* v___x_279_; uint8_t v_isShared_280_; uint8_t v_isSharedCheck_286_; 
v_k_276_ = lean_ctor_get(v_x_275_, 0);
v_v_277_ = lean_ctor_get(v_x_275_, 1);
v_isSharedCheck_286_ = !lean_is_exclusive(v_x_275_);
if (v_isSharedCheck_286_ == 0)
{
v___x_279_ = v_x_275_;
v_isShared_280_ = v_isSharedCheck_286_;
goto v_resetjp_278_;
}
else
{
lean_inc(v_v_277_);
lean_inc(v_k_276_);
lean_dec(v_x_275_);
v___x_279_ = lean_box(0);
v_isShared_280_ = v_isSharedCheck_286_;
goto v_resetjp_278_;
}
v_resetjp_278_:
{
lean_object* v___x_281_; lean_object* v___x_282_; lean_object* v___x_284_; 
v___x_281_ = lp_bounded_Bounded_Ren_key(v_r_274_, v_k_276_);
lean_dec(v_k_276_);
v___x_282_ = lp_bounded_Bounded_Ren_val(v_r_274_, v_v_277_);
lean_dec(v_v_277_);
if (v_isShared_280_ == 0)
{
lean_ctor_set(v___x_279_, 1, v___x_282_);
lean_ctor_set(v___x_279_, 0, v___x_281_);
v___x_284_ = v___x_279_;
goto v_reusejp_283_;
}
else
{
lean_object* v_reuseFailAlloc_285_; 
v_reuseFailAlloc_285_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_285_, 0, v___x_281_);
lean_ctor_set(v_reuseFailAlloc_285_, 1, v___x_282_);
v___x_284_ = v_reuseFailAlloc_285_;
goto v_reusejp_283_;
}
v_reusejp_283_:
{
return v___x_284_;
}
}
}
case 1:
{
return v_x_275_;
}
case 2:
{
lean_object* v_k_287_; lean_object* v___x_289_; uint8_t v_isShared_290_; uint8_t v_isSharedCheck_295_; 
v_k_287_ = lean_ctor_get(v_x_275_, 0);
v_isSharedCheck_295_ = !lean_is_exclusive(v_x_275_);
if (v_isSharedCheck_295_ == 0)
{
v___x_289_ = v_x_275_;
v_isShared_290_ = v_isSharedCheck_295_;
goto v_resetjp_288_;
}
else
{
lean_inc(v_k_287_);
lean_dec(v_x_275_);
v___x_289_ = lean_box(0);
v_isShared_290_ = v_isSharedCheck_295_;
goto v_resetjp_288_;
}
v_resetjp_288_:
{
lean_object* v___x_291_; lean_object* v___x_293_; 
v___x_291_ = lp_bounded_Bounded_Ren_key(v_r_274_, v_k_287_);
lean_dec(v_k_287_);
if (v_isShared_290_ == 0)
{
lean_ctor_set(v___x_289_, 0, v___x_291_);
v___x_293_ = v___x_289_;
goto v_reusejp_292_;
}
else
{
lean_object* v_reuseFailAlloc_294_; 
v_reuseFailAlloc_294_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v_reuseFailAlloc_294_, 0, v___x_291_);
v___x_293_ = v_reuseFailAlloc_294_;
goto v_reusejp_292_;
}
v_reusejp_292_:
{
return v___x_293_;
}
}
}
case 3:
{
lean_object* v_k_296_; lean_object* v_v_297_; lean_object* v___x_299_; uint8_t v_isShared_300_; uint8_t v_isSharedCheck_306_; 
v_k_296_ = lean_ctor_get(v_x_275_, 0);
v_v_297_ = lean_ctor_get(v_x_275_, 1);
v_isSharedCheck_306_ = !lean_is_exclusive(v_x_275_);
if (v_isSharedCheck_306_ == 0)
{
v___x_299_ = v_x_275_;
v_isShared_300_ = v_isSharedCheck_306_;
goto v_resetjp_298_;
}
else
{
lean_inc(v_v_297_);
lean_inc(v_k_296_);
lean_dec(v_x_275_);
v___x_299_ = lean_box(0);
v_isShared_300_ = v_isSharedCheck_306_;
goto v_resetjp_298_;
}
v_resetjp_298_:
{
lean_object* v___x_301_; lean_object* v___x_302_; lean_object* v___x_304_; 
v___x_301_ = lp_bounded_Bounded_Ren_key(v_r_274_, v_k_296_);
lean_dec(v_k_296_);
v___x_302_ = lp_bounded_Bounded_Ren_val(v_r_274_, v_v_297_);
lean_dec(v_v_297_);
if (v_isShared_300_ == 0)
{
lean_ctor_set(v___x_299_, 1, v___x_302_);
lean_ctor_set(v___x_299_, 0, v___x_301_);
v___x_304_ = v___x_299_;
goto v_reusejp_303_;
}
else
{
lean_object* v_reuseFailAlloc_305_; 
v_reuseFailAlloc_305_ = lean_alloc_ctor(3, 2, 0);
lean_ctor_set(v_reuseFailAlloc_305_, 0, v___x_301_);
lean_ctor_set(v_reuseFailAlloc_305_, 1, v___x_302_);
v___x_304_ = v_reuseFailAlloc_305_;
goto v_reusejp_303_;
}
v_reusejp_303_:
{
return v___x_304_;
}
}
}
default: 
{
return v_x_275_;
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_renStep___boxed(lean_object* v_r_307_, lean_object* v_x_308_){
_start:
{
lean_object* v_res_309_; 
v_res_309_ = lp_bounded_Bounded_renStep(v_r_307_, v_x_308_);
lean_dec_ref(v_r_307_);
return v_res_309_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_renScript(lean_object* v_r_310_, lean_object* v_s_311_){
_start:
{
lean_object* v___x_312_; lean_object* v___x_313_; 
v___x_312_ = lean_alloc_closure((void*)(lp_bounded_Bounded_renStep___boxed), 2, 1);
lean_closure_set(v___x_312_, 0, v_r_310_);
v___x_313_ = lp_bounded_Bounded_BList_map___redArg(v___x_312_, v_s_311_);
return v___x_313_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_renKSet___lam__0(uint8_t v___y_314_){
_start:
{
return v___y_314_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_renKSet___lam__0___boxed(lean_object* v___y_315_){
_start:
{
uint8_t v___y_7__boxed_316_; uint8_t v_res_317_; lean_object* v_r_318_; 
v___y_7__boxed_316_ = lean_unbox(v___y_315_);
v_res_317_ = lp_bounded_Bounded_renKSet___lam__0(v___y_7__boxed_316_);
v_r_318_ = lean_box(v_res_317_);
return v_r_318_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_renKSet(lean_object* v_r_320_, lean_object* v_m_321_){
_start:
{
lean_object* v___f_322_; lean_object* v___x_323_; 
v___f_322_ = ((lean_object*)(lp_bounded_Bounded_renKSet___closed__0));
v___x_323_ = lp_bounded_Bounded_KMap_ren___redArg(v_r_320_, v___f_322_, v_m_321_);
return v___x_323_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_renKSet___boxed(lean_object* v_r_324_, lean_object* v_m_325_){
_start:
{
lean_object* v_res_326_; 
v_res_326_ = lp_bounded_Bounded_renKSet(v_r_324_, v_m_325_);
lean_dec_ref(v_m_325_);
lean_dec_ref(v_r_324_);
return v_res_326_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_renTable___lam__0(lean_object* v_r_327_, lean_object* v___y_328_){
_start:
{
if (lean_obj_tag(v___y_328_) == 0)
{
return v___y_328_;
}
else
{
lean_object* v_val_329_; lean_object* v___x_331_; uint8_t v_isShared_332_; uint8_t v_isSharedCheck_337_; 
v_val_329_ = lean_ctor_get(v___y_328_, 0);
v_isSharedCheck_337_ = !lean_is_exclusive(v___y_328_);
if (v_isSharedCheck_337_ == 0)
{
v___x_331_ = v___y_328_;
v_isShared_332_ = v_isSharedCheck_337_;
goto v_resetjp_330_;
}
else
{
lean_inc(v_val_329_);
lean_dec(v___y_328_);
v___x_331_ = lean_box(0);
v_isShared_332_ = v_isSharedCheck_337_;
goto v_resetjp_330_;
}
v_resetjp_330_:
{
lean_object* v___x_333_; lean_object* v___x_335_; 
v___x_333_ = lp_bounded_Bounded_Ren_val(v_r_327_, v_val_329_);
lean_dec(v_val_329_);
if (v_isShared_332_ == 0)
{
lean_ctor_set(v___x_331_, 0, v___x_333_);
v___x_335_ = v___x_331_;
goto v_reusejp_334_;
}
else
{
lean_object* v_reuseFailAlloc_336_; 
v_reuseFailAlloc_336_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_336_, 0, v___x_333_);
v___x_335_ = v_reuseFailAlloc_336_;
goto v_reusejp_334_;
}
v_reusejp_334_:
{
return v___x_335_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_renTable___lam__0___boxed(lean_object* v_r_338_, lean_object* v___y_339_){
_start:
{
lean_object* v_res_340_; 
v_res_340_ = lp_bounded_Bounded_renTable___lam__0(v_r_338_, v___y_339_);
lean_dec_ref(v_r_338_);
return v_res_340_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_renTable(lean_object* v_r_341_, lean_object* v_m_342_){
_start:
{
lean_object* v___f_343_; lean_object* v___x_344_; 
lean_inc_ref(v_r_341_);
v___f_343_ = lean_alloc_closure((void*)(lp_bounded_Bounded_renTable___lam__0___boxed), 2, 1);
lean_closure_set(v___f_343_, 0, v_r_341_);
v___x_344_ = lp_bounded_Bounded_KMap_ren___redArg(v_r_341_, v___f_343_, v_m_342_);
lean_dec_ref(v_r_341_);
return v___x_344_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_renTable___boxed(lean_object* v_r_345_, lean_object* v_m_346_){
_start:
{
lean_object* v_res_347_; 
v_res_347_ = lp_bounded_Bounded_renTable(v_r_345_, v_m_346_);
lean_dec_ref(v_m_346_);
return v_res_347_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_renView___lam__0(lean_object* v_r_348_, lean_object* v___y_349_){
_start:
{
if (lean_obj_tag(v___y_349_) == 0)
{
return v___y_349_;
}
else
{
lean_object* v_val_350_; lean_object* v___x_352_; uint8_t v_isShared_353_; uint8_t v_isSharedCheck_358_; 
v_val_350_ = lean_ctor_get(v___y_349_, 0);
v_isSharedCheck_358_ = !lean_is_exclusive(v___y_349_);
if (v_isSharedCheck_358_ == 0)
{
v___x_352_ = v___y_349_;
v_isShared_353_ = v_isSharedCheck_358_;
goto v_resetjp_351_;
}
else
{
lean_inc(v_val_350_);
lean_dec(v___y_349_);
v___x_352_ = lean_box(0);
v_isShared_353_ = v_isSharedCheck_358_;
goto v_resetjp_351_;
}
v_resetjp_351_:
{
lean_object* v___x_354_; lean_object* v___x_356_; 
v___x_354_ = lp_bounded_Bounded_Ren_slot(v_r_348_, v_val_350_);
lean_dec(v_val_350_);
if (v_isShared_353_ == 0)
{
lean_ctor_set(v___x_352_, 0, v___x_354_);
v___x_356_ = v___x_352_;
goto v_reusejp_355_;
}
else
{
lean_object* v_reuseFailAlloc_357_; 
v_reuseFailAlloc_357_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_357_, 0, v___x_354_);
v___x_356_ = v_reuseFailAlloc_357_;
goto v_reusejp_355_;
}
v_reusejp_355_:
{
return v___x_356_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_renView___lam__0___boxed(lean_object* v_r_359_, lean_object* v___y_360_){
_start:
{
lean_object* v_res_361_; 
v_res_361_ = lp_bounded_Bounded_renView___lam__0(v_r_359_, v___y_360_);
lean_dec_ref(v_r_359_);
return v_res_361_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_renView(lean_object* v_r_362_, lean_object* v_00_u03c9_363_){
_start:
{
lean_object* v___f_364_; lean_object* v___x_365_; 
lean_inc_ref(v_r_362_);
v___f_364_ = lean_alloc_closure((void*)(lp_bounded_Bounded_renView___lam__0___boxed), 2, 1);
lean_closure_set(v___f_364_, 0, v_r_362_);
v___x_365_ = lp_bounded_Bounded_KMap_ren___redArg(v_r_362_, v___f_364_, v_00_u03c9_363_);
lean_dec_ref(v_r_362_);
return v___x_365_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_renView___boxed(lean_object* v_r_366_, lean_object* v_00_u03c9_367_){
_start:
{
lean_object* v_res_368_; 
v_res_368_ = lp_bounded_Bounded_renView(v_r_366_, v_00_u03c9_367_);
lean_dec_ref(v_00_u03c9_367_);
return v_res_368_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_renComponent(lean_object* v_r_369_, lean_object* v_c_370_){
_start:
{
lean_object* v_deps_371_; lean_object* v_provs_372_; lean_object* v_script_373_; lean_object* v___x_375_; uint8_t v_isShared_376_; uint8_t v_isSharedCheck_383_; 
v_deps_371_ = lean_ctor_get(v_c_370_, 0);
v_provs_372_ = lean_ctor_get(v_c_370_, 1);
v_script_373_ = lean_ctor_get(v_c_370_, 2);
v_isSharedCheck_383_ = !lean_is_exclusive(v_c_370_);
if (v_isSharedCheck_383_ == 0)
{
v___x_375_ = v_c_370_;
v_isShared_376_ = v_isSharedCheck_383_;
goto v_resetjp_374_;
}
else
{
lean_inc(v_script_373_);
lean_inc(v_provs_372_);
lean_inc(v_deps_371_);
lean_dec(v_c_370_);
v___x_375_ = lean_box(0);
v_isShared_376_ = v_isSharedCheck_383_;
goto v_resetjp_374_;
}
v_resetjp_374_:
{
lean_object* v___x_377_; lean_object* v___x_378_; lean_object* v___x_379_; lean_object* v___x_381_; 
v___x_377_ = lp_bounded_Bounded_renKSet(v_r_369_, v_deps_371_);
lean_dec_ref(v_deps_371_);
v___x_378_ = lp_bounded_Bounded_renKSet(v_r_369_, v_provs_372_);
lean_dec_ref(v_provs_372_);
v___x_379_ = lp_bounded_Bounded_renScript(v_r_369_, v_script_373_);
if (v_isShared_376_ == 0)
{
lean_ctor_set(v___x_375_, 2, v___x_379_);
lean_ctor_set(v___x_375_, 1, v___x_378_);
lean_ctor_set(v___x_375_, 0, v___x_377_);
v___x_381_ = v___x_375_;
goto v_reusejp_380_;
}
else
{
lean_object* v_reuseFailAlloc_382_; 
v_reuseFailAlloc_382_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v_reuseFailAlloc_382_, 0, v___x_377_);
lean_ctor_set(v_reuseFailAlloc_382_, 1, v___x_378_);
lean_ctor_set(v_reuseFailAlloc_382_, 2, v___x_379_);
v___x_381_ = v_reuseFailAlloc_382_;
goto v_reusejp_380_;
}
v_reusejp_380_:
{
return v___x_381_;
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_renInv(lean_object* v_r_384_, lean_object* v_x_385_){
_start:
{
switch(lean_obj_tag(v_x_385_))
{
case 0:
{
lean_object* v_k_386_; lean_object* v___x_388_; uint8_t v_isShared_389_; uint8_t v_isSharedCheck_394_; 
v_k_386_ = lean_ctor_get(v_x_385_, 0);
v_isSharedCheck_394_ = !lean_is_exclusive(v_x_385_);
if (v_isSharedCheck_394_ == 0)
{
v___x_388_ = v_x_385_;
v_isShared_389_ = v_isSharedCheck_394_;
goto v_resetjp_387_;
}
else
{
lean_inc(v_k_386_);
lean_dec(v_x_385_);
v___x_388_ = lean_box(0);
v_isShared_389_ = v_isSharedCheck_394_;
goto v_resetjp_387_;
}
v_resetjp_387_:
{
lean_object* v___x_390_; lean_object* v___x_392_; 
v___x_390_ = lp_bounded_Bounded_Ren_key(v_r_384_, v_k_386_);
lean_dec(v_k_386_);
if (v_isShared_389_ == 0)
{
lean_ctor_set(v___x_388_, 0, v___x_390_);
v___x_392_ = v___x_388_;
goto v_reusejp_391_;
}
else
{
lean_object* v_reuseFailAlloc_393_; 
v_reuseFailAlloc_393_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_393_, 0, v___x_390_);
v___x_392_ = v_reuseFailAlloc_393_;
goto v_reusejp_391_;
}
v_reusejp_391_:
{
return v___x_392_;
}
}
}
case 1:
{
return v_x_385_;
}
default: 
{
lean_object* v_s_395_; lean_object* v___x_397_; uint8_t v_isShared_398_; uint8_t v_isSharedCheck_403_; 
v_s_395_ = lean_ctor_get(v_x_385_, 0);
v_isSharedCheck_403_ = !lean_is_exclusive(v_x_385_);
if (v_isSharedCheck_403_ == 0)
{
v___x_397_ = v_x_385_;
v_isShared_398_ = v_isSharedCheck_403_;
goto v_resetjp_396_;
}
else
{
lean_inc(v_s_395_);
lean_dec(v_x_385_);
v___x_397_ = lean_box(0);
v_isShared_398_ = v_isSharedCheck_403_;
goto v_resetjp_396_;
}
v_resetjp_396_:
{
lean_object* v___x_399_; lean_object* v___x_401_; 
v___x_399_ = lp_bounded_Bounded_Ren_slot(v_r_384_, v_s_395_);
lean_dec(v_s_395_);
if (v_isShared_398_ == 0)
{
lean_ctor_set(v___x_397_, 0, v___x_399_);
v___x_401_ = v___x_397_;
goto v_reusejp_400_;
}
else
{
lean_object* v_reuseFailAlloc_402_; 
v_reuseFailAlloc_402_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v_reuseFailAlloc_402_, 0, v___x_399_);
v___x_401_ = v_reuseFailAlloc_402_;
goto v_reusejp_400_;
}
v_reusejp_400_:
{
return v___x_401_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_renInv___boxed(lean_object* v_r_404_, lean_object* v_x_405_){
_start:
{
lean_object* v_res_406_; 
v_res_406_ = lp_bounded_Bounded_renInv(v_r_404_, v_x_405_);
lean_dec_ref(v_r_404_);
return v_res_406_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_renAcc(lean_object* v_r_407_, lean_object* v_a_408_){
_start:
{
lean_object* v___x_409_; lean_object* v___x_410_; 
v___x_409_ = lean_alloc_closure((void*)(lp_bounded_Bounded_renInv___boxed), 2, 1);
lean_closure_set(v___x_409_, 0, v_r_407_);
v___x_410_ = lp_bounded_Bounded_BList_map___redArg(v___x_409_, v_a_408_);
return v___x_410_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_renLState(lean_object* v_r_411_, lean_object* v_x_412_){
_start:
{
switch(lean_obj_tag(v_x_412_))
{
case 0:
{
lean_dec_ref(v_r_411_);
return v_x_412_;
}
case 1:
{
lean_object* v_remaining_413_; lean_object* v_acc_414_; lean_object* v_view_415_; lean_object* v___x_417_; uint8_t v_isShared_418_; uint8_t v_isSharedCheck_425_; 
v_remaining_413_ = lean_ctor_get(v_x_412_, 0);
v_acc_414_ = lean_ctor_get(v_x_412_, 1);
v_view_415_ = lean_ctor_get(v_x_412_, 2);
v_isSharedCheck_425_ = !lean_is_exclusive(v_x_412_);
if (v_isSharedCheck_425_ == 0)
{
v___x_417_ = v_x_412_;
v_isShared_418_ = v_isSharedCheck_425_;
goto v_resetjp_416_;
}
else
{
lean_inc(v_view_415_);
lean_inc(v_acc_414_);
lean_inc(v_remaining_413_);
lean_dec(v_x_412_);
v___x_417_ = lean_box(0);
v_isShared_418_ = v_isSharedCheck_425_;
goto v_resetjp_416_;
}
v_resetjp_416_:
{
lean_object* v___x_419_; lean_object* v___x_420_; lean_object* v___x_421_; lean_object* v___x_423_; 
lean_inc_ref_n(v_r_411_, 2);
v___x_419_ = lp_bounded_Bounded_renScript(v_r_411_, v_remaining_413_);
v___x_420_ = lp_bounded_Bounded_renAcc(v_r_411_, v_acc_414_);
v___x_421_ = lp_bounded_Bounded_renView(v_r_411_, v_view_415_);
lean_dec_ref(v_view_415_);
if (v_isShared_418_ == 0)
{
lean_ctor_set(v___x_417_, 2, v___x_421_);
lean_ctor_set(v___x_417_, 1, v___x_420_);
lean_ctor_set(v___x_417_, 0, v___x_419_);
v___x_423_ = v___x_417_;
goto v_reusejp_422_;
}
else
{
lean_object* v_reuseFailAlloc_424_; 
v_reuseFailAlloc_424_ = lean_alloc_ctor(1, 3, 0);
lean_ctor_set(v_reuseFailAlloc_424_, 0, v___x_419_);
lean_ctor_set(v_reuseFailAlloc_424_, 1, v___x_420_);
lean_ctor_set(v_reuseFailAlloc_424_, 2, v___x_421_);
v___x_423_ = v_reuseFailAlloc_424_;
goto v_reusejp_422_;
}
v_reusejp_422_:
{
return v___x_423_;
}
}
}
case 2:
{
lean_object* v_acc_426_; lean_object* v_view_427_; lean_object* v___x_429_; uint8_t v_isShared_430_; uint8_t v_isSharedCheck_436_; 
v_acc_426_ = lean_ctor_get(v_x_412_, 0);
v_view_427_ = lean_ctor_get(v_x_412_, 1);
v_isSharedCheck_436_ = !lean_is_exclusive(v_x_412_);
if (v_isSharedCheck_436_ == 0)
{
v___x_429_ = v_x_412_;
v_isShared_430_ = v_isSharedCheck_436_;
goto v_resetjp_428_;
}
else
{
lean_inc(v_view_427_);
lean_inc(v_acc_426_);
lean_dec(v_x_412_);
v___x_429_ = lean_box(0);
v_isShared_430_ = v_isSharedCheck_436_;
goto v_resetjp_428_;
}
v_resetjp_428_:
{
lean_object* v___x_431_; lean_object* v___x_432_; lean_object* v___x_434_; 
lean_inc_ref(v_r_411_);
v___x_431_ = lp_bounded_Bounded_renAcc(v_r_411_, v_acc_426_);
v___x_432_ = lp_bounded_Bounded_renView(v_r_411_, v_view_427_);
lean_dec_ref(v_view_427_);
if (v_isShared_430_ == 0)
{
lean_ctor_set(v___x_429_, 1, v___x_432_);
lean_ctor_set(v___x_429_, 0, v___x_431_);
v___x_434_ = v___x_429_;
goto v_reusejp_433_;
}
else
{
lean_object* v_reuseFailAlloc_435_; 
v_reuseFailAlloc_435_ = lean_alloc_ctor(2, 2, 0);
lean_ctor_set(v_reuseFailAlloc_435_, 0, v___x_431_);
lean_ctor_set(v_reuseFailAlloc_435_, 1, v___x_432_);
v___x_434_ = v_reuseFailAlloc_435_;
goto v_reusejp_433_;
}
v_reusejp_433_:
{
return v___x_434_;
}
}
}
default: 
{
lean_object* v_acc_437_; lean_object* v_view_438_; uint8_t v_o_439_; lean_object* v___x_441_; uint8_t v_isShared_442_; uint8_t v_isSharedCheck_448_; 
v_acc_437_ = lean_ctor_get(v_x_412_, 0);
v_view_438_ = lean_ctor_get(v_x_412_, 1);
v_o_439_ = lean_ctor_get_uint8(v_x_412_, sizeof(void*)*2);
v_isSharedCheck_448_ = !lean_is_exclusive(v_x_412_);
if (v_isSharedCheck_448_ == 0)
{
v___x_441_ = v_x_412_;
v_isShared_442_ = v_isSharedCheck_448_;
goto v_resetjp_440_;
}
else
{
lean_inc(v_view_438_);
lean_inc(v_acc_437_);
lean_dec(v_x_412_);
v___x_441_ = lean_box(0);
v_isShared_442_ = v_isSharedCheck_448_;
goto v_resetjp_440_;
}
v_resetjp_440_:
{
lean_object* v___x_443_; lean_object* v___x_444_; lean_object* v___x_446_; 
lean_inc_ref(v_r_411_);
v___x_443_ = lp_bounded_Bounded_renAcc(v_r_411_, v_acc_437_);
v___x_444_ = lp_bounded_Bounded_renView(v_r_411_, v_view_438_);
lean_dec_ref(v_view_438_);
if (v_isShared_442_ == 0)
{
lean_ctor_set(v___x_441_, 1, v___x_444_);
lean_ctor_set(v___x_441_, 0, v___x_443_);
v___x_446_ = v___x_441_;
goto v_reusejp_445_;
}
else
{
lean_object* v_reuseFailAlloc_447_; 
v_reuseFailAlloc_447_ = lean_alloc_ctor(3, 2, 1);
lean_ctor_set(v_reuseFailAlloc_447_, 0, v___x_443_);
lean_ctor_set(v_reuseFailAlloc_447_, 1, v___x_444_);
lean_ctor_set_uint8(v_reuseFailAlloc_447_, sizeof(void*)*2, v_o_439_);
v___x_446_ = v_reuseFailAlloc_447_;
goto v_reusejp_445_;
}
v_reusejp_445_:
{
return v___x_446_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_renFiber(lean_object* v_r_449_, lean_object* v_f_450_){
_start:
{
lean_object* v_comp_451_; lean_object* v_parent_452_; uint8_t v_retired_453_; lean_object* v_table_454_; lean_object* v_st_455_; lean_object* v___x_457_; uint8_t v_isShared_458_; uint8_t v_isSharedCheck_476_; 
v_comp_451_ = lean_ctor_get(v_f_450_, 0);
v_parent_452_ = lean_ctor_get(v_f_450_, 1);
v_retired_453_ = lean_ctor_get_uint8(v_f_450_, sizeof(void*)*4);
v_table_454_ = lean_ctor_get(v_f_450_, 2);
v_st_455_ = lean_ctor_get(v_f_450_, 3);
v_isSharedCheck_476_ = !lean_is_exclusive(v_f_450_);
if (v_isSharedCheck_476_ == 0)
{
v___x_457_ = v_f_450_;
v_isShared_458_ = v_isSharedCheck_476_;
goto v_resetjp_456_;
}
else
{
lean_inc(v_st_455_);
lean_inc(v_table_454_);
lean_inc(v_parent_452_);
lean_inc(v_comp_451_);
lean_dec(v_f_450_);
v___x_457_ = lean_box(0);
v_isShared_458_ = v_isSharedCheck_476_;
goto v_resetjp_456_;
}
v_resetjp_456_:
{
lean_object* v___x_459_; lean_object* v___y_461_; 
lean_inc_ref(v_r_449_);
v___x_459_ = lp_bounded_Bounded_renComponent(v_r_449_, v_comp_451_);
if (lean_obj_tag(v_parent_452_) == 0)
{
v___y_461_ = v_parent_452_;
goto v___jp_460_;
}
else
{
lean_object* v_val_467_; lean_object* v___x_469_; uint8_t v_isShared_470_; uint8_t v_isSharedCheck_475_; 
v_val_467_ = lean_ctor_get(v_parent_452_, 0);
v_isSharedCheck_475_ = !lean_is_exclusive(v_parent_452_);
if (v_isSharedCheck_475_ == 0)
{
v___x_469_ = v_parent_452_;
v_isShared_470_ = v_isSharedCheck_475_;
goto v_resetjp_468_;
}
else
{
lean_inc(v_val_467_);
lean_dec(v_parent_452_);
v___x_469_ = lean_box(0);
v_isShared_470_ = v_isSharedCheck_475_;
goto v_resetjp_468_;
}
v_resetjp_468_:
{
lean_object* v___x_471_; lean_object* v___x_473_; 
v___x_471_ = lp_bounded_Bounded_Ren_slot(v_r_449_, v_val_467_);
lean_dec(v_val_467_);
if (v_isShared_470_ == 0)
{
lean_ctor_set(v___x_469_, 0, v___x_471_);
v___x_473_ = v___x_469_;
goto v_reusejp_472_;
}
else
{
lean_object* v_reuseFailAlloc_474_; 
v_reuseFailAlloc_474_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_474_, 0, v___x_471_);
v___x_473_ = v_reuseFailAlloc_474_;
goto v_reusejp_472_;
}
v_reusejp_472_:
{
v___y_461_ = v___x_473_;
goto v___jp_460_;
}
}
}
v___jp_460_:
{
lean_object* v___x_462_; lean_object* v___x_463_; lean_object* v___x_465_; 
lean_inc_ref(v_r_449_);
v___x_462_ = lp_bounded_Bounded_renTable(v_r_449_, v_table_454_);
lean_dec_ref(v_table_454_);
v___x_463_ = lp_bounded_Bounded_renLState(v_r_449_, v_st_455_);
if (v_isShared_458_ == 0)
{
lean_ctor_set(v___x_457_, 3, v___x_463_);
lean_ctor_set(v___x_457_, 2, v___x_462_);
lean_ctor_set(v___x_457_, 1, v___y_461_);
lean_ctor_set(v___x_457_, 0, v___x_459_);
v___x_465_ = v___x_457_;
goto v_reusejp_464_;
}
else
{
lean_object* v_reuseFailAlloc_466_; 
v_reuseFailAlloc_466_ = lean_alloc_ctor(0, 4, 1);
lean_ctor_set(v_reuseFailAlloc_466_, 0, v___x_459_);
lean_ctor_set(v_reuseFailAlloc_466_, 1, v___y_461_);
lean_ctor_set(v_reuseFailAlloc_466_, 2, v___x_462_);
lean_ctor_set(v_reuseFailAlloc_466_, 3, v___x_463_);
lean_ctor_set_uint8(v_reuseFailAlloc_466_, sizeof(void*)*4, v_retired_453_);
v___x_465_ = v_reuseFailAlloc_466_;
goto v_reusejp_464_;
}
v_reusejp_464_:
{
return v___x_465_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_renConfig___lam__0(lean_object* v_r_477_, lean_object* v___y_478_){
_start:
{
if (lean_obj_tag(v___y_478_) == 0)
{
lean_dec_ref(v_r_477_);
return v___y_478_;
}
else
{
lean_object* v_val_479_; lean_object* v___x_481_; uint8_t v_isShared_482_; uint8_t v_isSharedCheck_487_; 
v_val_479_ = lean_ctor_get(v___y_478_, 0);
v_isSharedCheck_487_ = !lean_is_exclusive(v___y_478_);
if (v_isSharedCheck_487_ == 0)
{
v___x_481_ = v___y_478_;
v_isShared_482_ = v_isSharedCheck_487_;
goto v_resetjp_480_;
}
else
{
lean_inc(v_val_479_);
lean_dec(v___y_478_);
v___x_481_ = lean_box(0);
v_isShared_482_ = v_isSharedCheck_487_;
goto v_resetjp_480_;
}
v_resetjp_480_:
{
lean_object* v___x_483_; lean_object* v___x_485_; 
v___x_483_ = lp_bounded_Bounded_renFiber(v_r_477_, v_val_479_);
if (v_isShared_482_ == 0)
{
lean_ctor_set(v___x_481_, 0, v___x_483_);
v___x_485_ = v___x_481_;
goto v_reusejp_484_;
}
else
{
lean_object* v_reuseFailAlloc_486_; 
v_reuseFailAlloc_486_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_486_, 0, v___x_483_);
v___x_485_ = v_reuseFailAlloc_486_;
goto v_reusejp_484_;
}
v_reusejp_484_:
{
return v___x_485_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_renConfig(lean_object* v_r_488_, lean_object* v_00_u03b3_489_){
_start:
{
lean_object* v___f_490_; lean_object* v___x_491_; 
lean_inc_ref(v_r_488_);
v___f_490_ = lean_alloc_closure((void*)(lp_bounded_Bounded_renConfig___lam__0), 2, 1);
lean_closure_set(v___f_490_, 0, v_r_488_);
v___x_491_ = lp_bounded_Bounded_SMap_ren___redArg(v_r_488_, v___f_490_, v_00_u03b3_489_);
lean_dec_ref(v_r_488_);
return v___x_491_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_renConfig___boxed(lean_object* v_r_492_, lean_object* v_00_u03b3_493_){
_start:
{
lean_object* v_res_494_; 
v_res_494_ = lp_bounded_Bounded_renConfig(v_r_492_, v_00_u03b3_493_);
lean_dec_ref(v_00_u03b3_493_);
return v_res_494_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_renAct(lean_object* v_r_495_, lean_object* v_x_496_){
_start:
{
switch(lean_obj_tag(v_x_496_))
{
case 0:
{
lean_object* v_n_497_; lean_object* v_c_498_; lean_object* v___x_500_; uint8_t v_isShared_501_; uint8_t v_isSharedCheck_507_; 
v_n_497_ = lean_ctor_get(v_x_496_, 0);
v_c_498_ = lean_ctor_get(v_x_496_, 1);
v_isSharedCheck_507_ = !lean_is_exclusive(v_x_496_);
if (v_isSharedCheck_507_ == 0)
{
v___x_500_ = v_x_496_;
v_isShared_501_ = v_isSharedCheck_507_;
goto v_resetjp_499_;
}
else
{
lean_inc(v_c_498_);
lean_inc(v_n_497_);
lean_dec(v_x_496_);
v___x_500_ = lean_box(0);
v_isShared_501_ = v_isSharedCheck_507_;
goto v_resetjp_499_;
}
v_resetjp_499_:
{
lean_object* v___x_502_; lean_object* v___x_503_; lean_object* v___x_505_; 
v___x_502_ = lp_bounded_Bounded_Ren_slot(v_r_495_, v_n_497_);
lean_dec(v_n_497_);
v___x_503_ = lp_bounded_Bounded_renComponent(v_r_495_, v_c_498_);
if (v_isShared_501_ == 0)
{
lean_ctor_set(v___x_500_, 1, v___x_503_);
lean_ctor_set(v___x_500_, 0, v___x_502_);
v___x_505_ = v___x_500_;
goto v_reusejp_504_;
}
else
{
lean_object* v_reuseFailAlloc_506_; 
v_reuseFailAlloc_506_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_506_, 0, v___x_502_);
lean_ctor_set(v_reuseFailAlloc_506_, 1, v___x_503_);
v___x_505_ = v_reuseFailAlloc_506_;
goto v_reusejp_504_;
}
v_reusejp_504_:
{
return v___x_505_;
}
}
}
case 1:
{
lean_object* v_n_508_; lean_object* v___x_510_; uint8_t v_isShared_511_; uint8_t v_isSharedCheck_516_; 
v_n_508_ = lean_ctor_get(v_x_496_, 0);
v_isSharedCheck_516_ = !lean_is_exclusive(v_x_496_);
if (v_isSharedCheck_516_ == 0)
{
v___x_510_ = v_x_496_;
v_isShared_511_ = v_isSharedCheck_516_;
goto v_resetjp_509_;
}
else
{
lean_inc(v_n_508_);
lean_dec(v_x_496_);
v___x_510_ = lean_box(0);
v_isShared_511_ = v_isSharedCheck_516_;
goto v_resetjp_509_;
}
v_resetjp_509_:
{
lean_object* v___x_512_; lean_object* v___x_514_; 
v___x_512_ = lp_bounded_Bounded_Ren_slot(v_r_495_, v_n_508_);
lean_dec(v_n_508_);
lean_dec_ref(v_r_495_);
if (v_isShared_511_ == 0)
{
lean_ctor_set(v___x_510_, 0, v___x_512_);
v___x_514_ = v___x_510_;
goto v_reusejp_513_;
}
else
{
lean_object* v_reuseFailAlloc_515_; 
v_reuseFailAlloc_515_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_515_, 0, v___x_512_);
v___x_514_ = v_reuseFailAlloc_515_;
goto v_reusejp_513_;
}
v_reusejp_513_:
{
return v___x_514_;
}
}
}
case 2:
{
lean_object* v_n_517_; lean_object* v___x_519_; uint8_t v_isShared_520_; uint8_t v_isSharedCheck_525_; 
v_n_517_ = lean_ctor_get(v_x_496_, 0);
v_isSharedCheck_525_ = !lean_is_exclusive(v_x_496_);
if (v_isSharedCheck_525_ == 0)
{
v___x_519_ = v_x_496_;
v_isShared_520_ = v_isSharedCheck_525_;
goto v_resetjp_518_;
}
else
{
lean_inc(v_n_517_);
lean_dec(v_x_496_);
v___x_519_ = lean_box(0);
v_isShared_520_ = v_isSharedCheck_525_;
goto v_resetjp_518_;
}
v_resetjp_518_:
{
lean_object* v___x_521_; lean_object* v___x_523_; 
v___x_521_ = lp_bounded_Bounded_Ren_slot(v_r_495_, v_n_517_);
lean_dec(v_n_517_);
lean_dec_ref(v_r_495_);
if (v_isShared_520_ == 0)
{
lean_ctor_set(v___x_519_, 0, v___x_521_);
v___x_523_ = v___x_519_;
goto v_reusejp_522_;
}
else
{
lean_object* v_reuseFailAlloc_524_; 
v_reuseFailAlloc_524_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v_reuseFailAlloc_524_, 0, v___x_521_);
v___x_523_ = v_reuseFailAlloc_524_;
goto v_reusejp_522_;
}
v_reusejp_522_:
{
return v___x_523_;
}
}
}
case 3:
{
lean_object* v_n_526_; lean_object* v___x_528_; uint8_t v_isShared_529_; uint8_t v_isSharedCheck_534_; 
v_n_526_ = lean_ctor_get(v_x_496_, 0);
v_isSharedCheck_534_ = !lean_is_exclusive(v_x_496_);
if (v_isSharedCheck_534_ == 0)
{
v___x_528_ = v_x_496_;
v_isShared_529_ = v_isSharedCheck_534_;
goto v_resetjp_527_;
}
else
{
lean_inc(v_n_526_);
lean_dec(v_x_496_);
v___x_528_ = lean_box(0);
v_isShared_529_ = v_isSharedCheck_534_;
goto v_resetjp_527_;
}
v_resetjp_527_:
{
lean_object* v___x_530_; lean_object* v___x_532_; 
v___x_530_ = lp_bounded_Bounded_Ren_slot(v_r_495_, v_n_526_);
lean_dec(v_n_526_);
lean_dec_ref(v_r_495_);
if (v_isShared_529_ == 0)
{
lean_ctor_set(v___x_528_, 0, v___x_530_);
v___x_532_ = v___x_528_;
goto v_reusejp_531_;
}
else
{
lean_object* v_reuseFailAlloc_533_; 
v_reuseFailAlloc_533_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v_reuseFailAlloc_533_, 0, v___x_530_);
v___x_532_ = v_reuseFailAlloc_533_;
goto v_reusejp_531_;
}
v_reusejp_531_:
{
return v___x_532_;
}
}
}
case 4:
{
lean_object* v_n_535_; lean_object* v_creg_536_; lean_object* v___x_538_; uint8_t v_isShared_539_; uint8_t v_isSharedCheck_556_; 
v_n_535_ = lean_ctor_get(v_x_496_, 0);
v_creg_536_ = lean_ctor_get(v_x_496_, 1);
v_isSharedCheck_556_ = !lean_is_exclusive(v_x_496_);
if (v_isSharedCheck_556_ == 0)
{
v___x_538_ = v_x_496_;
v_isShared_539_ = v_isSharedCheck_556_;
goto v_resetjp_537_;
}
else
{
lean_inc(v_creg_536_);
lean_inc(v_n_535_);
lean_dec(v_x_496_);
v___x_538_ = lean_box(0);
v_isShared_539_ = v_isSharedCheck_556_;
goto v_resetjp_537_;
}
v_resetjp_537_:
{
lean_object* v___x_540_; 
v___x_540_ = lp_bounded_Bounded_Ren_slot(v_r_495_, v_n_535_);
lean_dec(v_n_535_);
if (lean_obj_tag(v_creg_536_) == 0)
{
lean_object* v___x_542_; 
lean_dec_ref(v_r_495_);
if (v_isShared_539_ == 0)
{
lean_ctor_set(v___x_538_, 0, v___x_540_);
v___x_542_ = v___x_538_;
goto v_reusejp_541_;
}
else
{
lean_object* v_reuseFailAlloc_543_; 
v_reuseFailAlloc_543_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v_reuseFailAlloc_543_, 0, v___x_540_);
lean_ctor_set(v_reuseFailAlloc_543_, 1, v_creg_536_);
v___x_542_ = v_reuseFailAlloc_543_;
goto v_reusejp_541_;
}
v_reusejp_541_:
{
return v___x_542_;
}
}
else
{
lean_object* v_val_544_; lean_object* v___x_546_; uint8_t v_isShared_547_; uint8_t v_isSharedCheck_555_; 
v_val_544_ = lean_ctor_get(v_creg_536_, 0);
v_isSharedCheck_555_ = !lean_is_exclusive(v_creg_536_);
if (v_isSharedCheck_555_ == 0)
{
v___x_546_ = v_creg_536_;
v_isShared_547_ = v_isSharedCheck_555_;
goto v_resetjp_545_;
}
else
{
lean_inc(v_val_544_);
lean_dec(v_creg_536_);
v___x_546_ = lean_box(0);
v_isShared_547_ = v_isSharedCheck_555_;
goto v_resetjp_545_;
}
v_resetjp_545_:
{
lean_object* v___x_548_; lean_object* v___x_550_; 
v___x_548_ = lp_bounded_Bounded_Ren_slot(v_r_495_, v_val_544_);
lean_dec(v_val_544_);
lean_dec_ref(v_r_495_);
if (v_isShared_547_ == 0)
{
lean_ctor_set(v___x_546_, 0, v___x_548_);
v___x_550_ = v___x_546_;
goto v_reusejp_549_;
}
else
{
lean_object* v_reuseFailAlloc_554_; 
v_reuseFailAlloc_554_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_554_, 0, v___x_548_);
v___x_550_ = v_reuseFailAlloc_554_;
goto v_reusejp_549_;
}
v_reusejp_549_:
{
lean_object* v___x_552_; 
if (v_isShared_539_ == 0)
{
lean_ctor_set(v___x_538_, 1, v___x_550_);
lean_ctor_set(v___x_538_, 0, v___x_540_);
v___x_552_ = v___x_538_;
goto v_reusejp_551_;
}
else
{
lean_object* v_reuseFailAlloc_553_; 
v_reuseFailAlloc_553_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v_reuseFailAlloc_553_, 0, v___x_540_);
lean_ctor_set(v_reuseFailAlloc_553_, 1, v___x_550_);
v___x_552_ = v_reuseFailAlloc_553_;
goto v_reusejp_551_;
}
v_reusejp_551_:
{
return v___x_552_;
}
}
}
}
}
}
case 5:
{
lean_object* v_n_557_; lean_object* v___x_559_; uint8_t v_isShared_560_; uint8_t v_isSharedCheck_565_; 
v_n_557_ = lean_ctor_get(v_x_496_, 0);
v_isSharedCheck_565_ = !lean_is_exclusive(v_x_496_);
if (v_isSharedCheck_565_ == 0)
{
v___x_559_ = v_x_496_;
v_isShared_560_ = v_isSharedCheck_565_;
goto v_resetjp_558_;
}
else
{
lean_inc(v_n_557_);
lean_dec(v_x_496_);
v___x_559_ = lean_box(0);
v_isShared_560_ = v_isSharedCheck_565_;
goto v_resetjp_558_;
}
v_resetjp_558_:
{
lean_object* v___x_561_; lean_object* v___x_563_; 
v___x_561_ = lp_bounded_Bounded_Ren_slot(v_r_495_, v_n_557_);
lean_dec(v_n_557_);
lean_dec_ref(v_r_495_);
if (v_isShared_560_ == 0)
{
lean_ctor_set(v___x_559_, 0, v___x_561_);
v___x_563_ = v___x_559_;
goto v_reusejp_562_;
}
else
{
lean_object* v_reuseFailAlloc_564_; 
v_reuseFailAlloc_564_ = lean_alloc_ctor(5, 1, 0);
lean_ctor_set(v_reuseFailAlloc_564_, 0, v___x_561_);
v___x_563_ = v_reuseFailAlloc_564_;
goto v_reusejp_562_;
}
v_reusejp_562_:
{
return v___x_563_;
}
}
}
case 6:
{
lean_object* v_n_566_; lean_object* v___x_568_; uint8_t v_isShared_569_; uint8_t v_isSharedCheck_574_; 
v_n_566_ = lean_ctor_get(v_x_496_, 0);
v_isSharedCheck_574_ = !lean_is_exclusive(v_x_496_);
if (v_isSharedCheck_574_ == 0)
{
v___x_568_ = v_x_496_;
v_isShared_569_ = v_isSharedCheck_574_;
goto v_resetjp_567_;
}
else
{
lean_inc(v_n_566_);
lean_dec(v_x_496_);
v___x_568_ = lean_box(0);
v_isShared_569_ = v_isSharedCheck_574_;
goto v_resetjp_567_;
}
v_resetjp_567_:
{
lean_object* v___x_570_; lean_object* v___x_572_; 
v___x_570_ = lp_bounded_Bounded_Ren_slot(v_r_495_, v_n_566_);
lean_dec(v_n_566_);
lean_dec_ref(v_r_495_);
if (v_isShared_569_ == 0)
{
lean_ctor_set(v___x_568_, 0, v___x_570_);
v___x_572_ = v___x_568_;
goto v_reusejp_571_;
}
else
{
lean_object* v_reuseFailAlloc_573_; 
v_reuseFailAlloc_573_ = lean_alloc_ctor(6, 1, 0);
lean_ctor_set(v_reuseFailAlloc_573_, 0, v___x_570_);
v___x_572_ = v_reuseFailAlloc_573_;
goto v_reusejp_571_;
}
v_reusejp_571_:
{
return v___x_572_;
}
}
}
case 7:
{
lean_object* v_n_575_; lean_object* v___x_577_; uint8_t v_isShared_578_; uint8_t v_isSharedCheck_583_; 
v_n_575_ = lean_ctor_get(v_x_496_, 0);
v_isSharedCheck_583_ = !lean_is_exclusive(v_x_496_);
if (v_isSharedCheck_583_ == 0)
{
v___x_577_ = v_x_496_;
v_isShared_578_ = v_isSharedCheck_583_;
goto v_resetjp_576_;
}
else
{
lean_inc(v_n_575_);
lean_dec(v_x_496_);
v___x_577_ = lean_box(0);
v_isShared_578_ = v_isSharedCheck_583_;
goto v_resetjp_576_;
}
v_resetjp_576_:
{
lean_object* v___x_579_; lean_object* v___x_581_; 
v___x_579_ = lp_bounded_Bounded_Ren_slot(v_r_495_, v_n_575_);
lean_dec(v_n_575_);
lean_dec_ref(v_r_495_);
if (v_isShared_578_ == 0)
{
lean_ctor_set(v___x_577_, 0, v___x_579_);
v___x_581_ = v___x_577_;
goto v_reusejp_580_;
}
else
{
lean_object* v_reuseFailAlloc_582_; 
v_reuseFailAlloc_582_ = lean_alloc_ctor(7, 1, 0);
lean_ctor_set(v_reuseFailAlloc_582_, 0, v___x_579_);
v___x_581_ = v_reuseFailAlloc_582_;
goto v_reusejp_580_;
}
v_reusejp_580_:
{
return v___x_581_;
}
}
}
case 8:
{
lean_object* v_n_584_; lean_object* v___x_586_; uint8_t v_isShared_587_; uint8_t v_isSharedCheck_592_; 
v_n_584_ = lean_ctor_get(v_x_496_, 0);
v_isSharedCheck_592_ = !lean_is_exclusive(v_x_496_);
if (v_isSharedCheck_592_ == 0)
{
v___x_586_ = v_x_496_;
v_isShared_587_ = v_isSharedCheck_592_;
goto v_resetjp_585_;
}
else
{
lean_inc(v_n_584_);
lean_dec(v_x_496_);
v___x_586_ = lean_box(0);
v_isShared_587_ = v_isSharedCheck_592_;
goto v_resetjp_585_;
}
v_resetjp_585_:
{
lean_object* v___x_588_; lean_object* v___x_590_; 
v___x_588_ = lp_bounded_Bounded_Ren_slot(v_r_495_, v_n_584_);
lean_dec(v_n_584_);
lean_dec_ref(v_r_495_);
if (v_isShared_587_ == 0)
{
lean_ctor_set(v___x_586_, 0, v___x_588_);
v___x_590_ = v___x_586_;
goto v_reusejp_589_;
}
else
{
lean_object* v_reuseFailAlloc_591_; 
v_reuseFailAlloc_591_ = lean_alloc_ctor(8, 1, 0);
lean_ctor_set(v_reuseFailAlloc_591_, 0, v___x_588_);
v___x_590_ = v_reuseFailAlloc_591_;
goto v_reusejp_589_;
}
v_reusejp_589_:
{
return v___x_590_;
}
}
}
default: 
{
lean_object* v_n_593_; lean_object* v___x_595_; uint8_t v_isShared_596_; uint8_t v_isSharedCheck_601_; 
v_n_593_ = lean_ctor_get(v_x_496_, 0);
v_isSharedCheck_601_ = !lean_is_exclusive(v_x_496_);
if (v_isSharedCheck_601_ == 0)
{
v___x_595_ = v_x_496_;
v_isShared_596_ = v_isSharedCheck_601_;
goto v_resetjp_594_;
}
else
{
lean_inc(v_n_593_);
lean_dec(v_x_496_);
v___x_595_ = lean_box(0);
v_isShared_596_ = v_isSharedCheck_601_;
goto v_resetjp_594_;
}
v_resetjp_594_:
{
lean_object* v___x_597_; lean_object* v___x_599_; 
v___x_597_ = lp_bounded_Bounded_Ren_slot(v_r_495_, v_n_593_);
lean_dec(v_n_593_);
lean_dec_ref(v_r_495_);
if (v_isShared_596_ == 0)
{
lean_ctor_set(v___x_595_, 0, v___x_597_);
v___x_599_ = v___x_595_;
goto v_reusejp_598_;
}
else
{
lean_object* v_reuseFailAlloc_600_; 
v_reuseFailAlloc_600_ = lean_alloc_ctor(9, 1, 0);
lean_ctor_set(v_reuseFailAlloc_600_, 0, v___x_597_);
v___x_599_ = v_reuseFailAlloc_600_;
goto v_reusejp_598_;
}
v_reusejp_598_:
{
return v___x_599_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_renEvent(lean_object* v_r_602_, lean_object* v_x_603_){
_start:
{
switch(lean_obj_tag(v_x_603_))
{
case 0:
{
lean_object* v_n_604_; lean_object* v___x_606_; uint8_t v_isShared_607_; uint8_t v_isSharedCheck_612_; 
v_n_604_ = lean_ctor_get(v_x_603_, 0);
v_isSharedCheck_612_ = !lean_is_exclusive(v_x_603_);
if (v_isSharedCheck_612_ == 0)
{
v___x_606_ = v_x_603_;
v_isShared_607_ = v_isSharedCheck_612_;
goto v_resetjp_605_;
}
else
{
lean_inc(v_n_604_);
lean_dec(v_x_603_);
v___x_606_ = lean_box(0);
v_isShared_607_ = v_isSharedCheck_612_;
goto v_resetjp_605_;
}
v_resetjp_605_:
{
lean_object* v___x_608_; lean_object* v___x_610_; 
v___x_608_ = lp_bounded_Bounded_Ren_slot(v_r_602_, v_n_604_);
lean_dec(v_n_604_);
if (v_isShared_607_ == 0)
{
lean_ctor_set(v___x_606_, 0, v___x_608_);
v___x_610_ = v___x_606_;
goto v_reusejp_609_;
}
else
{
lean_object* v_reuseFailAlloc_611_; 
v_reuseFailAlloc_611_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_611_, 0, v___x_608_);
v___x_610_ = v_reuseFailAlloc_611_;
goto v_reusejp_609_;
}
v_reusejp_609_:
{
return v___x_610_;
}
}
}
case 1:
{
lean_object* v_n_613_; lean_object* v___x_615_; uint8_t v_isShared_616_; uint8_t v_isSharedCheck_621_; 
v_n_613_ = lean_ctor_get(v_x_603_, 0);
v_isSharedCheck_621_ = !lean_is_exclusive(v_x_603_);
if (v_isSharedCheck_621_ == 0)
{
v___x_615_ = v_x_603_;
v_isShared_616_ = v_isSharedCheck_621_;
goto v_resetjp_614_;
}
else
{
lean_inc(v_n_613_);
lean_dec(v_x_603_);
v___x_615_ = lean_box(0);
v_isShared_616_ = v_isSharedCheck_621_;
goto v_resetjp_614_;
}
v_resetjp_614_:
{
lean_object* v___x_617_; lean_object* v___x_619_; 
v___x_617_ = lp_bounded_Bounded_Ren_slot(v_r_602_, v_n_613_);
lean_dec(v_n_613_);
if (v_isShared_616_ == 0)
{
lean_ctor_set(v___x_615_, 0, v___x_617_);
v___x_619_ = v___x_615_;
goto v_reusejp_618_;
}
else
{
lean_object* v_reuseFailAlloc_620_; 
v_reuseFailAlloc_620_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_620_, 0, v___x_617_);
v___x_619_ = v_reuseFailAlloc_620_;
goto v_reusejp_618_;
}
v_reusejp_618_:
{
return v___x_619_;
}
}
}
case 2:
{
lean_object* v_n_622_; lean_object* v___x_624_; uint8_t v_isShared_625_; uint8_t v_isSharedCheck_630_; 
v_n_622_ = lean_ctor_get(v_x_603_, 0);
v_isSharedCheck_630_ = !lean_is_exclusive(v_x_603_);
if (v_isSharedCheck_630_ == 0)
{
v___x_624_ = v_x_603_;
v_isShared_625_ = v_isSharedCheck_630_;
goto v_resetjp_623_;
}
else
{
lean_inc(v_n_622_);
lean_dec(v_x_603_);
v___x_624_ = lean_box(0);
v_isShared_625_ = v_isSharedCheck_630_;
goto v_resetjp_623_;
}
v_resetjp_623_:
{
lean_object* v___x_626_; lean_object* v___x_628_; 
v___x_626_ = lp_bounded_Bounded_Ren_slot(v_r_602_, v_n_622_);
lean_dec(v_n_622_);
if (v_isShared_625_ == 0)
{
lean_ctor_set(v___x_624_, 0, v___x_626_);
v___x_628_ = v___x_624_;
goto v_reusejp_627_;
}
else
{
lean_object* v_reuseFailAlloc_629_; 
v_reuseFailAlloc_629_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v_reuseFailAlloc_629_, 0, v___x_626_);
v___x_628_ = v_reuseFailAlloc_629_;
goto v_reusejp_627_;
}
v_reusejp_627_:
{
return v___x_628_;
}
}
}
case 3:
{
lean_object* v_n_631_; lean_object* v___x_633_; uint8_t v_isShared_634_; uint8_t v_isSharedCheck_639_; 
v_n_631_ = lean_ctor_get(v_x_603_, 0);
v_isSharedCheck_639_ = !lean_is_exclusive(v_x_603_);
if (v_isSharedCheck_639_ == 0)
{
v___x_633_ = v_x_603_;
v_isShared_634_ = v_isSharedCheck_639_;
goto v_resetjp_632_;
}
else
{
lean_inc(v_n_631_);
lean_dec(v_x_603_);
v___x_633_ = lean_box(0);
v_isShared_634_ = v_isSharedCheck_639_;
goto v_resetjp_632_;
}
v_resetjp_632_:
{
lean_object* v___x_635_; lean_object* v___x_637_; 
v___x_635_ = lp_bounded_Bounded_Ren_slot(v_r_602_, v_n_631_);
lean_dec(v_n_631_);
if (v_isShared_634_ == 0)
{
lean_ctor_set(v___x_633_, 0, v___x_635_);
v___x_637_ = v___x_633_;
goto v_reusejp_636_;
}
else
{
lean_object* v_reuseFailAlloc_638_; 
v_reuseFailAlloc_638_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v_reuseFailAlloc_638_, 0, v___x_635_);
v___x_637_ = v_reuseFailAlloc_638_;
goto v_reusejp_636_;
}
v_reusejp_636_:
{
return v___x_637_;
}
}
}
case 4:
{
lean_object* v_n_640_; lean_object* v_k_641_; lean_object* v___x_643_; uint8_t v_isShared_644_; uint8_t v_isSharedCheck_650_; 
v_n_640_ = lean_ctor_get(v_x_603_, 0);
v_k_641_ = lean_ctor_get(v_x_603_, 1);
v_isSharedCheck_650_ = !lean_is_exclusive(v_x_603_);
if (v_isSharedCheck_650_ == 0)
{
v___x_643_ = v_x_603_;
v_isShared_644_ = v_isSharedCheck_650_;
goto v_resetjp_642_;
}
else
{
lean_inc(v_k_641_);
lean_inc(v_n_640_);
lean_dec(v_x_603_);
v___x_643_ = lean_box(0);
v_isShared_644_ = v_isSharedCheck_650_;
goto v_resetjp_642_;
}
v_resetjp_642_:
{
lean_object* v___x_645_; lean_object* v___x_646_; lean_object* v___x_648_; 
v___x_645_ = lp_bounded_Bounded_Ren_slot(v_r_602_, v_n_640_);
lean_dec(v_n_640_);
v___x_646_ = lp_bounded_Bounded_Ren_key(v_r_602_, v_k_641_);
lean_dec(v_k_641_);
if (v_isShared_644_ == 0)
{
lean_ctor_set(v___x_643_, 1, v___x_646_);
lean_ctor_set(v___x_643_, 0, v___x_645_);
v___x_648_ = v___x_643_;
goto v_reusejp_647_;
}
else
{
lean_object* v_reuseFailAlloc_649_; 
v_reuseFailAlloc_649_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v_reuseFailAlloc_649_, 0, v___x_645_);
lean_ctor_set(v_reuseFailAlloc_649_, 1, v___x_646_);
v___x_648_ = v_reuseFailAlloc_649_;
goto v_reusejp_647_;
}
v_reusejp_647_:
{
return v___x_648_;
}
}
}
case 5:
{
lean_object* v_n_651_; lean_object* v_t_652_; lean_object* v___x_654_; uint8_t v_isShared_655_; uint8_t v_isSharedCheck_660_; 
v_n_651_ = lean_ctor_get(v_x_603_, 0);
v_t_652_ = lean_ctor_get(v_x_603_, 1);
v_isSharedCheck_660_ = !lean_is_exclusive(v_x_603_);
if (v_isSharedCheck_660_ == 0)
{
v___x_654_ = v_x_603_;
v_isShared_655_ = v_isSharedCheck_660_;
goto v_resetjp_653_;
}
else
{
lean_inc(v_t_652_);
lean_inc(v_n_651_);
lean_dec(v_x_603_);
v___x_654_ = lean_box(0);
v_isShared_655_ = v_isSharedCheck_660_;
goto v_resetjp_653_;
}
v_resetjp_653_:
{
lean_object* v___x_656_; lean_object* v___x_658_; 
v___x_656_ = lp_bounded_Bounded_Ren_slot(v_r_602_, v_n_651_);
lean_dec(v_n_651_);
if (v_isShared_655_ == 0)
{
lean_ctor_set(v___x_654_, 0, v___x_656_);
v___x_658_ = v___x_654_;
goto v_reusejp_657_;
}
else
{
lean_object* v_reuseFailAlloc_659_; 
v_reuseFailAlloc_659_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v_reuseFailAlloc_659_, 0, v___x_656_);
lean_ctor_set(v_reuseFailAlloc_659_, 1, v_t_652_);
v___x_658_ = v_reuseFailAlloc_659_;
goto v_reusejp_657_;
}
v_reusejp_657_:
{
return v___x_658_;
}
}
}
case 6:
{
lean_object* v_n_661_; lean_object* v_k_662_; lean_object* v_v_663_; lean_object* v___x_665_; uint8_t v_isShared_666_; uint8_t v_isSharedCheck_673_; 
v_n_661_ = lean_ctor_get(v_x_603_, 0);
v_k_662_ = lean_ctor_get(v_x_603_, 1);
v_v_663_ = lean_ctor_get(v_x_603_, 2);
v_isSharedCheck_673_ = !lean_is_exclusive(v_x_603_);
if (v_isSharedCheck_673_ == 0)
{
v___x_665_ = v_x_603_;
v_isShared_666_ = v_isSharedCheck_673_;
goto v_resetjp_664_;
}
else
{
lean_inc(v_v_663_);
lean_inc(v_k_662_);
lean_inc(v_n_661_);
lean_dec(v_x_603_);
v___x_665_ = lean_box(0);
v_isShared_666_ = v_isSharedCheck_673_;
goto v_resetjp_664_;
}
v_resetjp_664_:
{
lean_object* v___x_667_; lean_object* v___x_668_; lean_object* v___x_669_; lean_object* v___x_671_; 
v___x_667_ = lp_bounded_Bounded_Ren_slot(v_r_602_, v_n_661_);
lean_dec(v_n_661_);
v___x_668_ = lp_bounded_Bounded_Ren_key(v_r_602_, v_k_662_);
lean_dec(v_k_662_);
v___x_669_ = lp_bounded_Bounded_Ren_val(v_r_602_, v_v_663_);
lean_dec(v_v_663_);
if (v_isShared_666_ == 0)
{
lean_ctor_set(v___x_665_, 2, v___x_669_);
lean_ctor_set(v___x_665_, 1, v___x_668_);
lean_ctor_set(v___x_665_, 0, v___x_667_);
v___x_671_ = v___x_665_;
goto v_reusejp_670_;
}
else
{
lean_object* v_reuseFailAlloc_672_; 
v_reuseFailAlloc_672_ = lean_alloc_ctor(6, 3, 0);
lean_ctor_set(v_reuseFailAlloc_672_, 0, v___x_667_);
lean_ctor_set(v_reuseFailAlloc_672_, 1, v___x_668_);
lean_ctor_set(v_reuseFailAlloc_672_, 2, v___x_669_);
v___x_671_ = v_reuseFailAlloc_672_;
goto v_reusejp_670_;
}
v_reusejp_670_:
{
return v___x_671_;
}
}
}
case 7:
{
lean_object* v_n_674_; lean_object* v_k_675_; uint8_t v_ia_676_; lean_object* v___x_678_; uint8_t v_isShared_679_; uint8_t v_isSharedCheck_685_; 
v_n_674_ = lean_ctor_get(v_x_603_, 0);
v_k_675_ = lean_ctor_get(v_x_603_, 1);
v_ia_676_ = lean_ctor_get_uint8(v_x_603_, sizeof(void*)*2);
v_isSharedCheck_685_ = !lean_is_exclusive(v_x_603_);
if (v_isSharedCheck_685_ == 0)
{
v___x_678_ = v_x_603_;
v_isShared_679_ = v_isSharedCheck_685_;
goto v_resetjp_677_;
}
else
{
lean_inc(v_k_675_);
lean_inc(v_n_674_);
lean_dec(v_x_603_);
v___x_678_ = lean_box(0);
v_isShared_679_ = v_isSharedCheck_685_;
goto v_resetjp_677_;
}
v_resetjp_677_:
{
lean_object* v___x_680_; lean_object* v___x_681_; lean_object* v___x_683_; 
v___x_680_ = lp_bounded_Bounded_Ren_slot(v_r_602_, v_n_674_);
lean_dec(v_n_674_);
v___x_681_ = lp_bounded_Bounded_Ren_key(v_r_602_, v_k_675_);
lean_dec(v_k_675_);
if (v_isShared_679_ == 0)
{
lean_ctor_set(v___x_678_, 1, v___x_681_);
lean_ctor_set(v___x_678_, 0, v___x_680_);
v___x_683_ = v___x_678_;
goto v_reusejp_682_;
}
else
{
lean_object* v_reuseFailAlloc_684_; 
v_reuseFailAlloc_684_ = lean_alloc_ctor(7, 2, 1);
lean_ctor_set(v_reuseFailAlloc_684_, 0, v___x_680_);
lean_ctor_set(v_reuseFailAlloc_684_, 1, v___x_681_);
lean_ctor_set_uint8(v_reuseFailAlloc_684_, sizeof(void*)*2, v_ia_676_);
v___x_683_ = v_reuseFailAlloc_684_;
goto v_reusejp_682_;
}
v_reusejp_682_:
{
return v___x_683_;
}
}
}
case 8:
{
lean_object* v_n_686_; lean_object* v_k_687_; lean_object* v_v_688_; lean_object* v___x_690_; uint8_t v_isShared_691_; uint8_t v_isSharedCheck_698_; 
v_n_686_ = lean_ctor_get(v_x_603_, 0);
v_k_687_ = lean_ctor_get(v_x_603_, 1);
v_v_688_ = lean_ctor_get(v_x_603_, 2);
v_isSharedCheck_698_ = !lean_is_exclusive(v_x_603_);
if (v_isSharedCheck_698_ == 0)
{
v___x_690_ = v_x_603_;
v_isShared_691_ = v_isSharedCheck_698_;
goto v_resetjp_689_;
}
else
{
lean_inc(v_v_688_);
lean_inc(v_k_687_);
lean_inc(v_n_686_);
lean_dec(v_x_603_);
v___x_690_ = lean_box(0);
v_isShared_691_ = v_isSharedCheck_698_;
goto v_resetjp_689_;
}
v_resetjp_689_:
{
lean_object* v___x_692_; lean_object* v___x_693_; lean_object* v___x_694_; lean_object* v___x_696_; 
v___x_692_ = lp_bounded_Bounded_Ren_slot(v_r_602_, v_n_686_);
lean_dec(v_n_686_);
v___x_693_ = lp_bounded_Bounded_Ren_key(v_r_602_, v_k_687_);
lean_dec(v_k_687_);
v___x_694_ = lp_bounded_Bounded_Ren_val(v_r_602_, v_v_688_);
lean_dec(v_v_688_);
if (v_isShared_691_ == 0)
{
lean_ctor_set(v___x_690_, 2, v___x_694_);
lean_ctor_set(v___x_690_, 1, v___x_693_);
lean_ctor_set(v___x_690_, 0, v___x_692_);
v___x_696_ = v___x_690_;
goto v_reusejp_695_;
}
else
{
lean_object* v_reuseFailAlloc_697_; 
v_reuseFailAlloc_697_ = lean_alloc_ctor(8, 3, 0);
lean_ctor_set(v_reuseFailAlloc_697_, 0, v___x_692_);
lean_ctor_set(v_reuseFailAlloc_697_, 1, v___x_693_);
lean_ctor_set(v_reuseFailAlloc_697_, 2, v___x_694_);
v___x_696_ = v_reuseFailAlloc_697_;
goto v_reusejp_695_;
}
v_reusejp_695_:
{
return v___x_696_;
}
}
}
case 9:
{
lean_object* v_n_699_; lean_object* v_child_700_; lean_object* v___x_702_; uint8_t v_isShared_703_; uint8_t v_isSharedCheck_709_; 
v_n_699_ = lean_ctor_get(v_x_603_, 0);
v_child_700_ = lean_ctor_get(v_x_603_, 1);
v_isSharedCheck_709_ = !lean_is_exclusive(v_x_603_);
if (v_isSharedCheck_709_ == 0)
{
v___x_702_ = v_x_603_;
v_isShared_703_ = v_isSharedCheck_709_;
goto v_resetjp_701_;
}
else
{
lean_inc(v_child_700_);
lean_inc(v_n_699_);
lean_dec(v_x_603_);
v___x_702_ = lean_box(0);
v_isShared_703_ = v_isSharedCheck_709_;
goto v_resetjp_701_;
}
v_resetjp_701_:
{
lean_object* v___x_704_; lean_object* v___x_705_; lean_object* v___x_707_; 
v___x_704_ = lp_bounded_Bounded_Ren_slot(v_r_602_, v_n_699_);
lean_dec(v_n_699_);
v___x_705_ = lp_bounded_Bounded_Ren_slot(v_r_602_, v_child_700_);
lean_dec(v_child_700_);
if (v_isShared_703_ == 0)
{
lean_ctor_set(v___x_702_, 1, v___x_705_);
lean_ctor_set(v___x_702_, 0, v___x_704_);
v___x_707_ = v___x_702_;
goto v_reusejp_706_;
}
else
{
lean_object* v_reuseFailAlloc_708_; 
v_reuseFailAlloc_708_ = lean_alloc_ctor(9, 2, 0);
lean_ctor_set(v_reuseFailAlloc_708_, 0, v___x_704_);
lean_ctor_set(v_reuseFailAlloc_708_, 1, v___x_705_);
v___x_707_ = v_reuseFailAlloc_708_;
goto v_reusejp_706_;
}
v_reusejp_706_:
{
return v___x_707_;
}
}
}
case 10:
{
lean_object* v_n_710_; lean_object* v___x_712_; uint8_t v_isShared_713_; uint8_t v_isSharedCheck_718_; 
v_n_710_ = lean_ctor_get(v_x_603_, 0);
v_isSharedCheck_718_ = !lean_is_exclusive(v_x_603_);
if (v_isSharedCheck_718_ == 0)
{
v___x_712_ = v_x_603_;
v_isShared_713_ = v_isSharedCheck_718_;
goto v_resetjp_711_;
}
else
{
lean_inc(v_n_710_);
lean_dec(v_x_603_);
v___x_712_ = lean_box(0);
v_isShared_713_ = v_isSharedCheck_718_;
goto v_resetjp_711_;
}
v_resetjp_711_:
{
lean_object* v___x_714_; lean_object* v___x_716_; 
v___x_714_ = lp_bounded_Bounded_Ren_slot(v_r_602_, v_n_710_);
lean_dec(v_n_710_);
if (v_isShared_713_ == 0)
{
lean_ctor_set(v___x_712_, 0, v___x_714_);
v___x_716_ = v___x_712_;
goto v_reusejp_715_;
}
else
{
lean_object* v_reuseFailAlloc_717_; 
v_reuseFailAlloc_717_ = lean_alloc_ctor(10, 1, 0);
lean_ctor_set(v_reuseFailAlloc_717_, 0, v___x_714_);
v___x_716_ = v_reuseFailAlloc_717_;
goto v_reusejp_715_;
}
v_reusejp_715_:
{
return v___x_716_;
}
}
}
case 11:
{
lean_object* v_n_719_; lean_object* v___x_721_; uint8_t v_isShared_722_; uint8_t v_isSharedCheck_727_; 
v_n_719_ = lean_ctor_get(v_x_603_, 0);
v_isSharedCheck_727_ = !lean_is_exclusive(v_x_603_);
if (v_isSharedCheck_727_ == 0)
{
v___x_721_ = v_x_603_;
v_isShared_722_ = v_isSharedCheck_727_;
goto v_resetjp_720_;
}
else
{
lean_inc(v_n_719_);
lean_dec(v_x_603_);
v___x_721_ = lean_box(0);
v_isShared_722_ = v_isSharedCheck_727_;
goto v_resetjp_720_;
}
v_resetjp_720_:
{
lean_object* v___x_723_; lean_object* v___x_725_; 
v___x_723_ = lp_bounded_Bounded_Ren_slot(v_r_602_, v_n_719_);
lean_dec(v_n_719_);
if (v_isShared_722_ == 0)
{
lean_ctor_set(v___x_721_, 0, v___x_723_);
v___x_725_ = v___x_721_;
goto v_reusejp_724_;
}
else
{
lean_object* v_reuseFailAlloc_726_; 
v_reuseFailAlloc_726_ = lean_alloc_ctor(11, 1, 0);
lean_ctor_set(v_reuseFailAlloc_726_, 0, v___x_723_);
v___x_725_ = v_reuseFailAlloc_726_;
goto v_reusejp_724_;
}
v_reusejp_724_:
{
return v___x_725_;
}
}
}
case 12:
{
lean_object* v_n_728_; lean_object* v___x_730_; uint8_t v_isShared_731_; uint8_t v_isSharedCheck_736_; 
v_n_728_ = lean_ctor_get(v_x_603_, 0);
v_isSharedCheck_736_ = !lean_is_exclusive(v_x_603_);
if (v_isSharedCheck_736_ == 0)
{
v___x_730_ = v_x_603_;
v_isShared_731_ = v_isSharedCheck_736_;
goto v_resetjp_729_;
}
else
{
lean_inc(v_n_728_);
lean_dec(v_x_603_);
v___x_730_ = lean_box(0);
v_isShared_731_ = v_isSharedCheck_736_;
goto v_resetjp_729_;
}
v_resetjp_729_:
{
lean_object* v___x_732_; lean_object* v___x_734_; 
v___x_732_ = lp_bounded_Bounded_Ren_slot(v_r_602_, v_n_728_);
lean_dec(v_n_728_);
if (v_isShared_731_ == 0)
{
lean_ctor_set(v___x_730_, 0, v___x_732_);
v___x_734_ = v___x_730_;
goto v_reusejp_733_;
}
else
{
lean_object* v_reuseFailAlloc_735_; 
v_reuseFailAlloc_735_ = lean_alloc_ctor(12, 1, 0);
lean_ctor_set(v_reuseFailAlloc_735_, 0, v___x_732_);
v___x_734_ = v_reuseFailAlloc_735_;
goto v_reusejp_733_;
}
v_reusejp_733_:
{
return v___x_734_;
}
}
}
case 13:
{
lean_object* v_n_737_; lean_object* v___x_739_; uint8_t v_isShared_740_; uint8_t v_isSharedCheck_745_; 
v_n_737_ = lean_ctor_get(v_x_603_, 0);
v_isSharedCheck_745_ = !lean_is_exclusive(v_x_603_);
if (v_isSharedCheck_745_ == 0)
{
v___x_739_ = v_x_603_;
v_isShared_740_ = v_isSharedCheck_745_;
goto v_resetjp_738_;
}
else
{
lean_inc(v_n_737_);
lean_dec(v_x_603_);
v___x_739_ = lean_box(0);
v_isShared_740_ = v_isSharedCheck_745_;
goto v_resetjp_738_;
}
v_resetjp_738_:
{
lean_object* v___x_741_; lean_object* v___x_743_; 
v___x_741_ = lp_bounded_Bounded_Ren_slot(v_r_602_, v_n_737_);
lean_dec(v_n_737_);
if (v_isShared_740_ == 0)
{
lean_ctor_set(v___x_739_, 0, v___x_741_);
v___x_743_ = v___x_739_;
goto v_reusejp_742_;
}
else
{
lean_object* v_reuseFailAlloc_744_; 
v_reuseFailAlloc_744_ = lean_alloc_ctor(13, 1, 0);
lean_ctor_set(v_reuseFailAlloc_744_, 0, v___x_741_);
v___x_743_ = v_reuseFailAlloc_744_;
goto v_reusejp_742_;
}
v_reusejp_742_:
{
return v___x_743_;
}
}
}
case 14:
{
lean_object* v_n_746_; lean_object* v_t_747_; lean_object* v___x_749_; uint8_t v_isShared_750_; uint8_t v_isSharedCheck_755_; 
v_n_746_ = lean_ctor_get(v_x_603_, 0);
v_t_747_ = lean_ctor_get(v_x_603_, 1);
v_isSharedCheck_755_ = !lean_is_exclusive(v_x_603_);
if (v_isSharedCheck_755_ == 0)
{
v___x_749_ = v_x_603_;
v_isShared_750_ = v_isSharedCheck_755_;
goto v_resetjp_748_;
}
else
{
lean_inc(v_t_747_);
lean_inc(v_n_746_);
lean_dec(v_x_603_);
v___x_749_ = lean_box(0);
v_isShared_750_ = v_isSharedCheck_755_;
goto v_resetjp_748_;
}
v_resetjp_748_:
{
lean_object* v___x_751_; lean_object* v___x_753_; 
v___x_751_ = lp_bounded_Bounded_Ren_slot(v_r_602_, v_n_746_);
lean_dec(v_n_746_);
if (v_isShared_750_ == 0)
{
lean_ctor_set(v___x_749_, 0, v___x_751_);
v___x_753_ = v___x_749_;
goto v_reusejp_752_;
}
else
{
lean_object* v_reuseFailAlloc_754_; 
v_reuseFailAlloc_754_ = lean_alloc_ctor(14, 2, 0);
lean_ctor_set(v_reuseFailAlloc_754_, 0, v___x_751_);
lean_ctor_set(v_reuseFailAlloc_754_, 1, v_t_747_);
v___x_753_ = v_reuseFailAlloc_754_;
goto v_reusejp_752_;
}
v_reusejp_752_:
{
return v___x_753_;
}
}
}
case 15:
{
lean_object* v_n_756_; lean_object* v_k_757_; lean_object* v___x_759_; uint8_t v_isShared_760_; uint8_t v_isSharedCheck_766_; 
v_n_756_ = lean_ctor_get(v_x_603_, 0);
v_k_757_ = lean_ctor_get(v_x_603_, 1);
v_isSharedCheck_766_ = !lean_is_exclusive(v_x_603_);
if (v_isSharedCheck_766_ == 0)
{
v___x_759_ = v_x_603_;
v_isShared_760_ = v_isSharedCheck_766_;
goto v_resetjp_758_;
}
else
{
lean_inc(v_k_757_);
lean_inc(v_n_756_);
lean_dec(v_x_603_);
v___x_759_ = lean_box(0);
v_isShared_760_ = v_isSharedCheck_766_;
goto v_resetjp_758_;
}
v_resetjp_758_:
{
lean_object* v___x_761_; lean_object* v___x_762_; lean_object* v___x_764_; 
v___x_761_ = lp_bounded_Bounded_Ren_slot(v_r_602_, v_n_756_);
lean_dec(v_n_756_);
v___x_762_ = lp_bounded_Bounded_Ren_key(v_r_602_, v_k_757_);
lean_dec(v_k_757_);
if (v_isShared_760_ == 0)
{
lean_ctor_set(v___x_759_, 1, v___x_762_);
lean_ctor_set(v___x_759_, 0, v___x_761_);
v___x_764_ = v___x_759_;
goto v_reusejp_763_;
}
else
{
lean_object* v_reuseFailAlloc_765_; 
v_reuseFailAlloc_765_ = lean_alloc_ctor(15, 2, 0);
lean_ctor_set(v_reuseFailAlloc_765_, 0, v___x_761_);
lean_ctor_set(v_reuseFailAlloc_765_, 1, v___x_762_);
v___x_764_ = v_reuseFailAlloc_765_;
goto v_reusejp_763_;
}
v_reusejp_763_:
{
return v___x_764_;
}
}
}
case 16:
{
lean_object* v_n_767_; lean_object* v_child_768_; lean_object* v___x_770_; uint8_t v_isShared_771_; uint8_t v_isSharedCheck_777_; 
v_n_767_ = lean_ctor_get(v_x_603_, 0);
v_child_768_ = lean_ctor_get(v_x_603_, 1);
v_isSharedCheck_777_ = !lean_is_exclusive(v_x_603_);
if (v_isSharedCheck_777_ == 0)
{
v___x_770_ = v_x_603_;
v_isShared_771_ = v_isSharedCheck_777_;
goto v_resetjp_769_;
}
else
{
lean_inc(v_child_768_);
lean_inc(v_n_767_);
lean_dec(v_x_603_);
v___x_770_ = lean_box(0);
v_isShared_771_ = v_isSharedCheck_777_;
goto v_resetjp_769_;
}
v_resetjp_769_:
{
lean_object* v___x_772_; lean_object* v___x_773_; lean_object* v___x_775_; 
v___x_772_ = lp_bounded_Bounded_Ren_slot(v_r_602_, v_n_767_);
lean_dec(v_n_767_);
v___x_773_ = lp_bounded_Bounded_Ren_slot(v_r_602_, v_child_768_);
lean_dec(v_child_768_);
if (v_isShared_771_ == 0)
{
lean_ctor_set(v___x_770_, 1, v___x_773_);
lean_ctor_set(v___x_770_, 0, v___x_772_);
v___x_775_ = v___x_770_;
goto v_reusejp_774_;
}
else
{
lean_object* v_reuseFailAlloc_776_; 
v_reuseFailAlloc_776_ = lean_alloc_ctor(16, 2, 0);
lean_ctor_set(v_reuseFailAlloc_776_, 0, v___x_772_);
lean_ctor_set(v_reuseFailAlloc_776_, 1, v___x_773_);
v___x_775_ = v_reuseFailAlloc_776_;
goto v_reusejp_774_;
}
v_reusejp_774_:
{
return v___x_775_;
}
}
}
default: 
{
lean_object* v_n_778_; lean_object* v___x_780_; uint8_t v_isShared_781_; uint8_t v_isSharedCheck_786_; 
v_n_778_ = lean_ctor_get(v_x_603_, 0);
v_isSharedCheck_786_ = !lean_is_exclusive(v_x_603_);
if (v_isSharedCheck_786_ == 0)
{
v___x_780_ = v_x_603_;
v_isShared_781_ = v_isSharedCheck_786_;
goto v_resetjp_779_;
}
else
{
lean_inc(v_n_778_);
lean_dec(v_x_603_);
v___x_780_ = lean_box(0);
v_isShared_781_ = v_isSharedCheck_786_;
goto v_resetjp_779_;
}
v_resetjp_779_:
{
lean_object* v___x_782_; lean_object* v___x_784_; 
v___x_782_ = lp_bounded_Bounded_Ren_slot(v_r_602_, v_n_778_);
lean_dec(v_n_778_);
if (v_isShared_781_ == 0)
{
lean_ctor_set(v___x_780_, 0, v___x_782_);
v___x_784_ = v___x_780_;
goto v_reusejp_783_;
}
else
{
lean_object* v_reuseFailAlloc_785_; 
v_reuseFailAlloc_785_ = lean_alloc_ctor(17, 1, 0);
lean_ctor_set(v_reuseFailAlloc_785_, 0, v___x_782_);
v___x_784_ = v_reuseFailAlloc_785_;
goto v_reusejp_783_;
}
v_reusejp_783_:
{
return v___x_784_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_renEvent___boxed(lean_object* v_r_787_, lean_object* v_x_788_){
_start:
{
lean_object* v_res_789_; 
v_res_789_ = lp_bounded_Bounded_renEvent(v_r_787_, v_x_788_);
lean_dec_ref(v_r_787_);
return v_res_789_;
}
}
LEAN_EXPORT lean_object* lp_bounded_List_mapTR_loop___at___00Bounded_renEv_spec__0(lean_object* v_r_790_, lean_object* v_a_791_, lean_object* v_a_792_){
_start:
{
if (lean_obj_tag(v_a_791_) == 0)
{
lean_object* v___x_793_; 
v___x_793_ = l_List_reverse___redArg(v_a_792_);
return v___x_793_;
}
else
{
lean_object* v_head_794_; lean_object* v_tail_795_; lean_object* v___x_797_; uint8_t v_isShared_798_; uint8_t v_isSharedCheck_804_; 
v_head_794_ = lean_ctor_get(v_a_791_, 0);
v_tail_795_ = lean_ctor_get(v_a_791_, 1);
v_isSharedCheck_804_ = !lean_is_exclusive(v_a_791_);
if (v_isSharedCheck_804_ == 0)
{
v___x_797_ = v_a_791_;
v_isShared_798_ = v_isSharedCheck_804_;
goto v_resetjp_796_;
}
else
{
lean_inc(v_tail_795_);
lean_inc(v_head_794_);
lean_dec(v_a_791_);
v___x_797_ = lean_box(0);
v_isShared_798_ = v_isSharedCheck_804_;
goto v_resetjp_796_;
}
v_resetjp_796_:
{
lean_object* v___x_799_; lean_object* v___x_801_; 
v___x_799_ = lp_bounded_Bounded_renEvent(v_r_790_, v_head_794_);
if (v_isShared_798_ == 0)
{
lean_ctor_set(v___x_797_, 1, v_a_792_);
lean_ctor_set(v___x_797_, 0, v___x_799_);
v___x_801_ = v___x_797_;
goto v_reusejp_800_;
}
else
{
lean_object* v_reuseFailAlloc_803_; 
v_reuseFailAlloc_803_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_803_, 0, v___x_799_);
lean_ctor_set(v_reuseFailAlloc_803_, 1, v_a_792_);
v___x_801_ = v_reuseFailAlloc_803_;
goto v_reusejp_800_;
}
v_reusejp_800_:
{
v_a_791_ = v_tail_795_;
v_a_792_ = v___x_801_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_List_mapTR_loop___at___00Bounded_renEv_spec__0___boxed(lean_object* v_r_805_, lean_object* v_a_806_, lean_object* v_a_807_){
_start:
{
lean_object* v_res_808_; 
v_res_808_ = lp_bounded_List_mapTR_loop___at___00Bounded_renEv_spec__0(v_r_805_, v_a_806_, v_a_807_);
lean_dec_ref(v_r_805_);
return v_res_808_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_renEv(lean_object* v_r_809_, lean_object* v_e_810_){
_start:
{
lean_object* v___x_811_; lean_object* v___x_812_; 
v___x_811_ = lean_box(0);
v___x_812_ = lp_bounded_List_mapTR_loop___at___00Bounded_renEv_spec__0(v_r_809_, v_e_810_, v___x_811_);
return v___x_812_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_renEv___boxed(lean_object* v_r_813_, lean_object* v_e_814_){
_start:
{
lean_object* v_res_815_; 
v_res_815_ = lp_bounded_Bounded_renEv(v_r_813_, v_e_814_);
lean_dec_ref(v_r_813_);
return v_res_815_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_renRow(lean_object* v_r_816_, lean_object* v_p_817_){
_start:
{
lean_object* v_fst_818_; lean_object* v_snd_819_; lean_object* v___x_821_; uint8_t v_isShared_822_; uint8_t v_isSharedCheck_828_; 
v_fst_818_ = lean_ctor_get(v_p_817_, 0);
v_snd_819_ = lean_ctor_get(v_p_817_, 1);
v_isSharedCheck_828_ = !lean_is_exclusive(v_p_817_);
if (v_isSharedCheck_828_ == 0)
{
v___x_821_ = v_p_817_;
v_isShared_822_ = v_isSharedCheck_828_;
goto v_resetjp_820_;
}
else
{
lean_inc(v_snd_819_);
lean_inc(v_fst_818_);
lean_dec(v_p_817_);
v___x_821_ = lean_box(0);
v_isShared_822_ = v_isSharedCheck_828_;
goto v_resetjp_820_;
}
v_resetjp_820_:
{
lean_object* v___x_823_; lean_object* v___x_824_; lean_object* v___x_826_; 
v___x_823_ = lp_bounded_Bounded_renEv(v_r_816_, v_fst_818_);
v___x_824_ = lp_bounded_Bounded_renConfig(v_r_816_, v_snd_819_);
lean_dec(v_snd_819_);
if (v_isShared_822_ == 0)
{
lean_ctor_set(v___x_821_, 1, v___x_824_);
lean_ctor_set(v___x_821_, 0, v___x_823_);
v___x_826_ = v___x_821_;
goto v_reusejp_825_;
}
else
{
lean_object* v_reuseFailAlloc_827_; 
v_reuseFailAlloc_827_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_827_, 0, v___x_823_);
lean_ctor_set(v_reuseFailAlloc_827_, 1, v___x_824_);
v___x_826_ = v_reuseFailAlloc_827_;
goto v_reusejp_825_;
}
v_reusejp_825_:
{
return v___x_826_;
}
}
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_renFixesChild(lean_object* v_r_829_){
_start:
{
lean_object* v___x_830_; lean_object* v___x_831_; uint8_t v___x_832_; 
v___x_830_ = lp_bounded_Bounded_childComp;
v___x_831_ = lp_bounded_Bounded_renComponent(v_r_829_, v___x_830_);
v___x_832_ = lp_bounded_Bounded_instDecidableEqComponent_decEq(v___x_831_, v___x_830_);
return v___x_832_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_renFixesChild___boxed(lean_object* v_r_833_){
_start:
{
uint8_t v_res_834_; lean_object* v_r_835_; 
v_res_834_ = lp_bounded_Bounded_renFixesChild(v_r_833_);
v_r_835_ = lean_box(v_res_834_);
return v_r_835_;
}
}
LEAN_EXPORT lean_object* lp_bounded_List_filterTR_loop___at___00Bounded_kRens_spec__0(lean_object* v_a_836_, lean_object* v_a_837_){
_start:
{
if (lean_obj_tag(v_a_836_) == 0)
{
lean_object* v___x_838_; 
v___x_838_ = l_List_reverse___redArg(v_a_837_);
return v___x_838_;
}
else
{
lean_object* v_head_839_; lean_object* v_tail_840_; lean_object* v___x_842_; uint8_t v_isShared_843_; uint8_t v_isSharedCheck_850_; 
v_head_839_ = lean_ctor_get(v_a_836_, 0);
v_tail_840_ = lean_ctor_get(v_a_836_, 1);
v_isSharedCheck_850_ = !lean_is_exclusive(v_a_836_);
if (v_isSharedCheck_850_ == 0)
{
v___x_842_ = v_a_836_;
v_isShared_843_ = v_isSharedCheck_850_;
goto v_resetjp_841_;
}
else
{
lean_inc(v_tail_840_);
lean_inc(v_head_839_);
lean_dec(v_a_836_);
v___x_842_ = lean_box(0);
v_isShared_843_ = v_isSharedCheck_850_;
goto v_resetjp_841_;
}
v_resetjp_841_:
{
uint8_t v___x_844_; 
lean_inc(v_head_839_);
v___x_844_ = lp_bounded_Bounded_renFixesChild(v_head_839_);
if (v___x_844_ == 0)
{
lean_del_object(v___x_842_);
lean_dec(v_head_839_);
v_a_836_ = v_tail_840_;
goto _start;
}
else
{
lean_object* v___x_847_; 
if (v_isShared_843_ == 0)
{
lean_ctor_set(v___x_842_, 1, v_a_837_);
v___x_847_ = v___x_842_;
goto v_reusejp_846_;
}
else
{
lean_object* v_reuseFailAlloc_849_; 
v_reuseFailAlloc_849_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_849_, 0, v_head_839_);
lean_ctor_set(v_reuseFailAlloc_849_, 1, v_a_837_);
v___x_847_ = v_reuseFailAlloc_849_;
goto v_reusejp_846_;
}
v_reusejp_846_:
{
v_a_836_ = v_tail_840_;
v_a_837_ = v___x_847_;
goto _start;
}
}
}
}
}
}
static lean_object* _init_lp_bounded_Bounded_kRens___closed__0(void){
_start:
{
lean_object* v___x_851_; lean_object* v___x_852_; lean_object* v___x_853_; 
v___x_851_ = lean_box(0);
v___x_852_ = lp_bounded_Bounded_allRens;
v___x_853_ = lp_bounded_List_filterTR_loop___at___00Bounded_kRens_spec__0(v___x_852_, v___x_851_);
return v___x_853_;
}
}
static lean_object* _init_lp_bounded_Bounded_kRens(void){
_start:
{
lean_object* v___x_854_; 
v___x_854_ = lean_obj_once(&lp_bounded_Bounded_kRens___closed__0, &lp_bounded_Bounded_kRens___closed__0_once, _init_lp_bounded_Bounded_kRens___closed__0);
return v___x_854_;
}
}
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_bounded_Bounded_Explore(uint8_t builtin);
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_bounded_Bounded_Equiv(uint8_t builtin) {
lean_object * res;
if (_G_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_initialized = true;
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_bounded_Bounded_Explore(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
lp_bounded_Bounded_instFinEnumRen = _init_lp_bounded_Bounded_instFinEnumRen();
lean_mark_persistent(lp_bounded_Bounded_instFinEnumRen);
lp_bounded_Bounded_allRens = _init_lp_bounded_Bounded_allRens();
lean_mark_persistent(lp_bounded_Bounded_allRens);
lp_bounded_Bounded_kRens = _init_lp_bounded_Bounded_kRens();
lean_mark_persistent(lp_bounded_Bounded_kRens);
return lean_io_result_mk_ok(lean_box(0));
}
#ifdef __cplusplus
}
#endif

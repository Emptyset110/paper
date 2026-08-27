// Lean compiler output
// Module: Bounded.Explore
// Imports: public import Init public meta import Init public import Std.Data.HashMap public import Bounded.Enum
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
lean_object* lp_bounded_Bounded_instHashableFiber_hash___boxed(lean_object*);
lean_object* l_instHashableOption___redArg___lam__0___boxed(lean_object*, lean_object*);
uint64_t lp_bounded_Bounded_instHashableSMap_hash___redArg(lean_object*, lean_object*);
uint8_t lp_bounded_Bounded_instDecidableEqConfig___aux__1(lean_object*, lean_object*);
lean_object* l_List_appendTR___redArg(lean_object*, lean_object*);
uint8_t lean_nat_dec_eq(lean_object*, lean_object*);
lean_object* l_List_reverse___redArg(lean_object*);
lean_object* lean_nat_sub(lean_object*, lean_object*);
extern lean_object* lp_bounded_Bounded_catalogActs;
lean_object* lean_mk_empty_array_with_capacity(lean_object*);
lean_object* lean_array_to_list(lean_object*);
lean_object* lp_bounded_Bounded_specStep(lean_object*, lean_object*);
lean_object* lean_array_push(lean_object*, lean_object*);
lean_object* lean_array_get_size(lean_object*);
uint64_t lean_uint64_mix_hash(uint64_t, uint64_t);
uint64_t lp_bounded_Bounded_instHashableFiber_hash(lean_object*);
uint64_t lean_uint64_shift_right(uint64_t, uint64_t);
uint64_t lean_uint64_xor(uint64_t, uint64_t);
size_t lean_uint64_to_usize(uint64_t);
size_t lean_usize_of_nat(lean_object*);
size_t lean_usize_sub(size_t, size_t);
size_t lean_usize_land(size_t, size_t);
lean_object* lean_array_uget_borrowed(lean_object*, size_t);
lean_object* lean_nat_add(lean_object*, lean_object*);
lean_object* lean_array_uset(lean_object*, size_t, lean_object*);
lean_object* lean_nat_mul(lean_object*, lean_object*);
lean_object* lean_nat_div(lean_object*, lean_object*);
uint8_t lean_nat_dec_le(lean_object*, lean_object*);
lean_object* lean_mk_array(lean_object*, lean_object*);
uint8_t lean_nat_dec_lt(lean_object*, lean_object*);
lean_object* lean_array_fget(lean_object*, lean_object*);
lean_object* lean_array_fset(lean_object*, lean_object*, lean_object*);
extern lean_object* lp_bounded_Bounded_emptyConfig;
LEAN_EXPORT lean_object* lp_bounded_Bounded_00_u03b30;
LEAN_EXPORT lean_object* lp_bounded_Bounded_runFrom(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded___private_Bounded_Explore_0__Bounded_runFrom_match__3_splitter___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded___private_Bounded_Explore_0__Bounded_runFrom_match__3_splitter(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded___private_Bounded_Explore_0__Bounded_runFrom_match__1_splitter___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded___private_Bounded_Explore_0__Bounded_runFrom_match__1_splitter(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded___private_Bounded_Explore_0__Bounded_runFrom__append_match__1_splitter___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded___private_Bounded_Explore_0__Bounded_runFrom__append_match__1_splitter(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_List_filterMapTR_go___at___00Bounded_succsOf_spec__0(lean_object*, lean_object*, lean_object*);
static const lean_array_object lp_bounded_Bounded_succsOf___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_array_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 246}, .m_size = 0, .m_capacity = 0, .m_data = {}};
static const lean_object* lp_bounded_Bounded_succsOf___closed__0 = (const lean_object*)&lp_bounded_Bounded_succsOf___closed__0_value;
LEAN_EXPORT lean_object* lp_bounded_Bounded_succsOf(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_List_mapTR_loop___at___00Bounded_seenConfigs_spec__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_seenConfigs(lean_object*);
LEAN_EXPORT uint8_t lp_bounded_List_any___at___00Bounded_addNew_spec__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_List_any___at___00Bounded_addNew_spec__0___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_addNew(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_List_foldl___at___00Bounded_expand_spec__0(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_expand(lean_object*, lean_object*);
static lean_once_cell_t lp_bounded_Bounded_st0___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_st0___closed__0;
static lean_once_cell_t lp_bounded_Bounded_st0___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_st0___closed__1;
static lean_once_cell_t lp_bounded_Bounded_st0___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_st0___closed__2;
LEAN_EXPORT lean_object* lp_bounded_Bounded_st0;
LEAN_EXPORT lean_object* lp_bounded___private_Bounded_Explore_0__Bounded_expand_match__3_splitter___redArg(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded___private_Bounded_Explore_0__Bounded_expand_match__3_splitter___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded___private_Bounded_Explore_0__Bounded_expand_match__3_splitter(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded___private_Bounded_Explore_0__Bounded_expand_match__3_splitter___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded___private_Bounded_Explore_0__Bounded_expand_match__1_splitter___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded___private_Bounded_Explore_0__Bounded_expand_match__1_splitter(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_FUEL;
static const lean_closure_object lp_bounded_Bounded_instHashableConfig___aux__1___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_bounded_Bounded_instHashableFiber_hash___boxed, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_bounded_Bounded_instHashableConfig___aux__1___closed__0 = (const lean_object*)&lp_bounded_Bounded_instHashableConfig___aux__1___closed__0_value;
static const lean_closure_object lp_bounded_Bounded_instHashableConfig___aux__1___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*1, .m_other = 0, .m_tag = 245}, .m_fun = (void*)l_instHashableOption___redArg___lam__0___boxed, .m_arity = 2, .m_num_fixed = 1, .m_objs = {((lean_object*)&lp_bounded_Bounded_instHashableConfig___aux__1___closed__0_value)} };
static const lean_object* lp_bounded_Bounded_instHashableConfig___aux__1___closed__1 = (const lean_object*)&lp_bounded_Bounded_instHashableConfig___aux__1___closed__1_value;
LEAN_EXPORT uint64_t lp_bounded_Bounded_instHashableConfig___aux__1(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instHashableConfig___aux__1___boxed(lean_object*);
static const lean_closure_object lp_bounded_Bounded_instHashableConfig___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_bounded_Bounded_instHashableConfig___aux__1___boxed, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_bounded_Bounded_instHashableConfig___closed__0 = (const lean_object*)&lp_bounded_Bounded_instHashableConfig___closed__0_value;
LEAN_EXPORT const lean_object* lp_bounded_Bounded_instHashableConfig = (const lean_object*)&lp_bounded_Bounded_instHashableConfig___closed__0_value;
LEAN_EXPORT uint64_t lp_bounded_Bounded_instHashableSMap_hash___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00Bounded_fastExpand_spec__0_spec__0(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instHashableSMap_hash___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00Bounded_fastExpand_spec__0_spec__0___boxed(lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00Bounded_fastExpand_spec__0_spec__1___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00Bounded_fastExpand_spec__0_spec__1___redArg___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Std_DHashMap_Internal_Raw_u2080_contains___at___00Bounded_fastExpand_spec__0___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Std_DHashMap_Internal_Raw_u2080_contains___at___00Bounded_fastExpand_spec__0___redArg___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Std_DHashMap_Internal_AssocList_replace___at___00Std_DHashMap_Internal_Raw_u2080_insert___at___00Bounded_fastExpand_spec__1_spec__4___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Std_DHashMap_Internal_AssocList_foldlM___at___00__private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insert___at___00Bounded_fastExpand_spec__1_spec__3_spec__4_spec__6___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded___private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insert___at___00Bounded_fastExpand_spec__1_spec__3_spec__4___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insert___at___00Bounded_fastExpand_spec__1_spec__3___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Std_DHashMap_Internal_Raw_u2080_insert___at___00Bounded_fastExpand_spec__1___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_List_foldl___at___00Bounded_fastExpand_spec__2(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_fastExpand(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Std_DHashMap_Internal_Raw_u2080_contains___at___00Bounded_fastExpand_spec__0(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Std_DHashMap_Internal_Raw_u2080_contains___at___00Bounded_fastExpand_spec__0___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Std_DHashMap_Internal_Raw_u2080_insert___at___00Bounded_fastExpand_spec__1(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00Bounded_fastExpand_spec__0_spec__1(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00Bounded_fastExpand_spec__0_spec__1___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insert___at___00Bounded_fastExpand_spec__1_spec__3(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Std_DHashMap_Internal_AssocList_replace___at___00Std_DHashMap_Internal_Raw_u2080_insert___at___00Bounded_fastExpand_spec__1_spec__4(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded___private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insert___at___00Bounded_fastExpand_spec__1_spec__3_spec__4(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Std_DHashMap_Internal_AssocList_foldlM___at___00__private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insert___at___00Bounded_fastExpand_spec__1_spec__3_spec__4_spec__6(lean_object*, lean_object*, lean_object*);
static lean_once_cell_t lp_bounded_Bounded_visitedP___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_visitedP___closed__0;
static lean_once_cell_t lp_bounded_Bounded_visitedP___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_visitedP___closed__1;
static lean_once_cell_t lp_bounded_Bounded_visitedP___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_visitedP___closed__2;
static lean_once_cell_t lp_bounded_Bounded_visitedP___closed__3_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_visitedP___closed__3;
LEAN_EXPORT lean_object* lp_bounded_Bounded_visitedP;
static lean_once_cell_t lp_bounded_Bounded_visited___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_visited___closed__0;
LEAN_EXPORT lean_object* lp_bounded_Bounded_visited;
static lean_object* _init_lp_bounded_Bounded_00_u03b30(void){
_start:
{
lean_object* v___x_1_; 
v___x_1_ = lp_bounded_Bounded_emptyConfig;
return v___x_1_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_runFrom(lean_object* v_00_u03b3_2_, lean_object* v_x_3_){
_start:
{
if (lean_obj_tag(v_x_3_) == 0)
{
lean_object* v___x_4_; 
v___x_4_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_4_, 0, v_00_u03b3_2_);
return v___x_4_;
}
else
{
lean_object* v_head_5_; lean_object* v_tail_6_; lean_object* v___x_7_; 
v_head_5_ = lean_ctor_get(v_x_3_, 0);
lean_inc(v_head_5_);
v_tail_6_ = lean_ctor_get(v_x_3_, 1);
lean_inc(v_tail_6_);
lean_dec_ref_known(v_x_3_, 2);
v___x_7_ = lp_bounded_Bounded_specStep(v_head_5_, v_00_u03b3_2_);
if (lean_obj_tag(v___x_7_) == 0)
{
lean_object* v___x_8_; 
lean_dec(v_tail_6_);
v___x_8_ = lean_box(0);
return v___x_8_;
}
else
{
lean_object* v_val_9_; lean_object* v_snd_10_; 
v_val_9_ = lean_ctor_get(v___x_7_, 0);
lean_inc(v_val_9_);
lean_dec_ref_known(v___x_7_, 1);
v_snd_10_ = lean_ctor_get(v_val_9_, 1);
lean_inc(v_snd_10_);
lean_dec(v_val_9_);
v_00_u03b3_2_ = v_snd_10_;
v_x_3_ = v_tail_6_;
goto _start;
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded___private_Bounded_Explore_0__Bounded_runFrom_match__3_splitter___redArg(lean_object* v_x_12_, lean_object* v_h__1_13_, lean_object* v_h__2_14_){
_start:
{
if (lean_obj_tag(v_x_12_) == 0)
{
lean_object* v___x_15_; lean_object* v___x_16_; 
lean_dec(v_h__2_14_);
v___x_15_ = lean_box(0);
v___x_16_ = lean_apply_1(v_h__1_13_, v___x_15_);
return v___x_16_;
}
else
{
lean_object* v_head_17_; lean_object* v_tail_18_; lean_object* v___x_19_; 
lean_dec(v_h__1_13_);
v_head_17_ = lean_ctor_get(v_x_12_, 0);
lean_inc(v_head_17_);
v_tail_18_ = lean_ctor_get(v_x_12_, 1);
lean_inc(v_tail_18_);
lean_dec_ref_known(v_x_12_, 2);
v___x_19_ = lean_apply_2(v_h__2_14_, v_head_17_, v_tail_18_);
return v___x_19_;
}
}
}
LEAN_EXPORT lean_object* lp_bounded___private_Bounded_Explore_0__Bounded_runFrom_match__3_splitter(lean_object* v_motive_20_, lean_object* v_x_21_, lean_object* v_h__1_22_, lean_object* v_h__2_23_){
_start:
{
if (lean_obj_tag(v_x_21_) == 0)
{
lean_object* v___x_24_; lean_object* v___x_25_; 
lean_dec(v_h__2_23_);
v___x_24_ = lean_box(0);
v___x_25_ = lean_apply_1(v_h__1_22_, v___x_24_);
return v___x_25_;
}
else
{
lean_object* v_head_26_; lean_object* v_tail_27_; lean_object* v___x_28_; 
lean_dec(v_h__1_22_);
v_head_26_ = lean_ctor_get(v_x_21_, 0);
lean_inc(v_head_26_);
v_tail_27_ = lean_ctor_get(v_x_21_, 1);
lean_inc(v_tail_27_);
lean_dec_ref_known(v_x_21_, 2);
v___x_28_ = lean_apply_2(v_h__2_23_, v_head_26_, v_tail_27_);
return v___x_28_;
}
}
}
LEAN_EXPORT lean_object* lp_bounded___private_Bounded_Explore_0__Bounded_runFrom_match__1_splitter___redArg(lean_object* v_x_29_, lean_object* v_h__1_30_, lean_object* v_h__2_31_){
_start:
{
if (lean_obj_tag(v_x_29_) == 0)
{
lean_object* v___x_32_; lean_object* v___x_33_; 
lean_dec(v_h__1_30_);
v___x_32_ = lean_box(0);
v___x_33_ = lean_apply_1(v_h__2_31_, v___x_32_);
return v___x_33_;
}
else
{
lean_object* v_val_34_; lean_object* v___x_35_; 
lean_dec(v_h__2_31_);
v_val_34_ = lean_ctor_get(v_x_29_, 0);
lean_inc(v_val_34_);
lean_dec_ref_known(v_x_29_, 1);
v___x_35_ = lean_apply_1(v_h__1_30_, v_val_34_);
return v___x_35_;
}
}
}
LEAN_EXPORT lean_object* lp_bounded___private_Bounded_Explore_0__Bounded_runFrom_match__1_splitter(lean_object* v_motive_36_, lean_object* v_x_37_, lean_object* v_h__1_38_, lean_object* v_h__2_39_){
_start:
{
if (lean_obj_tag(v_x_37_) == 0)
{
lean_object* v___x_40_; lean_object* v___x_41_; 
lean_dec(v_h__1_38_);
v___x_40_ = lean_box(0);
v___x_41_ = lean_apply_1(v_h__2_39_, v___x_40_);
return v___x_41_;
}
else
{
lean_object* v_val_42_; lean_object* v___x_43_; 
lean_dec(v_h__2_39_);
v_val_42_ = lean_ctor_get(v_x_37_, 0);
lean_inc(v_val_42_);
lean_dec_ref_known(v_x_37_, 1);
v___x_43_ = lean_apply_1(v_h__1_38_, v_val_42_);
return v___x_43_;
}
}
}
LEAN_EXPORT lean_object* lp_bounded___private_Bounded_Explore_0__Bounded_runFrom__append_match__1_splitter___redArg(lean_object* v_x_44_, lean_object* v_h__1_45_, lean_object* v_h__2_46_){
_start:
{
if (lean_obj_tag(v_x_44_) == 0)
{
lean_object* v___x_47_; lean_object* v___x_48_; 
lean_dec(v_h__1_45_);
v___x_47_ = lean_box(0);
v___x_48_ = lean_apply_1(v_h__2_46_, v___x_47_);
return v___x_48_;
}
else
{
lean_object* v_val_49_; lean_object* v___x_50_; 
lean_dec(v_h__2_46_);
v_val_49_ = lean_ctor_get(v_x_44_, 0);
lean_inc(v_val_49_);
lean_dec_ref_known(v_x_44_, 1);
v___x_50_ = lean_apply_1(v_h__1_45_, v_val_49_);
return v___x_50_;
}
}
}
LEAN_EXPORT lean_object* lp_bounded___private_Bounded_Explore_0__Bounded_runFrom__append_match__1_splitter(lean_object* v_motive_51_, lean_object* v_x_52_, lean_object* v_h__1_53_, lean_object* v_h__2_54_){
_start:
{
if (lean_obj_tag(v_x_52_) == 0)
{
lean_object* v___x_55_; lean_object* v___x_56_; 
lean_dec(v_h__1_53_);
v___x_55_ = lean_box(0);
v___x_56_ = lean_apply_1(v_h__2_54_, v___x_55_);
return v___x_56_;
}
else
{
lean_object* v_val_57_; lean_object* v___x_58_; 
lean_dec(v_h__2_54_);
v_val_57_ = lean_ctor_get(v_x_52_, 0);
lean_inc(v_val_57_);
lean_dec_ref_known(v_x_52_, 1);
v___x_58_ = lean_apply_1(v_h__1_53_, v_val_57_);
return v___x_58_;
}
}
}
LEAN_EXPORT lean_object* lp_bounded_List_filterMapTR_go___at___00Bounded_succsOf_spec__0(lean_object* v_00_u03b3_59_, lean_object* v_a_60_, lean_object* v_a_61_){
_start:
{
if (lean_obj_tag(v_a_60_) == 0)
{
lean_object* v___x_62_; 
lean_dec_ref(v_00_u03b3_59_);
v___x_62_ = lean_array_to_list(v_a_61_);
return v___x_62_;
}
else
{
lean_object* v_head_63_; lean_object* v_tail_64_; lean_object* v___x_65_; 
v_head_63_ = lean_ctor_get(v_a_60_, 0);
lean_inc_n(v_head_63_, 2);
v_tail_64_ = lean_ctor_get(v_a_60_, 1);
lean_inc(v_tail_64_);
lean_dec_ref_known(v_a_60_, 2);
lean_inc_ref(v_00_u03b3_59_);
v___x_65_ = lp_bounded_Bounded_specStep(v_head_63_, v_00_u03b3_59_);
if (lean_obj_tag(v___x_65_) == 0)
{
lean_dec(v_head_63_);
v_a_60_ = v_tail_64_;
goto _start;
}
else
{
lean_object* v_val_67_; lean_object* v_snd_68_; lean_object* v___x_70_; uint8_t v_isShared_71_; uint8_t v_isSharedCheck_77_; 
v_val_67_ = lean_ctor_get(v___x_65_, 0);
lean_inc(v_val_67_);
lean_dec_ref_known(v___x_65_, 1);
v_snd_68_ = lean_ctor_get(v_val_67_, 1);
v_isSharedCheck_77_ = !lean_is_exclusive(v_val_67_);
if (v_isSharedCheck_77_ == 0)
{
lean_object* v_unused_78_; 
v_unused_78_ = lean_ctor_get(v_val_67_, 0);
lean_dec(v_unused_78_);
v___x_70_ = v_val_67_;
v_isShared_71_ = v_isSharedCheck_77_;
goto v_resetjp_69_;
}
else
{
lean_inc(v_snd_68_);
lean_dec(v_val_67_);
v___x_70_ = lean_box(0);
v_isShared_71_ = v_isSharedCheck_77_;
goto v_resetjp_69_;
}
v_resetjp_69_:
{
lean_object* v___x_73_; 
if (v_isShared_71_ == 0)
{
lean_ctor_set(v___x_70_, 0, v_head_63_);
v___x_73_ = v___x_70_;
goto v_reusejp_72_;
}
else
{
lean_object* v_reuseFailAlloc_76_; 
v_reuseFailAlloc_76_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_76_, 0, v_head_63_);
lean_ctor_set(v_reuseFailAlloc_76_, 1, v_snd_68_);
v___x_73_ = v_reuseFailAlloc_76_;
goto v_reusejp_72_;
}
v_reusejp_72_:
{
lean_object* v___x_74_; 
v___x_74_ = lean_array_push(v_a_61_, v___x_73_);
v_a_60_ = v_tail_64_;
v_a_61_ = v___x_74_;
goto _start;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_succsOf(lean_object* v_00_u03b3_81_){
_start:
{
lean_object* v___x_82_; lean_object* v___x_83_; lean_object* v___x_84_; 
v___x_82_ = lp_bounded_Bounded_catalogActs;
v___x_83_ = ((lean_object*)(lp_bounded_Bounded_succsOf___closed__0));
v___x_84_ = lp_bounded_List_filterMapTR_go___at___00Bounded_succsOf_spec__0(v_00_u03b3_81_, v___x_82_, v___x_83_);
return v___x_84_;
}
}
LEAN_EXPORT lean_object* lp_bounded_List_mapTR_loop___at___00Bounded_seenConfigs_spec__0(lean_object* v_a_85_, lean_object* v_a_86_){
_start:
{
if (lean_obj_tag(v_a_85_) == 0)
{
lean_object* v___x_87_; 
v___x_87_ = l_List_reverse___redArg(v_a_86_);
return v___x_87_;
}
else
{
lean_object* v_head_88_; lean_object* v_tail_89_; lean_object* v___x_91_; uint8_t v_isShared_92_; uint8_t v_isSharedCheck_98_; 
v_head_88_ = lean_ctor_get(v_a_85_, 0);
v_tail_89_ = lean_ctor_get(v_a_85_, 1);
v_isSharedCheck_98_ = !lean_is_exclusive(v_a_85_);
if (v_isSharedCheck_98_ == 0)
{
v___x_91_ = v_a_85_;
v_isShared_92_ = v_isSharedCheck_98_;
goto v_resetjp_90_;
}
else
{
lean_inc(v_tail_89_);
lean_inc(v_head_88_);
lean_dec(v_a_85_);
v___x_91_ = lean_box(0);
v_isShared_92_ = v_isSharedCheck_98_;
goto v_resetjp_90_;
}
v_resetjp_90_:
{
lean_object* v_fst_93_; lean_object* v___x_95_; 
v_fst_93_ = lean_ctor_get(v_head_88_, 0);
lean_inc(v_fst_93_);
lean_dec(v_head_88_);
if (v_isShared_92_ == 0)
{
lean_ctor_set(v___x_91_, 1, v_a_86_);
lean_ctor_set(v___x_91_, 0, v_fst_93_);
v___x_95_ = v___x_91_;
goto v_reusejp_94_;
}
else
{
lean_object* v_reuseFailAlloc_97_; 
v_reuseFailAlloc_97_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_97_, 0, v_fst_93_);
lean_ctor_set(v_reuseFailAlloc_97_, 1, v_a_86_);
v___x_95_ = v_reuseFailAlloc_97_;
goto v_reusejp_94_;
}
v_reusejp_94_:
{
v_a_85_ = v_tail_89_;
v_a_86_ = v___x_95_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_seenConfigs(lean_object* v_st_99_){
_start:
{
lean_object* v_seen_100_; lean_object* v___x_101_; lean_object* v___x_102_; 
v_seen_100_ = lean_ctor_get(v_st_99_, 1);
lean_inc(v_seen_100_);
lean_dec_ref(v_st_99_);
v___x_101_ = lean_box(0);
v___x_102_ = lp_bounded_List_mapTR_loop___at___00Bounded_seenConfigs_spec__0(v_seen_100_, v___x_101_);
return v___x_102_;
}
}
LEAN_EXPORT uint8_t lp_bounded_List_any___at___00Bounded_addNew_spec__0(lean_object* v_ac_103_, lean_object* v_x_104_){
_start:
{
if (lean_obj_tag(v_x_104_) == 0)
{
uint8_t v___x_105_; 
lean_dec_ref(v_ac_103_);
v___x_105_ = 0;
return v___x_105_;
}
else
{
lean_object* v_head_106_; lean_object* v_tail_107_; lean_object* v_fst_108_; lean_object* v_snd_109_; uint8_t v___x_110_; 
v_head_106_ = lean_ctor_get(v_x_104_, 0);
lean_inc(v_head_106_);
v_tail_107_ = lean_ctor_get(v_x_104_, 1);
lean_inc(v_tail_107_);
lean_dec_ref_known(v_x_104_, 2);
v_fst_108_ = lean_ctor_get(v_head_106_, 0);
lean_inc(v_fst_108_);
lean_dec(v_head_106_);
v_snd_109_ = lean_ctor_get(v_ac_103_, 1);
lean_inc(v_snd_109_);
v___x_110_ = lp_bounded_Bounded_instDecidableEqConfig___aux__1(v_fst_108_, v_snd_109_);
if (v___x_110_ == 0)
{
v_x_104_ = v_tail_107_;
goto _start;
}
else
{
lean_dec(v_tail_107_);
lean_dec_ref(v_ac_103_);
return v___x_110_;
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_List_any___at___00Bounded_addNew_spec__0___boxed(lean_object* v_ac_112_, lean_object* v_x_113_){
_start:
{
uint8_t v_res_114_; lean_object* v_r_115_; 
v_res_114_ = lp_bounded_List_any___at___00Bounded_addNew_spec__0(v_ac_112_, v_x_113_);
v_r_115_ = lean_box(v_res_114_);
return v_r_115_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_addNew(lean_object* v_w_116_, lean_object* v_st_117_, lean_object* v_ac_118_){
_start:
{
lean_object* v_todo_119_; lean_object* v_seen_120_; uint8_t v___x_121_; 
v_todo_119_ = lean_ctor_get(v_st_117_, 0);
v_seen_120_ = lean_ctor_get(v_st_117_, 1);
lean_inc(v_seen_120_);
lean_inc_ref(v_ac_118_);
v___x_121_ = lp_bounded_List_any___at___00Bounded_addNew_spec__0(v_ac_118_, v_seen_120_);
if (v___x_121_ == 0)
{
lean_object* v___x_123_; uint8_t v_isShared_124_; uint8_t v_isSharedCheck_143_; 
lean_inc(v_seen_120_);
lean_inc(v_todo_119_);
v_isSharedCheck_143_ = !lean_is_exclusive(v_st_117_);
if (v_isSharedCheck_143_ == 0)
{
lean_object* v_unused_144_; lean_object* v_unused_145_; 
v_unused_144_ = lean_ctor_get(v_st_117_, 1);
lean_dec(v_unused_144_);
v_unused_145_ = lean_ctor_get(v_st_117_, 0);
lean_dec(v_unused_145_);
v___x_123_ = v_st_117_;
v_isShared_124_ = v_isSharedCheck_143_;
goto v_resetjp_122_;
}
else
{
lean_dec(v_st_117_);
v___x_123_ = lean_box(0);
v_isShared_124_ = v_isSharedCheck_143_;
goto v_resetjp_122_;
}
v_resetjp_122_:
{
lean_object* v_fst_125_; lean_object* v_snd_126_; lean_object* v___x_128_; uint8_t v_isShared_129_; uint8_t v_isSharedCheck_142_; 
v_fst_125_ = lean_ctor_get(v_ac_118_, 0);
v_snd_126_ = lean_ctor_get(v_ac_118_, 1);
v_isSharedCheck_142_ = !lean_is_exclusive(v_ac_118_);
if (v_isSharedCheck_142_ == 0)
{
v___x_128_ = v_ac_118_;
v_isShared_129_ = v_isSharedCheck_142_;
goto v_resetjp_127_;
}
else
{
lean_inc(v_snd_126_);
lean_inc(v_fst_125_);
lean_dec(v_ac_118_);
v___x_128_ = lean_box(0);
v_isShared_129_ = v_isSharedCheck_142_;
goto v_resetjp_127_;
}
v_resetjp_127_:
{
lean_object* v___x_130_; lean_object* v___x_131_; lean_object* v___x_132_; lean_object* v___x_134_; 
v___x_130_ = lean_box(0);
v___x_131_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_131_, 0, v_fst_125_);
lean_ctor_set(v___x_131_, 1, v___x_130_);
v___x_132_ = l_List_appendTR___redArg(v_w_116_, v___x_131_);
if (v_isShared_129_ == 0)
{
lean_ctor_set(v___x_128_, 1, v___x_132_);
lean_ctor_set(v___x_128_, 0, v_snd_126_);
v___x_134_ = v___x_128_;
goto v_reusejp_133_;
}
else
{
lean_object* v_reuseFailAlloc_141_; 
v_reuseFailAlloc_141_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_141_, 0, v_snd_126_);
lean_ctor_set(v_reuseFailAlloc_141_, 1, v___x_132_);
v___x_134_ = v_reuseFailAlloc_141_;
goto v_reusejp_133_;
}
v_reusejp_133_:
{
lean_object* v___x_135_; lean_object* v___x_136_; lean_object* v___x_137_; lean_object* v___x_139_; 
v___x_135_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_135_, 0, v___x_134_);
lean_ctor_set(v___x_135_, 1, v___x_130_);
lean_inc_ref(v___x_135_);
v___x_136_ = l_List_appendTR___redArg(v_todo_119_, v___x_135_);
v___x_137_ = l_List_appendTR___redArg(v_seen_120_, v___x_135_);
if (v_isShared_124_ == 0)
{
lean_ctor_set(v___x_123_, 1, v___x_137_);
lean_ctor_set(v___x_123_, 0, v___x_136_);
v___x_139_ = v___x_123_;
goto v_reusejp_138_;
}
else
{
lean_object* v_reuseFailAlloc_140_; 
v_reuseFailAlloc_140_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_140_, 0, v___x_136_);
lean_ctor_set(v_reuseFailAlloc_140_, 1, v___x_137_);
v___x_139_ = v_reuseFailAlloc_140_;
goto v_reusejp_138_;
}
v_reusejp_138_:
{
return v___x_139_;
}
}
}
}
}
else
{
lean_dec_ref(v_ac_118_);
lean_dec(v_w_116_);
return v_st_117_;
}
}
}
LEAN_EXPORT lean_object* lp_bounded_List_foldl___at___00Bounded_expand_spec__0(lean_object* v_snd_146_, lean_object* v_x_147_, lean_object* v_x_148_){
_start:
{
if (lean_obj_tag(v_x_148_) == 0)
{
lean_dec(v_snd_146_);
return v_x_147_;
}
else
{
lean_object* v_head_149_; lean_object* v_tail_150_; lean_object* v___x_151_; 
v_head_149_ = lean_ctor_get(v_x_148_, 0);
lean_inc(v_head_149_);
v_tail_150_ = lean_ctor_get(v_x_148_, 1);
lean_inc(v_tail_150_);
lean_dec_ref_known(v_x_148_, 2);
lean_inc(v_snd_146_);
v___x_151_ = lp_bounded_Bounded_addNew(v_snd_146_, v_x_147_, v_head_149_);
v_x_147_ = v___x_151_;
v_x_148_ = v_tail_150_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_expand(lean_object* v_x_153_, lean_object* v_x_154_){
_start:
{
lean_object* v_zero_155_; uint8_t v_isZero_156_; 
v_zero_155_ = lean_unsigned_to_nat(0u);
v_isZero_156_ = lean_nat_dec_eq(v_x_153_, v_zero_155_);
if (v_isZero_156_ == 1)
{
lean_dec(v_x_153_);
return v_x_154_;
}
else
{
lean_object* v_todo_157_; 
v_todo_157_ = lean_ctor_get(v_x_154_, 0);
if (lean_obj_tag(v_todo_157_) == 0)
{
lean_dec(v_x_153_);
return v_x_154_;
}
else
{
lean_object* v_head_158_; lean_object* v_seen_159_; lean_object* v___x_161_; uint8_t v_isShared_162_; uint8_t v_isSharedCheck_174_; 
lean_inc_ref(v_todo_157_);
v_head_158_ = lean_ctor_get(v_todo_157_, 0);
lean_inc(v_head_158_);
v_seen_159_ = lean_ctor_get(v_x_154_, 1);
v_isSharedCheck_174_ = !lean_is_exclusive(v_x_154_);
if (v_isSharedCheck_174_ == 0)
{
lean_object* v_unused_175_; 
v_unused_175_ = lean_ctor_get(v_x_154_, 0);
lean_dec(v_unused_175_);
v___x_161_ = v_x_154_;
v_isShared_162_ = v_isSharedCheck_174_;
goto v_resetjp_160_;
}
else
{
lean_inc(v_seen_159_);
lean_dec(v_x_154_);
v___x_161_ = lean_box(0);
v_isShared_162_ = v_isSharedCheck_174_;
goto v_resetjp_160_;
}
v_resetjp_160_:
{
lean_object* v_tail_163_; lean_object* v_fst_164_; lean_object* v_snd_165_; lean_object* v_one_166_; lean_object* v_n_167_; lean_object* v___x_169_; 
v_tail_163_ = lean_ctor_get(v_todo_157_, 1);
lean_inc(v_tail_163_);
lean_dec_ref_known(v_todo_157_, 2);
v_fst_164_ = lean_ctor_get(v_head_158_, 0);
lean_inc(v_fst_164_);
v_snd_165_ = lean_ctor_get(v_head_158_, 1);
lean_inc(v_snd_165_);
lean_dec(v_head_158_);
v_one_166_ = lean_unsigned_to_nat(1u);
v_n_167_ = lean_nat_sub(v_x_153_, v_one_166_);
lean_dec(v_x_153_);
if (v_isShared_162_ == 0)
{
lean_ctor_set(v___x_161_, 0, v_tail_163_);
v___x_169_ = v___x_161_;
goto v_reusejp_168_;
}
else
{
lean_object* v_reuseFailAlloc_173_; 
v_reuseFailAlloc_173_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_173_, 0, v_tail_163_);
lean_ctor_set(v_reuseFailAlloc_173_, 1, v_seen_159_);
v___x_169_ = v_reuseFailAlloc_173_;
goto v_reusejp_168_;
}
v_reusejp_168_:
{
lean_object* v___x_170_; lean_object* v___x_171_; 
v___x_170_ = lp_bounded_Bounded_succsOf(v_fst_164_);
v___x_171_ = lp_bounded_List_foldl___at___00Bounded_expand_spec__0(v_snd_165_, v___x_169_, v___x_170_);
v_x_153_ = v_n_167_;
v_x_154_ = v___x_171_;
goto _start;
}
}
}
}
}
}
static lean_object* _init_lp_bounded_Bounded_st0___closed__0(void){
_start:
{
lean_object* v___x_176_; lean_object* v___x_177_; lean_object* v___x_178_; 
v___x_176_ = lean_box(0);
v___x_177_ = lp_bounded_Bounded_emptyConfig;
v___x_178_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_178_, 0, v___x_177_);
lean_ctor_set(v___x_178_, 1, v___x_176_);
return v___x_178_;
}
}
static lean_object* _init_lp_bounded_Bounded_st0___closed__1(void){
_start:
{
lean_object* v___x_179_; lean_object* v___x_180_; lean_object* v___x_181_; 
v___x_179_ = lean_box(0);
v___x_180_ = lean_obj_once(&lp_bounded_Bounded_st0___closed__0, &lp_bounded_Bounded_st0___closed__0_once, _init_lp_bounded_Bounded_st0___closed__0);
v___x_181_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_181_, 0, v___x_180_);
lean_ctor_set(v___x_181_, 1, v___x_179_);
return v___x_181_;
}
}
static lean_object* _init_lp_bounded_Bounded_st0___closed__2(void){
_start:
{
lean_object* v___x_182_; lean_object* v___x_183_; 
v___x_182_ = lean_obj_once(&lp_bounded_Bounded_st0___closed__1, &lp_bounded_Bounded_st0___closed__1_once, _init_lp_bounded_Bounded_st0___closed__1);
v___x_183_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_183_, 0, v___x_182_);
lean_ctor_set(v___x_183_, 1, v___x_182_);
return v___x_183_;
}
}
static lean_object* _init_lp_bounded_Bounded_st0(void){
_start:
{
lean_object* v___x_184_; 
v___x_184_ = lean_obj_once(&lp_bounded_Bounded_st0___closed__2, &lp_bounded_Bounded_st0___closed__2_once, _init_lp_bounded_Bounded_st0___closed__2);
return v___x_184_;
}
}
LEAN_EXPORT lean_object* lp_bounded___private_Bounded_Explore_0__Bounded_expand_match__3_splitter___redArg(lean_object* v_x_185_, lean_object* v_x_186_, lean_object* v_h__1_187_, lean_object* v_h__2_188_){
_start:
{
lean_object* v_zero_189_; uint8_t v_isZero_190_; 
v_zero_189_ = lean_unsigned_to_nat(0u);
v_isZero_190_ = lean_nat_dec_eq(v_x_185_, v_zero_189_);
if (v_isZero_190_ == 1)
{
lean_object* v___x_191_; 
lean_dec(v_h__2_188_);
v___x_191_ = lean_apply_1(v_h__1_187_, v_x_186_);
return v___x_191_;
}
else
{
lean_object* v_one_192_; lean_object* v_n_193_; lean_object* v___x_194_; 
lean_dec(v_h__1_187_);
v_one_192_ = lean_unsigned_to_nat(1u);
v_n_193_ = lean_nat_sub(v_x_185_, v_one_192_);
v___x_194_ = lean_apply_2(v_h__2_188_, v_n_193_, v_x_186_);
return v___x_194_;
}
}
}
LEAN_EXPORT lean_object* lp_bounded___private_Bounded_Explore_0__Bounded_expand_match__3_splitter___redArg___boxed(lean_object* v_x_195_, lean_object* v_x_196_, lean_object* v_h__1_197_, lean_object* v_h__2_198_){
_start:
{
lean_object* v_res_199_; 
v_res_199_ = lp_bounded___private_Bounded_Explore_0__Bounded_expand_match__3_splitter___redArg(v_x_195_, v_x_196_, v_h__1_197_, v_h__2_198_);
lean_dec(v_x_195_);
return v_res_199_;
}
}
LEAN_EXPORT lean_object* lp_bounded___private_Bounded_Explore_0__Bounded_expand_match__3_splitter(lean_object* v_motive_200_, lean_object* v_x_201_, lean_object* v_x_202_, lean_object* v_h__1_203_, lean_object* v_h__2_204_){
_start:
{
lean_object* v_zero_205_; uint8_t v_isZero_206_; 
v_zero_205_ = lean_unsigned_to_nat(0u);
v_isZero_206_ = lean_nat_dec_eq(v_x_201_, v_zero_205_);
if (v_isZero_206_ == 1)
{
lean_object* v___x_207_; 
lean_dec(v_h__2_204_);
v___x_207_ = lean_apply_1(v_h__1_203_, v_x_202_);
return v___x_207_;
}
else
{
lean_object* v_one_208_; lean_object* v_n_209_; lean_object* v___x_210_; 
lean_dec(v_h__1_203_);
v_one_208_ = lean_unsigned_to_nat(1u);
v_n_209_ = lean_nat_sub(v_x_201_, v_one_208_);
v___x_210_ = lean_apply_2(v_h__2_204_, v_n_209_, v_x_202_);
return v___x_210_;
}
}
}
LEAN_EXPORT lean_object* lp_bounded___private_Bounded_Explore_0__Bounded_expand_match__3_splitter___boxed(lean_object* v_motive_211_, lean_object* v_x_212_, lean_object* v_x_213_, lean_object* v_h__1_214_, lean_object* v_h__2_215_){
_start:
{
lean_object* v_res_216_; 
v_res_216_ = lp_bounded___private_Bounded_Explore_0__Bounded_expand_match__3_splitter(v_motive_211_, v_x_212_, v_x_213_, v_h__1_214_, v_h__2_215_);
lean_dec(v_x_212_);
return v_res_216_;
}
}
LEAN_EXPORT lean_object* lp_bounded___private_Bounded_Explore_0__Bounded_expand_match__1_splitter___redArg(lean_object* v_x_217_, lean_object* v_h__1_218_, lean_object* v_h__2_219_){
_start:
{
if (lean_obj_tag(v_x_217_) == 0)
{
lean_object* v___x_220_; lean_object* v___x_221_; 
lean_dec(v_h__2_219_);
v___x_220_ = lean_box(0);
v___x_221_ = lean_apply_1(v_h__1_218_, v___x_220_);
return v___x_221_;
}
else
{
lean_object* v_head_222_; lean_object* v_tail_223_; lean_object* v_fst_224_; lean_object* v_snd_225_; lean_object* v___x_226_; 
lean_dec(v_h__1_218_);
v_head_222_ = lean_ctor_get(v_x_217_, 0);
lean_inc(v_head_222_);
v_tail_223_ = lean_ctor_get(v_x_217_, 1);
lean_inc(v_tail_223_);
lean_dec_ref_known(v_x_217_, 2);
v_fst_224_ = lean_ctor_get(v_head_222_, 0);
lean_inc(v_fst_224_);
v_snd_225_ = lean_ctor_get(v_head_222_, 1);
lean_inc(v_snd_225_);
lean_dec(v_head_222_);
v___x_226_ = lean_apply_3(v_h__2_219_, v_fst_224_, v_snd_225_, v_tail_223_);
return v___x_226_;
}
}
}
LEAN_EXPORT lean_object* lp_bounded___private_Bounded_Explore_0__Bounded_expand_match__1_splitter(lean_object* v_motive_227_, lean_object* v_x_228_, lean_object* v_h__1_229_, lean_object* v_h__2_230_){
_start:
{
if (lean_obj_tag(v_x_228_) == 0)
{
lean_object* v___x_231_; lean_object* v___x_232_; 
lean_dec(v_h__2_230_);
v___x_231_ = lean_box(0);
v___x_232_ = lean_apply_1(v_h__1_229_, v___x_231_);
return v___x_232_;
}
else
{
lean_object* v_head_233_; lean_object* v_tail_234_; lean_object* v_fst_235_; lean_object* v_snd_236_; lean_object* v___x_237_; 
lean_dec(v_h__1_229_);
v_head_233_ = lean_ctor_get(v_x_228_, 0);
lean_inc(v_head_233_);
v_tail_234_ = lean_ctor_get(v_x_228_, 1);
lean_inc(v_tail_234_);
lean_dec_ref_known(v_x_228_, 2);
v_fst_235_ = lean_ctor_get(v_head_233_, 0);
lean_inc(v_fst_235_);
v_snd_236_ = lean_ctor_get(v_head_233_, 1);
lean_inc(v_snd_236_);
lean_dec(v_head_233_);
v___x_237_ = lean_apply_3(v_h__2_230_, v_fst_235_, v_snd_236_, v_tail_234_);
return v___x_237_;
}
}
}
static lean_object* _init_lp_bounded_Bounded_FUEL(void){
_start:
{
lean_object* v___x_238_; 
v___x_238_ = lean_unsigned_to_nat(1000000u);
return v___x_238_;
}
}
LEAN_EXPORT uint64_t lp_bounded_Bounded_instHashableConfig___aux__1(lean_object* v_x_242_){
_start:
{
lean_object* v___f_243_; uint64_t v___x_244_; 
v___f_243_ = ((lean_object*)(lp_bounded_Bounded_instHashableConfig___aux__1___closed__1));
v___x_244_ = lp_bounded_Bounded_instHashableSMap_hash___redArg(v___f_243_, v_x_242_);
return v___x_244_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instHashableConfig___aux__1___boxed(lean_object* v_x_245_){
_start:
{
uint64_t v_res_246_; lean_object* v_r_247_; 
v_res_246_ = lp_bounded_Bounded_instHashableConfig___aux__1(v_x_245_);
v_r_247_ = lean_box_uint64(v_res_246_);
return v_r_247_;
}
}
LEAN_EXPORT uint64_t lp_bounded_Bounded_instHashableSMap_hash___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00Bounded_fastExpand_spec__0_spec__0(lean_object* v_x_250_){
_start:
{
lean_object* v_s0_251_; lean_object* v_s1_252_; lean_object* v_s2_253_; uint64_t v___y_255_; uint64_t v___y_256_; uint64_t v___x_265_; uint64_t v___y_267_; 
v_s0_251_ = lean_ctor_get(v_x_250_, 0);
v_s1_252_ = lean_ctor_get(v_x_250_, 1);
v_s2_253_ = lean_ctor_get(v_x_250_, 2);
v___x_265_ = 0ULL;
if (lean_obj_tag(v_s0_251_) == 0)
{
uint64_t v___x_274_; 
v___x_274_ = 11ULL;
v___y_267_ = v___x_274_;
goto v___jp_266_;
}
else
{
lean_object* v_val_275_; uint64_t v___x_276_; uint64_t v___x_277_; uint64_t v___x_278_; 
v_val_275_ = lean_ctor_get(v_s0_251_, 0);
v___x_276_ = lp_bounded_Bounded_instHashableFiber_hash(v_val_275_);
v___x_277_ = 13ULL;
v___x_278_ = lean_uint64_mix_hash(v___x_276_, v___x_277_);
v___y_267_ = v___x_278_;
goto v___jp_266_;
}
v___jp_254_:
{
uint64_t v___x_257_; 
v___x_257_ = lean_uint64_mix_hash(v___y_255_, v___y_256_);
if (lean_obj_tag(v_s2_253_) == 0)
{
uint64_t v___x_258_; uint64_t v___x_259_; 
v___x_258_ = 11ULL;
v___x_259_ = lean_uint64_mix_hash(v___x_257_, v___x_258_);
return v___x_259_;
}
else
{
lean_object* v_val_260_; uint64_t v___x_261_; uint64_t v___x_262_; uint64_t v___x_263_; uint64_t v___x_264_; 
v_val_260_ = lean_ctor_get(v_s2_253_, 0);
v___x_261_ = lp_bounded_Bounded_instHashableFiber_hash(v_val_260_);
v___x_262_ = 13ULL;
v___x_263_ = lean_uint64_mix_hash(v___x_261_, v___x_262_);
v___x_264_ = lean_uint64_mix_hash(v___x_257_, v___x_263_);
return v___x_264_;
}
}
v___jp_266_:
{
uint64_t v___x_268_; 
v___x_268_ = lean_uint64_mix_hash(v___x_265_, v___y_267_);
if (lean_obj_tag(v_s1_252_) == 0)
{
uint64_t v___x_269_; 
v___x_269_ = 11ULL;
v___y_255_ = v___x_268_;
v___y_256_ = v___x_269_;
goto v___jp_254_;
}
else
{
lean_object* v_val_270_; uint64_t v___x_271_; uint64_t v___x_272_; uint64_t v___x_273_; 
v_val_270_ = lean_ctor_get(v_s1_252_, 0);
v___x_271_ = lp_bounded_Bounded_instHashableFiber_hash(v_val_270_);
v___x_272_ = 13ULL;
v___x_273_ = lean_uint64_mix_hash(v___x_271_, v___x_272_);
v___y_255_ = v___x_268_;
v___y_256_ = v___x_273_;
goto v___jp_254_;
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instHashableSMap_hash___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00Bounded_fastExpand_spec__0_spec__0___boxed(lean_object* v_x_279_){
_start:
{
uint64_t v_res_280_; lean_object* v_r_281_; 
v_res_280_ = lp_bounded_Bounded_instHashableSMap_hash___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00Bounded_fastExpand_spec__0_spec__0(v_x_279_);
lean_dec_ref(v_x_279_);
v_r_281_ = lean_box_uint64(v_res_280_);
return v_r_281_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00Bounded_fastExpand_spec__0_spec__1___redArg(lean_object* v_a_282_, lean_object* v_x_283_){
_start:
{
if (lean_obj_tag(v_x_283_) == 0)
{
uint8_t v___x_284_; 
lean_dec_ref(v_a_282_);
v___x_284_ = 0;
return v___x_284_;
}
else
{
lean_object* v_key_285_; lean_object* v_tail_286_; uint8_t v___x_287_; 
v_key_285_ = lean_ctor_get(v_x_283_, 0);
lean_inc(v_key_285_);
v_tail_286_ = lean_ctor_get(v_x_283_, 2);
lean_inc(v_tail_286_);
lean_dec_ref_known(v_x_283_, 3);
lean_inc_ref(v_a_282_);
v___x_287_ = lp_bounded_Bounded_instDecidableEqConfig___aux__1(v_key_285_, v_a_282_);
if (v___x_287_ == 0)
{
v_x_283_ = v_tail_286_;
goto _start;
}
else
{
lean_dec(v_tail_286_);
lean_dec_ref(v_a_282_);
return v___x_287_;
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00Bounded_fastExpand_spec__0_spec__1___redArg___boxed(lean_object* v_a_289_, lean_object* v_x_290_){
_start:
{
uint8_t v_res_291_; lean_object* v_r_292_; 
v_res_291_ = lp_bounded_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00Bounded_fastExpand_spec__0_spec__1___redArg(v_a_289_, v_x_290_);
v_r_292_ = lean_box(v_res_291_);
return v_r_292_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Std_DHashMap_Internal_Raw_u2080_contains___at___00Bounded_fastExpand_spec__0___redArg(lean_object* v_m_293_, lean_object* v_a_294_){
_start:
{
lean_object* v_buckets_295_; lean_object* v___x_296_; uint64_t v___x_297_; uint64_t v___x_298_; uint64_t v___x_299_; uint64_t v_fold_300_; uint64_t v___x_301_; uint64_t v___x_302_; uint64_t v___x_303_; size_t v___x_304_; size_t v___x_305_; size_t v___x_306_; size_t v___x_307_; size_t v___x_308_; lean_object* v___x_309_; uint8_t v___x_310_; 
v_buckets_295_ = lean_ctor_get(v_m_293_, 1);
v___x_296_ = lean_array_get_size(v_buckets_295_);
v___x_297_ = lp_bounded_Bounded_instHashableSMap_hash___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00Bounded_fastExpand_spec__0_spec__0(v_a_294_);
v___x_298_ = 32ULL;
v___x_299_ = lean_uint64_shift_right(v___x_297_, v___x_298_);
v_fold_300_ = lean_uint64_xor(v___x_297_, v___x_299_);
v___x_301_ = 16ULL;
v___x_302_ = lean_uint64_shift_right(v_fold_300_, v___x_301_);
v___x_303_ = lean_uint64_xor(v_fold_300_, v___x_302_);
v___x_304_ = lean_uint64_to_usize(v___x_303_);
v___x_305_ = lean_usize_of_nat(v___x_296_);
v___x_306_ = ((size_t)1ULL);
v___x_307_ = lean_usize_sub(v___x_305_, v___x_306_);
v___x_308_ = lean_usize_land(v___x_304_, v___x_307_);
v___x_309_ = lean_array_uget_borrowed(v_buckets_295_, v___x_308_);
lean_inc(v___x_309_);
v___x_310_ = lp_bounded_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00Bounded_fastExpand_spec__0_spec__1___redArg(v_a_294_, v___x_309_);
return v___x_310_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Std_DHashMap_Internal_Raw_u2080_contains___at___00Bounded_fastExpand_spec__0___redArg___boxed(lean_object* v_m_311_, lean_object* v_a_312_){
_start:
{
uint8_t v_res_313_; lean_object* v_r_314_; 
v_res_313_ = lp_bounded_Std_DHashMap_Internal_Raw_u2080_contains___at___00Bounded_fastExpand_spec__0___redArg(v_m_311_, v_a_312_);
lean_dec_ref(v_m_311_);
v_r_314_ = lean_box(v_res_313_);
return v_r_314_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Std_DHashMap_Internal_AssocList_replace___at___00Std_DHashMap_Internal_Raw_u2080_insert___at___00Bounded_fastExpand_spec__1_spec__4___redArg(lean_object* v_a_315_, lean_object* v_b_316_, lean_object* v_x_317_){
_start:
{
if (lean_obj_tag(v_x_317_) == 0)
{
lean_dec(v_b_316_);
lean_dec_ref(v_a_315_);
return v_x_317_;
}
else
{
lean_object* v_key_318_; lean_object* v_value_319_; lean_object* v_tail_320_; lean_object* v___x_322_; uint8_t v_isShared_323_; uint8_t v_isSharedCheck_332_; 
v_key_318_ = lean_ctor_get(v_x_317_, 0);
v_value_319_ = lean_ctor_get(v_x_317_, 1);
v_tail_320_ = lean_ctor_get(v_x_317_, 2);
v_isSharedCheck_332_ = !lean_is_exclusive(v_x_317_);
if (v_isSharedCheck_332_ == 0)
{
v___x_322_ = v_x_317_;
v_isShared_323_ = v_isSharedCheck_332_;
goto v_resetjp_321_;
}
else
{
lean_inc(v_tail_320_);
lean_inc(v_value_319_);
lean_inc(v_key_318_);
lean_dec(v_x_317_);
v___x_322_ = lean_box(0);
v_isShared_323_ = v_isSharedCheck_332_;
goto v_resetjp_321_;
}
v_resetjp_321_:
{
uint8_t v___x_324_; 
lean_inc_ref(v_a_315_);
lean_inc(v_key_318_);
v___x_324_ = lp_bounded_Bounded_instDecidableEqConfig___aux__1(v_key_318_, v_a_315_);
if (v___x_324_ == 0)
{
lean_object* v___x_325_; lean_object* v___x_327_; 
v___x_325_ = lp_bounded_Std_DHashMap_Internal_AssocList_replace___at___00Std_DHashMap_Internal_Raw_u2080_insert___at___00Bounded_fastExpand_spec__1_spec__4___redArg(v_a_315_, v_b_316_, v_tail_320_);
if (v_isShared_323_ == 0)
{
lean_ctor_set(v___x_322_, 2, v___x_325_);
v___x_327_ = v___x_322_;
goto v_reusejp_326_;
}
else
{
lean_object* v_reuseFailAlloc_328_; 
v_reuseFailAlloc_328_ = lean_alloc_ctor(1, 3, 0);
lean_ctor_set(v_reuseFailAlloc_328_, 0, v_key_318_);
lean_ctor_set(v_reuseFailAlloc_328_, 1, v_value_319_);
lean_ctor_set(v_reuseFailAlloc_328_, 2, v___x_325_);
v___x_327_ = v_reuseFailAlloc_328_;
goto v_reusejp_326_;
}
v_reusejp_326_:
{
return v___x_327_;
}
}
else
{
lean_object* v___x_330_; 
lean_dec(v_value_319_);
lean_dec(v_key_318_);
if (v_isShared_323_ == 0)
{
lean_ctor_set(v___x_322_, 1, v_b_316_);
lean_ctor_set(v___x_322_, 0, v_a_315_);
v___x_330_ = v___x_322_;
goto v_reusejp_329_;
}
else
{
lean_object* v_reuseFailAlloc_331_; 
v_reuseFailAlloc_331_ = lean_alloc_ctor(1, 3, 0);
lean_ctor_set(v_reuseFailAlloc_331_, 0, v_a_315_);
lean_ctor_set(v_reuseFailAlloc_331_, 1, v_b_316_);
lean_ctor_set(v_reuseFailAlloc_331_, 2, v_tail_320_);
v___x_330_ = v_reuseFailAlloc_331_;
goto v_reusejp_329_;
}
v_reusejp_329_:
{
return v___x_330_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Std_DHashMap_Internal_AssocList_foldlM___at___00__private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insert___at___00Bounded_fastExpand_spec__1_spec__3_spec__4_spec__6___redArg(lean_object* v_x_333_, lean_object* v_x_334_){
_start:
{
if (lean_obj_tag(v_x_334_) == 0)
{
return v_x_333_;
}
else
{
lean_object* v_key_335_; lean_object* v_value_336_; lean_object* v_tail_337_; lean_object* v___x_339_; uint8_t v_isShared_340_; uint8_t v_isSharedCheck_360_; 
v_key_335_ = lean_ctor_get(v_x_334_, 0);
v_value_336_ = lean_ctor_get(v_x_334_, 1);
v_tail_337_ = lean_ctor_get(v_x_334_, 2);
v_isSharedCheck_360_ = !lean_is_exclusive(v_x_334_);
if (v_isSharedCheck_360_ == 0)
{
v___x_339_ = v_x_334_;
v_isShared_340_ = v_isSharedCheck_360_;
goto v_resetjp_338_;
}
else
{
lean_inc(v_tail_337_);
lean_inc(v_value_336_);
lean_inc(v_key_335_);
lean_dec(v_x_334_);
v___x_339_ = lean_box(0);
v_isShared_340_ = v_isSharedCheck_360_;
goto v_resetjp_338_;
}
v_resetjp_338_:
{
lean_object* v___x_341_; uint64_t v___x_342_; uint64_t v___x_343_; uint64_t v___x_344_; uint64_t v_fold_345_; uint64_t v___x_346_; uint64_t v___x_347_; uint64_t v___x_348_; size_t v___x_349_; size_t v___x_350_; size_t v___x_351_; size_t v___x_352_; size_t v___x_353_; lean_object* v___x_354_; lean_object* v___x_356_; 
v___x_341_ = lean_array_get_size(v_x_333_);
v___x_342_ = lp_bounded_Bounded_instHashableSMap_hash___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00Bounded_fastExpand_spec__0_spec__0(v_key_335_);
v___x_343_ = 32ULL;
v___x_344_ = lean_uint64_shift_right(v___x_342_, v___x_343_);
v_fold_345_ = lean_uint64_xor(v___x_342_, v___x_344_);
v___x_346_ = 16ULL;
v___x_347_ = lean_uint64_shift_right(v_fold_345_, v___x_346_);
v___x_348_ = lean_uint64_xor(v_fold_345_, v___x_347_);
v___x_349_ = lean_uint64_to_usize(v___x_348_);
v___x_350_ = lean_usize_of_nat(v___x_341_);
v___x_351_ = ((size_t)1ULL);
v___x_352_ = lean_usize_sub(v___x_350_, v___x_351_);
v___x_353_ = lean_usize_land(v___x_349_, v___x_352_);
v___x_354_ = lean_array_uget_borrowed(v_x_333_, v___x_353_);
lean_inc(v___x_354_);
if (v_isShared_340_ == 0)
{
lean_ctor_set(v___x_339_, 2, v___x_354_);
v___x_356_ = v___x_339_;
goto v_reusejp_355_;
}
else
{
lean_object* v_reuseFailAlloc_359_; 
v_reuseFailAlloc_359_ = lean_alloc_ctor(1, 3, 0);
lean_ctor_set(v_reuseFailAlloc_359_, 0, v_key_335_);
lean_ctor_set(v_reuseFailAlloc_359_, 1, v_value_336_);
lean_ctor_set(v_reuseFailAlloc_359_, 2, v___x_354_);
v___x_356_ = v_reuseFailAlloc_359_;
goto v_reusejp_355_;
}
v_reusejp_355_:
{
lean_object* v___x_357_; 
v___x_357_ = lean_array_uset(v_x_333_, v___x_353_, v___x_356_);
v_x_333_ = v___x_357_;
v_x_334_ = v_tail_337_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded___private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insert___at___00Bounded_fastExpand_spec__1_spec__3_spec__4___redArg(lean_object* v_i_361_, lean_object* v_source_362_, lean_object* v_target_363_){
_start:
{
lean_object* v___x_364_; uint8_t v___x_365_; 
v___x_364_ = lean_array_get_size(v_source_362_);
v___x_365_ = lean_nat_dec_lt(v_i_361_, v___x_364_);
if (v___x_365_ == 0)
{
lean_dec_ref(v_source_362_);
lean_dec(v_i_361_);
return v_target_363_;
}
else
{
lean_object* v_es_366_; lean_object* v___x_367_; lean_object* v_source_368_; lean_object* v_target_369_; lean_object* v___x_370_; lean_object* v___x_371_; 
v_es_366_ = lean_array_fget(v_source_362_, v_i_361_);
v___x_367_ = lean_box(0);
v_source_368_ = lean_array_fset(v_source_362_, v_i_361_, v___x_367_);
v_target_369_ = lp_bounded_Std_DHashMap_Internal_AssocList_foldlM___at___00__private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insert___at___00Bounded_fastExpand_spec__1_spec__3_spec__4_spec__6___redArg(v_target_363_, v_es_366_);
v___x_370_ = lean_unsigned_to_nat(1u);
v___x_371_ = lean_nat_add(v_i_361_, v___x_370_);
lean_dec(v_i_361_);
v_i_361_ = v___x_371_;
v_source_362_ = v_source_368_;
v_target_363_ = v_target_369_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insert___at___00Bounded_fastExpand_spec__1_spec__3___redArg(lean_object* v_data_373_){
_start:
{
lean_object* v___x_374_; lean_object* v___x_375_; lean_object* v_nbuckets_376_; lean_object* v___x_377_; lean_object* v___x_378_; lean_object* v___x_379_; lean_object* v___x_380_; 
v___x_374_ = lean_array_get_size(v_data_373_);
v___x_375_ = lean_unsigned_to_nat(2u);
v_nbuckets_376_ = lean_nat_mul(v___x_374_, v___x_375_);
v___x_377_ = lean_unsigned_to_nat(0u);
v___x_378_ = lean_box(0);
v___x_379_ = lean_mk_array(v_nbuckets_376_, v___x_378_);
v___x_380_ = lp_bounded___private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insert___at___00Bounded_fastExpand_spec__1_spec__3_spec__4___redArg(v___x_377_, v_data_373_, v___x_379_);
return v___x_380_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Std_DHashMap_Internal_Raw_u2080_insert___at___00Bounded_fastExpand_spec__1___redArg(lean_object* v_m_381_, lean_object* v_a_382_, lean_object* v_b_383_){
_start:
{
lean_object* v_size_384_; lean_object* v_buckets_385_; lean_object* v___x_387_; uint8_t v_isShared_388_; uint8_t v_isSharedCheck_428_; 
v_size_384_ = lean_ctor_get(v_m_381_, 0);
v_buckets_385_ = lean_ctor_get(v_m_381_, 1);
v_isSharedCheck_428_ = !lean_is_exclusive(v_m_381_);
if (v_isSharedCheck_428_ == 0)
{
v___x_387_ = v_m_381_;
v_isShared_388_ = v_isSharedCheck_428_;
goto v_resetjp_386_;
}
else
{
lean_inc(v_buckets_385_);
lean_inc(v_size_384_);
lean_dec(v_m_381_);
v___x_387_ = lean_box(0);
v_isShared_388_ = v_isSharedCheck_428_;
goto v_resetjp_386_;
}
v_resetjp_386_:
{
lean_object* v___x_389_; uint64_t v___x_390_; uint64_t v___x_391_; uint64_t v___x_392_; uint64_t v_fold_393_; uint64_t v___x_394_; uint64_t v___x_395_; uint64_t v___x_396_; size_t v___x_397_; size_t v___x_398_; size_t v___x_399_; size_t v___x_400_; size_t v___x_401_; lean_object* v_bkt_402_; uint8_t v___x_403_; 
v___x_389_ = lean_array_get_size(v_buckets_385_);
v___x_390_ = lp_bounded_Bounded_instHashableSMap_hash___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00Bounded_fastExpand_spec__0_spec__0(v_a_382_);
v___x_391_ = 32ULL;
v___x_392_ = lean_uint64_shift_right(v___x_390_, v___x_391_);
v_fold_393_ = lean_uint64_xor(v___x_390_, v___x_392_);
v___x_394_ = 16ULL;
v___x_395_ = lean_uint64_shift_right(v_fold_393_, v___x_394_);
v___x_396_ = lean_uint64_xor(v_fold_393_, v___x_395_);
v___x_397_ = lean_uint64_to_usize(v___x_396_);
v___x_398_ = lean_usize_of_nat(v___x_389_);
v___x_399_ = ((size_t)1ULL);
v___x_400_ = lean_usize_sub(v___x_398_, v___x_399_);
v___x_401_ = lean_usize_land(v___x_397_, v___x_400_);
v_bkt_402_ = lean_array_uget_borrowed(v_buckets_385_, v___x_401_);
lean_inc(v_bkt_402_);
lean_inc_ref(v_a_382_);
v___x_403_ = lp_bounded_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00Bounded_fastExpand_spec__0_spec__1___redArg(v_a_382_, v_bkt_402_);
if (v___x_403_ == 0)
{
lean_object* v___x_404_; lean_object* v_size_x27_405_; lean_object* v___x_406_; lean_object* v_buckets_x27_407_; lean_object* v___x_408_; lean_object* v___x_409_; lean_object* v___x_410_; lean_object* v___x_411_; lean_object* v___x_412_; uint8_t v___x_413_; 
v___x_404_ = lean_unsigned_to_nat(1u);
v_size_x27_405_ = lean_nat_add(v_size_384_, v___x_404_);
lean_dec(v_size_384_);
lean_inc(v_bkt_402_);
v___x_406_ = lean_alloc_ctor(1, 3, 0);
lean_ctor_set(v___x_406_, 0, v_a_382_);
lean_ctor_set(v___x_406_, 1, v_b_383_);
lean_ctor_set(v___x_406_, 2, v_bkt_402_);
v_buckets_x27_407_ = lean_array_uset(v_buckets_385_, v___x_401_, v___x_406_);
v___x_408_ = lean_unsigned_to_nat(4u);
v___x_409_ = lean_nat_mul(v_size_x27_405_, v___x_408_);
v___x_410_ = lean_unsigned_to_nat(3u);
v___x_411_ = lean_nat_div(v___x_409_, v___x_410_);
lean_dec(v___x_409_);
v___x_412_ = lean_array_get_size(v_buckets_x27_407_);
v___x_413_ = lean_nat_dec_le(v___x_411_, v___x_412_);
lean_dec(v___x_411_);
if (v___x_413_ == 0)
{
lean_object* v_val_414_; lean_object* v___x_416_; 
v_val_414_ = lp_bounded_Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insert___at___00Bounded_fastExpand_spec__1_spec__3___redArg(v_buckets_x27_407_);
if (v_isShared_388_ == 0)
{
lean_ctor_set(v___x_387_, 1, v_val_414_);
lean_ctor_set(v___x_387_, 0, v_size_x27_405_);
v___x_416_ = v___x_387_;
goto v_reusejp_415_;
}
else
{
lean_object* v_reuseFailAlloc_417_; 
v_reuseFailAlloc_417_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_417_, 0, v_size_x27_405_);
lean_ctor_set(v_reuseFailAlloc_417_, 1, v_val_414_);
v___x_416_ = v_reuseFailAlloc_417_;
goto v_reusejp_415_;
}
v_reusejp_415_:
{
return v___x_416_;
}
}
else
{
lean_object* v___x_419_; 
if (v_isShared_388_ == 0)
{
lean_ctor_set(v___x_387_, 1, v_buckets_x27_407_);
lean_ctor_set(v___x_387_, 0, v_size_x27_405_);
v___x_419_ = v___x_387_;
goto v_reusejp_418_;
}
else
{
lean_object* v_reuseFailAlloc_420_; 
v_reuseFailAlloc_420_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_420_, 0, v_size_x27_405_);
lean_ctor_set(v_reuseFailAlloc_420_, 1, v_buckets_x27_407_);
v___x_419_ = v_reuseFailAlloc_420_;
goto v_reusejp_418_;
}
v_reusejp_418_:
{
return v___x_419_;
}
}
}
else
{
lean_object* v___x_421_; lean_object* v_buckets_x27_422_; lean_object* v___x_423_; lean_object* v___x_424_; lean_object* v___x_426_; 
lean_inc(v_bkt_402_);
v___x_421_ = lean_box(0);
v_buckets_x27_422_ = lean_array_uset(v_buckets_385_, v___x_401_, v___x_421_);
v___x_423_ = lp_bounded_Std_DHashMap_Internal_AssocList_replace___at___00Std_DHashMap_Internal_Raw_u2080_insert___at___00Bounded_fastExpand_spec__1_spec__4___redArg(v_a_382_, v_b_383_, v_bkt_402_);
v___x_424_ = lean_array_uset(v_buckets_x27_422_, v___x_401_, v___x_423_);
if (v_isShared_388_ == 0)
{
lean_ctor_set(v___x_387_, 1, v___x_424_);
v___x_426_ = v___x_387_;
goto v_reusejp_425_;
}
else
{
lean_object* v_reuseFailAlloc_427_; 
v_reuseFailAlloc_427_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_427_, 0, v_size_384_);
lean_ctor_set(v_reuseFailAlloc_427_, 1, v___x_424_);
v___x_426_ = v_reuseFailAlloc_427_;
goto v_reusejp_425_;
}
v_reusejp_425_:
{
return v___x_426_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_List_foldl___at___00Bounded_fastExpand_spec__2(lean_object* v_snd_429_, lean_object* v_x_430_, lean_object* v_x_431_){
_start:
{
if (lean_obj_tag(v_x_431_) == 0)
{
lean_dec(v_snd_429_);
return v_x_430_;
}
else
{
lean_object* v_head_432_; lean_object* v_tail_433_; lean_object* v___x_435_; uint8_t v_isShared_436_; uint8_t v_isSharedCheck_478_; 
v_head_432_ = lean_ctor_get(v_x_431_, 0);
v_tail_433_ = lean_ctor_get(v_x_431_, 1);
v_isSharedCheck_478_ = !lean_is_exclusive(v_x_431_);
if (v_isSharedCheck_478_ == 0)
{
v___x_435_ = v_x_431_;
v_isShared_436_ = v_isSharedCheck_478_;
goto v_resetjp_434_;
}
else
{
lean_inc(v_tail_433_);
lean_inc(v_head_432_);
lean_dec(v_x_431_);
v___x_435_ = lean_box(0);
v_isShared_436_ = v_isSharedCheck_478_;
goto v_resetjp_434_;
}
v_resetjp_434_:
{
lean_object* v_fst_437_; lean_object* v_snd_438_; lean_object* v_fst_439_; lean_object* v_snd_440_; lean_object* v___x_442_; uint8_t v_isShared_443_; uint8_t v_isSharedCheck_477_; 
v_fst_437_ = lean_ctor_get(v_x_430_, 0);
v_snd_438_ = lean_ctor_get(v_x_430_, 1);
lean_inc(v_snd_438_);
v_fst_439_ = lean_ctor_get(v_head_432_, 0);
v_snd_440_ = lean_ctor_get(v_head_432_, 1);
v_isSharedCheck_477_ = !lean_is_exclusive(v_head_432_);
if (v_isSharedCheck_477_ == 0)
{
v___x_442_ = v_head_432_;
v_isShared_443_ = v_isSharedCheck_477_;
goto v_resetjp_441_;
}
else
{
lean_inc(v_snd_440_);
lean_inc(v_fst_439_);
lean_dec(v_head_432_);
v___x_442_ = lean_box(0);
v_isShared_443_ = v_isSharedCheck_477_;
goto v_resetjp_441_;
}
v_resetjp_441_:
{
uint8_t v___x_444_; 
lean_inc(v_snd_440_);
v___x_444_ = lp_bounded_Std_DHashMap_Internal_Raw_u2080_contains___at___00Bounded_fastExpand_spec__0___redArg(v_fst_437_, v_snd_440_);
if (v___x_444_ == 0)
{
lean_object* v___x_446_; uint8_t v_isShared_447_; uint8_t v_isSharedCheck_473_; 
lean_inc(v_fst_437_);
v_isSharedCheck_473_ = !lean_is_exclusive(v_x_430_);
if (v_isSharedCheck_473_ == 0)
{
lean_object* v_unused_474_; lean_object* v_unused_475_; 
v_unused_474_ = lean_ctor_get(v_x_430_, 1);
lean_dec(v_unused_474_);
v_unused_475_ = lean_ctor_get(v_x_430_, 0);
lean_dec(v_unused_475_);
v___x_446_ = v_x_430_;
v_isShared_447_ = v_isSharedCheck_473_;
goto v_resetjp_445_;
}
else
{
lean_dec(v_x_430_);
v___x_446_ = lean_box(0);
v_isShared_447_ = v_isSharedCheck_473_;
goto v_resetjp_445_;
}
v_resetjp_445_:
{
lean_object* v_fst_448_; lean_object* v_snd_449_; lean_object* v___x_451_; uint8_t v_isShared_452_; uint8_t v_isSharedCheck_472_; 
v_fst_448_ = lean_ctor_get(v_snd_438_, 0);
v_snd_449_ = lean_ctor_get(v_snd_438_, 1);
v_isSharedCheck_472_ = !lean_is_exclusive(v_snd_438_);
if (v_isSharedCheck_472_ == 0)
{
v___x_451_ = v_snd_438_;
v_isShared_452_ = v_isSharedCheck_472_;
goto v_resetjp_450_;
}
else
{
lean_inc(v_snd_449_);
lean_inc(v_fst_448_);
lean_dec(v_snd_438_);
v___x_451_ = lean_box(0);
v_isShared_452_ = v_isSharedCheck_472_;
goto v_resetjp_450_;
}
v_resetjp_450_:
{
lean_object* v___x_453_; lean_object* v___x_454_; lean_object* v___x_455_; lean_object* v___x_457_; 
v___x_453_ = lean_box(0);
lean_inc(v_snd_440_);
v___x_454_ = lp_bounded_Std_DHashMap_Internal_Raw_u2080_insert___at___00Bounded_fastExpand_spec__1___redArg(v_fst_437_, v_snd_440_, v___x_453_);
v___x_455_ = lean_box(0);
if (v_isShared_436_ == 0)
{
lean_ctor_set(v___x_435_, 1, v___x_455_);
lean_ctor_set(v___x_435_, 0, v_fst_439_);
v___x_457_ = v___x_435_;
goto v_reusejp_456_;
}
else
{
lean_object* v_reuseFailAlloc_471_; 
v_reuseFailAlloc_471_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_471_, 0, v_fst_439_);
lean_ctor_set(v_reuseFailAlloc_471_, 1, v___x_455_);
v___x_457_ = v_reuseFailAlloc_471_;
goto v_reusejp_456_;
}
v_reusejp_456_:
{
lean_object* v___x_458_; lean_object* v___x_460_; 
lean_inc(v_snd_429_);
v___x_458_ = l_List_appendTR___redArg(v_snd_429_, v___x_457_);
if (v_isShared_452_ == 0)
{
lean_ctor_set(v___x_451_, 1, v___x_458_);
lean_ctor_set(v___x_451_, 0, v_snd_440_);
v___x_460_ = v___x_451_;
goto v_reusejp_459_;
}
else
{
lean_object* v_reuseFailAlloc_470_; 
v_reuseFailAlloc_470_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_470_, 0, v_snd_440_);
lean_ctor_set(v_reuseFailAlloc_470_, 1, v___x_458_);
v___x_460_ = v_reuseFailAlloc_470_;
goto v_reusejp_459_;
}
v_reusejp_459_:
{
lean_object* v___x_461_; lean_object* v___x_462_; lean_object* v___x_464_; 
lean_inc_ref(v___x_460_);
v___x_461_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_461_, 0, v___x_460_);
lean_ctor_set(v___x_461_, 1, v_fst_448_);
v___x_462_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_462_, 0, v___x_460_);
lean_ctor_set(v___x_462_, 1, v_snd_449_);
if (v_isShared_443_ == 0)
{
lean_ctor_set(v___x_442_, 1, v___x_462_);
lean_ctor_set(v___x_442_, 0, v___x_461_);
v___x_464_ = v___x_442_;
goto v_reusejp_463_;
}
else
{
lean_object* v_reuseFailAlloc_469_; 
v_reuseFailAlloc_469_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_469_, 0, v___x_461_);
lean_ctor_set(v_reuseFailAlloc_469_, 1, v___x_462_);
v___x_464_ = v_reuseFailAlloc_469_;
goto v_reusejp_463_;
}
v_reusejp_463_:
{
lean_object* v___x_466_; 
if (v_isShared_447_ == 0)
{
lean_ctor_set(v___x_446_, 1, v___x_464_);
lean_ctor_set(v___x_446_, 0, v___x_454_);
v___x_466_ = v___x_446_;
goto v_reusejp_465_;
}
else
{
lean_object* v_reuseFailAlloc_468_; 
v_reuseFailAlloc_468_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_468_, 0, v___x_454_);
lean_ctor_set(v_reuseFailAlloc_468_, 1, v___x_464_);
v___x_466_ = v_reuseFailAlloc_468_;
goto v_reusejp_465_;
}
v_reusejp_465_:
{
v_x_430_ = v___x_466_;
v_x_431_ = v_tail_433_;
goto _start;
}
}
}
}
}
}
}
else
{
lean_del_object(v___x_442_);
lean_dec(v_snd_440_);
lean_dec(v_fst_439_);
lean_dec(v_snd_438_);
lean_del_object(v___x_435_);
v_x_431_ = v_tail_433_;
goto _start;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_fastExpand(lean_object* v_x_479_, lean_object* v_x_480_, lean_object* v_x_481_, lean_object* v_x_482_, lean_object* v_x_483_){
_start:
{
lean_object* v_zero_484_; uint8_t v_isZero_485_; 
v_zero_484_ = lean_unsigned_to_nat(0u);
v_isZero_485_ = lean_nat_dec_eq(v_x_479_, v_zero_484_);
if (v_isZero_485_ == 1)
{
lean_object* v___x_486_; 
lean_dec(v_x_482_);
lean_dec(v_x_481_);
lean_dec_ref(v_x_480_);
lean_dec(v_x_479_);
v___x_486_ = l_List_reverse___redArg(v_x_483_);
return v___x_486_;
}
else
{
lean_object* v_one_487_; lean_object* v_n_488_; 
v_one_487_ = lean_unsigned_to_nat(1u);
v_n_488_ = lean_nat_sub(v_x_479_, v_one_487_);
lean_dec(v_x_479_);
if (lean_obj_tag(v_x_481_) == 0)
{
lean_object* v___x_489_; 
v___x_489_ = l_List_reverse___redArg(v_x_482_);
if (lean_obj_tag(v___x_489_) == 0)
{
lean_object* v___x_490_; 
lean_dec(v_n_488_);
lean_dec_ref(v_x_480_);
v___x_490_ = l_List_reverse___redArg(v_x_483_);
return v___x_490_;
}
else
{
{
lean_object* _tmp_0 = v_n_488_;
lean_object* _tmp_2 = v___x_489_;
lean_object* _tmp_3 = v_x_481_;
v_x_479_ = _tmp_0;
v_x_481_ = _tmp_2;
v_x_482_ = _tmp_3;
}
goto _start;
}
}
else
{
lean_object* v_head_492_; lean_object* v_tail_493_; lean_object* v___x_495_; uint8_t v_isShared_496_; uint8_t v_isSharedCheck_516_; 
v_head_492_ = lean_ctor_get(v_x_481_, 0);
v_tail_493_ = lean_ctor_get(v_x_481_, 1);
v_isSharedCheck_516_ = !lean_is_exclusive(v_x_481_);
if (v_isSharedCheck_516_ == 0)
{
v___x_495_ = v_x_481_;
v_isShared_496_ = v_isSharedCheck_516_;
goto v_resetjp_494_;
}
else
{
lean_inc(v_tail_493_);
lean_inc(v_head_492_);
lean_dec(v_x_481_);
v___x_495_ = lean_box(0);
v_isShared_496_ = v_isSharedCheck_516_;
goto v_resetjp_494_;
}
v_resetjp_494_:
{
lean_object* v_fst_497_; lean_object* v_snd_498_; lean_object* v___x_500_; uint8_t v_isShared_501_; uint8_t v_isSharedCheck_515_; 
v_fst_497_ = lean_ctor_get(v_head_492_, 0);
v_snd_498_ = lean_ctor_get(v_head_492_, 1);
v_isSharedCheck_515_ = !lean_is_exclusive(v_head_492_);
if (v_isSharedCheck_515_ == 0)
{
v___x_500_ = v_head_492_;
v_isShared_501_ = v_isSharedCheck_515_;
goto v_resetjp_499_;
}
else
{
lean_inc(v_snd_498_);
lean_inc(v_fst_497_);
lean_dec(v_head_492_);
v___x_500_ = lean_box(0);
v_isShared_501_ = v_isSharedCheck_515_;
goto v_resetjp_499_;
}
v_resetjp_499_:
{
lean_object* v___x_503_; 
if (v_isShared_501_ == 0)
{
lean_ctor_set(v___x_500_, 1, v_x_483_);
lean_ctor_set(v___x_500_, 0, v_x_482_);
v___x_503_ = v___x_500_;
goto v_reusejp_502_;
}
else
{
lean_object* v_reuseFailAlloc_514_; 
v_reuseFailAlloc_514_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_514_, 0, v_x_482_);
lean_ctor_set(v_reuseFailAlloc_514_, 1, v_x_483_);
v___x_503_ = v_reuseFailAlloc_514_;
goto v_reusejp_502_;
}
v_reusejp_502_:
{
lean_object* v___x_505_; 
if (v_isShared_496_ == 0)
{
lean_ctor_set_tag(v___x_495_, 0);
lean_ctor_set(v___x_495_, 1, v___x_503_);
lean_ctor_set(v___x_495_, 0, v_x_480_);
v___x_505_ = v___x_495_;
goto v_reusejp_504_;
}
else
{
lean_object* v_reuseFailAlloc_513_; 
v_reuseFailAlloc_513_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_513_, 0, v_x_480_);
lean_ctor_set(v_reuseFailAlloc_513_, 1, v___x_503_);
v___x_505_ = v_reuseFailAlloc_513_;
goto v_reusejp_504_;
}
v_reusejp_504_:
{
lean_object* v___x_506_; lean_object* v_r_507_; lean_object* v_snd_508_; lean_object* v_fst_509_; lean_object* v_fst_510_; lean_object* v_snd_511_; 
v___x_506_ = lp_bounded_Bounded_succsOf(v_fst_497_);
v_r_507_ = lp_bounded_List_foldl___at___00Bounded_fastExpand_spec__2(v_snd_498_, v___x_505_, v___x_506_);
v_snd_508_ = lean_ctor_get(v_r_507_, 1);
lean_inc(v_snd_508_);
v_fst_509_ = lean_ctor_get(v_r_507_, 0);
lean_inc(v_fst_509_);
lean_dec_ref(v_r_507_);
v_fst_510_ = lean_ctor_get(v_snd_508_, 0);
lean_inc(v_fst_510_);
v_snd_511_ = lean_ctor_get(v_snd_508_, 1);
lean_inc(v_snd_511_);
lean_dec(v_snd_508_);
v_x_479_ = v_n_488_;
v_x_480_ = v_fst_509_;
v_x_481_ = v_tail_493_;
v_x_482_ = v_fst_510_;
v_x_483_ = v_snd_511_;
goto _start;
}
}
}
}
}
}
}
}
LEAN_EXPORT uint8_t lp_bounded_Std_DHashMap_Internal_Raw_u2080_contains___at___00Bounded_fastExpand_spec__0(lean_object* v_00_u03b2_517_, lean_object* v_m_518_, lean_object* v_a_519_){
_start:
{
uint8_t v___x_520_; 
v___x_520_ = lp_bounded_Std_DHashMap_Internal_Raw_u2080_contains___at___00Bounded_fastExpand_spec__0___redArg(v_m_518_, v_a_519_);
return v___x_520_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Std_DHashMap_Internal_Raw_u2080_contains___at___00Bounded_fastExpand_spec__0___boxed(lean_object* v_00_u03b2_521_, lean_object* v_m_522_, lean_object* v_a_523_){
_start:
{
uint8_t v_res_524_; lean_object* v_r_525_; 
v_res_524_ = lp_bounded_Std_DHashMap_Internal_Raw_u2080_contains___at___00Bounded_fastExpand_spec__0(v_00_u03b2_521_, v_m_522_, v_a_523_);
lean_dec_ref(v_m_522_);
v_r_525_ = lean_box(v_res_524_);
return v_r_525_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Std_DHashMap_Internal_Raw_u2080_insert___at___00Bounded_fastExpand_spec__1(lean_object* v_00_u03b2_526_, lean_object* v_m_527_, lean_object* v_a_528_, lean_object* v_b_529_){
_start:
{
lean_object* v___x_530_; 
v___x_530_ = lp_bounded_Std_DHashMap_Internal_Raw_u2080_insert___at___00Bounded_fastExpand_spec__1___redArg(v_m_527_, v_a_528_, v_b_529_);
return v___x_530_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00Bounded_fastExpand_spec__0_spec__1(lean_object* v_00_u03b2_531_, lean_object* v_a_532_, lean_object* v_x_533_){
_start:
{
uint8_t v___x_534_; 
v___x_534_ = lp_bounded_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00Bounded_fastExpand_spec__0_spec__1___redArg(v_a_532_, v_x_533_);
return v___x_534_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00Bounded_fastExpand_spec__0_spec__1___boxed(lean_object* v_00_u03b2_535_, lean_object* v_a_536_, lean_object* v_x_537_){
_start:
{
uint8_t v_res_538_; lean_object* v_r_539_; 
v_res_538_ = lp_bounded_Std_DHashMap_Internal_AssocList_contains___at___00Std_DHashMap_Internal_Raw_u2080_contains___at___00Bounded_fastExpand_spec__0_spec__1(v_00_u03b2_535_, v_a_536_, v_x_537_);
v_r_539_ = lean_box(v_res_538_);
return v_r_539_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insert___at___00Bounded_fastExpand_spec__1_spec__3(lean_object* v_00_u03b2_540_, lean_object* v_data_541_){
_start:
{
lean_object* v___x_542_; 
v___x_542_ = lp_bounded_Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insert___at___00Bounded_fastExpand_spec__1_spec__3___redArg(v_data_541_);
return v___x_542_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Std_DHashMap_Internal_AssocList_replace___at___00Std_DHashMap_Internal_Raw_u2080_insert___at___00Bounded_fastExpand_spec__1_spec__4(lean_object* v_00_u03b2_543_, lean_object* v_a_544_, lean_object* v_b_545_, lean_object* v_x_546_){
_start:
{
lean_object* v___x_547_; 
v___x_547_ = lp_bounded_Std_DHashMap_Internal_AssocList_replace___at___00Std_DHashMap_Internal_Raw_u2080_insert___at___00Bounded_fastExpand_spec__1_spec__4___redArg(v_a_544_, v_b_545_, v_x_546_);
return v___x_547_;
}
}
LEAN_EXPORT lean_object* lp_bounded___private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insert___at___00Bounded_fastExpand_spec__1_spec__3_spec__4(lean_object* v_00_u03b2_548_, lean_object* v_i_549_, lean_object* v_source_550_, lean_object* v_target_551_){
_start:
{
lean_object* v___x_552_; 
v___x_552_ = lp_bounded___private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insert___at___00Bounded_fastExpand_spec__1_spec__3_spec__4___redArg(v_i_549_, v_source_550_, v_target_551_);
return v___x_552_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Std_DHashMap_Internal_AssocList_foldlM___at___00__private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insert___at___00Bounded_fastExpand_spec__1_spec__3_spec__4_spec__6(lean_object* v_00_u03b2_553_, lean_object* v_x_554_, lean_object* v_x_555_){
_start:
{
lean_object* v___x_556_; 
v___x_556_ = lp_bounded_Std_DHashMap_Internal_AssocList_foldlM___at___00__private_Std_Data_DHashMap_Internal_Defs_0__Std_DHashMap_Internal_Raw_u2080_expand_go___at___00Std_DHashMap_Internal_Raw_u2080_expand___at___00Std_DHashMap_Internal_Raw_u2080_insert___at___00Bounded_fastExpand_spec__1_spec__3_spec__4_spec__6___redArg(v_x_554_, v_x_555_);
return v___x_556_;
}
}
static lean_object* _init_lp_bounded_Bounded_visitedP___closed__0(void){
_start:
{
lean_object* v___x_557_; lean_object* v___x_558_; lean_object* v___x_559_; 
v___x_557_ = lean_box(0);
v___x_558_ = lean_unsigned_to_nat(16u);
v___x_559_ = lean_mk_array(v___x_558_, v___x_557_);
return v___x_559_;
}
}
static lean_object* _init_lp_bounded_Bounded_visitedP___closed__1(void){
_start:
{
lean_object* v___x_560_; lean_object* v___x_561_; lean_object* v___x_562_; 
v___x_560_ = lean_obj_once(&lp_bounded_Bounded_visitedP___closed__0, &lp_bounded_Bounded_visitedP___closed__0_once, _init_lp_bounded_Bounded_visitedP___closed__0);
v___x_561_ = lean_unsigned_to_nat(0u);
v___x_562_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_562_, 0, v___x_561_);
lean_ctor_set(v___x_562_, 1, v___x_560_);
return v___x_562_;
}
}
static lean_object* _init_lp_bounded_Bounded_visitedP___closed__2(void){
_start:
{
lean_object* v___x_563_; lean_object* v___x_564_; lean_object* v___x_565_; lean_object* v___x_566_; 
v___x_563_ = lean_box(0);
v___x_564_ = lp_bounded_Bounded_emptyConfig;
v___x_565_ = lean_obj_once(&lp_bounded_Bounded_visitedP___closed__1, &lp_bounded_Bounded_visitedP___closed__1_once, _init_lp_bounded_Bounded_visitedP___closed__1);
v___x_566_ = lp_bounded_Std_DHashMap_Internal_Raw_u2080_insert___at___00Bounded_fastExpand_spec__1___redArg(v___x_565_, v___x_564_, v___x_563_);
return v___x_566_;
}
}
static lean_object* _init_lp_bounded_Bounded_visitedP___closed__3(void){
_start:
{
lean_object* v___x_567_; lean_object* v___x_568_; lean_object* v___x_569_; lean_object* v___x_570_; lean_object* v___x_571_; 
v___x_567_ = lean_box(0);
v___x_568_ = lean_obj_once(&lp_bounded_Bounded_st0___closed__1, &lp_bounded_Bounded_st0___closed__1_once, _init_lp_bounded_Bounded_st0___closed__1);
v___x_569_ = lean_obj_once(&lp_bounded_Bounded_visitedP___closed__2, &lp_bounded_Bounded_visitedP___closed__2_once, _init_lp_bounded_Bounded_visitedP___closed__2);
v___x_570_ = lean_unsigned_to_nat(1000000u);
v___x_571_ = lp_bounded_Bounded_fastExpand(v___x_570_, v___x_569_, v___x_568_, v___x_567_, v___x_568_);
return v___x_571_;
}
}
static lean_object* _init_lp_bounded_Bounded_visitedP(void){
_start:
{
lean_object* v___x_572_; 
v___x_572_ = lean_obj_once(&lp_bounded_Bounded_visitedP___closed__3, &lp_bounded_Bounded_visitedP___closed__3_once, _init_lp_bounded_Bounded_visitedP___closed__3);
return v___x_572_;
}
}
static lean_object* _init_lp_bounded_Bounded_visited___closed__0(void){
_start:
{
lean_object* v___x_573_; lean_object* v___x_574_; lean_object* v___x_575_; 
v___x_573_ = lean_box(0);
v___x_574_ = lp_bounded_Bounded_visitedP;
v___x_575_ = lp_bounded_List_mapTR_loop___at___00Bounded_seenConfigs_spec__0(v___x_574_, v___x_573_);
return v___x_575_;
}
}
static lean_object* _init_lp_bounded_Bounded_visited(void){
_start:
{
lean_object* v___x_576_; 
v___x_576_ = lean_obj_once(&lp_bounded_Bounded_visited___closed__0, &lp_bounded_Bounded_visited___closed__0_once, _init_lp_bounded_Bounded_visited___closed__0);
return v___x_576_;
}
}
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Std_Data_HashMap(uint8_t builtin);
lean_object* initialize_bounded_Bounded_Enum(uint8_t builtin);
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_bounded_Bounded_Explore(uint8_t builtin) {
lean_object * res;
if (_G_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_initialized = true;
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Std_Data_HashMap(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_bounded_Bounded_Enum(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
lp_bounded_Bounded_00_u03b30 = _init_lp_bounded_Bounded_00_u03b30();
lean_mark_persistent(lp_bounded_Bounded_00_u03b30);
lp_bounded_Bounded_st0 = _init_lp_bounded_Bounded_st0();
lean_mark_persistent(lp_bounded_Bounded_st0);
lp_bounded_Bounded_FUEL = _init_lp_bounded_Bounded_FUEL();
lean_mark_persistent(lp_bounded_Bounded_FUEL);
lp_bounded_Bounded_visitedP = _init_lp_bounded_Bounded_visitedP();
lean_mark_persistent(lp_bounded_Bounded_visitedP);
lp_bounded_Bounded_visited = _init_lp_bounded_Bounded_visited();
lean_mark_persistent(lp_bounded_Bounded_visited);
return lean_io_result_mk_ok(lean_box(0));
}
#ifdef __cplusplus
}
#endif

// Lean compiler output
// Module: Bounded.Charact
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
uint8_t lp_bounded_Bounded_Act_rule(lean_object*);
lean_object* lp_bounded_Bounded_sig(lean_object*, lean_object*);
lean_object* lp_bounded_Bounded_liftStep(lean_object*, lean_object*, lean_object*);
lean_object* lp_bounded_Bounded_obsRow(lean_object*);
lean_object* l_List_reverse___redArg(lean_object*);
lean_object* l_List_appendTR___redArg(lean_object*, lean_object*);
lean_object* lean_mk_empty_array_with_capacity(lean_object*);
lean_object* lean_array_to_list(lean_object*);
extern lean_object* lp_bounded_Bounded_catalogActs;
lean_object* l_List_foldl___at___00Array_appendList_spec__0___redArg(lean_object*, lean_object*);
extern lean_object* lp_bounded_Bounded_visitedP;
LEAN_EXPORT lean_object* lp_bounded_Bounded_implStep(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_certOf(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_rowOf(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_nextState(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_runObs(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_runState(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_List_mapTR_loop___at___00Bounded_suite_spec__0(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00Bounded_suite_spec__1(lean_object*, lean_object*);
static const lean_array_object lp_bounded_Bounded_suite___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_array_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 246}, .m_size = 0, .m_capacity = 0, .m_data = {}};
static const lean_object* lp_bounded_Bounded_suite___closed__0 = (const lean_object*)&lp_bounded_Bounded_suite___closed__0_value;
static lean_once_cell_t lp_bounded_Bounded_suite___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_suite___closed__1;
LEAN_EXPORT lean_object* lp_bounded_Bounded_suite;
LEAN_EXPORT lean_object* lp_bounded___private_Bounded_Charact_0__Bounded_runObs_match__1_splitter___redArg(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded___private_Bounded_Charact_0__Bounded_runObs_match__1_splitter(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded___private_Bounded_Charact_0__Bounded_runFrom_match__1_splitter___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded___private_Bounded_Charact_0__Bounded_runFrom_match__1_splitter(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_implStep(lean_object* v_fI_1_, lean_object* v_a_2_, lean_object* v_00_u03b3_3_){
_start:
{
lean_object* v___x_4_; lean_object* v___x_5_; lean_object* v___x_6_; 
lean_inc_ref(v_00_u03b3_3_);
lean_inc_ref(v_a_2_);
v___x_4_ = lp_bounded_Bounded_sig(v_a_2_, v_00_u03b3_3_);
v___x_5_ = lean_apply_1(v_fI_1_, v___x_4_);
v___x_6_ = lp_bounded_Bounded_liftStep(v_a_2_, v_00_u03b3_3_, v___x_5_);
return v___x_6_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_certOf(lean_object* v_fI_7_, lean_object* v_a_8_, lean_object* v_00_u03b3_9_){
_start:
{
uint8_t v___x_10_; lean_object* v___x_11_; lean_object* v___x_12_; lean_object* v___x_13_; lean_object* v___x_14_; lean_object* v___x_15_; 
v___x_10_ = lp_bounded_Bounded_Act_rule(v_a_8_);
v___x_11_ = lp_bounded_Bounded_sig(v_a_8_, v_00_u03b3_9_);
lean_inc_ref(v___x_11_);
v___x_12_ = lean_apply_1(v_fI_7_, v___x_11_);
v___x_13_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_13_, 0, v___x_11_);
lean_ctor_set(v___x_13_, 1, v___x_12_);
v___x_14_ = lean_box(v___x_10_);
v___x_15_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_15_, 0, v___x_14_);
lean_ctor_set(v___x_15_, 1, v___x_13_);
return v___x_15_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_rowOf(lean_object* v_fI_16_, lean_object* v_a_17_, lean_object* v_00_u03b3_18_){
_start:
{
lean_object* v___x_19_; lean_object* v___x_20_; lean_object* v___x_21_; lean_object* v___x_22_; 
lean_inc_ref(v_00_u03b3_18_);
lean_inc_ref(v_a_17_);
lean_inc_ref(v_fI_16_);
v___x_19_ = lp_bounded_Bounded_certOf(v_fI_16_, v_a_17_, v_00_u03b3_18_);
v___x_20_ = lp_bounded_Bounded_implStep(v_fI_16_, v_a_17_, v_00_u03b3_18_);
v___x_21_ = lp_bounded_Bounded_obsRow(v___x_20_);
v___x_22_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_22_, 0, v___x_19_);
lean_ctor_set(v___x_22_, 1, v___x_21_);
return v___x_22_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_nextState(lean_object* v_fI_23_, lean_object* v_a_24_, lean_object* v_00_u03b3_25_){
_start:
{
lean_object* v___x_26_; 
lean_inc_ref(v_00_u03b3_25_);
v___x_26_ = lp_bounded_Bounded_implStep(v_fI_23_, v_a_24_, v_00_u03b3_25_);
if (lean_obj_tag(v___x_26_) == 0)
{
return v_00_u03b3_25_;
}
else
{
lean_object* v_val_27_; lean_object* v_snd_28_; 
lean_dec_ref(v_00_u03b3_25_);
v_val_27_ = lean_ctor_get(v___x_26_, 0);
lean_inc(v_val_27_);
lean_dec_ref_known(v___x_26_, 1);
v_snd_28_ = lean_ctor_get(v_val_27_, 1);
lean_inc(v_snd_28_);
lean_dec(v_val_27_);
return v_snd_28_;
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_runObs(lean_object* v_fI_29_, lean_object* v_x_30_, lean_object* v_x_31_){
_start:
{
if (lean_obj_tag(v_x_31_) == 0)
{
lean_object* v___x_32_; 
lean_dec_ref(v_x_30_);
lean_dec_ref(v_fI_29_);
v___x_32_ = lean_box(0);
return v___x_32_;
}
else
{
lean_object* v_head_33_; lean_object* v_tail_34_; lean_object* v___x_36_; uint8_t v_isShared_37_; uint8_t v_isSharedCheck_44_; 
v_head_33_ = lean_ctor_get(v_x_31_, 0);
v_tail_34_ = lean_ctor_get(v_x_31_, 1);
v_isSharedCheck_44_ = !lean_is_exclusive(v_x_31_);
if (v_isSharedCheck_44_ == 0)
{
v___x_36_ = v_x_31_;
v_isShared_37_ = v_isSharedCheck_44_;
goto v_resetjp_35_;
}
else
{
lean_inc(v_tail_34_);
lean_inc(v_head_33_);
lean_dec(v_x_31_);
v___x_36_ = lean_box(0);
v_isShared_37_ = v_isSharedCheck_44_;
goto v_resetjp_35_;
}
v_resetjp_35_:
{
lean_object* v___x_38_; lean_object* v___x_39_; lean_object* v___x_40_; lean_object* v___x_42_; 
lean_inc_ref(v_x_30_);
lean_inc(v_head_33_);
lean_inc_ref_n(v_fI_29_, 2);
v___x_38_ = lp_bounded_Bounded_rowOf(v_fI_29_, v_head_33_, v_x_30_);
v___x_39_ = lp_bounded_Bounded_nextState(v_fI_29_, v_head_33_, v_x_30_);
v___x_40_ = lp_bounded_Bounded_runObs(v_fI_29_, v___x_39_, v_tail_34_);
if (v_isShared_37_ == 0)
{
lean_ctor_set(v___x_36_, 1, v___x_40_);
lean_ctor_set(v___x_36_, 0, v___x_38_);
v___x_42_ = v___x_36_;
goto v_reusejp_41_;
}
else
{
lean_object* v_reuseFailAlloc_43_; 
v_reuseFailAlloc_43_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_43_, 0, v___x_38_);
lean_ctor_set(v_reuseFailAlloc_43_, 1, v___x_40_);
v___x_42_ = v_reuseFailAlloc_43_;
goto v_reusejp_41_;
}
v_reusejp_41_:
{
return v___x_42_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_runState(lean_object* v_fI_45_, lean_object* v_x_46_, lean_object* v_x_47_){
_start:
{
if (lean_obj_tag(v_x_47_) == 0)
{
lean_dec_ref(v_fI_45_);
return v_x_46_;
}
else
{
lean_object* v_head_48_; lean_object* v_tail_49_; lean_object* v___x_50_; 
v_head_48_ = lean_ctor_get(v_x_47_, 0);
lean_inc(v_head_48_);
v_tail_49_ = lean_ctor_get(v_x_47_, 1);
lean_inc(v_tail_49_);
lean_dec_ref_known(v_x_47_, 2);
lean_inc_ref(v_fI_45_);
v___x_50_ = lp_bounded_Bounded_nextState(v_fI_45_, v_head_48_, v_x_46_);
v_x_46_ = v___x_50_;
v_x_47_ = v_tail_49_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* lp_bounded_List_mapTR_loop___at___00Bounded_suite_spec__0(lean_object* v_p_52_, lean_object* v_a_53_, lean_object* v_a_54_){
_start:
{
if (lean_obj_tag(v_a_53_) == 0)
{
lean_object* v___x_55_; 
lean_dec_ref(v_p_52_);
v___x_55_ = l_List_reverse___redArg(v_a_54_);
return v___x_55_;
}
else
{
lean_object* v_head_56_; lean_object* v_tail_57_; lean_object* v___x_59_; uint8_t v_isShared_60_; uint8_t v_isSharedCheck_69_; 
v_head_56_ = lean_ctor_get(v_a_53_, 0);
v_tail_57_ = lean_ctor_get(v_a_53_, 1);
v_isSharedCheck_69_ = !lean_is_exclusive(v_a_53_);
if (v_isSharedCheck_69_ == 0)
{
v___x_59_ = v_a_53_;
v_isShared_60_ = v_isSharedCheck_69_;
goto v_resetjp_58_;
}
else
{
lean_inc(v_tail_57_);
lean_inc(v_head_56_);
lean_dec(v_a_53_);
v___x_59_ = lean_box(0);
v_isShared_60_ = v_isSharedCheck_69_;
goto v_resetjp_58_;
}
v_resetjp_58_:
{
lean_object* v_snd_61_; lean_object* v___x_62_; lean_object* v___x_64_; 
v_snd_61_ = lean_ctor_get(v_p_52_, 1);
v___x_62_ = lean_box(0);
if (v_isShared_60_ == 0)
{
lean_ctor_set(v___x_59_, 1, v___x_62_);
v___x_64_ = v___x_59_;
goto v_reusejp_63_;
}
else
{
lean_object* v_reuseFailAlloc_68_; 
v_reuseFailAlloc_68_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_68_, 0, v_head_56_);
lean_ctor_set(v_reuseFailAlloc_68_, 1, v___x_62_);
v___x_64_ = v_reuseFailAlloc_68_;
goto v_reusejp_63_;
}
v_reusejp_63_:
{
lean_object* v___x_65_; lean_object* v___x_66_; 
lean_inc(v_snd_61_);
v___x_65_ = l_List_appendTR___redArg(v_snd_61_, v___x_64_);
v___x_66_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_66_, 0, v___x_65_);
lean_ctor_set(v___x_66_, 1, v_a_54_);
v_a_53_ = v_tail_57_;
v_a_54_ = v___x_66_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00Bounded_suite_spec__1(lean_object* v_a_70_, lean_object* v_a_71_){
_start:
{
if (lean_obj_tag(v_a_70_) == 0)
{
lean_object* v___x_72_; 
v___x_72_ = lean_array_to_list(v_a_71_);
return v___x_72_;
}
else
{
lean_object* v_head_73_; lean_object* v_tail_74_; lean_object* v___x_75_; lean_object* v___x_76_; lean_object* v___x_77_; lean_object* v___x_78_; 
v_head_73_ = lean_ctor_get(v_a_70_, 0);
lean_inc(v_head_73_);
v_tail_74_ = lean_ctor_get(v_a_70_, 1);
lean_inc(v_tail_74_);
lean_dec_ref_known(v_a_70_, 2);
v___x_75_ = lp_bounded_Bounded_catalogActs;
v___x_76_ = lean_box(0);
v___x_77_ = lp_bounded_List_mapTR_loop___at___00Bounded_suite_spec__0(v_head_73_, v___x_75_, v___x_76_);
v___x_78_ = l_List_foldl___at___00Array_appendList_spec__0___redArg(v_a_71_, v___x_77_);
v_a_70_ = v_tail_74_;
v_a_71_ = v___x_78_;
goto _start;
}
}
}
static lean_object* _init_lp_bounded_Bounded_suite___closed__1(void){
_start:
{
lean_object* v___x_82_; lean_object* v___x_83_; lean_object* v___x_84_; 
v___x_82_ = ((lean_object*)(lp_bounded_Bounded_suite___closed__0));
v___x_83_ = lp_bounded_Bounded_visitedP;
v___x_84_ = lp_bounded___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00Bounded_suite_spec__1(v___x_83_, v___x_82_);
return v___x_84_;
}
}
static lean_object* _init_lp_bounded_Bounded_suite(void){
_start:
{
lean_object* v___x_85_; 
v___x_85_ = lean_obj_once(&lp_bounded_Bounded_suite___closed__1, &lp_bounded_Bounded_suite___closed__1_once, _init_lp_bounded_Bounded_suite___closed__1);
return v___x_85_;
}
}
LEAN_EXPORT lean_object* lp_bounded___private_Bounded_Charact_0__Bounded_runObs_match__1_splitter___redArg(lean_object* v_x_86_, lean_object* v_x_87_, lean_object* v_h__1_88_, lean_object* v_h__2_89_){
_start:
{
if (lean_obj_tag(v_x_87_) == 0)
{
lean_object* v___x_90_; 
lean_dec(v_h__2_89_);
v___x_90_ = lean_apply_1(v_h__1_88_, v_x_86_);
return v___x_90_;
}
else
{
lean_object* v_head_91_; lean_object* v_tail_92_; lean_object* v___x_93_; 
lean_dec(v_h__1_88_);
v_head_91_ = lean_ctor_get(v_x_87_, 0);
lean_inc(v_head_91_);
v_tail_92_ = lean_ctor_get(v_x_87_, 1);
lean_inc(v_tail_92_);
lean_dec_ref_known(v_x_87_, 2);
v___x_93_ = lean_apply_3(v_h__2_89_, v_x_86_, v_head_91_, v_tail_92_);
return v___x_93_;
}
}
}
LEAN_EXPORT lean_object* lp_bounded___private_Bounded_Charact_0__Bounded_runObs_match__1_splitter(lean_object* v_motive_94_, lean_object* v_x_95_, lean_object* v_x_96_, lean_object* v_h__1_97_, lean_object* v_h__2_98_){
_start:
{
if (lean_obj_tag(v_x_96_) == 0)
{
lean_object* v___x_99_; 
lean_dec(v_h__2_98_);
v___x_99_ = lean_apply_1(v_h__1_97_, v_x_95_);
return v___x_99_;
}
else
{
lean_object* v_head_100_; lean_object* v_tail_101_; lean_object* v___x_102_; 
lean_dec(v_h__1_97_);
v_head_100_ = lean_ctor_get(v_x_96_, 0);
lean_inc(v_head_100_);
v_tail_101_ = lean_ctor_get(v_x_96_, 1);
lean_inc(v_tail_101_);
lean_dec_ref_known(v_x_96_, 2);
v___x_102_ = lean_apply_3(v_h__2_98_, v_x_95_, v_head_100_, v_tail_101_);
return v___x_102_;
}
}
}
LEAN_EXPORT lean_object* lp_bounded___private_Bounded_Charact_0__Bounded_runFrom_match__1_splitter___redArg(lean_object* v_x_103_, lean_object* v_h__1_104_, lean_object* v_h__2_105_){
_start:
{
if (lean_obj_tag(v_x_103_) == 0)
{
lean_object* v___x_106_; lean_object* v___x_107_; 
lean_dec(v_h__1_104_);
v___x_106_ = lean_box(0);
v___x_107_ = lean_apply_1(v_h__2_105_, v___x_106_);
return v___x_107_;
}
else
{
lean_object* v_val_108_; lean_object* v___x_109_; 
lean_dec(v_h__2_105_);
v_val_108_ = lean_ctor_get(v_x_103_, 0);
lean_inc(v_val_108_);
lean_dec_ref_known(v_x_103_, 1);
v___x_109_ = lean_apply_1(v_h__1_104_, v_val_108_);
return v___x_109_;
}
}
}
LEAN_EXPORT lean_object* lp_bounded___private_Bounded_Charact_0__Bounded_runFrom_match__1_splitter(lean_object* v_motive_110_, lean_object* v_x_111_, lean_object* v_h__1_112_, lean_object* v_h__2_113_){
_start:
{
if (lean_obj_tag(v_x_111_) == 0)
{
lean_object* v___x_114_; lean_object* v___x_115_; 
lean_dec(v_h__1_112_);
v___x_114_ = lean_box(0);
v___x_115_ = lean_apply_1(v_h__2_113_, v___x_114_);
return v___x_115_;
}
else
{
lean_object* v_val_116_; lean_object* v___x_117_; 
lean_dec(v_h__2_113_);
v_val_116_ = lean_ctor_get(v_x_111_, 0);
lean_inc(v_val_116_);
lean_dec_ref_known(v_x_111_, 1);
v___x_117_ = lean_apply_1(v_h__1_112_, v_val_116_);
return v___x_117_;
}
}
}
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_bounded_Bounded_Explore(uint8_t builtin);
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_bounded_Bounded_Charact(uint8_t builtin) {
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
lp_bounded_Bounded_suite = _init_lp_bounded_Bounded_suite();
lean_mark_persistent(lp_bounded_Bounded_suite);
return lean_io_result_mk_ok(lean_box(0));
}
#ifdef __cplusplus
}
#endif

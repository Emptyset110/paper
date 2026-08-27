// Lean compiler output
// Module: Bounded.Basic
// Imports: public import Init public meta import Init
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
uint8_t lean_nat_dec_eq(lean_object*, lean_object*);
lean_object* lean_nat_sub(lean_object*, lean_object*);
lean_object* l_List_mapTR_loop___redArg(lean_object*, lean_object*, lean_object*);
lean_object* lean_mk_empty_array_with_capacity(lean_object*);
lean_object* l___private_Init_Data_List_Impl_0__List_flatMapTR_go___redArg(lean_object*, lean_object*, lean_object*);
uint8_t l_instDecidableEqList___redArg(lean_object*, lean_object*, lean_object*);
uint8_t l_List_decidableBEx___redArg(lean_object*, lean_object*);
uint8_t l_List_isEmpty___redArg(lean_object*);
uint64_t lean_uint64_mix_hash(uint64_t, uint64_t);
lean_object* l_List_appendTR___redArg(lean_object*, lean_object*);
lean_object* l_List_lengthTR___redArg(lean_object*);
lean_object* lean_nat_add(lean_object*, lean_object*);
uint8_t lean_nat_dec_le(lean_object*, lean_object*);
lean_object* l_List_foldl___redArg(lean_object*, lean_object*, lean_object*);
lean_object* l_List_head_x3f___redArg(lean_object*);
lean_object* l_List_reverse___redArg(lean_object*);
lean_object* l_List_filterMapTR_go___redArg(lean_object*, lean_object*, lean_object*);
lean_object* lean_nat_mod(lean_object*, lean_object*);
lean_object* l_Fin_succ___redArg(lean_object*);
uint8_t l_List_decidableBAll___redArg(lean_object*, lean_object*);
static const lean_ctor_object lp_bounded_Bounded_instFinEnumBool___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(1) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_bounded_Bounded_instFinEnumBool___closed__0 = (const lean_object*)&lp_bounded_Bounded_instFinEnumBool___closed__0_value;
static const lean_ctor_object lp_bounded_Bounded_instFinEnumBool___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_bounded_Bounded_instFinEnumBool___closed__0_value)}};
static const lean_object* lp_bounded_Bounded_instFinEnumBool___closed__1 = (const lean_object*)&lp_bounded_Bounded_instFinEnumBool___closed__1_value;
LEAN_EXPORT const lean_object* lp_bounded_Bounded_instFinEnumBool = (const lean_object*)&lp_bounded_Bounded_instFinEnumBool___closed__1_value;
static const lean_ctor_object lp_bounded_Bounded_instFinEnumUnit___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_bounded_Bounded_instFinEnumUnit___closed__0 = (const lean_object*)&lp_bounded_Bounded_instFinEnumUnit___closed__0_value;
LEAN_EXPORT const lean_object* lp_bounded_Bounded_instFinEnumUnit = (const lean_object*)&lp_bounded_Bounded_instFinEnumUnit___closed__0_value;
LEAN_EXPORT lean_object* lp_bounded_List_mapTR_loop___at___00Bounded_finList_spec__0___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_finList(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_finList___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_List_mapTR_loop___at___00Bounded_finList_spec__0(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_List_mapTR_loop___at___00Bounded_finList_spec__0___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumFin(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumFin___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumOption___redArg___lam__0(lean_object*);
static const lean_closure_object lp_bounded_Bounded_instFinEnumOption___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_bounded_Bounded_instFinEnumOption___redArg___lam__0, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_bounded_Bounded_instFinEnumOption___redArg___closed__0 = (const lean_object*)&lp_bounded_Bounded_instFinEnumOption___redArg___closed__0_value;
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumOption___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumOption(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumProd___redArg___lam__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumProd___redArg___lam__1(lean_object*, lean_object*);
static const lean_array_object lp_bounded_Bounded_instFinEnumProd___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_array_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 246}, .m_size = 0, .m_capacity = 0, .m_data = {}};
static const lean_object* lp_bounded_Bounded_instFinEnumProd___redArg___closed__0 = (const lean_object*)&lp_bounded_Bounded_instFinEnumProd___redArg___closed__0_value;
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumProd___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumProd(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumSum___redArg___lam__0(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumSum___redArg___lam__1(lean_object*);
static const lean_closure_object lp_bounded_Bounded_instFinEnumSum___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_bounded_Bounded_instFinEnumSum___redArg___lam__0, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_bounded_Bounded_instFinEnumSum___redArg___closed__0 = (const lean_object*)&lp_bounded_Bounded_instFinEnumSum___redArg___closed__0_value;
static const lean_closure_object lp_bounded_Bounded_instFinEnumSum___redArg___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_bounded_Bounded_instFinEnumSum___redArg___lam__1, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_bounded_Bounded_instFinEnumSum___redArg___closed__1 = (const lean_object*)&lp_bounded_Bounded_instFinEnumSum___redArg___closed__1_value;
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumSum___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumSum(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_decidableBallFinEnum___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_decidableBallFinEnum___redArg___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_decidableBallFinEnum(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_decidableBallFinEnum___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_decidableBexFinEnum___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_decidableBexFinEnum___redArg___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_decidableBexFinEnum(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_decidableBexFinEnum___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_decEqFinEnumFun___redArg___lam__0(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_decEqFinEnumFun___redArg___lam__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_decEqFinEnumFun___redArg(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_decEqFinEnumFun___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_decEqFinEnumFun(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_decEqFinEnumFun___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_funUpdate___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_funUpdate___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_funUpdate(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_funUpdate___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_allFunAux___redArg___lam__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_allFunAux___redArg___lam__0___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_allFunAux___redArg___lam__1(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_allFunAux___redArg___lam__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_allFunAux___redArg___lam__2(lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_array_object lp_bounded_Bounded_allFunAux___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_array_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 246}, .m_size = 0, .m_capacity = 0, .m_data = {}};
static const lean_object* lp_bounded_Bounded_allFunAux___redArg___closed__0 = (const lean_object*)&lp_bounded_Bounded_allFunAux___redArg___closed__0_value;
LEAN_EXPORT lean_object* lp_bounded_Bounded_allFunAux___redArg(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_allFunAux(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_finEnumFun___redArg(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_finEnumFun(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_listsLE___redArg___lam__0(lean_object*, lean_object*);
static const lean_ctor_object lp_bounded_Bounded_listsLE___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_bounded_Bounded_listsLE___redArg___closed__0 = (const lean_object*)&lp_bounded_Bounded_listsLE___redArg___closed__0_value;
LEAN_EXPORT lean_object* lp_bounded_Bounded_listsLE___redArg___lam__1___boxed(lean_object*, lean_object*, lean_object*);
static const lean_array_object lp_bounded_Bounded_listsLE___redArg___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_array_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 246}, .m_size = 0, .m_capacity = 0, .m_data = {}};
static const lean_object* lp_bounded_Bounded_listsLE___redArg___closed__1 = (const lean_object*)&lp_bounded_Bounded_listsLE___redArg___closed__1_value;
LEAN_EXPORT lean_object* lp_bounded_Bounded_listsLE___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_listsLE___redArg___lam__1(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_listsLE___redArg___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_listsLE(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_listsLE___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded___private_Bounded_Basic_0__Bounded_finList_match__1_splitter___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded___private_Bounded_Basic_0__Bounded_finList_match__1_splitter___redArg___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded___private_Bounded_Basic_0__Bounded_finList_match__1_splitter(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded___private_Bounded_Basic_0__Bounded_finList_match__1_splitter___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_BList_instDecidableEq___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_BList_instDecidableEq___redArg___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_BList_instDecidableEq(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_BList_instDecidableEq___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint64_t lp_bounded_Bounded_BList_instHashable___redArg___lam__0(lean_object*, uint64_t, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_BList_instHashable___redArg___lam__0___boxed(lean_object*, lean_object*, lean_object*);
static const lean_ctor_object lp_bounded_Bounded_BList_instHashable___redArg___lam__1___boxed__const__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*0 + 8, .m_other = 0, .m_tag = 0}, .m_objs = {LEAN_SCALAR_PTR_LITERAL(7, 0, 0, 0, 0, 0, 0, 0)}};
LEAN_EXPORT const lean_object* lp_bounded_Bounded_BList_instHashable___redArg___lam__1___boxed__const__1 = (const lean_object*)&lp_bounded_Bounded_BList_instHashable___redArg___lam__1___boxed__const__1_value;
LEAN_EXPORT uint64_t lp_bounded_Bounded_BList_instHashable___redArg___lam__1(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_BList_instHashable___redArg___lam__1___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_BList_instHashable___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_BList_instHashable(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_BList_instHashable___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_BList_instFinEnum___redArg___lam__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_BList_instFinEnum___redArg___lam__0___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_BList_instFinEnum___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_BList_instFinEnum(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_BList_nil(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_BList_nil___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_BList_push___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_BList_push___redArg___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_BList_push(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_BList_push___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_BList_head_x3f___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_BList_head_x3f___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_BList_head_x3f(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_BList_head_x3f___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_BList_tail___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_BList_tail___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_BList_tail(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_BList_tail___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_BList_isEmpty___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_BList_isEmpty___redArg___boxed(lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_BList_isEmpty(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_BList_isEmpty___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_List_mapTR_loop___at___00Bounded_BList_map_spec__0___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_BList_map___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_BList_map(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_BList_map___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_List_mapTR_loop___at___00Bounded_BList_map_spec__0(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_List_mapTR_loop___at___00Bounded_finList_spec__0___redArg(lean_object* v_a_14_, lean_object* v_a_15_){
_start:
{
if (lean_obj_tag(v_a_14_) == 0)
{
lean_object* v___x_16_; 
v___x_16_ = l_List_reverse___redArg(v_a_15_);
return v___x_16_;
}
else
{
lean_object* v_head_17_; lean_object* v_tail_18_; lean_object* v___x_20_; uint8_t v_isShared_21_; uint8_t v_isSharedCheck_27_; 
v_head_17_ = lean_ctor_get(v_a_14_, 0);
v_tail_18_ = lean_ctor_get(v_a_14_, 1);
v_isSharedCheck_27_ = !lean_is_exclusive(v_a_14_);
if (v_isSharedCheck_27_ == 0)
{
v___x_20_ = v_a_14_;
v_isShared_21_ = v_isSharedCheck_27_;
goto v_resetjp_19_;
}
else
{
lean_inc(v_tail_18_);
lean_inc(v_head_17_);
lean_dec(v_a_14_);
v___x_20_ = lean_box(0);
v_isShared_21_ = v_isSharedCheck_27_;
goto v_resetjp_19_;
}
v_resetjp_19_:
{
lean_object* v___x_22_; lean_object* v___x_24_; 
v___x_22_ = l_Fin_succ___redArg(v_head_17_);
lean_dec(v_head_17_);
if (v_isShared_21_ == 0)
{
lean_ctor_set(v___x_20_, 1, v_a_15_);
lean_ctor_set(v___x_20_, 0, v___x_22_);
v___x_24_ = v___x_20_;
goto v_reusejp_23_;
}
else
{
lean_object* v_reuseFailAlloc_26_; 
v_reuseFailAlloc_26_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_26_, 0, v___x_22_);
lean_ctor_set(v_reuseFailAlloc_26_, 1, v_a_15_);
v___x_24_ = v_reuseFailAlloc_26_;
goto v_reusejp_23_;
}
v_reusejp_23_:
{
v_a_14_ = v_tail_18_;
v_a_15_ = v___x_24_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_finList(lean_object* v_x_28_){
_start:
{
lean_object* v_zero_29_; uint8_t v_isZero_30_; 
v_zero_29_ = lean_unsigned_to_nat(0u);
v_isZero_30_ = lean_nat_dec_eq(v_x_28_, v_zero_29_);
if (v_isZero_30_ == 1)
{
lean_object* v___x_31_; 
v___x_31_ = lean_box(0);
return v___x_31_;
}
else
{
lean_object* v_one_32_; lean_object* v_n_33_; lean_object* v___x_34_; lean_object* v___x_35_; lean_object* v___x_36_; lean_object* v___x_37_; lean_object* v___x_38_; lean_object* v___x_39_; 
v_one_32_ = lean_unsigned_to_nat(1u);
v_n_33_ = lean_nat_sub(v_x_28_, v_one_32_);
v___x_34_ = lean_nat_add(v_n_33_, v_one_32_);
v___x_35_ = lean_nat_mod(v_zero_29_, v___x_34_);
lean_dec(v___x_34_);
v___x_36_ = lp_bounded_Bounded_finList(v_n_33_);
lean_dec(v_n_33_);
v___x_37_ = lean_box(0);
v___x_38_ = lp_bounded_List_mapTR_loop___at___00Bounded_finList_spec__0___redArg(v___x_36_, v___x_37_);
v___x_39_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_39_, 0, v___x_35_);
lean_ctor_set(v___x_39_, 1, v___x_38_);
return v___x_39_;
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_finList___boxed(lean_object* v_x_40_){
_start:
{
lean_object* v_res_41_; 
v_res_41_ = lp_bounded_Bounded_finList(v_x_40_);
lean_dec(v_x_40_);
return v_res_41_;
}
}
LEAN_EXPORT lean_object* lp_bounded_List_mapTR_loop___at___00Bounded_finList_spec__0(lean_object* v_n_42_, lean_object* v_a_43_, lean_object* v_a_44_){
_start:
{
lean_object* v___x_45_; 
v___x_45_ = lp_bounded_List_mapTR_loop___at___00Bounded_finList_spec__0___redArg(v_a_43_, v_a_44_);
return v___x_45_;
}
}
LEAN_EXPORT lean_object* lp_bounded_List_mapTR_loop___at___00Bounded_finList_spec__0___boxed(lean_object* v_n_46_, lean_object* v_a_47_, lean_object* v_a_48_){
_start:
{
lean_object* v_res_49_; 
v_res_49_ = lp_bounded_List_mapTR_loop___at___00Bounded_finList_spec__0(v_n_46_, v_a_47_, v_a_48_);
lean_dec(v_n_46_);
return v_res_49_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumFin(lean_object* v_n_50_){
_start:
{
lean_object* v___x_51_; 
v___x_51_ = lp_bounded_Bounded_finList(v_n_50_);
return v___x_51_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumFin___boxed(lean_object* v_n_52_){
_start:
{
lean_object* v_res_53_; 
v_res_53_ = lp_bounded_Bounded_instFinEnumFin(v_n_52_);
lean_dec(v_n_52_);
return v_res_53_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumOption___redArg___lam__0(lean_object* v_val_54_){
_start:
{
lean_object* v___x_55_; 
v___x_55_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_55_, 0, v_val_54_);
return v___x_55_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumOption___redArg(lean_object* v_inst_57_){
_start:
{
lean_object* v___f_58_; lean_object* v___x_59_; lean_object* v___x_60_; lean_object* v___x_61_; lean_object* v___x_62_; 
v___f_58_ = ((lean_object*)(lp_bounded_Bounded_instFinEnumOption___redArg___closed__0));
v___x_59_ = lean_box(0);
v___x_60_ = lean_box(0);
v___x_61_ = l_List_mapTR_loop___redArg(v___f_58_, v_inst_57_, v___x_60_);
v___x_62_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_62_, 0, v___x_59_);
lean_ctor_set(v___x_62_, 1, v___x_61_);
return v___x_62_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumOption(lean_object* v_00_u03b1_63_, lean_object* v_inst_64_){
_start:
{
lean_object* v___x_65_; 
v___x_65_ = lp_bounded_Bounded_instFinEnumOption___redArg(v_inst_64_);
return v___x_65_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumProd___redArg___lam__0(lean_object* v_a_66_, lean_object* v_b_67_){
_start:
{
lean_object* v___x_68_; 
v___x_68_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_68_, 0, v_a_66_);
lean_ctor_set(v___x_68_, 1, v_b_67_);
return v___x_68_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumProd___redArg___lam__1(lean_object* v_inst_69_, lean_object* v_a_70_){
_start:
{
lean_object* v___f_71_; lean_object* v___x_72_; lean_object* v___x_73_; 
v___f_71_ = lean_alloc_closure((void*)(lp_bounded_Bounded_instFinEnumProd___redArg___lam__0), 2, 1);
lean_closure_set(v___f_71_, 0, v_a_70_);
v___x_72_ = lean_box(0);
v___x_73_ = l_List_mapTR_loop___redArg(v___f_71_, v_inst_69_, v___x_72_);
return v___x_73_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumProd___redArg(lean_object* v_inst_76_, lean_object* v_inst_77_){
_start:
{
lean_object* v___f_78_; lean_object* v___x_79_; lean_object* v___x_80_; 
v___f_78_ = lean_alloc_closure((void*)(lp_bounded_Bounded_instFinEnumProd___redArg___lam__1), 2, 1);
lean_closure_set(v___f_78_, 0, v_inst_77_);
v___x_79_ = ((lean_object*)(lp_bounded_Bounded_instFinEnumProd___redArg___closed__0));
v___x_80_ = l___private_Init_Data_List_Impl_0__List_flatMapTR_go___redArg(v___f_78_, v_inst_76_, v___x_79_);
return v___x_80_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumProd(lean_object* v_00_u03b1_81_, lean_object* v_00_u03b2_82_, lean_object* v_inst_83_, lean_object* v_inst_84_){
_start:
{
lean_object* v___x_85_; 
v___x_85_ = lp_bounded_Bounded_instFinEnumProd___redArg(v_inst_83_, v_inst_84_);
return v___x_85_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumSum___redArg___lam__0(lean_object* v_val_86_){
_start:
{
lean_object* v___x_87_; 
v___x_87_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_87_, 0, v_val_86_);
return v___x_87_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumSum___redArg___lam__1(lean_object* v_val_88_){
_start:
{
lean_object* v___x_89_; 
v___x_89_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_89_, 0, v_val_88_);
return v___x_89_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumSum___redArg(lean_object* v_inst_92_, lean_object* v_inst_93_){
_start:
{
lean_object* v___f_94_; lean_object* v___f_95_; lean_object* v___x_96_; lean_object* v___x_97_; lean_object* v___x_98_; lean_object* v___x_99_; 
v___f_94_ = ((lean_object*)(lp_bounded_Bounded_instFinEnumSum___redArg___closed__0));
v___f_95_ = ((lean_object*)(lp_bounded_Bounded_instFinEnumSum___redArg___closed__1));
v___x_96_ = lean_box(0);
v___x_97_ = l_List_mapTR_loop___redArg(v___f_94_, v_inst_92_, v___x_96_);
v___x_98_ = l_List_mapTR_loop___redArg(v___f_95_, v_inst_93_, v___x_96_);
v___x_99_ = l_List_appendTR___redArg(v___x_97_, v___x_98_);
return v___x_99_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumSum(lean_object* v_00_u03b1_100_, lean_object* v_00_u03b2_101_, lean_object* v_inst_102_, lean_object* v_inst_103_){
_start:
{
lean_object* v___x_104_; 
v___x_104_ = lp_bounded_Bounded_instFinEnumSum___redArg(v_inst_102_, v_inst_103_);
return v___x_104_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_decidableBallFinEnum___redArg(lean_object* v_inst_105_, lean_object* v_inst_106_){
_start:
{
uint8_t v___x_107_; 
v___x_107_ = l_List_decidableBAll___redArg(v_inst_106_, v_inst_105_);
return v___x_107_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_decidableBallFinEnum___redArg___boxed(lean_object* v_inst_108_, lean_object* v_inst_109_){
_start:
{
uint8_t v_res_110_; lean_object* v_r_111_; 
v_res_110_ = lp_bounded_Bounded_decidableBallFinEnum___redArg(v_inst_108_, v_inst_109_);
v_r_111_ = lean_box(v_res_110_);
return v_r_111_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_decidableBallFinEnum(lean_object* v_00_u03b1_112_, lean_object* v_inst_113_, lean_object* v_p_114_, lean_object* v_inst_115_){
_start:
{
uint8_t v___x_116_; 
v___x_116_ = l_List_decidableBAll___redArg(v_inst_115_, v_inst_113_);
return v___x_116_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_decidableBallFinEnum___boxed(lean_object* v_00_u03b1_117_, lean_object* v_inst_118_, lean_object* v_p_119_, lean_object* v_inst_120_){
_start:
{
uint8_t v_res_121_; lean_object* v_r_122_; 
v_res_121_ = lp_bounded_Bounded_decidableBallFinEnum(v_00_u03b1_117_, v_inst_118_, v_p_119_, v_inst_120_);
v_r_122_ = lean_box(v_res_121_);
return v_r_122_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_decidableBexFinEnum___redArg(lean_object* v_inst_123_, lean_object* v_inst_124_){
_start:
{
uint8_t v___x_125_; 
v___x_125_ = l_List_decidableBEx___redArg(v_inst_124_, v_inst_123_);
return v___x_125_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_decidableBexFinEnum___redArg___boxed(lean_object* v_inst_126_, lean_object* v_inst_127_){
_start:
{
uint8_t v_res_128_; lean_object* v_r_129_; 
v_res_128_ = lp_bounded_Bounded_decidableBexFinEnum___redArg(v_inst_126_, v_inst_127_);
v_r_129_ = lean_box(v_res_128_);
return v_r_129_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_decidableBexFinEnum(lean_object* v_00_u03b1_130_, lean_object* v_inst_131_, lean_object* v_p_132_, lean_object* v_inst_133_){
_start:
{
uint8_t v___x_134_; 
v___x_134_ = l_List_decidableBEx___redArg(v_inst_133_, v_inst_131_);
return v___x_134_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_decidableBexFinEnum___boxed(lean_object* v_00_u03b1_135_, lean_object* v_inst_136_, lean_object* v_p_137_, lean_object* v_inst_138_){
_start:
{
uint8_t v_res_139_; lean_object* v_r_140_; 
v_res_139_ = lp_bounded_Bounded_decidableBexFinEnum(v_00_u03b1_135_, v_inst_136_, v_p_137_, v_inst_138_);
v_r_140_ = lean_box(v_res_139_);
return v_r_140_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_decEqFinEnumFun___redArg___lam__0(lean_object* v_f_141_, lean_object* v_g_142_, lean_object* v_inst_143_, lean_object* v_a_144_){
_start:
{
lean_object* v___x_145_; lean_object* v___x_146_; lean_object* v___x_147_; uint8_t v___x_148_; 
lean_inc(v_a_144_);
v___x_145_ = lean_apply_1(v_f_141_, v_a_144_);
v___x_146_ = lean_apply_1(v_g_142_, v_a_144_);
v___x_147_ = lean_apply_2(v_inst_143_, v___x_145_, v___x_146_);
v___x_148_ = lean_unbox(v___x_147_);
return v___x_148_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_decEqFinEnumFun___redArg___lam__0___boxed(lean_object* v_f_149_, lean_object* v_g_150_, lean_object* v_inst_151_, lean_object* v_a_152_){
_start:
{
uint8_t v_res_153_; lean_object* v_r_154_; 
v_res_153_ = lp_bounded_Bounded_decEqFinEnumFun___redArg___lam__0(v_f_149_, v_g_150_, v_inst_151_, v_a_152_);
v_r_154_ = lean_box(v_res_153_);
return v_r_154_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_decEqFinEnumFun___redArg(lean_object* v_inst_155_, lean_object* v_inst_156_, lean_object* v_f_157_, lean_object* v_g_158_){
_start:
{
lean_object* v___f_159_; uint8_t v___x_160_; 
v___f_159_ = lean_alloc_closure((void*)(lp_bounded_Bounded_decEqFinEnumFun___redArg___lam__0___boxed), 4, 3);
lean_closure_set(v___f_159_, 0, v_f_157_);
lean_closure_set(v___f_159_, 1, v_g_158_);
lean_closure_set(v___f_159_, 2, v_inst_156_);
v___x_160_ = l_List_decidableBAll___redArg(v___f_159_, v_inst_155_);
return v___x_160_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_decEqFinEnumFun___redArg___boxed(lean_object* v_inst_161_, lean_object* v_inst_162_, lean_object* v_f_163_, lean_object* v_g_164_){
_start:
{
uint8_t v_res_165_; lean_object* v_r_166_; 
v_res_165_ = lp_bounded_Bounded_decEqFinEnumFun___redArg(v_inst_161_, v_inst_162_, v_f_163_, v_g_164_);
v_r_166_ = lean_box(v_res_165_);
return v_r_166_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_decEqFinEnumFun(lean_object* v_00_u03b1_167_, lean_object* v_00_u03b2_168_, lean_object* v_inst_169_, lean_object* v_inst_170_, lean_object* v_f_171_, lean_object* v_g_172_){
_start:
{
uint8_t v___x_173_; 
v___x_173_ = lp_bounded_Bounded_decEqFinEnumFun___redArg(v_inst_169_, v_inst_170_, v_f_171_, v_g_172_);
return v___x_173_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_decEqFinEnumFun___boxed(lean_object* v_00_u03b1_174_, lean_object* v_00_u03b2_175_, lean_object* v_inst_176_, lean_object* v_inst_177_, lean_object* v_f_178_, lean_object* v_g_179_){
_start:
{
uint8_t v_res_180_; lean_object* v_r_181_; 
v_res_180_ = lp_bounded_Bounded_decEqFinEnumFun(v_00_u03b1_174_, v_00_u03b2_175_, v_inst_176_, v_inst_177_, v_f_178_, v_g_179_);
v_r_181_ = lean_box(v_res_180_);
return v_r_181_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_funUpdate___redArg(lean_object* v_inst_182_, lean_object* v_f_183_, lean_object* v_x_184_, lean_object* v_v_185_, lean_object* v_y_186_){
_start:
{
lean_object* v___x_187_; uint8_t v___x_188_; 
lean_inc(v_y_186_);
v___x_187_ = lean_apply_2(v_inst_182_, v_y_186_, v_x_184_);
v___x_188_ = lean_unbox(v___x_187_);
if (v___x_188_ == 0)
{
lean_object* v___x_189_; 
v___x_189_ = lean_apply_1(v_f_183_, v_y_186_);
return v___x_189_;
}
else
{
lean_dec(v_y_186_);
lean_dec(v_f_183_);
lean_inc(v_v_185_);
return v_v_185_;
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_funUpdate___redArg___boxed(lean_object* v_inst_190_, lean_object* v_f_191_, lean_object* v_x_192_, lean_object* v_v_193_, lean_object* v_y_194_){
_start:
{
lean_object* v_res_195_; 
v_res_195_ = lp_bounded_Bounded_funUpdate___redArg(v_inst_190_, v_f_191_, v_x_192_, v_v_193_, v_y_194_);
lean_dec(v_v_193_);
return v_res_195_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_funUpdate(lean_object* v_00_u03b1_196_, lean_object* v_00_u03b2_197_, lean_object* v_inst_198_, lean_object* v_f_199_, lean_object* v_x_200_, lean_object* v_v_201_, lean_object* v_y_202_){
_start:
{
lean_object* v___x_203_; 
v___x_203_ = lp_bounded_Bounded_funUpdate___redArg(v_inst_198_, v_f_199_, v_x_200_, v_v_201_, v_y_202_);
return v___x_203_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_funUpdate___boxed(lean_object* v_00_u03b1_204_, lean_object* v_00_u03b2_205_, lean_object* v_inst_206_, lean_object* v_f_207_, lean_object* v_x_208_, lean_object* v_v_209_, lean_object* v_y_210_){
_start:
{
lean_object* v_res_211_; 
v_res_211_ = lp_bounded_Bounded_funUpdate(v_00_u03b1_204_, v_00_u03b2_205_, v_inst_206_, v_f_207_, v_x_208_, v_v_209_, v_y_210_);
lean_dec(v_v_209_);
return v_res_211_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_allFunAux___redArg___lam__0(lean_object* v_dflt_212_, lean_object* v_x_213_){
_start:
{
lean_inc(v_dflt_212_);
return v_dflt_212_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_allFunAux___redArg___lam__0___boxed(lean_object* v_dflt_214_, lean_object* v_x_215_){
_start:
{
lean_object* v_res_216_; 
v_res_216_ = lp_bounded_Bounded_allFunAux___redArg___lam__0(v_dflt_214_, v_x_215_);
lean_dec(v_x_215_);
lean_dec(v_dflt_214_);
return v_res_216_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_allFunAux___redArg___lam__1(lean_object* v_inst_217_, lean_object* v_f_218_, lean_object* v_head_219_, lean_object* v_v_220_, lean_object* v___y_221_){
_start:
{
lean_object* v___x_222_; 
v___x_222_ = lp_bounded_Bounded_funUpdate___redArg(v_inst_217_, v_f_218_, v_head_219_, v_v_220_, v___y_221_);
return v___x_222_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_allFunAux___redArg___lam__1___boxed(lean_object* v_inst_223_, lean_object* v_f_224_, lean_object* v_head_225_, lean_object* v_v_226_, lean_object* v___y_227_){
_start:
{
lean_object* v_res_228_; 
v_res_228_ = lp_bounded_Bounded_allFunAux___redArg___lam__1(v_inst_223_, v_f_224_, v_head_225_, v_v_226_, v___y_227_);
lean_dec(v_v_226_);
return v_res_228_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_allFunAux___redArg___lam__2(lean_object* v_inst_229_, lean_object* v_head_230_, lean_object* v_inst_231_, lean_object* v_f_232_){
_start:
{
lean_object* v___f_233_; lean_object* v___x_234_; lean_object* v___x_235_; 
v___f_233_ = lean_alloc_closure((void*)(lp_bounded_Bounded_allFunAux___redArg___lam__1___boxed), 5, 3);
lean_closure_set(v___f_233_, 0, v_inst_229_);
lean_closure_set(v___f_233_, 1, v_f_232_);
lean_closure_set(v___f_233_, 2, v_head_230_);
v___x_234_ = lean_box(0);
v___x_235_ = l_List_mapTR_loop___redArg(v___f_233_, v_inst_231_, v___x_234_);
return v___x_235_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_allFunAux___redArg(lean_object* v_inst_238_, lean_object* v_inst_239_, lean_object* v_dflt_240_, lean_object* v_x_241_){
_start:
{
if (lean_obj_tag(v_x_241_) == 0)
{
lean_object* v___f_242_; lean_object* v___x_243_; lean_object* v___x_244_; 
lean_dec(v_inst_239_);
lean_dec_ref(v_inst_238_);
v___f_242_ = lean_alloc_closure((void*)(lp_bounded_Bounded_allFunAux___redArg___lam__0___boxed), 2, 1);
lean_closure_set(v___f_242_, 0, v_dflt_240_);
v___x_243_ = lean_box(0);
v___x_244_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_244_, 0, v___f_242_);
lean_ctor_set(v___x_244_, 1, v___x_243_);
return v___x_244_;
}
else
{
lean_object* v_head_245_; lean_object* v_tail_246_; lean_object* v___f_247_; lean_object* v___x_248_; lean_object* v___x_249_; lean_object* v___x_250_; 
v_head_245_ = lean_ctor_get(v_x_241_, 0);
lean_inc(v_head_245_);
v_tail_246_ = lean_ctor_get(v_x_241_, 1);
lean_inc(v_tail_246_);
lean_dec_ref_known(v_x_241_, 2);
lean_inc(v_inst_239_);
lean_inc_ref(v_inst_238_);
v___f_247_ = lean_alloc_closure((void*)(lp_bounded_Bounded_allFunAux___redArg___lam__2), 4, 3);
lean_closure_set(v___f_247_, 0, v_inst_238_);
lean_closure_set(v___f_247_, 1, v_head_245_);
lean_closure_set(v___f_247_, 2, v_inst_239_);
v___x_248_ = lp_bounded_Bounded_allFunAux___redArg(v_inst_238_, v_inst_239_, v_dflt_240_, v_tail_246_);
v___x_249_ = ((lean_object*)(lp_bounded_Bounded_allFunAux___redArg___closed__0));
v___x_250_ = l___private_Init_Data_List_Impl_0__List_flatMapTR_go___redArg(v___f_247_, v___x_248_, v___x_249_);
return v___x_250_;
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_allFunAux(lean_object* v_00_u03b1_251_, lean_object* v_00_u03b2_252_, lean_object* v_inst_253_, lean_object* v_inst_254_, lean_object* v_dflt_255_, lean_object* v_x_256_){
_start:
{
lean_object* v___x_257_; 
v___x_257_ = lp_bounded_Bounded_allFunAux___redArg(v_inst_253_, v_inst_254_, v_dflt_255_, v_x_256_);
return v___x_257_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_finEnumFun___redArg(lean_object* v_inst_258_, lean_object* v_inst_259_, lean_object* v_inst_260_, lean_object* v_inst_261_){
_start:
{
lean_object* v___x_262_; 
v___x_262_ = lp_bounded_Bounded_allFunAux___redArg(v_inst_258_, v_inst_260_, v_inst_261_, v_inst_259_);
return v___x_262_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_finEnumFun(lean_object* v_00_u03b1_263_, lean_object* v_00_u03b2_264_, lean_object* v_inst_265_, lean_object* v_inst_266_, lean_object* v_inst_267_, lean_object* v_inst_268_){
_start:
{
lean_object* v___x_269_; 
v___x_269_ = lp_bounded_Bounded_allFunAux___redArg(v_inst_265_, v_inst_267_, v_inst_268_, v_inst_266_);
return v___x_269_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_listsLE___redArg___lam__0(lean_object* v_a_270_, lean_object* v_l_271_){
_start:
{
lean_object* v___x_272_; 
v___x_272_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_272_, 0, v_a_270_);
lean_ctor_set(v___x_272_, 1, v_l_271_);
return v___x_272_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_listsLE___redArg___lam__1___boxed(lean_object* v_inst_275_, lean_object* v_n_276_, lean_object* v_a_277_){
_start:
{
lean_object* v_res_278_; 
v_res_278_ = lp_bounded_Bounded_listsLE___redArg___lam__1(v_inst_275_, v_n_276_, v_a_277_);
lean_dec(v_n_276_);
return v_res_278_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_listsLE___redArg(lean_object* v_inst_281_, lean_object* v_x_282_){
_start:
{
lean_object* v_zero_283_; uint8_t v_isZero_284_; 
v_zero_283_ = lean_unsigned_to_nat(0u);
v_isZero_284_ = lean_nat_dec_eq(v_x_282_, v_zero_283_);
if (v_isZero_284_ == 1)
{
lean_object* v___x_285_; 
lean_dec(v_inst_281_);
v___x_285_ = ((lean_object*)(lp_bounded_Bounded_listsLE___redArg___closed__0));
return v___x_285_;
}
else
{
lean_object* v_one_286_; lean_object* v_n_287_; lean_object* v___f_288_; lean_object* v___x_289_; lean_object* v___x_290_; lean_object* v___x_291_; lean_object* v___x_292_; 
v_one_286_ = lean_unsigned_to_nat(1u);
v_n_287_ = lean_nat_sub(v_x_282_, v_one_286_);
lean_inc(v_inst_281_);
v___f_288_ = lean_alloc_closure((void*)(lp_bounded_Bounded_listsLE___redArg___lam__1___boxed), 3, 2);
lean_closure_set(v___f_288_, 0, v_inst_281_);
lean_closure_set(v___f_288_, 1, v_n_287_);
v___x_289_ = lean_box(0);
v___x_290_ = ((lean_object*)(lp_bounded_Bounded_listsLE___redArg___closed__1));
v___x_291_ = l___private_Init_Data_List_Impl_0__List_flatMapTR_go___redArg(v___f_288_, v_inst_281_, v___x_290_);
v___x_292_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_292_, 0, v___x_289_);
lean_ctor_set(v___x_292_, 1, v___x_291_);
return v___x_292_;
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_listsLE___redArg___lam__1(lean_object* v_inst_293_, lean_object* v_n_294_, lean_object* v_a_295_){
_start:
{
lean_object* v___f_296_; lean_object* v___x_297_; lean_object* v___x_298_; lean_object* v___x_299_; 
v___f_296_ = lean_alloc_closure((void*)(lp_bounded_Bounded_listsLE___redArg___lam__0), 2, 1);
lean_closure_set(v___f_296_, 0, v_a_295_);
v___x_297_ = lp_bounded_Bounded_listsLE___redArg(v_inst_293_, v_n_294_);
v___x_298_ = lean_box(0);
v___x_299_ = l_List_mapTR_loop___redArg(v___f_296_, v___x_297_, v___x_298_);
return v___x_299_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_listsLE___redArg___boxed(lean_object* v_inst_300_, lean_object* v_x_301_){
_start:
{
lean_object* v_res_302_; 
v_res_302_ = lp_bounded_Bounded_listsLE___redArg(v_inst_300_, v_x_301_);
lean_dec(v_x_301_);
return v_res_302_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_listsLE(lean_object* v_00_u03b1_303_, lean_object* v_inst_304_, lean_object* v_x_305_){
_start:
{
lean_object* v___x_306_; 
v___x_306_ = lp_bounded_Bounded_listsLE___redArg(v_inst_304_, v_x_305_);
return v___x_306_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_listsLE___boxed(lean_object* v_00_u03b1_307_, lean_object* v_inst_308_, lean_object* v_x_309_){
_start:
{
lean_object* v_res_310_; 
v_res_310_ = lp_bounded_Bounded_listsLE(v_00_u03b1_307_, v_inst_308_, v_x_309_);
lean_dec(v_x_309_);
return v_res_310_;
}
}
LEAN_EXPORT lean_object* lp_bounded___private_Bounded_Basic_0__Bounded_finList_match__1_splitter___redArg(lean_object* v_x_311_, lean_object* v_h__1_312_, lean_object* v_h__2_313_){
_start:
{
lean_object* v_zero_314_; uint8_t v_isZero_315_; 
v_zero_314_ = lean_unsigned_to_nat(0u);
v_isZero_315_ = lean_nat_dec_eq(v_x_311_, v_zero_314_);
if (v_isZero_315_ == 1)
{
lean_object* v___x_316_; lean_object* v___x_317_; 
lean_dec(v_h__2_313_);
v___x_316_ = lean_box(0);
v___x_317_ = lean_apply_1(v_h__1_312_, v___x_316_);
return v___x_317_;
}
else
{
lean_object* v_one_318_; lean_object* v_n_319_; lean_object* v___x_320_; 
lean_dec(v_h__1_312_);
v_one_318_ = lean_unsigned_to_nat(1u);
v_n_319_ = lean_nat_sub(v_x_311_, v_one_318_);
v___x_320_ = lean_apply_1(v_h__2_313_, v_n_319_);
return v___x_320_;
}
}
}
LEAN_EXPORT lean_object* lp_bounded___private_Bounded_Basic_0__Bounded_finList_match__1_splitter___redArg___boxed(lean_object* v_x_321_, lean_object* v_h__1_322_, lean_object* v_h__2_323_){
_start:
{
lean_object* v_res_324_; 
v_res_324_ = lp_bounded___private_Bounded_Basic_0__Bounded_finList_match__1_splitter___redArg(v_x_321_, v_h__1_322_, v_h__2_323_);
lean_dec(v_x_321_);
return v_res_324_;
}
}
LEAN_EXPORT lean_object* lp_bounded___private_Bounded_Basic_0__Bounded_finList_match__1_splitter(lean_object* v_motive_325_, lean_object* v_x_326_, lean_object* v_h__1_327_, lean_object* v_h__2_328_){
_start:
{
lean_object* v_zero_329_; uint8_t v_isZero_330_; 
v_zero_329_ = lean_unsigned_to_nat(0u);
v_isZero_330_ = lean_nat_dec_eq(v_x_326_, v_zero_329_);
if (v_isZero_330_ == 1)
{
lean_object* v___x_331_; lean_object* v___x_332_; 
lean_dec(v_h__2_328_);
v___x_331_ = lean_box(0);
v___x_332_ = lean_apply_1(v_h__1_327_, v___x_331_);
return v___x_332_;
}
else
{
lean_object* v_one_333_; lean_object* v_n_334_; lean_object* v___x_335_; 
lean_dec(v_h__1_327_);
v_one_333_ = lean_unsigned_to_nat(1u);
v_n_334_ = lean_nat_sub(v_x_326_, v_one_333_);
v___x_335_ = lean_apply_1(v_h__2_328_, v_n_334_);
return v___x_335_;
}
}
}
LEAN_EXPORT lean_object* lp_bounded___private_Bounded_Basic_0__Bounded_finList_match__1_splitter___boxed(lean_object* v_motive_336_, lean_object* v_x_337_, lean_object* v_h__1_338_, lean_object* v_h__2_339_){
_start:
{
lean_object* v_res_340_; 
v_res_340_ = lp_bounded___private_Bounded_Basic_0__Bounded_finList_match__1_splitter(v_motive_336_, v_x_337_, v_h__1_338_, v_h__2_339_);
lean_dec(v_x_337_);
return v_res_340_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_BList_instDecidableEq___redArg(lean_object* v_inst_341_, lean_object* v_a_342_, lean_object* v_b_343_){
_start:
{
uint8_t v___x_344_; 
v___x_344_ = l_instDecidableEqList___redArg(v_inst_341_, v_a_342_, v_b_343_);
return v___x_344_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_BList_instDecidableEq___redArg___boxed(lean_object* v_inst_345_, lean_object* v_a_346_, lean_object* v_b_347_){
_start:
{
uint8_t v_res_348_; lean_object* v_r_349_; 
v_res_348_ = lp_bounded_Bounded_BList_instDecidableEq___redArg(v_inst_345_, v_a_346_, v_b_347_);
v_r_349_ = lean_box(v_res_348_);
return v_r_349_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_BList_instDecidableEq(lean_object* v_00_u03b1_350_, lean_object* v_n_351_, lean_object* v_inst_352_, lean_object* v_a_353_, lean_object* v_b_354_){
_start:
{
uint8_t v___x_355_; 
v___x_355_ = l_instDecidableEqList___redArg(v_inst_352_, v_a_353_, v_b_354_);
return v___x_355_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_BList_instDecidableEq___boxed(lean_object* v_00_u03b1_356_, lean_object* v_n_357_, lean_object* v_inst_358_, lean_object* v_a_359_, lean_object* v_b_360_){
_start:
{
uint8_t v_res_361_; lean_object* v_r_362_; 
v_res_361_ = lp_bounded_Bounded_BList_instDecidableEq(v_00_u03b1_356_, v_n_357_, v_inst_358_, v_a_359_, v_b_360_);
lean_dec(v_n_357_);
v_r_362_ = lean_box(v_res_361_);
return v_r_362_;
}
}
LEAN_EXPORT uint64_t lp_bounded_Bounded_BList_instHashable___redArg___lam__0(lean_object* v_inst_363_, uint64_t v_r_364_, lean_object* v_a_365_){
_start:
{
lean_object* v___x_366_; uint64_t v___x_367_; uint64_t v___x_368_; 
v___x_366_ = lean_apply_1(v_inst_363_, v_a_365_);
v___x_367_ = lean_unbox_uint64(v___x_366_);
lean_dec_ref(v___x_366_);
v___x_368_ = lean_uint64_mix_hash(v_r_364_, v___x_367_);
return v___x_368_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_BList_instHashable___redArg___lam__0___boxed(lean_object* v_inst_369_, lean_object* v_r_370_, lean_object* v_a_371_){
_start:
{
uint64_t v_r_boxed_372_; uint64_t v_res_373_; lean_object* v_r_374_; 
v_r_boxed_372_ = lean_unbox_uint64(v_r_370_);
lean_dec_ref(v_r_370_);
v_res_373_ = lp_bounded_Bounded_BList_instHashable___redArg___lam__0(v_inst_369_, v_r_boxed_372_, v_a_371_);
v_r_374_ = lean_box_uint64(v_res_373_);
return v_r_374_;
}
}
LEAN_EXPORT uint64_t lp_bounded_Bounded_BList_instHashable___redArg___lam__1(lean_object* v___f_377_, lean_object* v_l_378_){
_start:
{
lean_object* v___x_379_; lean_object* v___x_380_; uint64_t v___x_381_; 
v___x_379_ = ((lean_object*)(lp_bounded_Bounded_BList_instHashable___redArg___lam__1___boxed__const__1));
v___x_380_ = l_List_foldl___redArg(v___f_377_, v___x_379_, v_l_378_);
v___x_381_ = lean_unbox_uint64(v___x_380_);
lean_dec(v___x_380_);
return v___x_381_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_BList_instHashable___redArg___lam__1___boxed(lean_object* v___f_382_, lean_object* v_l_383_){
_start:
{
uint64_t v_res_384_; lean_object* v_r_385_; 
v_res_384_ = lp_bounded_Bounded_BList_instHashable___redArg___lam__1(v___f_382_, v_l_383_);
v_r_385_ = lean_box_uint64(v_res_384_);
return v_r_385_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_BList_instHashable___redArg(lean_object* v_inst_386_){
_start:
{
lean_object* v___f_387_; lean_object* v___f_388_; 
v___f_387_ = lean_alloc_closure((void*)(lp_bounded_Bounded_BList_instHashable___redArg___lam__0___boxed), 3, 1);
lean_closure_set(v___f_387_, 0, v_inst_386_);
v___f_388_ = lean_alloc_closure((void*)(lp_bounded_Bounded_BList_instHashable___redArg___lam__1___boxed), 2, 1);
lean_closure_set(v___f_388_, 0, v___f_387_);
return v___f_388_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_BList_instHashable(lean_object* v_00_u03b1_389_, lean_object* v_n_390_, lean_object* v_inst_391_){
_start:
{
lean_object* v___x_392_; 
v___x_392_ = lp_bounded_Bounded_BList_instHashable___redArg(v_inst_391_);
return v___x_392_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_BList_instHashable___boxed(lean_object* v_00_u03b1_393_, lean_object* v_n_394_, lean_object* v_inst_395_){
_start:
{
lean_object* v_res_396_; 
v_res_396_ = lp_bounded_Bounded_BList_instHashable(v_00_u03b1_393_, v_n_394_, v_inst_395_);
lean_dec(v_n_394_);
return v_res_396_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_BList_instFinEnum___redArg___lam__0(lean_object* v_n_397_, lean_object* v_l_398_){
_start:
{
lean_object* v___x_399_; uint8_t v___x_400_; 
v___x_399_ = l_List_lengthTR___redArg(v_l_398_);
v___x_400_ = lean_nat_dec_le(v___x_399_, v_n_397_);
lean_dec(v___x_399_);
if (v___x_400_ == 0)
{
lean_object* v___x_401_; 
lean_dec(v_l_398_);
v___x_401_ = lean_box(0);
return v___x_401_;
}
else
{
lean_object* v___x_402_; 
v___x_402_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_402_, 0, v_l_398_);
return v___x_402_;
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_BList_instFinEnum___redArg___lam__0___boxed(lean_object* v_n_403_, lean_object* v_l_404_){
_start:
{
lean_object* v_res_405_; 
v_res_405_ = lp_bounded_Bounded_BList_instFinEnum___redArg___lam__0(v_n_403_, v_l_404_);
lean_dec(v_n_403_);
return v_res_405_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_BList_instFinEnum___redArg(lean_object* v_n_406_, lean_object* v_inst_407_){
_start:
{
lean_object* v___f_408_; lean_object* v___x_409_; lean_object* v___x_410_; lean_object* v___x_411_; 
lean_inc(v_n_406_);
v___f_408_ = lean_alloc_closure((void*)(lp_bounded_Bounded_BList_instFinEnum___redArg___lam__0___boxed), 2, 1);
lean_closure_set(v___f_408_, 0, v_n_406_);
v___x_409_ = lp_bounded_Bounded_listsLE___redArg(v_inst_407_, v_n_406_);
lean_dec(v_n_406_);
v___x_410_ = ((lean_object*)(lp_bounded_Bounded_listsLE___redArg___closed__1));
v___x_411_ = l_List_filterMapTR_go___redArg(v___f_408_, v___x_409_, v___x_410_);
return v___x_411_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_BList_instFinEnum(lean_object* v_00_u03b1_412_, lean_object* v_n_413_, lean_object* v_inst_414_){
_start:
{
lean_object* v___x_415_; 
v___x_415_ = lp_bounded_Bounded_BList_instFinEnum___redArg(v_n_413_, v_inst_414_);
return v___x_415_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_BList_nil(lean_object* v_00_u03b1_416_, lean_object* v_n_417_){
_start:
{
lean_object* v___x_418_; 
v___x_418_ = lean_box(0);
return v___x_418_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_BList_nil___boxed(lean_object* v_00_u03b1_419_, lean_object* v_n_420_){
_start:
{
lean_object* v_res_421_; 
v_res_421_ = lp_bounded_Bounded_BList_nil(v_00_u03b1_419_, v_n_420_);
lean_dec(v_n_420_);
return v_res_421_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_BList_push___redArg(lean_object* v_n_422_, lean_object* v_l_423_, lean_object* v_x_424_){
_start:
{
lean_object* v___x_425_; lean_object* v___x_426_; lean_object* v___x_427_; uint8_t v___x_428_; 
v___x_425_ = l_List_lengthTR___redArg(v_l_423_);
v___x_426_ = lean_unsigned_to_nat(1u);
v___x_427_ = lean_nat_add(v___x_425_, v___x_426_);
lean_dec(v___x_425_);
v___x_428_ = lean_nat_dec_le(v___x_427_, v_n_422_);
lean_dec(v___x_427_);
if (v___x_428_ == 0)
{
lean_dec(v_x_424_);
return v_l_423_;
}
else
{
lean_object* v___x_429_; lean_object* v___x_430_; lean_object* v___x_431_; 
v___x_429_ = lean_box(0);
v___x_430_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_430_, 0, v_x_424_);
lean_ctor_set(v___x_430_, 1, v___x_429_);
v___x_431_ = l_List_appendTR___redArg(v_l_423_, v___x_430_);
return v___x_431_;
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_BList_push___redArg___boxed(lean_object* v_n_432_, lean_object* v_l_433_, lean_object* v_x_434_){
_start:
{
lean_object* v_res_435_; 
v_res_435_ = lp_bounded_Bounded_BList_push___redArg(v_n_432_, v_l_433_, v_x_434_);
lean_dec(v_n_432_);
return v_res_435_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_BList_push(lean_object* v_00_u03b1_436_, lean_object* v_n_437_, lean_object* v_l_438_, lean_object* v_x_439_){
_start:
{
lean_object* v___x_440_; 
v___x_440_ = lp_bounded_Bounded_BList_push___redArg(v_n_437_, v_l_438_, v_x_439_);
return v___x_440_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_BList_push___boxed(lean_object* v_00_u03b1_441_, lean_object* v_n_442_, lean_object* v_l_443_, lean_object* v_x_444_){
_start:
{
lean_object* v_res_445_; 
v_res_445_ = lp_bounded_Bounded_BList_push(v_00_u03b1_441_, v_n_442_, v_l_443_, v_x_444_);
lean_dec(v_n_442_);
return v_res_445_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_BList_head_x3f___redArg(lean_object* v_l_446_){
_start:
{
lean_object* v___x_447_; 
v___x_447_ = l_List_head_x3f___redArg(v_l_446_);
return v___x_447_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_BList_head_x3f___redArg___boxed(lean_object* v_l_448_){
_start:
{
lean_object* v_res_449_; 
v_res_449_ = lp_bounded_Bounded_BList_head_x3f___redArg(v_l_448_);
lean_dec(v_l_448_);
return v_res_449_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_BList_head_x3f(lean_object* v_00_u03b1_450_, lean_object* v_n_451_, lean_object* v_l_452_){
_start:
{
lean_object* v___x_453_; 
v___x_453_ = l_List_head_x3f___redArg(v_l_452_);
return v___x_453_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_BList_head_x3f___boxed(lean_object* v_00_u03b1_454_, lean_object* v_n_455_, lean_object* v_l_456_){
_start:
{
lean_object* v_res_457_; 
v_res_457_ = lp_bounded_Bounded_BList_head_x3f(v_00_u03b1_454_, v_n_455_, v_l_456_);
lean_dec(v_l_456_);
lean_dec(v_n_455_);
return v_res_457_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_BList_tail___redArg(lean_object* v_l_458_){
_start:
{
if (lean_obj_tag(v_l_458_) == 0)
{
return v_l_458_;
}
else
{
lean_object* v_tail_459_; 
v_tail_459_ = lean_ctor_get(v_l_458_, 1);
lean_inc(v_tail_459_);
return v_tail_459_;
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_BList_tail___redArg___boxed(lean_object* v_l_460_){
_start:
{
lean_object* v_res_461_; 
v_res_461_ = lp_bounded_Bounded_BList_tail___redArg(v_l_460_);
lean_dec(v_l_460_);
return v_res_461_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_BList_tail(lean_object* v_00_u03b1_462_, lean_object* v_n_463_, lean_object* v_l_464_){
_start:
{
if (lean_obj_tag(v_l_464_) == 0)
{
return v_l_464_;
}
else
{
lean_object* v_tail_465_; 
v_tail_465_ = lean_ctor_get(v_l_464_, 1);
lean_inc(v_tail_465_);
return v_tail_465_;
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_BList_tail___boxed(lean_object* v_00_u03b1_466_, lean_object* v_n_467_, lean_object* v_l_468_){
_start:
{
lean_object* v_res_469_; 
v_res_469_ = lp_bounded_Bounded_BList_tail(v_00_u03b1_466_, v_n_467_, v_l_468_);
lean_dec(v_l_468_);
lean_dec(v_n_467_);
return v_res_469_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_BList_isEmpty___redArg(lean_object* v_l_470_){
_start:
{
uint8_t v___x_471_; 
v___x_471_ = l_List_isEmpty___redArg(v_l_470_);
return v___x_471_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_BList_isEmpty___redArg___boxed(lean_object* v_l_472_){
_start:
{
uint8_t v_res_473_; lean_object* v_r_474_; 
v_res_473_ = lp_bounded_Bounded_BList_isEmpty___redArg(v_l_472_);
lean_dec(v_l_472_);
v_r_474_ = lean_box(v_res_473_);
return v_r_474_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_BList_isEmpty(lean_object* v_00_u03b1_475_, lean_object* v_n_476_, lean_object* v_l_477_){
_start:
{
uint8_t v___x_478_; 
v___x_478_ = l_List_isEmpty___redArg(v_l_477_);
return v___x_478_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_BList_isEmpty___boxed(lean_object* v_00_u03b1_479_, lean_object* v_n_480_, lean_object* v_l_481_){
_start:
{
uint8_t v_res_482_; lean_object* v_r_483_; 
v_res_482_ = lp_bounded_Bounded_BList_isEmpty(v_00_u03b1_479_, v_n_480_, v_l_481_);
lean_dec(v_l_481_);
lean_dec(v_n_480_);
v_r_483_ = lean_box(v_res_482_);
return v_r_483_;
}
}
LEAN_EXPORT lean_object* lp_bounded_List_mapTR_loop___at___00Bounded_BList_map_spec__0___redArg(lean_object* v_f_484_, lean_object* v_a_485_, lean_object* v_a_486_){
_start:
{
if (lean_obj_tag(v_a_485_) == 0)
{
lean_object* v___x_487_; 
lean_dec(v_f_484_);
v___x_487_ = l_List_reverse___redArg(v_a_486_);
return v___x_487_;
}
else
{
lean_object* v_head_488_; lean_object* v_tail_489_; lean_object* v___x_491_; uint8_t v_isShared_492_; uint8_t v_isSharedCheck_498_; 
v_head_488_ = lean_ctor_get(v_a_485_, 0);
v_tail_489_ = lean_ctor_get(v_a_485_, 1);
v_isSharedCheck_498_ = !lean_is_exclusive(v_a_485_);
if (v_isSharedCheck_498_ == 0)
{
v___x_491_ = v_a_485_;
v_isShared_492_ = v_isSharedCheck_498_;
goto v_resetjp_490_;
}
else
{
lean_inc(v_tail_489_);
lean_inc(v_head_488_);
lean_dec(v_a_485_);
v___x_491_ = lean_box(0);
v_isShared_492_ = v_isSharedCheck_498_;
goto v_resetjp_490_;
}
v_resetjp_490_:
{
lean_object* v___x_493_; lean_object* v___x_495_; 
lean_inc(v_f_484_);
v___x_493_ = lean_apply_1(v_f_484_, v_head_488_);
if (v_isShared_492_ == 0)
{
lean_ctor_set(v___x_491_, 1, v_a_486_);
lean_ctor_set(v___x_491_, 0, v___x_493_);
v___x_495_ = v___x_491_;
goto v_reusejp_494_;
}
else
{
lean_object* v_reuseFailAlloc_497_; 
v_reuseFailAlloc_497_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_497_, 0, v___x_493_);
lean_ctor_set(v_reuseFailAlloc_497_, 1, v_a_486_);
v___x_495_ = v_reuseFailAlloc_497_;
goto v_reusejp_494_;
}
v_reusejp_494_:
{
v_a_485_ = v_tail_489_;
v_a_486_ = v___x_495_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_BList_map___redArg(lean_object* v_f_499_, lean_object* v_l_500_){
_start:
{
lean_object* v___x_501_; lean_object* v___x_502_; 
v___x_501_ = lean_box(0);
v___x_502_ = lp_bounded_List_mapTR_loop___at___00Bounded_BList_map_spec__0___redArg(v_f_499_, v_l_500_, v___x_501_);
return v___x_502_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_BList_map(lean_object* v_00_u03b1_503_, lean_object* v_00_u03b2_504_, lean_object* v_n_505_, lean_object* v_f_506_, lean_object* v_l_507_){
_start:
{
lean_object* v___x_508_; 
v___x_508_ = lp_bounded_Bounded_BList_map___redArg(v_f_506_, v_l_507_);
return v___x_508_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_BList_map___boxed(lean_object* v_00_u03b1_509_, lean_object* v_00_u03b2_510_, lean_object* v_n_511_, lean_object* v_f_512_, lean_object* v_l_513_){
_start:
{
lean_object* v_res_514_; 
v_res_514_ = lp_bounded_Bounded_BList_map(v_00_u03b1_509_, v_00_u03b2_510_, v_n_511_, v_f_512_, v_l_513_);
lean_dec(v_n_511_);
return v_res_514_;
}
}
LEAN_EXPORT lean_object* lp_bounded_List_mapTR_loop___at___00Bounded_BList_map_spec__0(lean_object* v_00_u03b1_515_, lean_object* v_00_u03b2_516_, lean_object* v_f_517_, lean_object* v_a_518_, lean_object* v_a_519_){
_start:
{
lean_object* v___x_520_; 
v___x_520_ = lp_bounded_List_mapTR_loop___at___00Bounded_BList_map_spec__0___redArg(v_f_517_, v_a_518_, v_a_519_);
return v___x_520_;
}
}
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Init(uint8_t builtin);
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_bounded_Bounded_Basic(uint8_t builtin) {
lean_object * res;
if (_G_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_initialized = true;
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return lean_io_result_mk_ok(lean_box(0));
}
#ifdef __cplusplus
}
#endif
